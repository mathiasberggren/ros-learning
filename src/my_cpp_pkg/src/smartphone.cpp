
#include <format>

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::placeholders;

class SmartphoneNode : public rclcpp::Node 
{
public:
    SmartphoneNode() : Node("smartphone")
    {
        subscriber = this->create_subscription<example_interfaces::msg::String>(
            "robot_news", 
            10,
            [this](const example_interfaces::msg::String::SharedPtr msg) { 
                this->robotNewsListener(msg); 
            }
        );

        RCLCPP_INFO(this->get_logger(), "Smartphone is listening");

    }
private:
    void robotNewsListener(const example_interfaces::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), std::format("{}", msg->data).c_str());
    }
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<SmartphoneNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}