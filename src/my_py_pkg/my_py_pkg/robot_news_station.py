#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from example_interfaces.msg import String

class RobotNewsStationNode(Node):

    def __init__(self):
        super().__init__("robot_news_station")
        self.publisher = self.create_publisher(String)


def main(args=None):
    rclpy.init(args=args)

    node = RobotNewsStationNode()

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()