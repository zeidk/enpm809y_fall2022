cmake_minimum_required(VERSION 3.8)
project(first_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

include_directories(include/first_package)


# add_executable(hello src/hello.cpp src/main.cpp)
# ament_target_dependencies(hello rclcpp)

# install(TARGETS 
# hello
# DESTINATION lib/${PROJECT_NAME})

add_executable(bot_pub_sub src/robot.cpp src/main.cpp)
ament_target_dependencies(bot_pub_sub rclcpp geometry_msgs nav_msgs)

install(TARGETS 
bot_pub_sub
DESTINATION lib/${PROJECT_NAME})

ament_package()
