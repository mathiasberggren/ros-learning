#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class SmartphoneNode(Node):
    def __init__(self):
        super().__init__("smartphone")
        self.subscriber_ = self.create_subscription(String, "robot_news", self.callback_read_message, 10)
        self.get_logger().info("Beep Bop, smartphone is up!")

    def callback_read_message(self, msg: String):
        self.get_logger().info("[Recieved message]: " + msg.data)

def main(args=None):
    rclpy.init(args=args)

    node = SmartphoneNode()

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()