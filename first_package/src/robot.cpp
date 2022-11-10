#include <rclcpp/rclcpp.hpp>
#include "robot.h"

void Robot::timer_callback()
{
    RCLCPP_INFO(this->get_logger(), "Publishing");
    m_msg.linear.x = 1.0;
    m_msg.angular.z = 1.0;
    m_publisher->publish(m_msg);
}

void Robot::odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "x position: %f", msg->pose.pose.position.x);
    RCLCPP_INFO(this->get_logger(), "y position: %f", msg->pose.pose.position.y);
}

rcl_interfaces::msg::SetParametersResult Robot::parameters_callback(
    const std::vector<rclcpp::Parameter> &parameters)
{
    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;
    result.reason = "success";
    // Here update class attributes, do some actions, etc.
    for (const auto &param : parameters)
    {
        RCLCPP_INFO(this->get_logger(), "%s", param.get_name().c_str());
        RCLCPP_INFO(this->get_logger(), "%s", param.get_type_name().c_str());
        RCLCPP_INFO(this->get_logger(), "%s", param.value_to_string().c_str());

        if (param.get_name() == "publisher_frequency")
        {
            m_publisher_frequency = param.as_double();
        }
    }

    return result;
}

// 15 (105 12
