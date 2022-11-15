#include <string>
#include "server.h"
using namespace std::chrono_literals;

void Server::camera1_callback(const std_msgs::msg::Float64::SharedPtr msg)
{
    RCLCPP_INFO_STREAM(this->get_logger(), "Received data: " << msg->data << " from camera1\n");
}

void Server::camera2_callback(const std_msgs::msg::Float64::SharedPtr msg)
{
    RCLCPP_INFO_STREAM(this->get_logger(), "Received data: " << msg->data << " from camera2\n");
}

void Server::camera3_callback(const std_msgs::msg::Float64::SharedPtr msg)
{
    RCLCPP_INFO_STREAM(this->get_logger(), "Received data: " << msg->data << " from camera3\n");
}

void Server::camera4_callback(const std_msgs::msg::Float64::SharedPtr msg)
{
    RCLCPP_INFO_STREAM(this->get_logger(), "Received data: " << msg->data << " from camera4\n");
}

std::string Server::timing_string()
{
    rclcpp::Time time = this->now();
    return std::to_string(time.nanoseconds());
}