#include <rclcpp/rclcpp.hpp>
// #include "robot.h"

// Hello
int main(int argc, char *argv[])
{
    // init
    rclcpp::init(argc, argv);
    // node
    auto node = std::make_shared<rclcpp::Node>("hello");
    RCLCPP_INFO(node->get_logger(), "Hello");
    // rclcpp::spin(node);
    // shutdown
    rclcpp::shutdown();
}

// Robot
// int main(int argc, char *argv[])
// {
//     // init
//     rclcpp::init(argc, argv);
//     // node
//     auto node = std::make_shared<Robot>("bot_pub_sub");
//     rclcpp::spin(node);
//     // shutdown
//     rclcpp::shutdown();
// }