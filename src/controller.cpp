#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
#include "../include/controller.h"
#include "sensor_msgs/LaserScan.h"
#include <sstream>

// #define RAD2DEG(x) ((x)*180./M_PI)
// void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan){
//     int count = scan->scan_time / scan->time_increment;
//     ROS_INFO("I heard a laser scan %s[%d]:", scan->header.frame_id.c_str(), count);
//     ROS_INFO("angle_range, %f, %f", RAD2DEG(scan->angle_min), RAD2DEG(scan->angle_max));
  
//     for(int i = 0; i < count; i++) {
//         float degree = RAD2DEG(scan->angle_min + scan->angle_increment * i);
//         ROS_INFO(": [%f, %f]", degree, scan->ranges[i]);
//     }
// 	ROS_INFO_STREAM("SCAN DETECTED");
// }

void Controller::driveForwardandStop(ros::NodeHandle n, ros::Publisher chatter_pub, ros::Rate loop_rate){
	int front_count = 0;
	geometry_msgs::Twist msg;
  	// ros::Subscriber sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 1000, scanCallback);
	while (ros::ok() && front_count < 80){
		if (front_count < 70){
		  msg.linear.x = front_speed;
		  msg.linear.y = 0.0;
		  msg.linear.z = 0.0;
		  msg.angular.x = 0;
		  msg.angular.y = 0;
		  msg.angular.z = 0;    
		}
		else if (front_count >= 70){
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

void Controller::turnBackwards(ros::NodeHandle n, ros::Publisher chatter_pub, ros::Rate loop_rate){
	int turn_count = 0;
	geometry_msgs::Twist msg;
	while (ros::ok() && turn_count < 75){
		if (turn_count < 65){
		  msg.linear.x = 0.0;
		  msg.linear.y = 0.0;
		  msg.linear.z = 0.0;
		  msg.angular.x = 0.0;
		  msg.angular.y = 0.0;
		  msg.angular.z = 0.5;    
		}
		else if (turn_count >= 65){
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
