#include "self_blance_car/serial.hpp"
#include <iostream>
#include "rclcpp/rclcpp.hpp"

using namespace SelfBlanceCar;
using namespace std::chrono_literals;

int main(int argc, const char** argv) {

    rclcpp::init(argc, argv);

    console_bridge::setLogLevel(console_bridge::CONSOLE_BRIDGE_LOG_DEBUG);

    std::shared_ptr<SBCarSerial> my_serial = std::make_shared<SBCarSerial>("/dev/ttyUSB0", 2000000);

    my_serial->connect();

    rclcpp::Node::SharedPtr node_ptr = rclcpp::Node::make_shared("serial_node");

    auto timer = node_ptr->create_wall_timer(1s, [my_serial](void){
        const uint8_t char_h = 'A';
        my_serial->send_bytes(&char_h, 1);
    });

    rclcpp::spin(node_ptr);    

    return 0;
}