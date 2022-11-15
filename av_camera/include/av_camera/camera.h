#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include "rcl_interfaces/msg/set_parameters_result.hpp"
#include <string>

// timer
class Camera : public rclcpp::Node
{
public:
    Camera(std::string node_name) : Node(node_name)
    {
        // parameters
        this->declare_parameter("camera_frequency", 24.0);
        this->declare_parameter("camera_bandwidth", 2);
        this->declare_parameter("camera_name", "camera_name");

        m_camera_frequency = this->get_parameter("camera_frequency").as_double();
        m_camera_bandwidth = this->get_parameter("camera_bandwidth").as_int();
        m_camera_name = this->get_parameter("camera_name").as_string();
        m_parameters_handle = this->add_on_set_parameters_callback(
            std::bind(&Camera::parameters_callback, this, std::placeholders::_1));

        // camera publishing data to server
        m_timer = this->create_wall_timer(std::chrono::milliseconds((int)(1000.0 / m_camera_frequency)),
                                          std::bind(&Camera::timer_callback, this));

        // publisher
        m_msg = std_msgs::msg::Float64();
        // use the camera name as the topic name
        m_publisher = this->create_publisher<std_msgs::msg::Float64>("camera_image", 10);
    }

private:
    // attributes
    rclcpp::TimerBase::SharedPtr m_timer;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr m_publisher;
    OnSetParametersCallbackHandle::SharedPtr m_parameters_handle;
    std_msgs::msg::Float64 m_msg;
    double m_camera_frequency;
    int m_camera_bandwidth;
    std::string m_camera_name;

    // methods
    void timer_callback();
    rcl_interfaces::msg::SetParametersResult parameters_callback(
        const std::vector<rclcpp::Parameter> &parameters);
};