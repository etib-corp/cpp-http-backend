/*
** EPITECH PROJECT, 2025
** hAPIthon
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <string>
#include <functional>

#include "Log.hpp"

#ifndef CPPHTTPLIB_OPENSSL_SUPPORT
#define CPPHTTPLIB_OPENSSL_SUPPORT
#endif /* !CPPHTTPLIB_OPENSSL_SUPPORT */
#include "httplib.h"

namespace ETIB {
    class Server {
        public:
            Server(const std::string &host = "localhost", unsigned int port = 4242);
            ~Server();

            void listen();

            void get(const std::string &path, const std::function<void(const httplib::Request &, httplib::Response &)> &callback);
            void post(const std::string &path, const std::function<void(const httplib::Request &, httplib::Response &)> &callback);
            void put(const std::string &path, const std::function<void(const httplib::Request &, httplib::Response &)> &callback);
            void del(const std::string &path, const std::function<void(const httplib::Request &, httplib::Response &)> &callback);

        protected:
            unsigned int _port;
            std::string _host;
            httplib::Server *_instance;
    };
}

#endif /* !SERVER_HPP_ */
