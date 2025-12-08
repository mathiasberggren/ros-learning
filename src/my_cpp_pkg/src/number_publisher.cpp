#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class NumberPublisherNode : public rclcpp::Node 
{
public:
    NumberPublisherNode() : Node("number_publisher")
    {
        publisher = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
        timer = this->create_wall_timer(std::chrono::seconds(3), [this]{ sendNumber(); });

        RCLCPP_INFO(this->get_logger(), "[Successfully set up number_publisher]");
    }

    void sendNumber()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = 3;
        this->publisher->publish(msg);
    }

private:
    rclcpp::TimerBase::SharedPtr timer;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<NumberPublisherNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}