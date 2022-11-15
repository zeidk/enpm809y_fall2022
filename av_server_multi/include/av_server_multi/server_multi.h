#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include "rcl_interfaces/msg/set_parameters_result.hpp"
#include <string>

class ServerMulti : public rclcpp::Node
{
public:
    ServerMulti(std::string node_name) : Node(node_name)
    {
        /* These define the callback groups
         * They don't really do much on their own, but they have to exist in order to
         * assign callbacks to them. They're also what the executor looks for when trying to run multiple threads
         */
        m_callback_group_camera1 = this->create_callback_group(
            rclcpp::CallbackGroupType::MutuallyExclusive);
        m_callback_group_camera2 = this->create_callback_group(
            rclcpp::CallbackGroupType::MutuallyExclusive);
        m_callback_group_camera3 = this->create_callback_group(
            rclcpp::CallbackGroupType::MutuallyExclusive);
        m_callback_group_camera4 = this->create_callback_group(
            rclcpp::CallbackGroupType::MutuallyExclusive);

        // Each of these callback groups is basically a thread
        // Everything assigned to one of them gets bundled into the same thread
        auto subscription_option1 = rclcpp::SubscriptionOptions();
        subscription_option1.callback_group = m_callback_group_camera1;
        auto subscription_option2 = rclcpp::SubscriptionOptions();
        subscription_option2.callback_group = m_callback_group_camera2;
        auto subscription_option3 = rclcpp::SubscriptionOptions();
        subscription_option3.callback_group = m_callback_group_camera3;
        auto subscription_option4 = rclcpp::SubscriptionOptions();
        subscription_option4.callback_group = m_callback_group_camera4;

        m_subscriber_camera1 = this->create_subscription<std_msgs::msg::Float64>("camera1_image", rclcpp::QoS(10), std::bind(&ServerMulti::camera1_callback, this, std::placeholders::_1), subscription_option1);
        m_subscriber_camera2 = this->create_subscription<std_msgs::msg::Float64>("camera2_image", rclcpp::QoS(10), std::bind(&ServerMulti::camera2_callback, this, std::placeholders::_1), subscription_option2);
        m_subscriber_camera3 = this->create_subscription<std_msgs::msg::Float64>("camera3_image", rclcpp::QoS(10), std::bind(&ServerMulti::camera3_callback, this, std::placeholders::_1), subscription_option3);
        m_subscriber_camera4 = this->create_subscription<std_msgs::msg::Float64>("camera4_image", rclcpp::QoS(10), std::bind(&ServerMulti::camera4_callback, this, std::placeholders::_1), subscription_option4);
    }

private:
    // attributes
    std_msgs::msg::Float64 m_msg;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr m_subscriber_camera1;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr m_subscriber_camera2;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr m_subscriber_camera3;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr m_subscriber_camera4;

    rclcpp::CallbackGroup::SharedPtr m_callback_group_camera1;
    rclcpp::CallbackGroup::SharedPtr m_callback_group_camera2;
    rclcpp::CallbackGroup::SharedPtr m_callback_group_camera3;
    rclcpp::CallbackGroup::SharedPtr m_callback_group_camera4;

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