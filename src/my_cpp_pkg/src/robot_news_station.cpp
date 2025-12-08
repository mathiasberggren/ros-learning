#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::chrono_literals;

class RobotNewsStationNode : public rclcpp::Node 
{
public:
    RobotNewsStationNode() : Node("robot_news_station"), robo_name("YaRule")
    {
        publisher = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);
        timer = this->create_wall_timer(0.5s, [this]{ this->publishNews(); });
        // timer = this->create_wall_timer(0.5s, std::bind(&RobotNewsStationNode::publishNews, this));
        RCLCPP_INFO(this->get_logger(), "Robot News Station is up up up");
    }
private:

    void publishNews()
    {
        auto msg = example_interfaces::msg::String();
        msg.data = "Hello this is " + robo_name + "-bot sending live to you from the RoboNews station";
        publisher->publish(msg);
    }

    std::string robo_name;
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher;
    rclcpp::TimerBase::SharedPtr timer;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<RobotNewsStationNode>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}