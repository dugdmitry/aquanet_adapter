// This program initializes the aquanet stack of protocols and
// creates outbound/inbound topics for passing the data over aquanet
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include <uuv_control_msgs/Waypoint.h>
#include <iomanip> // for std::setprecision and std::fixed

// dccl
#include "dccl.h"
#include "dccl_messages/aquanet.message.pb.h"

// Socket communication
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
#include <iostream>
#include <sstream>
#include <limits>
// thread-related stuff
#include <thread>
// Aqua-sockets
#include <sys/un.h>
#include "aquanet_include/aquanet_log.h"
#include "aquanet_include/aquanet_socket.h"

// // udp socket stuff
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <arpa/inet.h>
// #include <netinet/in.h>

char log_file[BUFSIZE];
char* log_file_name = log_file;

// Define inbound and outbound topics for communication over aquanet-enabled nodes
std::string inbound_topic = "aquanet_inbound";
std::string outbound_topic = "aquanet_outbound";

// Initialize publishers
ros::Publisher aquanet_inbound_publisher_twist;
ros::Publisher aquanet_inbound_publisher_string;
ros::Publisher aquanet_inbound_publisher_waypoint;

// Aquanet socket
int m_socket = -1;
struct sockaddr_aquanet m_to_addr;
dccl::Codec m_codec;

// // udp
// int send_sockfd;
// struct sockaddr_in servaddr;


struct aqua_header {
	unsigned short int frame_len;
	unsigned short int msg_id;
	char pkt_data[450];
};


// serialize/deserialize messages for sending/receiving to/from the sockets
std::string serializeStringMsg(const std_msgs::String::ConstPtr& msg)
{
    // Construct aqua-message with string-message inside
    std::string sent_msg;
    dccl::Codec send_codec;
    // m_codec.load<AquanetMessage>();
    send_codec.load<AquanetMessage>();
    {
        AquanetMessage r_out;
        r_out.set_ros_msg_id(2);                // 2 - ros string-message;
        r_out.set_body_message(msg->data.c_str());
        r_out.set_veh_class(AquanetMessage::AUV);
        r_out.set_battery_ok(true);
        // std::cout << r_out.ByteSize() << "\n"; 
        
        send_codec.encode(&sent_msg, r_out);
        // m_codec.encode(&sent_msg, r_out);
    }

    // Append length of the dccl serialized message

    unsigned char len_byte;

    len_byte = (sent_msg.size());

    // std::cout << sizeof(len_byte) << "\n";
    std::string s((const char*)&(len_byte), sizeof(len_byte));
    // std::cout << s << std::endl;
    // std::cout << s + sent_msg << "\n";

    // return sent_msg;
    return s + sent_msg;
}


// Callback functions for different ros data structures 
// twist velocity message
void twistMessageReceived(const geometry_msgs::Twist::ConstPtr& vel)
{
    ROS_INFO_STREAM(std::setprecision(2) << std::fixed << "position=(" << vel->linear.x << "," << vel->linear.y << ")" << " angle=" << vel->angular.z);

    // Construct aqua-message with twist-message inside
    std::string sent_msg;
    m_codec.load<AquanetMessage>();
    {
        AquanetMessage r_out;
        r_out.set_ros_msg_id(1);                // 1 - ros twist-message;
        r_out.set_x(vel->angular.z);            // set angular velocity to x
        r_out.set_y(vel->linear.x);            // set linear velocity to y
        r_out.set_z(0);
        r_out.set_veh_class(AquanetMessage::AUV);
        r_out.set_battery_ok(true);
        
        m_codec.encode(&sent_msg, r_out);
    }

    // Send aqua-message over aqua-socket
    if (aqua_sendto(m_socket, sent_msg.data(), sent_msg.size(), 0, (struct sockaddr *) & m_to_addr, sizeof (m_to_addr)) < 0) {
        printf("failed to send to the socket");
        perror("m_socket closed");
        exit(1);
    }

    // if (sendto(send_sockfd, sent_msg.data(), sent_msg.size(), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr)))
    // {
    //     printf("failed to send to the socket");
    //     perror("m_socket closed");
    //     exit(1);
    // }

}

