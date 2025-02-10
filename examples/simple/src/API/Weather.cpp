/*
** EPITECH PROJECT, 2025
** hAPIthon
** File description:
** Weather
*/

#include "API/Weather.hpp"

ETIB::API::Weather::Weather()
{
    lat = 0;
    lon = 0;
    timezone = "";
    timezone_offset = 0;
    dt = 0;
    sunrise = 0;
    sunset = 0;
    temp = 0;
    feels_like = 0;
    pressure = 0;
    humidity = 0;
    dew_point = 0;
    uvi = 0;
    clouds = 0;
    visibility = 0;
    wind_speed = 0;
    wind_deg = 0;
    wind_gust = 0;
    weather_id = 0;
    weather_main = "";
    weather_description = "";
    weather_icon = "";
}

ETIB::API::Weather::Weather(double lat, double lon, const std::string& timezone, int timezone_offset, int dt, int sunrise, int sunset, double temp, double feels_like, int pressure, int humidity, double dew_point, double uvi, int clouds, int visibility, double wind_speed, int wind_deg, double wind_gust, int weather_id, const std::string& weather_main, const std::string& weather_description, const std::string& weather_icon)
{
    this->lat = lat;
    this->lon = lon;
    this->timezone = timezone;
    this->timezone_offset = timezone_offset;
    this->dt = dt;
    this->sunrise = sunrise;
    this->sunset = sunset;
    this->temp = temp;
    this->feels_like = feels_like;
    this->pressure = pressure;
    this->humidity = humidity;
    this->dew_point = dew_point;
    this->uvi = uvi;
    this->clouds = clouds;
    this->visibility = visibility;
    this->wind_speed = wind_speed;
    this->wind_deg = wind_deg;
    this->wind_gust = wind_gust;
    this->weather_id = weather_id;
    this->weather_main = weather_main;
    this->weather_description = weather_description;
    this->weather_icon = weather_icon;
}

std::shared_ptr<ETIB::JsonValue> ETIB::API::Weather::serialize()
{
    auto obj = std::make_shared<ETIB::JsonObject>();
    auto current = std::make_shared<ETIB::JsonObject>();
    auto weather = std::make_shared<ETIB::JsonArray>();

    obj->addValue("lat", std::make_shared<ETIB::JsonNumber>(lat));
    obj->addValue("lon", std::make_shared<ETIB::JsonNumber>(lon));
    obj->addValue("timezone", std::make_shared<ETIB::JsonString>(timezone));
    obj->addValue("timezone_offset", std::make_shared<ETIB::JsonNumber>(timezone_offset));

    current->addValue("dt", std::make_shared<ETIB::JsonNumber>(dt));
    current->addValue("sunrise", std::make_shared<ETIB::JsonNumber>(sunrise));
    current->addValue("sunset", std::make_shared<ETIB::JsonNumber>(sunset));
    current->addValue("temp", std::make_shared<ETIB::JsonNumber>(temp));
    current->addValue("feels_like", std::make_shared<ETIB::JsonNumber>(feels_like));
    current->addValue("pressure", std::make_shared<ETIB::JsonNumber>(pressure));
    current->addValue("humidity", std::make_shared<ETIB::JsonNumber>(humidity));
    current->addValue("dew_point", std::make_shared<ETIB::JsonNumber>(dew_point));
    current->addValue("uvi", std::make_shared<ETIB::JsonNumber>(uvi));
    current->addValue("clouds", std::make_shared<ETIB::JsonNumber>(clouds));
    current->addValue("visibility", std::make_shared<ETIB::JsonNumber>(visibility));
    current->addValue("wind_speed", std::make_shared<ETIB::JsonNumber>(wind_speed));
    current->addValue("wind_deg", std::make_shared<ETIB::JsonNumber>(wind_deg));
    current->addValue("wind_gust", std::make_shared<ETIB::JsonNumber>(wind_gust));
    obj->addValue("current", current);

    weather->addValue(std::make_shared<ETIB::JsonNumber>(weather_id));
    weather->addValue(std::make_shared<ETIB::JsonString>(weather_main));
    weather->addValue(std::make_shared<ETIB::JsonString>(weather_description));
    weather->addValue(std::make_shared<ETIB::JsonString>(weather_icon));
    obj->addValue("weather", weather);

    return obj;
}

void ETIB::API::Weather::deserialize(const std::shared_ptr<ETIB::JsonValue>& json)
{
    lat = json->getObjectValue().at("lat")->getNumberValue();
    lon = json->getObjectValue().at("lon")->getNumberValue();
    timezone = json->getObjectValue().at("timezone")->getStringValue();
    timezone_offset = json->getObjectValue().at("timezone_offset")->getNumberValue();

    auto current = json->getObjectValue().at("current");
    dt = current->getObjectValue().at("dt")->getNumberValue();
    sunrise = current->getObjectValue().at("sunrise")->getNumberValue();
    sunset = current->getObjectValue().at("sunset")->getNumberValue();
    temp = current->getObjectValue().at("temp")->getNumberValue();
    feels_like = current->getObjectValue().at("feels_like")->getNumberValue();
    pressure = current->getObjectValue().at("pressure")->getNumberValue();
    humidity = current->getObjectValue().at("humidity")->getNumberValue();
    dew_point = current->getObjectValue().at("dew_point")->getNumberValue();
    uvi = current->getObjectValue().at("uvi")->getNumberValue();
    clouds = current->getObjectValue().at("clouds")->getNumberValue();
    visibility = current->getObjectValue().at("visibility")->getNumberValue();
    wind_speed = current->getObjectValue().at("wind_speed")->getNumberValue();
    wind_deg = current->getObjectValue().at("wind_deg")->getNumberValue();
    wind_gust = current->getObjectValue().at("wind_gust")->getNumberValue();

    auto weather = json->getObjectValue().at("weather");
    weather_id = weather->getArrayValue().at(0)->getNumberValue();
    weather_main = weather->getArrayValue().at(1)->getStringValue();
    weather_description = weather->getArrayValue().at(2)->getStringValue();
    weather_icon = weather->getArrayValue().at(3)->getStringValue();
}