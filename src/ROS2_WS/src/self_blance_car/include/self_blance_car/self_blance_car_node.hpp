#pragma once
#ifndef __SELF_BLANCE_CAR_NODE_HPP__
#define __SELF_BLANCE_CAR_NODE_HPP__

#include "self_blance_car/serial.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"

#define     PACKED                  __attribute__((packed)) // Don't use byte align

namespace SelfBlanceCar{

class SBCar_node : public rclcpp::Node{

public:
    SBCar_node(
        std::string node_name = "self_blance_node",
        std::string port_name = "/dev/ttyUSB0",
        const unsigned baudrate = 2000000);

    ~SBCar_node();

private:

    static constexpr int MSG_BUF_MAX = 1000;

    // Protocol parameter
    static constexpr uint8_t PKG_HEADER = 0xA7;
    static constexpr uint8_t PKG_HEADER_SIZE = 2;
    static constexpr uint8_t PKG_DATA_MIN_SIZE = 1;
    static constexpr uint8_t PKG_CRC_SIZE = 2;

    static constexpr uint8_t PKG_HEADER_INDEX = 0;
    static constexpr uint8_t PKG_SIZE_INDEX = 1;
    static constexpr uint8_t PKG_DATA_INDEX = 2;

    struct PACKED pkg_t {
        uint8_t header;
        uint8_t len;
        uint16_t fcf;
        uint8_t seq_num;
        uint16_t dest_pan;
        uint16_t dest_addr;
        uint16_t src_pan;
        uint16_t src_addr;
        uint8_t error_count;
        uint8_t sub_header;
        uint8_t sub_size;
        uint8_t sub_seq_num;
        uint8_t ADXL345_ID;
        int16_t acc_x;
        int16_t acc_y;
        int16_t acc_z;
        uint8_t BM180_ID;
    };

    std::shared_ptr<SBCarSerial> serial_dev_;
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub_;

    // storage the message bytes stream
    std::array<uint8_t, MSG_BUF_MAX> msg_buf_;
    size_t msg_buf_ptr_ = 0;

    void joy_msg_cb_(const sensor_msgs::msg::Joy::SharedPtr joy_msg_ptr);

    void messages_parase_(const uint8_t* data, size_t len);
};

}; // namespace
#endif