cmake_minimum_required(VERSION 3.0.2)
project(turtlebot_tutorials)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtlebot_talker 
		src/turtlebot_talker.cpp 
		src/controller.cpp)
target_link_libraries(turtlebot_talker ${catkin_LIBRARIES})
add_dependencies(turtlebot_talker beginner_tutorials_generate_messages_cpp)

