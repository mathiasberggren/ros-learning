#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        super().__init__("py_test")
        self.counter_ = 1
        self.create_timer(5, self.timer_callback)
        self.get_logger().info("Hello World")

    def timer_callback(self): 
        self.get_logger().info("Hello" + str(self.counter_))
        self.counter_ += 1




def main(args=None):
    # just testing
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()