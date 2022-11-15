#include <rclcpp/rclcpp.hpp>
#include "server_multi.h"


int main(int argc, char *argv[])
{
    // init
    rclcpp::init(argc, argv);

    // You MUST use the MultiThreadedExecutor to use, well, multiple threads
    rclcpp::executors::MultiThreadedExecutor executor;
    auto server_multi_node = std::make_shared<ServerMulti>("server_multi"); // This contains 4 subscriber callbacks.
                                                     // They will still run on different threads
                                                     // One Node. 4 callbacks. 4 Threads.
    executor.add_node(server_multi_node);
    executor.spin();
    // shutdown
    rclcpp::shutdown();
}