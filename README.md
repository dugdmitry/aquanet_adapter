# aquanet_adapter
Plugin to enable AquaNet stack of protocols for UWNs in ROS.


## Installation


The following steps are valid for `Ubuntu 18.04+` distribution with `ROS-melodic` system compiled and installed from source.

ROS compilation instructions can be found over here:
https://wiki.ros.org/melodic/Installation/Source

`$ROS_FOLDER` variable corresponds to a folder name of your ROS directory, usually named as `ros_catkin` or `ros_catkin_ws`.

### Step 1 

Clone `aquanet-adapter` repository to `src` folder of your ROS installation:

    cd $ROS_FOLDER/src/
    git clone https://github.com/dugdmitry/aquanet_adapter.git

### Step 2

Install additional libraries to support DCCL serialization:

    echo "deb http://packages.gobysoft.org/ubuntu/release/ `lsb_release -c -s`/" | sudo tee /etc/apt/sources.list.d/gobysoft_release.list

    sudo apt-key adv --recv-key --keyserver keyserver.ubuntu.com 19478082E2F8D3FE

    sudo apt update

    sudo apt install libdccl3-dev dccl3-compiler dccl3-apps

### Step 3

Recompile `.proto` messages with local version of `protoc` compiler:

    cd $ROS_FOLDER/src/aquanet_adapter/dccl_messages/
    protoc --cpp_out=. aquanet.message.proto -I . -I /usr/include
    protoc --cpp_out=. navreport.proto -I . -I /usr/include

### Step 4

Compile `aquanet_adapter` module inside your ROS installation:

    cd $ROS_FOLDER
    source install_isolated/setup.bash
    ./src/catkin/bin/catkin_make_isolated --pkg aquanet_adapter --install -DCMAKE_BUILD_TYPE=Release

### Step 5

Create a symlink for the compiled aquanet-protobuf messages:

    sudo ln -s ~/$ROS_FOLDER/devel_isolated/aquanet_adapter/lib/libaquanet.message.pb.so /usr/lib/libaquanet.message.pb.so

## Experimental: uuv_simulator with plume tracing tests

This section descirbes how to run `ros-aquanet-adapter` in the `local mode` for uuv_plume_simulator tests.

Start `multi_rov_test.launch` file:

    roslaunch multi_auv_sim multi_rov_test.launch

Start `aquanet-adapter` by executing the following:

    cd $ROS_FOLDER/src/aquanet_adapter/aquanet_scripts/
    rosrun aquanet_adapter start local

Replace original topic name in `leader.py` to `aquanet_outbound_waypoint` name, indicating an entry point to the aquanet-adapter stack:

Original topic name: `Waypoint_pub`

New topic name: `aquanet_outbound_waypoint`

Replace original topic name in `node2.py`, `node3.py` and `node4.py` files to `aquanet_inbound_waypoint` name, indicating an exit point from the aquanet-adapter stack at the receiver side:

Original topic name: `Waypoint_pub`

New topic name: `aquanet_inbound_waypoint`

Execute the plume tracing script:

    roslaunch multi_auv_sim start_mbplume.launch

Observe the output from the ros-aquanet-adapter console and make sure that the messages are successfully intercepted and forwarded. The following output should be observed:

    [ INFO] [1662861151.355090286, 2925.418000000]: Forwarding message:
    [ INFO] [1662861151.355172801, 2925.418000000]: position=(20.00,25.00) angle=-0.70



## Running aquanet-adapter

Run `roscore`, if not initialized already:

    roscore

Start `aquanet-adapter` by executing the following:

    cd $ROS_FOLDER/src/aquanet_adapter/aquanet_scripts/
    rosrun aquanet_adapter start 1 2


The command above initializes the AquaNet communication stack, assigning address **1** for a local machine, and address **2** for the destination/remote machine.

