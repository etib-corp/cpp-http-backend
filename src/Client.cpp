/*
** EPITECH PROJECT, 2025
** hAPIthon
** File description:
** Client
*/

#include "Client.hpp"

ETIB::Client::Client(const std::string &scheme) : _client(httplib::Client(scheme))
{
}

ETIB::Client::~Client()
{
}

std::shared_ptr<ETIB::JsonValue> ETIB::Client::get(const std::string &url)
{
    auto res = _client.Get(url.c_str());
    if (!res) {
        return nullptr;
    }
    auto json = std::make_shared<ETIB::JsonParser>();
    json->parse(res->body);
    return json->getJsonValue();
}

std::shared_ptr<ETIB::JsonValue> ETIB::Client::post(const std::string &url, const std::shared_ptr<ETIB::JsonValue> &body)
{
    auto res = _client.Post(url.c_str(), body->writeObject().c_str(), "application/json");
    if (!res) {
        return nullptr;
    }
    auto json = std::make_shared<ETIB::JsonParser>();
    json->parse(res->body);
    return json->getJsonValue();
}

std::shared_ptr<ETIB::JsonValue> ETIB::Client::put(const std::string &url, const std::shared_ptr<ETIB::JsonValue> &body)
{
    auto res = _client.Put(url.c_str(), body->writeObject().c_str(), "application/json");
    if (!res) {
        return nullptr;
    }
    auto json = std::make_shared<ETIB::JsonParser>();
    json->parse(res->body);
    return json->getJsonValue();
}

std::shared_ptr<ETIB::JsonValue> ETIB::Client::patch(const std::string &url, const std::shared_ptr<ETIB::JsonValue> &body)
{
    auto res = _client.Patch(url.c_str(), body->writeObject().c_str(), "application/json");
    if (!res) {
        return nullptr;
    }
    auto json = std::make_shared<ETIB::JsonParser>();
    json->parse(res->body);
    return json->getJsonValue();
}

std::shared_ptr<ETIB::JsonValue> ETIB::Client::del(const std::string &url)
{
    auto res = _client.Delete(url.c_str());
    if (!res) {
        return nullptr;
    }
    auto json = std::make_shared<ETIB::JsonParser>();
    json->parse(res->body);
    return json->getJsonValue();
}