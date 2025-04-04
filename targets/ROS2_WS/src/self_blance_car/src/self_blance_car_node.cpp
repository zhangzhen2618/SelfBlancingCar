#include "self_blance_car/self_blance_car_node.hpp"

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

    // Append the incoming data to the message buffer
    this->msg_buf_.insert(this->msg_buf_.end(), data, data + size);

msg_pase_start:
    // to find the protol header
    size_t protol_i = 0;
    for(; protol_i < msg_buf_.size(); protol_i++){
        if (msg_buf_[protol_i] == PROTO_SYN_HEADER){
            break;
        }
    }

    // remove the bytes, let the msg_buf begain with the PROTO_SYN_HEADER
    if(protol_i != 0){
        std::cout << "lost bytes : " << protol_i << " bytes" << std::endl;
        std::cout << "\t" << std::hex;
        for(size_t i = 0; i < protol_i; i++){
            std::cout << (this->msg_buf_[i] & 0xff) << " ";
        }
        std::cout << std::dec << std::endl;
        this->serial_dev_->set_lost_bytes(protol_i);
        msg_buf_.erase(msg_buf_.cbegin(), msg_buf_.cbegin() + protol_i);
    }

    // check the msg_buf length is enough or not
    if (msg_buf_.size() < PROTO_HEADER_SIZE || 
        msg_buf_.size() < msg_buf_[PROTO_LEN_INDEX] + PROTO_HEADER_SIZE + PROTO_CRC_SIZE){
        // msg_buf bytes is not enough
        return;
    }

    // crc check
    if (*(uint16_t *)(msg_buf_.data() + msg_buf_[PROTO_LEN_INDEX] + PROTO_HEADER_SIZE) != 
        crc16_calc(msg_buf_.data() + PROTO_NUM_INDEX, msg_buf_[PROTO_LEN_INDEX], DEFAULT_CRC_START_VALUE)){
            
        RCLCPP_WARN(this->get_logger(), "CRC ERROR !!!");
        // change the syn header reparse
        msg_buf_[PROTO_SYN_INDEX] = ~PROTO_SYN_HEADER;
        goto msg_pase_start;
    }

    switch (msg_buf_[PROTO_CMD_INDEX])
    {
    case PROTO_HEART_ID:
        {
            PROTO_HEART *heat_ = (PROTO_HEART *)(msg_buf_.data() + PROTO_DATA_INDEX);
            std::cout << "HEAT MSG : " << std::endl;
            std::cout << "\tnumber : " << (int)(msg_buf_[PROTO_NUM_INDEX]) << std::hex << std::endl;
            std::cout << "\tcontrol chip id : " << heat_->control_chip_id << std::endl;
            std::cout << "\tlocal chip id : " << heat_->local_chip_id << std::endl;
            std::cout << "\tremote chip id : " << heat_->remote_chip_id << std::endl;
            std::cout << std::dec << std::endl;
        }
        break;
    
    default:
        break;
    }


    // remove the bytes that have parsed
    msg_buf_.erase(msg_buf_.cbegin(), 
        msg_buf_.cbegin() + msg_buf_[PROTO_LEN_INDEX] + PROTO_HEADER_SIZE + PROTO_CRC_SIZE);
    goto msg_pase_start;
    // std::cout << "msg : " << std::endl;
    // std::cout << "\t" << std::hex;
    // for(size_t i = 0; i < this->msg_buf_.size(); i++){
    //     std::cout << (this->msg_buf_[i] & 0xff) << " ";
    // }
    // std::cout << std::dec << std::endl;
    // this->msg_buf_.clear();
    // copy the data to the messages buffer
    // memmove(msg_buf_.data() + msg_buf_ptr_, data, msg_size);

    // msg_buf_ptr_ += msg_size;

    // // To find the pkg header
    // size_t i = 0;
    // while(i < msg_buf_ptr_){
    //     if (msg_buf_[i] == PKG_HEADER){
    //         break;
    //     }

    //     i++;
    // }

    // if (i != 0){
    //     RCLCPP_WARN(get_logger(), "lost %d bytes", i);

    //     std::cout << "Data : ";
    //     std::cout << std::hex;

    //     for(int j = 0; j < i; j++){
    //         std::cout << (msg_buf_[j] & 0xff) << " ";
    //     }

    //     std::cout << std::dec << std::endl;
    //     memmove(msg_buf_.data(), msg_buf_.data() + i, msg_buf_ptr_ - i);
    //     msg_buf_ptr_ -= i;
    // }

    // // check the data_buf bytes num is enough or not
    // if (msg_buf_ptr_ < PKG_HEADER_SIZE + PKG_DATA_MIN_SIZE + PKG_CRC_SIZE || 
    //     msg_buf_ptr_ < PKG_HEADER_SIZE + msg_buf_[PKG_DATA_INDEX]){
        
    //     return;
    // }

    // // check the crc is right or not
    // uint16_t data_crc = *(uint16_t *)(msg_buf_.data() + 
    //             PKG_HEADER_SIZE + msg_buf_[PKG_SIZE_INDEX] - PKG_CRC_SIZE);
    // uint16_t now_crc =  crc16_calc(msg_buf_.data() + PKG_DATA_INDEX, 
    //                                 msg_buf_[PKG_SIZE_INDEX] - PKG_CRC_SIZE, 
    //                                 DEFAULT_CRC_START_VALUE);
    // if (data_crc != now_crc){
    
    //     msg_buf_[PKG_HEADER_INDEX] = ~PKG_HEADER;
    //     RCLCPP_WARN(get_logger(), "CRC ERROR!!, data crc %X, now crc : %X", data_crc, now_crc);
    //     // CRC ERROR return
    //     return;        
    // }

    // // std::cout << "Size : " << ((msg_buf_[PKG_SIZE_INDEX] + PKG_HEADER_SIZE) & 0xff)
    // //         << ", data : ";
    // // std::cout << std::hex;

    // // for(int i = 0; i < msg_buf_[PKG_SIZE_INDEX] + PKG_HEADER_SIZE; i++){
    // //     std::cout << (msg_buf_[i] & 0xff) << " ";
    // // }

    // // std::cout << std::dec << std::endl;

    // pkg_t *pkg_type = (pkg_t*)(msg_buf_.data());

    // RCLCPP_INFO(get_logger(), "\nHeader : 0X%X, Size : %d, fcf : 0X%X, seq_num : %d"
    // "\ndest_pan : 0X%X, dest_addr 0X%X, src_pan : 0X%X, src_addr : 0X%X"
    // "\nerror_count : %d, sub_header : 0X%X, sub_size : %d, sub_seq_num : %d"
    // "\nADXL345_ID : 0X%X, acc_x : %f, acc_y : %f, acc_z : %f"
    // "\nBM180_ID : 0X%X",
    //     pkg_type->header & 0xff, pkg_type->len, pkg_type->fcf & 0xffff, pkg_type->seq_num,
    //     pkg_type->dest_pan & 0xffff, pkg_type->dest_addr & 0xffff, 
    //     pkg_type->src_pan & 0xffff, pkg_type->src_addr & 0xffff,
    //     pkg_type->error_count, pkg_type->sub_header & 0xff, pkg_type->sub_size, pkg_type->sub_seq_num,
    //     pkg_type->ADXL345_ID & 0xff, 
    //     pkg_type->acc_x * 39.0 / 1000.0, pkg_type->acc_y * 39.0 / 1000, pkg_type->acc_z * 39.0 / 1000,
    //     pkg_type->BM180_ID & 0xff
    //     );

    // msg_buf_ptr_ -= (PKG_HEADER_SIZE + msg_buf_[PKG_SIZE_INDEX]);

    // if (msg_buf_ptr_ != 0){
    //     memmove(msg_buf_.data(), msg_buf_.data() + PKG_HEADER_SIZE + msg_buf_[PKG_SIZE_INDEX], msg_buf_ptr_);
    // }
}