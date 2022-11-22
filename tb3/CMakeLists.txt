cmake_minimum_required(VERSION 3.8)
project(tb3)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

add_executable(tf_broadcaster src/broadcaster.cpp)
ament_target_dependencies(tf_broadcaster rclcpp geometry_msgs tf2_ros)

add_executable(tf_listener src/listener.cpp)
ament_target_dependencies(tf_listener rclcpp geometry_msgs tf2_ros)


install(TARGETS 
tf_broadcaster
DESTINATION lib/${PROJECT_NAME})

install(TARGETS 
tf_listener
DESTINATION lib/${PROJECT_NAME})


install(DIRECTORY launch models urdf worlds rviz
  DESTINATION share/${PROJECT_NAME}/
)



ament_package()
