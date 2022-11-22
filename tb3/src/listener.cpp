#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "tf2/exceptions.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"


using namespace std::chrono_literals;

class FrameListener : public rclcpp::Node
{
public:
    FrameListener()
        : Node("tb3_listener")
    {
        m_tf_buffer =
            std::make_unique<tf2_ros::Buffer>(this->get_clock());
        m_tf_listener =
            std::make_shared<tf2_ros::TransformListener>(*m_tf_buffer);

        // Call on_timer function every second
        m_timer = this->create_wall_timer(
            1s, std::bind(&FrameListener::timer_callback, this));
    }

private:
    void timer_callback()
    {
        geometry_msgs::msg::TransformStamped t;

        // Look up for the transformation between odom and object frames
        try
        {
            t = m_tf_buffer->lookupTransform("odom", "object", tf2::TimePointZero);
        }
        catch (const tf2::TransformException &ex)
        {
            RCLCPP_INFO(
                this->get_logger(), "Could not transform %s to %s: %s",
                "object", "odom", ex.what());
            return;
        }

        RCLCPP_INFO(
            this->get_logger(), "Position of object in odom: [%f, %f, %f]", t.transform.translation.x, t.transform.translation.y, t.transform.translation.z);
    }
    
    rclcpp::TimerBase::SharedPtr m_timer{nullptr};
    std::shared_ptr<tf2_ros::TransformListener> m_tf_listener{nullptr};
    std::unique_ptr<tf2_ros::Buffer> m_tf_buffer;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FrameListener>());
    rclcpp::shutdown();
    return 0;
}