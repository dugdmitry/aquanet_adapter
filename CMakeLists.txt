cmake_minimum_required(VERSION 3.0.2)
project(aquanet_adapter)

find_package(catkin REQUIRED COMPONENTS roscpp)

include_directories(include ${catkin_INCLUDE_DIRS})
catkin_package(CATKIN_DEPENDS)

add_library(aquanet.message.pb dccl_messages/aquanet.message.pb.cc)

add_executable(start start.cpp)
target_link_libraries(start ${catkin_LIBRARIES} protobuf dccl aquanet.message.pb)

add_executable(echo_server_test test/echo_server_test.cpp)
target_link_libraries(echo_server_test ${catkin_LIBRARIES})

install(TARGETS start echo_server_test RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
