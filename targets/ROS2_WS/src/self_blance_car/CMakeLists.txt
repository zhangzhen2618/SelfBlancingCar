cmake_minimum_required(VERSION 3.8)
project(self_blance_car )

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

## System dependencies are found with CMake's conventions
find_package(console_bridge REQUIRED)
find_package(ASIO REQUIRED)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

include_directories(
  	include
  	${ASIO_INCLUDE_DIRS}
  	${console_bridge_INCLUDE_DIRS}
)
set_source_files_properties(
  ${PROJECT_SOURCE_DIR}/../../../../lib/common/src/crc.c 
  PROPERTIES LANGUAGE CXX )
  
add_executable(serial_node
    ${PROJECT_SOURCE_DIR}/../../../../lib/common/src/crc.c
    src/serial.cpp
    src/self_blance_car_node.cpp
    src/self_blance_car_node_main.cpp)

target_include_directories(serial_node
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/../../../../lib/common/include
)
ament_target_dependencies(
  serial_node 
  console_bridge 
  rclcpp 
  sensor_msgs)

install(TARGETS
	serial_node
	DESTINATION lib/${PROJECT_NAME})
            
install(DIRECTORY include/
  DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
