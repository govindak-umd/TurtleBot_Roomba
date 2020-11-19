#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
#include <sstream>

class Controller{
	private:
		double front_speed = 0.5;
	public:
		void driveForwardandStop(ros::NodeHandle, ros::Publisher , ros::Rate);
};
