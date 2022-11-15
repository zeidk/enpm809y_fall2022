#include <rclcpp/rclcpp.hpp>
#include "camera.h"

int main(int argc, char *argv[])
{
    // init
    rclcpp::init(argc, argv);
    // node
    auto node = std::make_shared<Camera>("camera");
    rclcpp::spin(node);
    // shutdown
    rclcpp::shutdown();
}