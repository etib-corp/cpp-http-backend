/*
** EPITECH PROJECT, 2025
** hAPIthon
** File description:
** Weather
*/

#ifndef WEATHER_HPP_
#define WEATHER_HPP_

#include "etibjson.hpp"

namespace ETIB  {
    namespace API {
        class Weather : public ETIB::JsonSerializable {
            public:
            Weather();
            Weather(double lat, double lon, const std::string& timezone, int timezone_offset, int dt, int sunrise, int sunset, double temp, double feels_like, int pressure, int humidity, double dew_point, double uvi, int clouds, int visibility, double wind_speed, int wind_deg, double wind_gust, int weather_id, const std::string& weather_main, const std::string& weather_description, const std::string& weather_icon);

            std::shared_ptr<ETIB::JsonValue> serialize() override;

            void deserialize(const std::shared_ptr<ETIB::JsonValue>& json) override;

            double lat;
            double lon;
            std::string timezone;
            int timezone_offset;
            int dt;
            int sunrise;
            int sunset;
            double temp;
            double feels_like;
            int pressure;
            int humidity;
            double dew_point;
            double uvi;
            int clouds;
            int visibility;
            double wind_speed;
            int wind_deg;
            double wind_gust;
            int weather_id;
            std::string weather_main;
            std::string weather_description;
            std::string weather_icon;
        };;
    }
}

#endif /* !WEATHER_HPP_ */
