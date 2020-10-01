//
// Created by kwecky on 01.10.20.
//

#ifndef OVING6_SIMPLECONNECTIONHANDLER_H
#define OVING6_SIMPLECONNECTIONHANDLER_H
#include <boost/asio.hpp>
#include <iostream>
#include <curl/curl.h>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
private:
    class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;
/*
HTTP/1.1 200 OK
Date: Thu, 01 Oct 2020 09:56:34 GMT
Expires: -1
Cache-Control: private, max-age=0
Content-Type: text/html; charset=ISO-8859-1
 */
    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        // Read from client until newline ("\r\n")
        async_read_until(connection->socket, *read_buffer, "\r\n",
                         [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                             // If not error:
                             if (!ec) {
                                 // Retrieve message from client as string:
                                 istream read_stream(read_buffer.get());
                                 std::string message;
                                 getline(read_stream, message);
                                 message.pop_back(); // Remove "\r" at the end of message

                                 // Close connection when "exit" is retrieved from client
                                 if (message == "exit")
                                     return;

                                 cout << "Message from a connected client: " << message << endl;


                                 istringstream iss(message);
                                 vector<string> words {istream_iterator<string>(iss),
                                         istream_iterator<string>{}};
                                 auto write_buffer = make_shared<boost::asio::streambuf>();

                                 ostream write_stream(write_buffer.get());
                                 if((words[0]=="GET")&& (words[1]=="/")){
                                     std::string header ="HTTP/1.1 200 OK\n"
                                                         "Content-Type: text/html; charset=UTF-8\n"
                                                         "Content-length: 60\n\n";
                                     write_stream << header <<"<!DOCTYPE html><html><body>Dette er hovedsiden</body></html>" << "\r\n";
                                 }else if((words[0]=="GET")&&(words[1]=="/en_side")){
                                     std::string header ="HTTP/1.1 200 OK\n"
                                                         "Content-Type: text/html; charset=UTF-8\n"
                                                         "Content-length: 57\n\n";
                                     write_stream << header<<"<!DOCTYPE html><html><body>Dette er en side</body></html>" << "\r\n";
                                 }else{
                                     std::string header ="HTTP/1.1 404 Not found\n"
                                                         "Content-Type: text/html; charset=UTF-8\n"
                                                         "Content-length: 54\n\n";
                                     write_stream << header<<"<!DOCTYPE html><html><body>404 Not Found</body></html>" << "\r\n";
                                 }



                                 // Add message to be written to client:


                                 // Write to client
                                 async_write(connection->socket, *write_buffer,
                                             [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                                 // If not error:
                                                 if (!ec)
                                                     handle_request(connection);
                                             });
                             }
                         });
    }

    void accept() {
        // The (client) connection is added to the lambda parameter and handle_request
        // in order to keep the object alive for as long as it is needed.
        auto connection = make_shared<Connection>(io_service);

        // Accepts a new (client) connection. On connection, immediately start accepting a new connection
        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();
            // If not error:
            if (!ec) {
                handle_request(connection);
            }
        });
    }

public:
    EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();

        io_service.run();
    }
};

#endif //OVING6_SIMPLECONNECTIONHANDLER_H
