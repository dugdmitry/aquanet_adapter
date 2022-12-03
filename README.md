# aquanet_adapter: wuwnet demo
This branch contains the code used in WUWNet'22 demo presentations.


## Demo run guide

To run the demo, checkout this branch first. Then, make sure that ROS and turtlesim applications are installed on your demo machine.

### Step 1

Run the receiver application by executing:

    cd $ROS_FOLDER/src/aquanet_adapter/aquanet_scripts/
    rosrun aquanet_adapter start 2 1 dccl

The command above will start the receiver application on node 2 with `dccl` serialization enabled.

### Step 2

Run the sender application:

    cd $ROS_FOLDER/src/aquanet_adapter/aquanet_scripts/
    rosrun aquanet_adapter start 1 2 dccl

The command assumes that Node 1 will forward the ROS-Turtlesim-Twist message commands to Node 2.

### Step 3

Run ROS `turtlesim_node` application on the receiver side:

    cd $HOME
    turtlesim_node

### Step 4

Run the sender ROS application that would generate a square-path:

    cd $HOME
    rosrun turtlesim generate_velocity square

### Optional steps

To spawn multiple turtles on the same `turtlesim_node` display, run:

    rosservice call /spawn "x: 0.0 y: 5.0 theta: 0.0 name: 'turtle2'" 

The command above will spawn a second turtle, placed at (5.0, 5.0) coordinate, rotated to the right.

Additionally, separate bash-scripts have been written to automate the sender/receiver process. The scripts can be found under `demo_scripts` folder.
