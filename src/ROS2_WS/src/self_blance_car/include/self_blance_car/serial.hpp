//
// libmavconn
// Copyright 2013,2014,2015,2016,2021 Vladimir Ermakov, All rights reserved.
//
// This file is part of the mavros package and subject to the license terms
// in the top-level LICENSE file of the mavros repository.
// https://github.com/mavlink/mavros/tree/master/LICENSE.md
//
/**
 * @brief MAVConn Serial link class
 * @file serial.h
 * @author Vladimir Ermakov <vooon341@gmail.com>
 *
 * @addtogroup mavconn
 * @{
 */

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

/**
 * @brief Serial interface
 */
class SBCarSerial : public std::enable_shared_from_this<SBCarSerial>{

public:
	static constexpr auto DEFAULT_DEVICE = "/dev/ttyUSB0";
	static constexpr auto DEFAULT_BAUDRATE = 115200;

	/**
	 * Open and run serial link.
	 *
	 * @param[in] device    TTY device path
	 * @param[in] baudrate  serial baudrate
	 */
	SBCarSerial(
		std::string device = DEFAULT_DEVICE, 
		unsigned baudrate = DEFAULT_BAUDRATE, 
		bool hwflow = false);

	~SBCarSerial();

	void close();

	void send_bytes(const uint8_t * bytes, size_t length);

	inline bool is_open(){
		return serial_dev.is_open();
	}
	void connect(const ReceivedCb & cb_handle_message);

private:
	asio::io_service io_service;
	std::thread io_thread;
	asio::serial_port serial_dev;
	//! Message receive callback
	ReceivedCb message_received_cb;

	std::atomic<bool> tx_in_progress;
	std::recursive_mutex mutex;
	std::array<uint8_t, PKG_MAX_LEN> rx_buf;

	void do_read();
	void do_write(bool check_tx_state);
};

};  // namespace mavconn

#endif  // MAVCONN__SERIAL_HPP_