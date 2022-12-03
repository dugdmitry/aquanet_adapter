#!/bin/bash
# A script to stop everything

AQUANET_SCRIPTS_FOLDER=/home/pi/ros_catkin_ws/src/aquanet_adapter/aquanet_scripts/

# reset the previous sessions
killall roscore
killall generate_velocity
killall turtlesim_node
cd $AQUANET_SCRIPTS_FOLDER
./stack-stop.sh
