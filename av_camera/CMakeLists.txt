cmake_minimum_required(VERSION 3.8)
project(av_camera)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include/av_camera)


add_executable(av_camera src/camera.cpp src/main.cpp)
ament_target_dependencies(av_camera rclcpp std_msgs)

install(TARGETS 
av_camera
DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
