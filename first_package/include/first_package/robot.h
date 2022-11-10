#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include "rcl_interfaces/msg/set_parameters_result.hpp"

// timer
class Robot : public rclcpp::Node
{
public:
    Robot(std::string node_name) : Node(node_name)
    {
        m_timer = this->create_wall_timer(std::chrono::seconds(1),
                                          std::bind(&Robot::timer_callback, this));
        // parameters
        this->declare_parameter("publisher_frequency", 1.0);
        m_publisher_frequency = this->get_parameter("publisher_frequency").as_double();
        m_parameters_handle = this->add_on_set_parameters_callback(
            std::bind(&Robot::parameters_callback, this, std::placeholders::_1));

        // publisher
        m_msg = geometry_msgs::msg::Twist();
        m_publisher = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        // subscriber
        m_subscriber = this->create_subscription<nav_msgs::msg::Odometry>("odom", 10, std::bind(&Robot::odom_callback, this, std::placeholders::_1));
    }

private:
    // attributes
    rclcpp::TimerBase::SharedPtr m_timer;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr m_publisher;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr m_subscriber;
    OnSetParametersCallbackHandle::SharedPtr m_parameters_handle;
    geometry_msgs::msg::Twist m_msg;
    double m_publisher_frequency;
    // methods
    void timer_callback();
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
    rcl_interfaces::msg::SetParametersResult parameters_callback(
        const std::vector<rclcpp::Parameter> &parameters);
};