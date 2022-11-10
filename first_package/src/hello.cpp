#include <rclcpp/rclcpp.hpp>
#include "hello.h"

void Hello::timer_callback()
{
    RCLCPP_INFO(this->get_logger(), "Hello");
}
