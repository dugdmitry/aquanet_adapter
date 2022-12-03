#!/bin/bash
# A script to start the sender side of the turtlesim demo

AQUANET_SCRIPTS_FOLDER=/home/pi/ros_catkin_ws/src/aquanet_adapter/aquanet_scripts/

# reset the previous sessions
killall roscore
cd $AQUANET_SCRIPTS_FOLDER
./stack-stop.sh
sleep 1

# start roscore
source /home/pi/ros_catkin_ws/install_isolated/setup.bash
cd $HOME
roscore &
sleep 3

# start aqanuet-vmds
cd $AQUANET_SCRIPTS_FOLDER
../aquanet_bin/aquanet-vmds 2021 &
sleep 5

# start aquanet-adapter
cd $AQUANET_SCRIPTS_FOLDER
rosrun aquanet_adapter start 1 2 dccl &
sleep 10

# start the sender applications
cd $HOME
rosrun turtlesim generate_velocity square &
sleep 0.5
rosrun turtlesim generate_velocity triangle &
sleep 0.5
rosrun turtlesim generate_velocity circle &
