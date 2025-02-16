#pragma once
#ifndef __SELF_BLANCE_CAR_SERIAL_HPP__
#define __SELF_BLANCE_CAR_SERIAL_HPP__

#include <atomic>
#include <deque>
#include <string>

#include <asio.hpp>

#include <console_bridge/console.h>

#include "self_blance_car/interface.hpp"

namespace SelfBlanceCar{

class SBCarSerial : public std::enable_shared_from_this<SBCarSerial>{

public:
	SBCarSerial(
	    const std::string device = DEFAULT_DEVICE, 
	    const unsigned baudrate = DEFAULT_BAUDRATE, 
	    const bool hwflow = false);

	~SBCarSerial();

	static constexpr auto DEFAULT_DEVICE = "/dev/ttyUSB0";
	static constexpr auto DEFAULT_BAUDRATE = 115200;
    static constexpr size_t RX_BUF_MAX = 1000;
    
	void close();

	void send_bytes(const uint8_t * bytes, size_t length);

	inline bool is_open(){
		return serial_dev.is_open();
	}
 
	void connect(std::function<void (const uint8_t *, size_t)> parse_msg);

    inline int64_t get_total_bytes(){
        return total_bytes;
    }

    inline void set_lost_bytes(int64_t bytes_num){
        lost_bytes += bytes_num;
    }

    inline double get_lost_rate(void){
        return lost_bytes * 1.0 / total_bytes;
    }

private:
	asio::io_service io_service;
	std::thread io_thread;
	asio::serial_port serial_dev;
	//! Message receive callback
	// ReceivedCb message_received_cb;

	std::atomic<bool> tx_in_progress;
	std::recursive_mutex mutex;
	std::array<uint8_t, RX_BUF_MAX> rx_buf;
	std::vector<uint8_t> tx_q;

    // count the receive bytes
    int64_t total_bytes = 0;
    int64_t lost_bytes = 0;

    // parse_msg funcation
    std::function<void (const uint8_t *, size_t)> parse_msg;

	void do_read();
	void do_write(bool check_tx_state);
	void default_parse_msg(uint8_t * buf, const size_t bufsize, size_t bytes_received);
};

};  // namespace SelfBlanceCar

#endif 