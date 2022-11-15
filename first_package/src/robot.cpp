#include <rclcpp/rclcpp.hpp>
#include "robot.h"

void Robot::timer_callback()
{
    RCLCPP_INFO(this->get_logger(), "Publishing data for the robot %s", m_robot_name.c_str());
    m_msg.linear.x = 1.0;
    m_msg.angular.z = 1.0;
    m_publisher->publish(m_msg);
}

void Robot::odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "x position: %f", msg->pose.pose.position.x);
    RCLCPP_INFO(this->get_logger(), "y position: %f", msg->pose.pose.position.y);
}

/**
 * @brief Callback function for the parameters
 *
 * @param parameters A vector of parameters to be set
 * @return rcl_interfaces::msg::SetParametersResult
 */
rcl_interfaces::msg::SetParametersResult Robot::parameters_callback(
    const std::vector<rclcpp::Parameter> &parameters)
{
    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;
    result.reason = "success";
    // Here update class attributes, do some actions, etc.
    for (const auto &parameter : parameters)
    {
        RCLCPP_INFO(this->get_logger(), "%s", parameter.get_name().c_str());
        RCLCPP_INFO(this->get_logger(), "%s", parameter.get_type_name().c_str());
        RCLCPP_INFO(this->get_logger(), "%s", parameter.value_to_string().c_str());

        if (parameter.get_name() == "robot_name" && parameter.get_type() == rclcpp::ParameterType::PARAMETER_STRING)
        {
            m_robot_name = parameter.as_string();
            RCLCPP_INFO(this->get_logger(), ("Parameter 'm_robot_name' changed: " + m_robot_name).c_str());
        }
    }

    return result;
}

// 15 (105 12
