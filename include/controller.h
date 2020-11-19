#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"
#include <sstream>

class Controller{
	private:
		double front_speed = 0.2;
		double turn_speed = 0.5;
	public:
		// void scanCallback(const sensor_msgs::LaserScan::ConstPtr&);
		void driveForwardandStop(ros::NodeHandle, ros::Publisher , ros::Rate);
		void turnBackwards(ros::NodeHandle, ros::Publisher , ros::Rate);
};
