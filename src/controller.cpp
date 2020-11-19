#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
#include "../include/controller.h"
#include <sstream>

void Controller::driveForwardandStop(ros::NodeHandle n, ros::Publisher chatter_pub, ros::Rate loop_rate){
	int count = 0;
	geometry_msgs::Twist msg;
	while (ros::ok() && count < 150){
		if (count < 140){
		  msg.linear.x = speed;
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
	ROS_INFO_STREAM("Front motion Stopped");
}