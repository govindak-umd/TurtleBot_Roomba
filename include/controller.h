/**
 * @file controller.h
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
#pragma once
#include <sstream>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"

/**
 * @brief      Controls the front and turning of the turtlebot
 */
class Controller{
 private:
  // Declaring the front speed of the turtlebot
  double front_speed = 0.2;
  // Declaring the turning speed of the turtlebot
  double turn_speed = 0.5;
 public:
  // Function to move forwards
  void driveForwardandStop(ros::NodeHandle, ros::Publisher, ros::Rate);

  // Function to turn backwards
  void turnBackwards(ros::NodeHandle, ros::Publisher, ros::Rate);

  // Function to stop the robot
  void stopRobot(ros::Publisher, ros::Rate);
};
