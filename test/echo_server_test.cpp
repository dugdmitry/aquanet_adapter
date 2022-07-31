#include <ros/ros.h>
#include "std_msgs/UInt32.h"
#include "std_msgs/UInt16.h"
#include "std_msgs/String.h"
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>


// generate random string of length len
// https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

ros::Publisher string_pub;
bool m_server_mode = false;
int m_msg_len = 5;
int m_msg_freq_hz = 1;

// count packet delivery ratio
int m_sent_msgs = 0;
int m_recv_msgs = 0;

// store the receiverd payload for integrity check
std::list<std::string> payload_buffer;
int max_buf_size = 1000;
void addPayload(std::string payload)
{
    if (payload_buffer.size() >= max_buf_size)
    {
        // Remove the first element
        payload_buffer.pop_front();
    }
    payload_buffer.push_back(payload);

    // // printing all current elements
    // std::cout << "SIZE: " << payload_buffer.size() << "\n";
    // for (auto it = payload_buffer.begin(); it != payload_buffer.end(); ++it)
    //     std::cout << ' ' << *it;
}

// check if a particular payload is in the buffer, and update the inegrity counters
int m_integriy_count = 0;
void checkIntegrity(std::string payload)
{
    if (std::find(payload_buffer.begin(), payload_buffer.end(), payload) != payload_buffer.end())
    {
        // Payload is present, integrity is okay
        m_integriy_count++;
    }
}

// callback to recieve the echoed messages
void echoCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("Received: [%s]", msg->data.c_str());

    if (m_server_mode)
    {
        // echo the message back
        ROS_INFO("Echoed: [%s]", msg->data.c_str());
        string_pub.publish(msg);
    }
    else
    {
        m_recv_msgs++;
        // Check message integrity over here
        char *token = std::strtok((char*)msg->data.c_str(), " ");
        // std::cout << "SN: " << token << "\n";
        token = std::strtok(NULL, " ");
        // std::cout << "Payload: " << token << "\n";

        // check integrity
        checkIntegrity(token);
    }
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Error! Invalid argument format!\n";
        return -1;
    }

    if (strcmp(argv[1], "s") == 0)
    {
        if (argc != 2)
        {
            std::cout << "Error! Invalid argument format!\n";
        }
        m_server_mode = true;
    }
    else if (strcmp(argv[1], "c") == 0)
    {
        if (argc != 4)
        {
            std::cout << "Error! Invalid argument format!\n";
        }
        m_server_mode = false;
        m_msg_len = std::stoi(argv[2]);
        m_msg_freq_hz = std::stoi(argv[3]);
    }
    else
    {
        std::cout << "Error! Invalid sending mode!\n";
        return -1;
    }

    ros::init(argc, argv, "echo_server_test");
    ros::NodeHandle nh_;
    // ros::Publisher string_pub = nh_.advertise<std_msgs::String>("aquanet_outbound_string", 1);
    string_pub = nh_.advertise<std_msgs::String>("aquanet_outbound_string", 1);
    ros::Subscriber sub = nh_.subscribe("/aquanet_inbound_string", 1, echoCallback);

    if (!m_server_mode)
    {
        // Generate a message of size N every X seconds
        ros::Rate loop_rate(m_msg_freq_hz);  // in Hz
        int count = 0;

        double time_count = 0;
        while (ros::ok())
        {
            std_msgs::String msg;
            std::stringstream ss;
            std::string rnd_string = random_string(m_msg_len);
            addPayload(rnd_string);
            ss << count << " " << rnd_string;
            msg.data = ss.str();

            ROS_INFO("Sent: %s", msg.data.c_str());

            string_pub.publish(msg);
            
            ros::spinOnce();    // necessary to receive callbacks
            loop_rate.sleep();

            count++;

            // print PDR
            if (m_recv_msgs > 0)
            {
                // update the file every 10 sends
                if ((m_sent_msgs % 10) == 0)
                {
                    // Create file to write PDR and integrity stats
                    std::ofstream stats;
                    stats.open ("stats_pdr.txt", std::ios_base::app);
                    // std::cout << std::to_string(m_recv_msgs-1) << " " << std::to_string(m_sent_msgs-1) << "\n";
                    time_count += (double) 10 / m_msg_freq_hz;
                    stats << "Time: " << std::to_string(time_count) << " " << std::to_string((double) 100*(m_recv_msgs) / (m_sent_msgs)) << " " << std::to_string((double) 100*(m_integriy_count) / (m_recv_msgs)) << "\n";
                    stats.close();
                }
                m_sent_msgs++;
            }
            else
            {
                m_sent_msgs = m_recv_msgs + 1;
            }
        }
    }
    else
    {
        // Let ROS take over.
        ros::spin();
    }

    return 0;
}