// waypoint message from uuv_control_msgs
void waypointMessageReceived(const uuv_control_msgs::Waypoint::ConstPtr& msg)
{
    ROS_INFO_STREAM("Forwarding message:");
    ROS_INFO_STREAM(std::setprecision(2) << std::fixed << "position=(" << msg->point.x << "," << msg->point.y << ")" << " angle=" << msg->point.z);

    // TODO: include the aquanet stack and forward the message over it locally
    // Forward message to the receiving topic, bypassing the aquanet stack so far
    aquanet_inbound_publisher_waypoint.publish(msg);
}

// string message
void stringMessageReceived(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("String message: [%s]", msg->data.c_str());

    // std::string send_str;
    // send_str = "hello";

    // // Construct aqua-message with string-message inside
    // std::string sent_msg;
    // dccl::Codec send_codec;
    // // m_codec.load<AquanetMessage>();
    // send_codec.load<AquanetMessage>();
    // {
    //     AquanetMessage r_out;
    //     r_out.set_ros_msg_id(2);                // 2 - ros string-message;
    //     r_out.set_body_message(msg->data.c_str());
    //     r_out.set_veh_class(AquanetMessage::AUV);
    //     r_out.set_battery_ok(true);
    //     std::cout << r_out.ByteSize() << "\n"; 
        
    //     send_codec.encode(&sent_msg, r_out);
    //     // m_codec.encode(&sent_msg, r_out);
    // }

    // // Send aqua-message over aqua-socket
    // if (aqua_sendto(m_socket, sent_msg.data(), sent_msg.size(), 0, (struct sockaddr *) & m_to_addr, sizeof (m_to_addr)) < 0) {
    //     printf("failed to send to the socket");
    //     perror("m_socket closed");
    //     exit(1);
    // }

    // // connect to server
    // if(connect(send_sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    // {
    //     printf("\n Error : Connect Failed \n");
    //     exit(0);
    // }

    // std::string sent_msg = serializeStringMsg(msg);


    aqua_header aqua_frame;
    aqua_frame.frame_len = msg->data.size();
    aqua_frame.msg_id = 2;      // 2 - ros string-message;
    memcpy(aqua_frame.pkt_data, msg->data.c_str(), msg->data.size());

    // std::cout << aqua_frame.frame_len << "\n";

    // if (sendto(send_sockfd, &aqua_frame, sizeof(aqua_frame), 0, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    // // if (sendto(send_sockfd, sent_msg.c_str(), sent_msg.size(), 0, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    // // if (sendto(send_sockfd, msg->data.c_str(), msg->data.size(), 0, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    // {
    //     printf("failed to send to the socket");
    //     perror("m_socket closed");
    //     exit(1);
    // }

    // Send aqua-message over aqua-socket
    if (aqua_sendto(m_socket, &aqua_frame, sizeof(aqua_frame), 0, (struct sockaddr *) & m_to_addr, sizeof (m_to_addr)) < 0) {
        printf("failed to send to the socket");
        perror("m_socket closed");
        exit(1);
    }

}