If everything is succesfull, the following output should appear in the console:

    ----------------------------------------------------------
    	Aqua-Net
    A network protocol stack for underwater networks
    Developed by Zheng (James) Peng
    All rights reserved
    ----------------------------------------------------------

    user-gazebo:1:1-01070757>[     stack]	Starting Aqua-Net.
    user-gazebo:1:1-01070757>[     stack]	Initializing Protocol Stack...
    user-gazebo:1:1-01070757>[     stack]	Protocol Stack Initialized.

    ----------------------------------------------------------
		Virtual Modem (VMDM) Driver
    A virtual modem for Aqua-Net
    Developed by Zheng Peng in 2021
    All rights reserved
    ----------------------------------------------------------

    user-gazebo:1:1-01070759>[      vmdc]	Starting VMDM Driver.
    user-gazebo:1:1-01070759>[      vmdc]	Local PHY address is: 1

    ----------------------------------------------------------
		UW-ALOHA 
    A MAC protocol for underwater networks in Aqua-Net
    Developed by Zheng (James) Peng
    All rights reserved
    ----------------------------------------------------------

    user-gazebo:1:1-01070803>[   uwaloha]	Starting UW-ALOHA.
    user-gazebo:1:1-01070803>[   uwaloha]	Mac address is 1
    user-gazebo:1:1-01070803>[   uwaloha]	UW-ALOHA started.

    ----------------------------------------------------------
		Static Routing Protocol 
    A routing protocol for underwater networks in Aqua-Net
    Developed by Zheng (James) Peng
    All rights reserved
    ----------------------------------------------------------

    user-gazebo:1:1-01070805>[    sroute]	Starting the Static Routing Protocol.
    user-gazebo:1:1-01070805>[    sroute]	Network address is 1
    user-gazebo:1:1-01070805>[    sroute]	Static Routing started.


## Troubleshooting

### Mismatched `protobuf` version error

If the following or a similar error appears during the compilation process:

    In file included from /home/user/ros_catkin_ws/src/aquanet_adapter/dccl_messages/aquanet.message.pb.cc:4:0:
    /home/user/ros_catkin_ws/src/aquanet_adapter/dccl_messages/aquanet.message.pb.h:12:2: error: #error This file was generated by a newer version of protoc which is
     #error This file was generated by a newer version of protoc which is
      ^~~~~
    /home/user/ros_catkin_ws/src/aquanet_adapter/dccl_messages/aquanet.message.pb.h:13:2: error: #error incompatible with your Protocol Buffer headers. Please update
     #error incompatible with your Protocol Buffer headers.  Please update

    error:
    /home/user/ros_catkin_ws/install_isolated/lib/aquanet_adapter/start: error while loading shared libraries: libaquanet.message.pb.so: cannot open shared object file: No such file or directory

The local version of the `protoc` compiler does not match with the one used for compiling the original .proto messages, presented as `.cc` and `.h` source files.

To fix this, execute **Step 3** from the installation instructions:

    cd $ROS_FOLDER/src/aquanet_adapter/dccl_messages/
    protoc --cpp_out=. aquanet.message.proto -I . -I /usr/include
    protoc --cpp_out=. navreport.proto -I . -I /usr/include

### Error loading shared `libaquanet` library

If during execution of aquanet the following error appears:

    /home/user/ros_catkin_ws/install_isolated/lib/aquanet_adapter/start: error while loading shared libraries: libaquanet.message.pb.so: cannot open shared object file: No such file or directory

The precompiled aquanet-message protobuf library should be symlinked over here:

    sudo ln -s ~/$ROS_FOLDER/devel_isolated/aquanet_adapter/lib/libaquanet.message.pb.so /usr/lib/libaquanet.message.pb.so

### No such file or directory error

When executing `aquanet-adapter`, the following error appears:

    sh: 1: ./run_aquanet.sh: not found
    config_add.cfg: No such file or directory
    Terminated

Make sure that `aquanet-adapter` is executed under `aquanet_scripts` folder:

    cd $ROS_FOLDER/src/aquanet_adapter/aquanet_scripts/
    rosrun aquanet_adapter start 1 2
