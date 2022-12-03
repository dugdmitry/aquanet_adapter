#!/bin/bash
# A script to start the receiver side of the turtlesim demo

AQUANET_SCRIPTS_FOLDER=/home/pi/ros_catkin_ws/src/aquanet_adapter/aquanet_scripts/
SCRIPT_FOLDER=/home/pi/demo_scripts/

# reset the previous sessions
cd $SCRIPT_FOLDER
./stop_all.sh
sleep 1

# start roscore
source /home/pi/ros_catkin_ws/install_isolated/setup.bash
cd $HOME
roscore &
sleep 3

# start aquanet-adapter
cd $AQUANET_SCRIPTS_FOLDER
rosrun aquanet_adapter start 2 1 dccl &
sleep 10

# start the sender applications
cd $HOME
export DISPLAY=:0
rosrun turtlesim turtlesim_node &

# spawn additional 2 turtles
sleep 1
rosservice call /spawn "x: 5.0
y: 5.0
theta: 0.0
name: 'turtle2'"
sleep 1
rosservice call /spawn "x: 6.0
y: 6.0
theta: 0.0
name: 'turtle3'"