// string message
void stringMessageReceivedDccl(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("String message: [%s]", msg->data.c_str());

    // Construct aqua-message with string-message inside
    std::string sent_msg;
    dccl::Codec send_codec;
    // m_codec.load<AquanetMessage>();
    send_codec.load<AquanetMessage>();
    {
        AquanetMessage r_out;
        r_out.set_ros_msg_id(2);                // 2 - ros string-message;
        r_out.set_body_message(msg->data.c_str());
        r_out.set_veh_class(AquanetMessage::AUV);
        r_out.set_battery_ok(true);
        std::cout << r_out.ByteSize() << "\n"; 
        
        send_codec.encode(&sent_msg, r_out);
        // m_codec.encode(&sent_msg, r_out);
    }

    // Send aqua-message over aqua-socket
    if (aqua_sendto(m_socket, sent_msg.data(), sent_msg.size(), 0, (struct sockaddr *) & m_to_addr, sizeof (m_to_addr)) < 0) {
        printf("failed to send to the socket");
        perror("m_socket closed");
        exit(1);
    }

    // // connect to server
    // if(connect(send_sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    // {
    //     printf("\n Error : Connect Failed \n");
    //     exit(0);
    // }

    // std::string sent_msg = serializeStringMsg(msg);


    // aqua_header aqua_frame;
    // aqua_frame.frame_len = msg->data.size();
    // aqua_frame.msg_id = 2;      // 2 - ros string-message;
    // memcpy(aqua_frame.pkt_data, msg->data.c_str(), msg->data.size());

    // std::cout << aqua_frame.frame_len << "\n";

    // if (sendto(send_sockfd, &aqua_frame, sizeof(aqua_frame), 0, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    // // if (sendto(send_sockfd, sent_msg.c_str(), sent_msg.size(), 0, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    // // if (sendto(send_sockfd, msg->data.c_str(), msg->data.size(), 0, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    // {
    //     printf("failed to send to the socket");
    //     perror("m_socket closed");
    //     exit(1);
    // }

    // // Send aqua-message over aqua-socket
    // if (aqua_sendto(m_socket, &aqua_frame, sizeof(aqua_frame), 0, (struct sockaddr *) & m_to_addr, sizeof (m_to_addr)) < 0) {
    //     printf("failed to send to the socket");
    //     perror("m_socket closed");
    //     exit(1);
    // }

}

// Receive thread
void receiveAqua(int recv_socket)
{
    struct sockaddr_aquanet remote_addr;
    int addr_size = sizeof (remote_addr);
    
    // struct sockaddr_in remote_addr;
    // memset(&remote_addr, 0, sizeof(remote_addr));
    // socklen_t addr_size = sizeof (remote_addr);

    // aqua_message received_values;
    // TODO: make it a parameter:
    // char recv_buf[512]; // 512 bytes is the maximum aquanet message size, provided by DCCL-protobuf
    // char len_buf[1];
    char recv_buf[450];
    std::string recv_msg;

    // socklen_t len;
    // // struct sockaddr_in servaddr, cliaddr;
    // // struct sockaddr_in cliaddr;
    // // bzero(&servaddr, sizeof(servaddr));
  
    // // // Create a UDP Socket
    // struct sockaddr_in servaddr1;
    // int listenfd;
    // listenfd = socket(AF_INET, SOCK_DGRAM, 0);        
    // servaddr1.sin_addr.s_addr = htonl(INADDR_ANY);
    // servaddr1.sin_port = htons(57777);
    // servaddr1.sin_family = AF_INET;
    // bind(listenfd, (struct sockaddr*)&servaddr1, sizeof(servaddr1));


    int out_value = 0;
    while (true)
    {
        // out_value = aqua_recvfrom(m_socket, &recv_buf, sizeof(recv_buf), 0, (struct sockaddr *) & remote_addr, &addr_size);
        // out_value = recvfrom(send_sockfd, &recv_buf, sizeof(recv_buf), 0, (struct sockaddr *) & remote_addr, &addr_size);
        // out_value = recvfrom(send_sockfd, &recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)NULL, NULL);
        // out_value = recvfrom(listenfd, &recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)NULL, NULL);
        struct aqua_header aqua_frame;
        // memset(&aqua_frame, 0, sizeof (aqua_frame));
        memset(recv_buf, 0, sizeof (recv_buf));
        // out_value = recvfrom(listenfd, &recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)NULL, NULL);
        out_value = aqua_recvfrom(m_socket, &recv_buf, sizeof(recv_buf), 0, (struct sockaddr *) & remote_addr, &addr_size);

        if (out_value < 0) {
            // printf(log_file_name, "failed to read from aqua_socket");
            break;
        }
        else if (out_value == 0)
        {
            // nothing was received during the socket timeout
            printf("socket timeout\n");
            continue;
        }

        // memcpy(&aqua_frame, recv_buf, 2);      // read first to bytes to get the frame length
        // memcpy(&aqua_frame, recv_buf, 2+aqua_frame.frame_len);
        memcpy(&aqua_frame, recv_buf, sizeof(recv_buf));
        // std::cout << "frame_len: " << aqua_frame.frame_len << "\n";
        uint16_t frame_size = aqua_frame.frame_len;
        memset(&aqua_frame, 0, sizeof (aqua_frame));
        memcpy(&aqua_frame, recv_buf, 4+frame_size);

        if (aqua_frame.msg_id == 2)         // handle string message
        {
            std_msgs::String msg;
            msg.data = aqua_frame.pkt_data;
            aquanet_inbound_publisher_string.publish(msg);
        }
    }
}

