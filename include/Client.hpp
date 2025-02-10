/*
** EPITECH PROJECT, 2025
** hAPIthon
** File description:
** Client
*/

#pragma once

#include "etibjson.hpp"
#include "httplib.h"

namespace ETIB {
    class Client {
        public:
            Client(const std::string &scheme);
            ~Client();
            std::shared_ptr<ETIB::JsonValue> get(const std::string &url);
            std::shared_ptr<ETIB::JsonValue> post(const std::string &url, const std::shared_ptr<ETIB::JsonValue> &body);
            std::shared_ptr<ETIB::JsonValue> put(const std::string &url, const std::shared_ptr<ETIB::JsonValue> &body);
            std::shared_ptr<ETIB::JsonValue> patch(const std::string &url, const std::shared_ptr<ETIB::JsonValue> &body);
            std::shared_ptr<ETIB::JsonValue> del(const std::string &url);
        private:
            httplib::Client _client;
    };
}