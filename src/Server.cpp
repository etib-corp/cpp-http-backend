/*
** EPITECH PROJECT, 2025
** hAPIthon
** File description:
** Server
*/

#include "Server.hpp"

ETIB::Server::Server(const std::string &host, unsigned int port)
{
    _host = host;
    _port = port;
    _instance = new httplib::Server();

    _instance->Options("/*", [](const httplib::Request &req, httplib::Response &res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        res.status = 204;
    });
}

ETIB::Server::~Server()
{
    ETIB::Log(ETIB::Log::WARNING, "Server stopped");
    _instance->stop();
    delete _instance;
}

void ETIB::Server::listen()
{
    ETIB::Log(ETIB::Log::WARNING, "Server listening on http://" + _host + ":" + std::to_string(_port));
    _instance->listen(_host.c_str(), _port);
}

void ETIB::Server::get(const std::string &path, const std::function<void(const httplib::Request &req, httplib::Response &res)> &callback)
{
    _instance->Get(path.c_str(), [&](const httplib::Request &req, httplib::Response &res) {
        callback(req, res);
        ETIB::Log(ETIB::Log::INFO, "GET " + path);
    });
}

void ETIB::Server::post(const std::string &path, const std::function<void(const httplib::Request &req, httplib::Response &res)> &callback)
{
    _instance->Post(path.c_str(), [&](const httplib::Request &req, httplib::Response &res) {
        callback(req, res);
        ETIB::Log(ETIB::Log::INFO, "POST " + path);
    });
}

void ETIB::Server::put(const std::string &path, const std::function<void(const httplib::Request &req, httplib::Response &res)> &callback)
{
    _instance->Put(path.c_str(), [&](const httplib::Request &req, httplib::Response &res) {
        callback(req, res);
        ETIB::Log(ETIB::Log::INFO, "PUT " + path);
    });
}

void ETIB::Server::del(const std::string &path, const std::function<void(const httplib::Request &req, httplib::Response &res)> &callback)
{
    _instance->Delete(path.c_str(), [&](const httplib::Request &req, httplib::Response &res) {
        callback(req, res);
        ETIB::Log(ETIB::Log::INFO, "DELETE " + path);
    });
}
