cmake_minimum_required(VERSION 3.8)
project(av_server)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include/av_server)


add_executable(av_server src/server.cpp src/main.cpp)
ament_target_dependencies(av_server rclcpp std_msgs)

install(TARGETS 
av_server
DESTINATION lib/${PROJECT_NAME})

ament_package()
