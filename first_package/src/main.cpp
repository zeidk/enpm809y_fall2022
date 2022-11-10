#include <rclcpp/rclcpp.hpp>
// #include "robot.h"

// Hello
int main(int argc, char *argv[])
{
    // init
    rclcpp::init(argc, argv);
    // instantiate a Node
    auto node = std::make_shared<rclcpp::Node>("hello");
    // do something with the Node
    RCLCPP_INFO(node->get_logger(), "Hello");
    // spin the Node
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