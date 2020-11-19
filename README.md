[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Turtlebot simulation in Gazebo

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

## Creating a custom world

 - Use Gazebo's model editor and building editor to create a custom world file. 
 - Store this in a .world file format.
 - Find the world file in the worlds/ folder.
 - A snapshot of the world file can be seen here.

<p align="center">
  <img height="500" src="images/custom_world.png">
</p>

## Turtlebot3 Installation

 -  Ensure that the requirements for turtlebot3 is met. Install using the following command:
		$ sudo apt-get install ros-melodic-turtlebot3-*

 - Verify installation by launching the turtlebot in your custom world file.

## Launch file
		
 - Add necessary lines to the launch file to spawn the custom world and a turtlebot in it

