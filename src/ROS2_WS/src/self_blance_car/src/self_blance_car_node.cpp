#include "self_blance_car/self_blance_car_node.hpp"
#include "crc.h"

using namespace SelfBlanceCar;

SBCar_node::SBCar_node(
    const std::string node_name,
    const std::string port_name,
    const unsigned baudrate):
    Node(node_name){
    
    crc16_init(DEFAULT_CRC_BITS, DEFAULT_CRC_POLY);

    serial_dev_ = std::make_shared<SBCarSerial>(port_name, baudrate);

    serial_dev_->connect(std::bind(&SBCar_node::messages_parase_, this, 
                                    std::placeholders::_1, std::placeholders::_2));

    this->joy_sub_ = this->create_subscription<sensor_msgs::msg::Joy>(
        "/joy", 10,
        std::bind(&SBCar_node::joy_msg_cb_, this, std::placeholders::_1));

}

SBCar_node::~SBCar_node(){

}

void SBCar_node::joy_msg_cb_(
    const sensor_msgs::msg::Joy::SharedPtr joy_msg_ptr_){

}

void SBCar_node::messages_parase_(const uint8_t *data, size_t size){

    size_t msg_size = size;

    // checked the buffer is full or not
    if (this->msg_buf_ptr_ + size > this->msg_buf_.size()){
        msg_size = msg_buf_.size() - this->msg_buf_ptr_;
        RCLCPP_WARN(get_logger(), "Messages buffer is full, will lost %d bytes!!", 
            this->msg_buf_ptr_ + size - this->msg_buf_.size());
    }

    // no new data come in, return
    if (size == 0){
        return;
    }

    // copy the data to the messages buffer
    memmove(msg_buf_.data() + msg_buf_ptr_, data, msg_size);

    msg_buf_ptr_ += msg_size;

    // To find the pkg header
    size_t i = 0;
    while(i < msg_buf_ptr_){
        if (msg_buf_[i] == PKG_HEADER){
            break;
        }

        i++;
    }

    if (i != 0){
        RCLCPP_WARN(get_logger(), "lost %d bytes", i);

        std::cout << "Data : ";
        std::cout << std::hex;

        for(int j = 0; j < i; j++){
            std::cout << (msg_buf_[j] & 0xff) << " ";
        }

        std::cout << std::dec << std::endl;
        memmove(msg_buf_.data(), msg_buf_.data() + i, msg_buf_ptr_ - i);
        msg_buf_ptr_ -= i;
    }

    // check the data_buf bytes num is enough or not
    if (msg_buf_ptr_ < PKG_HEADER_SIZE + PKG_DATA_MIN_SIZE + PKG_CRC_SIZE || 
        msg_buf_ptr_ < PKG_HEADER_SIZE + msg_buf_[PKG_DATA_INDEX]){
        
        return;
    }

    // check the crc is right or not
    uint16_t data_crc = *(uint16_t *)(msg_buf_.data() + 
                PKG_HEADER_SIZE + msg_buf_[PKG_SIZE_INDEX] - PKG_CRC_SIZE);
    uint16_t now_crc =  crc16_calc(msg_buf_.data() + PKG_DATA_INDEX, 
                                    msg_buf_[PKG_SIZE_INDEX] - PKG_CRC_SIZE, 
                                    DEFAULT_CRC_START_VALUE);
    if (data_crc != now_crc){
    
        msg_buf_[PKG_HEADER_INDEX] = ~PKG_HEADER;
        RCLCPP_WARN(get_logger(), "CRC ERROR!!, data crc %X, now crc : %X", data_crc, now_crc);
        // CRC ERROR return
        return;        
    }

    std::cout << "Size : " << ((msg_buf_[PKG_SIZE_INDEX] + PKG_HEADER_SIZE) & 0xff)
            << ", data : ";
    std::cout << std::hex;

    for(int i = 0; i < msg_buf_[PKG_SIZE_INDEX] + PKG_HEADER_SIZE; i++){
        std::cout << (msg_buf_[i] & 0xff) << " ";
    }

    std::cout << std::dec << std::endl;

    msg_buf_ptr_ -= (PKG_HEADER_SIZE + msg_buf_[PKG_SIZE_INDEX]);

    if (msg_buf_ptr_ != 0){
        memmove(msg_buf_.data(), msg_buf_.data() + PKG_HEADER_SIZE + msg_buf_[PKG_SIZE_INDEX], msg_buf_ptr_);
    }
}