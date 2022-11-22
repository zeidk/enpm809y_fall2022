#include <sstream>
#include <string>

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/static_transform_broadcaster.h"

class FramePublisher : public rclcpp::Node
{
public:
    FramePublisher()
        : Node("tb3_broadcaster")
    {
        // Initialize the transform broadcaster
        m_tf_broadcaster = std::make_unique<tf2_ros::StaticTransformBroadcaster>(this);
        // broadcast in a callback
        m_timer = this->create_wall_timer(std::chrono::milliseconds((int)(1000.0 / 10)),
                                          std::bind(&FramePublisher::timer_callback, this));
    }

private:
    void timer_callback()
    {
        geometry_msgs::msg::TransformStamped t;

        // Read message content and assign it to
        // corresponding tf variables
        t.header.stamp = this->get_clock()->now();
        t.header.frame_id = "base_link";
        t.child_frame_id = "object";

        // The object is at this position from the turtlebot
        t.transform.translation.x = 2.0;
        t.transform.translation.y = 0.0;
        t.transform.translation.z = 0.0;

        // The object orientation from the turtlebot
        tf2::Quaternion q;
        q.setRPY(0, 0, 0);
        t.transform.rotation.x = q.x();
        t.transform.rotation.y = q.y();
        t.transform.rotation.z = q.z();
        t.transform.rotation.w = q.w();

        // Send the transformation
        m_tf_broadcaster->sendTransform(t);
    }
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> m_tf_broadcaster;
    rclcpp::TimerBase::SharedPtr m_timer;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FramePublisher>());
    rclcpp::shutdown();
    return 0;
}