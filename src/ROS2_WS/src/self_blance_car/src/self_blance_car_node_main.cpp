#include "self_blance_car/self_blance_car_node.hpp"

using namespace std::chrono_literals;

int main(int argc, const char** argv) {

    rclcpp::init(argc, argv);
    
    console_bridge::setLogLevel(console_bridge::CONSOLE_BRIDGE_LOG_DEBUG);

    std::shared_ptr<SelfBlanceCar::SBCar_node> node_ptr;

    if (argc == 2){
        node_ptr = 
            std::make_shared<SelfBlanceCar::SBCar_node>(
                "SBC_node", argv[1], 2000000);
    }else{
        node_ptr = 
            std::make_shared<SelfBlanceCar::SBCar_node>(
                "SBC_node", "/dev/ttyUSB0", 2000000);
    }

    rclcpp::spin(node_ptr);    

    return 0;
}

