cmake_minimum_required(VERSION 3.8)
project(first_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
# find_package(geometry_msgs REQUIRED)
# find_package(nav_msgs REQUIRED)


#----- Hello class: start -----
add_executable(hello src/main.cpp)
ament_target_dependencies(hello rclcpp)

install(TARGETS 
hello
DESTINATION lib/${PROJECT_NAME})
#----- Hello class: end -----


#----- Robot class: start -----
# include_directories(include/first_package)

# add_executable(bot_pub_sub src/main.cpp src/robot.cpp)
# ament_target_dependencies(bot_pub_sub rclcpp geometry_msgs nav_msgs)

# install(TARGETS 
# bot_pub_sub
# DESTINATION lib/${PROJECT_NAME})
#----- Robot class: end -----



ament_package()
