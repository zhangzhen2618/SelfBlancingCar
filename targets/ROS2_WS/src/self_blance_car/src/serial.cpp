#include <linux/serial.h>

#include <cassert>
#include <string>

#include "self_blance_car/serial.hpp"
#include "self_blance_car/thread_utils.hpp"

#include <iostream>

using namespace SelfBlanceCar;

using asio::buffer;
using asio::io_service;
using std::error_code;
using std::lock_guard;

SBCarSerial::SBCarSerial(
    const std::string device, 
    const unsigned baudrate,
	const bool hwflow)
	: io_service(),
	serial_dev(io_service),
	tx_in_progress(false),
    parse_msg(nullptr){

  	using SPB = asio::serial_port_base;
	
  	CONSOLE_BRIDGE_logInform("device: %s @ %d bps", device.c_str(), baudrate);

	try {
		serial_dev.open(device);

		// Set baudrate and 8N1 mode
		serial_dev.set_option(SPB::baud_rate(baudrate));
		serial_dev.set_option(SPB::character_size(8));
		serial_dev.set_option(SPB::parity(SPB::parity::none));
		serial_dev.set_option(SPB::stop_bits(SPB::stop_bits::one));

		// Flow control setting in older versions of ASIO is broken, use workaround (below) for now.
		serial_dev.set_option(
		SPB::flow_control(
			(hwflow) ? SPB::flow_control::hardware : SPB::flow_control::none));
		// Enable low latency mode on Linux
		{
			int fd = serial_dev.native_handle();

			struct serial_struct ser_info;
			ioctl(fd, TIOCGSERIAL, &ser_info);

			ser_info.flags |= ASYNC_LOW_LATENCY;

			ioctl(fd, TIOCSSERIAL, &ser_info);
		}
	} catch (asio::system_error & err) {
		throw DeviceError("serial", err);
	}
}

SBCarSerial::~SBCarSerial(){
  	close();
}

void SBCarSerial::connect(std::function<void (const uint8_t *, size_t)> msg_cb){
    
    parse_msg = msg_cb;
	// message_received_cb = cb_handle_message;

	// give some work to io_service before start
	io_service.post(std::bind(&SBCarSerial::do_read, this));

	CONSOLE_BRIDGE_logInform("serial read thread created!!!");

	// run io_service for async io
	io_thread = std::thread(
		[this]() {
			utils::set_this_thread_name("mserial");
			io_service.run();
		});
	
}

void SBCarSerial::close(){

	lock_guard lock(mutex);
	if (!is_open()) {
		return;
	}

	serial_dev.cancel();
	serial_dev.close();

	io_service.stop();

	if (io_thread.joinable()) {
		io_thread.join();
	}

	io_service.reset();
}

void SBCarSerial::send_bytes(const uint8_t * bytes, size_t length){
	if (!is_open()) {
		CONSOLE_BRIDGE_logError("send: channel closed!");
		return;
	}

	{
		lock_guard lock(mutex);

		while(length--){
			tx_q.emplace_back(*bytes);
			bytes++;
		}
	}
	io_service.post(std::bind(&SBCarSerial::do_write, shared_from_this(), true));
}


void SBCarSerial::do_read(void){

	auto sthis = shared_from_this();
	serial_dev.async_read_some(
		buffer(rx_buf),
		[sthis](error_code error, size_t bytes_transferred) {
		if (error) {
			CONSOLE_BRIDGE_logError("receive: %s", error.message().c_str());
			sthis->close();
			return;
		}
        if (sthis->parse_msg != nullptr){
            sthis->parse_msg(sthis->rx_buf.data(), bytes_transferred);
        }else{
		    sthis->default_parse_msg(sthis->rx_buf.data(), bytes_transferred);
        }
        sthis->total_bytes += bytes_transferred;
		sthis->do_read();
    });
}

void SBCarSerial::default_parse_msg(uint8_t * buf,  size_t bytes_received){
    static int count = 0;
    std::cout << count++ << ", num, " << bytes_received << " : ";
	std::cout << std::hex;
	for(int i = 0; i < bytes_received; i++){
		std::cout << (int)buf[i] << " ";
	}
	std::cout << std::dec << std::endl;

}

void SBCarSerial::do_write(bool check_tx_state){

	if (check_tx_state && tx_in_progress) {
		return;
	}

	lock_guard lock(mutex);

	if (tx_q.empty()) {
		return;
	}

	tx_in_progress = true;
	auto sthis = shared_from_this();
	// auto & buf_ref = tx_q.front();
	serial_dev.async_write_some(

		buffer(tx_q.data(), tx_q.size()),

		[sthis](error_code error, size_t bytes_transferred) {

            assert(ssize_t(bytes_transferred) <= sthis->tx_q.size());

            if (error) {
                CONSOLE_BRIDGE_logError("write: %s", error.message().c_str());
                sthis->close();
                return;
            }

            // sthis->iostat_tx_add(bytes_transferred);
            lock_guard lock(sthis->mutex);

            sthis->tx_q.erase(sthis->tx_q.begin(), sthis->tx_q.begin() + bytes_transferred);
            
            if (sthis->tx_q.empty()) {
                sthis->tx_in_progress = false;
                return;
            }

            if (!sthis->tx_q.empty()) {
                sthis->do_write(false);
            } else {
                sthis->tx_in_progress = false;
            }
	});
}

