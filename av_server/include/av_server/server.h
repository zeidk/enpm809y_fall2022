#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include "rcl_interfaces/msg/set_parameters_result.hpp"
#include <string>

// timer
class Server : public rclcpp::Node
{
public:
    Server(std::string node_name) : Node(node_name)
    {
        m_subscriber_camera1 = this->create_subscription<std_msgs::msg::Float64>("camera1_image", 10, std::bind(&Server::camera1_callback, this, std::placeholders::_1));
        m_subscriber_camera2 = this->create_subscription<std_msgs::msg::Float64>("camera2_image", 10, std::bind(&Server::camera2_callback, this, std::placeholders::_1));
        m_subscriber_camera3 = this->create_subscription<std_msgs::msg::Float64>("camera3_image", 10, std::bind(&Server::camera3_callback, this, std::placeholders::_1));
        m_subscriber_camera4 = this->create_subscription<std_msgs::msg::Float64>("camera4_image", 10, std::bind(&Server::camera4_callback, this, std::placeholders::_1));
    }

private:
    // attributes
    std_msgs::msg::Float64 m_msg;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr m_subscriber_camera1;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr m_subscriber_camera2;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr m_subscriber_camera3;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr m_subscriber_camera4;

    // methods
    void camera1_callback(const std_msgs::msg::Float64::SharedPtr msg);
    void camera2_callback(const std_msgs::msg::Float64::SharedPtr msg);
    void camera3_callback(const std_msgs::msg::Float64::SharedPtr msg);
    void camera4_callback(const std_msgs::msg::Float64::SharedPtr msg);

    /**
     * Simple function for generating a timestamp
     * Used for somewhat ineffectually demonstrating that the multithreading doesn't cripple performace
     */
    std::string timing_string();
};