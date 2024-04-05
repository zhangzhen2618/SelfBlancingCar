#include "self_blance_car/serial.hpp"
#include <iostream>

using namespace SelfBlanceCar;

int main(int argc, const char** argv) {

    std::shared_ptr<SBCarSerial> my_serial = std::make_shared<SBCarSerial>("/dev/ttyUSB0", 2000000);

    my_serial->connect([](std::array<uint8_t, PKG_MAX_LEN> arr){
        std::cout << "arr size : " << arr.size() << std::endl;
        for(int i = 0; i < arr.size(); i++){
            printf("%c", arr[i]);
        }
    });
    while(true){

    }
    

    return 0;
}