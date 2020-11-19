#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
#include "../include/controller.h"
#include "sensor_msgs/LaserScan.h"
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlebot_talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);   
  ros::Rate loop_rate(10);
  //Declaring a controller object
  Controller controller;
  //moving forwards
  controller.driveForwardandStop(n, chatter_pub, loop_rate);
  //turning
  controller.turnBackwards(n, chatter_pub, loop_rate);
  //moving backwards
  controller.driveForwardandStop(n, chatter_pub, loop_rate);
  return 0;
}
