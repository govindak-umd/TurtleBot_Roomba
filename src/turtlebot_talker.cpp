#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlebot_talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);   
  ros::Rate loop_rate(10);

 int count = 0;
 geometry_msgs::Twist msg;
  while (ros::ok() && count < 150)
  {
    if (count < 140){
      msg.linear.x = 0.1;
      msg.linear.y = 0.0;
      msg.linear.z = 0.0;
      msg.angular.x = 0;
      msg.angular.y = 0;
      msg.angular.z = 0;    
    }
    else if (count >= 140){
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
    ROS_INFO_STREAM(count);
    ++count;
  }
  ROS_INFO_STREAM("COUNT RESET DONE!");
  return 0;
}
