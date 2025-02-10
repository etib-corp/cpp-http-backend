/*
** EPITECH PROJECT, 2025
** hAPIthon
** File description:
** main
*/

#include <iostream>
#include "Server.hpp"
#include "Client.hpp"
#include "API/Region.hpp"
#include "API/Weather.hpp"
#include "Log.hpp"

ETIB::Server *createServerFromArgs(int ac, char **av)
{
    if (ac == 2) {
        if (std::stoi(av[1]) > 0 && std::stoi(av[1]) < 65535)
            return new ETIB::Server("localhost", std::stoi(av[1]));
        if (av[1] == "help") {
            std::cout << "Usage: ./hAPIthon [port]" << std::endl;
            return nullptr;
        }
    }
    return new ETIB::Server();
}

std::shared_ptr<std::vector<ETIB::API::Region>> getRegions(ETIB::Client *regionReunion)
{
    std::shared_ptr<std::vector<ETIB::API::Region>> regions = std::make_shared<std::vector<ETIB::API::Region>>();
    std::shared_ptr<ETIB::JsonValue> json = regionReunion->get("/api/explore/v2.1/catalog/datasets/lieux-remarquables-lareunion-wssoubik/records?limit=100");

    if (!json) {
        ETIB::Log(ETIB::Log::ERROR, "Failed to get regions, bad API call.");
        return nullptr;
    }
    for (auto &elem : json->getObjectValue().at("results")->getArrayValue()) {
        ETIB::API::Region region;

        region.deserialize(elem);
        regions->push_back(region);
    }
    return regions;
}

std::string getFileContent(const std::string &filename)
{
    std::ifstream file(filename);
    std::string content;

    if (!file.is_open()) {
        ETIB::Log(ETIB::Log::ERROR, "Failed to open file " + filename);
        return "";
    }
    content = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

int main(int ac, char **av)
{
    std::string htmlContent = getFileContent("api.html");
    ETIB::Server *server = createServerFromArgs(ac, av);

    ETIB::Client *regionReunion = new ETIB::Client("https://data.regionreunion.com");
    std::shared_ptr<std::vector<ETIB::API::Region>> regionsValues = getRegions(regionReunion);
    ETIB::JsonArray regions = ETIB::JsonArray();

    ETIB::Client *weatherClient = new ETIB::Client("https://api.openweathermap.org");

    if (!regionsValues) {
        ETIB::Log(ETIB::Log::ERROR, "Failed to get regions");
        return 84;
    }
    for (auto &region : *regionsValues) {
        regions.addValue(region.serialize());
    }

    if (!server) {
        ETIB::Log(ETIB::Log::ERROR, "Failed to create server");
        return 84;
    }
    server->get("/", [&](const httplib::Request &req, httplib::Response &res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        res.status = 200;
        res.set_content(htmlContent, "text/html");
    });
    server->get("/test", [](const httplib::Request &req, httplib::Response &res) {
        res.status = 200;
        res.set_content("Hello World!", "text/plain");
    });
    server->get("/places", [&](const httplib::Request &req, httplib::Response &res) {
        res.status = 200;
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        res.set_content(regions.writeArray(), "application/json");
    });
    server->get("/weathers", [&](const httplib::Request &req, httplib::Response &res) {
        auto lat = req.get_param_value("lat");
        auto lon = req.get_param_value("lon");

        if (lat.empty() || lon.empty()) {
            res.status = 400;
            res.set_content("{\"error\":\"Missing latitude or longitude\"}", "application/json");
            ETIB::Log(ETIB::Log::ERROR, "Invalid request, missing latitude or longitude");
            return;
        }

        std::shared_ptr<ETIB::JsonValue> json = weatherClient->get("/data/2.5/weather?lat=" + lat + "&lon=" + lon + "&appid=63d2c9841547574de0ad680674b48c61");

        if (!json) {
            res.status = 500;
            res.set_content("{\"error\":\"Failed to get weather\"}", "application/json");
            ETIB::Log(ETIB::Log::ERROR, "Failed to get weather");
            return;
        }
        res.status = 200;
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        res.set_content(json->writeObject(), "application/json");
    });
    server->listen();
    delete server;
    return 0;
}