/**
 * @file controller.cpp
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

void Controller::driveForwardandStop(ros::NodeHandle n,
                                     ros::Publisher chatter_pub,
                                     ros::Rate loop_rate) {
  int front_count = 0;
  geometry_msgs::Twist msg;
  while (ros::ok() && front_count < 150) {
    if (front_count < 140) {
      msg.linear.x = front_speed;
      msg.linear.y = 0.0;
      msg.linear.z = 0.0;
      msg.angular.x = 0;
      msg.angular.y = 0;
      msg.angular.z = 0;
    } else {
      msg.linear.x = 0.0;
      msg.linear.y = 0.0;
      msg.linear.z = 0.0;
      msg.angular.x = 0;
      msg.angular.y = 0;
      msg.angular.z = 0;
    }
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ROS_INFO_STREAM(front_count);
    ++front_count;
  }
  ROS_INFO_STREAM("Front motion Stopped");
}

void Controller::keepTurning(ros::NodeHandle n, ros::Publisher chatter_pub,
                               ros::Rate loop_rate) {
  int turn_count = 0;
  geometry_msgs::Twist msg;
  while (ros::ok() && turn_count < 75) {
    if (turn_count < 60) {
      msg.linear.x = 0.0;
      msg.linear.y = 0.0;
      msg.linear.z = 0.0;
      msg.angular.x = 0.0;
      msg.angular.y = 0.0;
      msg.angular.z = turn_speed;
    } else {
      msg.linear.x = 0.0;
      msg.linear.y = 0.0;
      msg.linear.z = 0.0;
      msg.angular.x = 0.0;
      msg.angular.y = 0.0;
      msg.angular.z = 0.0;
    }
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ROS_INFO_STREAM(turn_count);
    ++turn_count;
  }
  ROS_INFO_STREAM("Turn motion Stopped");
}

void Controller::stopRobot(ros::Publisher chatter_pub, ros::Rate loop_rate){
  geometry_msgs::Twist msg;
  msg.linear.x = 0.0;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;
  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  chatter_pub.publish(msg);
  loop_rate.sleep();
}

