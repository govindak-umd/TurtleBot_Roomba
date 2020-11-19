/**
 * @file turtlebot_talker.cpp
 * @author Govind Ajith Kumar
 * @copyright MIT License
 * @brief Implementing the publisher
 * This is the talker file for ROS subscriber-publisher example.
 */

/**
 *MIT License
 *Copyright (c) 2020 Govind Ajith Kumar
 *Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software and associated documentation files (the "Software"), to deal
 *in the Software without restriction, including without limitation the rights
 *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *copies of the Software, and to permit persons to whom the Software is
 *furnished to do so, subject to the following conditions:
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *SOFTWARE.
 */
#include <sstream>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
#include "../include/controller.h"
#include "sensor_msgs/LaserScan.h"


/**
 * @brief      Main function controlling the robot
 *
 * @param[in]  argc  The count of arguments
 * @param      argv  The arguments array
 *
 * @return     returns nothing, 0
 */
int main(int argc, char **argv) {
  // Initialising the node
  ros::init(argc, argv, "turtlebot_talker");
  // starting ros node handle
  ros::NodeHandle n;
  // Declaring the publisher
  ros::Publisher chatter_pub = n.advertise
  <geometry_msgs::Twist>("cmd_vel", 1000);
  // Setting a loop rate
  ros::Rate loop_rate(10);
  // Declaring a controller object
  Controller controller;
  // Moving forwards
  controller.driveForwardandStop(n, chatter_pub, loop_rate);
  // Turning backwards
  controller.turnBackwards(n, chatter_pub, loop_rate);
  // Moving backwards
  controller.driveForwardandStop(n, chatter_pub, loop_rate);
  // returns 0, since the main function returns an integer
  return 0;
}