// Receive thread for DCCL
void receiveAquaDccl(int recv_socket)
{
    struct sockaddr_aquanet remote_addr;
    int addr_size = sizeof (remote_addr);
    
    char recv_buf[256];
    std::string recv_msg;


    int out_value = 0;
    while (true)
    {
        out_value = aqua_recvfrom(m_socket, &recv_buf, sizeof(recv_buf), 0, (struct sockaddr *) & remote_addr, &addr_size);
        if (out_value < 0) {
            // printf(log_file_name, "failed to read from aqua_socket");
            break;
        }
        else if (out_value == 0)
        {
            // nothing was received during the socket timeout
            printf("socket timeout\n");
            continue;
        }

        // reconstruct aqua-message
        // std::cout << "SIZEOF BUF: " << sizeof(recv_buf) << "\n";
        std::string ret(recv_buf, sizeof(recv_buf));
        recv_msg = ret;

        // std::string sub_str = recv_msg.substr(1, (uint8_t)recv_msg[0]);
        // std::cout << "len buf: " << +(uint8_t)recv_msg[0] << "\n";
        // std::cout << "msg: " << sub_str << "\n";

        dccl::Codec recv_codec;
        m_codec.load<AquanetMessage>();
        // recv_codec.load<AquanetMessage>();
        if(m_codec.id(recv_msg) == m_codec.id<AquanetMessage>())
        // if(recv_codec.id(sub_str) == recv_codec.id<AquanetMessage>())
        {
            AquanetMessage r_in;
            m_codec.decode(recv_msg, &r_in);
            // recv_codec.decode(sub_str, &r_in);
            std::cout << r_in.ShortDebugString() << std::endl;

            // Publish the messsages to the inbound topic
            // identify ros-message type and re-generate the correpsonding ros-message structure to be published
            if (r_in.ros_msg_id() == 1)              // handle twist message
            {
                geometry_msgs::Twist twist;
                twist.angular.z = 1.0*r_in.x();
                twist.linear.x = 1.0*r_in.y();
                aquanet_inbound_publisher_twist.publish(twist);
            }
            else if (r_in.ros_msg_id() == 2)        // handle string message
            {
                std_msgs::String msg;
                msg.data = r_in.body_message();
                aquanet_inbound_publisher_string.publish(msg);
            }
            else
            {
                ROS_INFO("Error! Unsupported message type: [%s]", r_in.ros_msg_id());
            }
        }
    }
}

