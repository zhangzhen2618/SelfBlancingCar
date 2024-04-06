#pragma once

#ifndef __SELF_BLANCE_CAR__INTERFACE_HPP__
#define __SELF_BLANCE_CAR__INTERFACE_HPP__

#include <atomic>
#include <cassert>
#include <chrono>
#include <deque>
#include <functional>
#include <memory>
#include <mutex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <system_error>
#include <thread>
#include <unordered_map>
#include <vector>

#include <string.h>

#include "self_blance_car/thread_utils.hpp"

#define	PKG_MAX_LEN			              130

namespace SelfBlanceCar{

/**
 * @brief Common exception for communication error
 */
class DeviceError : public std::runtime_error{
public:
    /**
     * @breif Construct error.
     */
    template<typename T>
    DeviceError(const char * module, T msg)
    : std::runtime_error(make_message(module, msg)){

    }

		template<typename T>
		static std::string make_message(const char * module, T msg){
		std::ostringstream ss;
		ss << "DeviceError:" << module << ":" << msg_to_string(msg);
		return ss.str();
    }

    static std::string msg_to_string(const char * description){
      	return description;
    }

    static std::string msg_to_string(int errnum){
      	return ::strerror(errnum);
    }

    static std::string msg_to_string(std::system_error & err){
      	return err.what();
    }
};


}

#endif  // MAVCONN__INTERFACE_HPP_
