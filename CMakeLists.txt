cmake_minimum_required(VERSION 3.0.2)
project(turtlebot_tutorials)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
)

## Declare a catkin package
catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtlebot_talker src/turtlebot_talker.cpp src/controller.cpp)
target_link_libraries(turtlebot_talker ${catkin_LIBRARIES})