int main(int argc, char **argv)
{
    // turn the local_mode on for gazebo integration tests
    bool localMode = false;
    if (argc == 2)
    {
        if (strcmp(argv[1], "local") == 0)
        {
            localMode = true;
        }
    }

    if ((argc < 3) && !localMode)
    {
        std::cout << "Error! No local and/or destination addresses specified!\n";
        return -1;
    }

    // check the additional dccl flag
    bool dccl_enabled = false;
    if ((argc == 4) && !localMode)
    {
        if (strcmp(argv[3], "dccl") == 0)
        {
            // enabling dccl
            dccl_enabled = true;
            std::cout << "WARNING! DCCL serialization is experimental! Use small message rates!\n";
        }
        else
        {
        std::cout << "Error! Unknown DCCL flag is specified!!\n";
        return -1;
        }
    }

    // Start aquanet stack
    if (!localMode)
    {
        // system("cd /home/ubuntu/ros_catkin_ws/src/aquanet_adapter/aquanet_scripts && ./run_aquanet.sh");
        system("./run_aquanet.sh");
    }

    // Initialize the ROS system and become a node.
    ros::init(argc, argv, "aquanet_node");
    ros::NodeHandle nh;

    if (!localMode)
    {
        // // Creating socket file descriptor
        // if ( (send_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        //     perror("socket creation failed");
        //     exit(EXIT_FAILURE);
        // }
    
        // // struct sockaddr_in servaddr;  
        // // clear servaddr
        // bzero(&servaddr, sizeof(servaddr));

        // if (std::stoi(argv[1]) == 1)
        // {
        //     servaddr.sin_addr.s_addr = inet_addr("10.13.13.101");
        // }
        // else
        // {
        //     servaddr.sin_addr.s_addr = inet_addr("10.13.13.102");
        // }
        // servaddr.sin_port = htons(57777);
        // servaddr.sin_family = AF_INET;

        // Create socket
        if ((m_socket = aqua_socket(AF_AQUANET, SOCK_AQUANET, 0)) < 0) {
            printf("socket creation failed\n");
            perror("m_socket closed");
            exit(1);
        }

        m_to_addr.sin_family = AF_AQUANET;
        // Set local and dest aquanet addresses from CLI
        m_to_addr.sin_addr.s_addr = std::stoi(argv[1]);
        m_to_addr.sin_addr.d_addr = std::stoi(argv[2]);
    }

    // Create subscriber objects for different message types
    if (dccl_enabled)
    {
        // twist
        ros::Subscriber sub_twist = nh.subscribe("aquanet_outbound_twist/", 1, twistMessageReceived);  // TODO: change name to Dccl
        aquanet_inbound_publisher_twist = nh.advertise<geometry_msgs::Twist>("aquanet_inbound_twist", 1);
        // string
        ros::Subscriber sub_string = nh.subscribe("aquanet_outbound_string/", 1, stringMessageReceivedDccl);
        aquanet_inbound_publisher_string = nh.advertise<std_msgs::String>("aquanet_inbound_string", 1);

        // Start the receive thread
        std::thread t1(receiveAquaDccl, m_socket);
    }
    else if (localMode)
    {
        ROS_INFO_STREAM("Starting aquanet-adapter in local mode. Experimental!");
        // introduce waypoint messages for gazebo tests
        // waypoint
        ros::Subscriber sub_waypoint = nh.subscribe("aquanet_outbound_waypoint/", 1, waypointMessageReceived);
        // TODO: change the topic name
        // aquanet_inbound_publisher_waypoint = nh.advertise<uuv_control_msgs::Waypoint>("aquanet_inbound_waypoint", 1);
        aquanet_inbound_publisher_waypoint = nh.advertise<uuv_control_msgs::Waypoint>("rov1/go_to", 1);

        // // Start the receive thread
        // std::thread t1(receiveAqua, m_socket);
    }
    else
    {
        // twist
        ros::Subscriber sub_twist = nh.subscribe("aquanet_outbound_twist/", 1, twistMessageReceived);
        aquanet_inbound_publisher_twist = nh.advertise<geometry_msgs::Twist>("aquanet_inbound_twist", 1);
        // string
        ros::Subscriber sub_string = nh.subscribe("aquanet_outbound_string/", 1, stringMessageReceived);
        aquanet_inbound_publisher_string = nh.advertise<std_msgs::String>("aquanet_inbound_string", 1);

        // Start the receive thread
        std::thread t1(receiveAqua, m_socket);
    }
    // Let ROS take over.
    ros::spin();
}
