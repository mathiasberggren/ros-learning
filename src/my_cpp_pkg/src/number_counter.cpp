#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class NumberCounterNode : public rclcpp::Node 
{
public:
    NumberCounterNode() : Node("number_counter"), count(0) {
        publisher = this->create_publisher<example_interfaces::msg::Int64>("number_count", 10);
        subscriber = this->create_subscription<example_interfaces::msg::Int64>(
            "number",
            10,
            [this](example_interfaces::msg::Int64::UniquePtr msg) {
                this->consumeMessage(std::move(msg));
            }
        );

        RCLCPP_INFO(this->get_logger(), "[Number counter started successfully]");
    }

    void consumeMessage(example_interfaces::msg::Int64::UniquePtr input) {
        count += input->data;

        auto msg = example_interfaces::msg::Int64();
        msg.data = count;

        this->publisher->publish(msg);
    }


private:
    int count;
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<NumberCounterNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}