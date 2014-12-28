/**
 * Author: Aravinth Panchadcharam
 * Email: me@aravinth.info
 * Date: 28/12/14.
 * Project: Gesture Recogntion for Human-Robot Interaction
 */

#ifndef __human_robot_interaction__udp_client__
#define __human_robot_interaction__udp_client__


#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

using boost::asio::ip::udp;
class udp_client
{
    
private:
    const int server_port = 50005;
    const int client_port = 50006;
    const char* server_host_name_remote = "nao5.local";
    const char* server_host_name_local = "localhost";
    boost::array<char, 16> receive_buffer;
    boost::array<char, 8> send_buffer;
    udp::endpoint server_endpoint;
    udp::socket socket_client;
    

    void send(boost::shared_ptr<std::string> message);
    void receive();
    void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred);
    void handle_send(boost::shared_ptr<std::string> message, const boost::system::error_code& error, std::size_t bytes_transferred);
    
public:
    udp_client(boost::asio::io_service& io_service);
};


#endif