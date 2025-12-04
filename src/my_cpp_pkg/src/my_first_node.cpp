#include "rclcpp/rclcpp.hpp"
#include <format>

class MyNode : public rclcpp::Node 
{
public:
    MyNode() : Node("cpp_test"), counter(0)
    {
        RCLCPP_INFO(this->get_logger(), "Hello World");
        timer = this->create_wall_timer(std::chrono::seconds(2), 
        
        [&]() { timerCallback(); }
        //std::bind(&MyNode::timerCallback, this)
    
    );
    }
private:
    void timerCallback()
    {
        RCLCPP_INFO(this->get_logger(), std::format("Hello {}", counter++).c_str());
        
    }

    rclcpp::TimerBase::SharedPtr timer;
    int counter;

};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}