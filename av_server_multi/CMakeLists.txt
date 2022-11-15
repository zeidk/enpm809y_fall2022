cmake_minimum_required(VERSION 3.8)
project(av_server_multi)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include/av_server_multi)


add_executable(av_server_multi src/server_multi.cpp src/main.cpp)
ament_target_dependencies(av_server_multi rclcpp std_msgs)

install(TARGETS 
av_server_multi
DESTINATION lib/${PROJECT_NAME})

ament_package()
