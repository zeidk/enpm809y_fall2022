#include <rclcpp/rclcpp.hpp>
#include "server.h"
#include <thread>



int main(int argc, char *argv[])
{
    // init
    rclcpp::init(argc, argv);
    // node
    auto node = std::make_shared<Server>("server");
    rclcpp::spin(node);
    // shutdown
    rclcpp::shutdown();
}