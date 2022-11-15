#include <rclcpp/rclcpp.hpp>
#include "camera.h"

void Camera::timer_callback()
{
    m_msg.data = 1.5;
    RCLCPP_INFO_STREAM(this->get_logger(), m_camera_name << " is publishing data: " << m_msg.data);
    m_publisher->publish(m_msg);
}

/**
 * @brief Callback function for the parameters
 *
 * @param parameters A vector of parameters to be set
 * @return rcl_interfaces::msg::SetParametersResult
 */
rcl_interfaces::msg::SetParametersResult Camera::parameters_callback(
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

        if (parameter.get_name() == "camera_name" && parameter.get_type() == rclcpp::ParameterType::PARAMETER_STRING)
        {
            m_camera_name = parameter.as_string();
            RCLCPP_INFO(this->get_logger(), ("Parameter 'm_camera_name' changed: " + m_camera_name).c_str());
        }
        else if (parameter.get_name() == "camera_bandwidth" && parameter.get_type() == rclcpp::ParameterType::PARAMETER_INTEGER)
        {
            m_camera_bandwidth = parameter.as_int();
            RCLCPP_INFO_STREAM(this->get_logger(), "Parameter 'm_camera_bandwidth' changed: " << m_camera_bandwidth);
        }
    }

    return result;
}

// 15 (105 12
