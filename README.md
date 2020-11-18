[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# ROS Publisher/Subscriber

 - Be sure to make changes to CMakeLists.txt and package.xml as needed.

## Author

Govind Ajith Kumar

## Overview

This code is a demo of turtlebot in a Gazebo world environment
 
## Assumptions
		ROS Melodic
		Ubuntu 18.04
## General structure of a catkin workspace

		workspace_folder/        -- WORKSPACE
		  src/                   -- SOURCE SPACE
		    CMakeLists.txt       -- 'Toplevel' CMake file, provided by catkin
		    package_1/
		      CMakeLists.txt     -- CMakeLists.txt file for package_1
		      package.xml        -- Package manifest for package_1
		    ...
		    package_n/
		      CMakeLists.txt     -- CMakeLists.txt file for package_n
		      package.xml        -- Package manifest for package_n

## Directory structure of this catkin_ws

		catkin_ws/
			build
			devel
			src
				turtlebot_tutorials
					CMakeLists.txt
					package.xml
				CMakeLists.txt

## To create the catkin package, building and sourcing it

		$ cd ~/catkin_ws/src
		$ catkin_create_pkg turtlebot_tutorials std_msgs rospy roscpp
		$ cd ..
		$ catkin_make
		$ . ~/catkin_ws/devel/setup.bash

