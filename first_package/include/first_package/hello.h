#include <rclcpp/rclcpp.hpp>

class Hello : public rclcpp::Node
{
public:
    Hello(std::string node_name) : Node(node_name)
    {
        m_timer = this->create_wall_timer(std::chrono::seconds(2),
                                          std::bind(&Hello::timer_callback));
    }

private:
    rclcpp::TimerBase::SharedPtr m_timer;
    void timer_callback();
};