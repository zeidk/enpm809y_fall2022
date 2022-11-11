#include <rclcpp/rclcpp.hpp>
#include "hello.h"
#include "robot.h"

// Hello
// int main(int argc, char *argv[])
// {
//     // init
//     rclcpp::init(argc, argv);
//     // instantiate a Node
//     auto node = std::make_shared<Hello>("hello");
    
//     // spin the Node
//     rclcpp::spin(node);
//     RCLCPP_INFO(node->get_logger(), "Shut down");
//     // shutdown
//     rclcpp::shutdown();
// }

// Robot
int main(int argc, char *argv[])
{
    // init
    rclcpp::init(argc, argv);
    // node
    auto node = std::make_shared<Robot>("bot_pub_sub");
    rclcpp::spin(node);
    // shutdown
    rclcpp::shutdown();
}