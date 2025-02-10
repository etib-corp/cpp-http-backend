/*
** EPITECH PROJECT, 2025
** hAPIthon
** File description:
** Region
*/

#include "API/Region.hpp"

ETIB::API::Region::Region()
{
    majorSpecs = "";
    isNationalPark = false;
    id = 0;
    coordinates = {0, 0};
    isWorldHeritage = false;
    isMajorPlace = false;
    name = "";
    district = "";
    locationName = "";
    inseeCode = 0;
    isReducedMobilityAccessible = false;
}

ETIB::API::Region::Region(const std::string& majorSpecs, bool isNationalPark, int id, const std::pair<double, double>& coordinates, bool isWorldHeritage, bool isMajorPlace, const std::string& name, const std::string& district, const std::string& locationName, unsigned int inseeCode, bool isReducedMobilityAccessible)
{
    this->majorSpecs = majorSpecs;
    this->isNationalPark = isNationalPark;
    this->id = id;
    this->coordinates = coordinates;
    this->isWorldHeritage = isWorldHeritage;
    this->isMajorPlace = isMajorPlace;
    this->name = name;
    this->district = district;
    this->locationName = locationName;
    this->inseeCode = inseeCode;
    this->isReducedMobilityAccessible = isReducedMobilityAccessible;
}

std::shared_ptr<ETIB::JsonValue> ETIB::API::Region::serialize()
{
    auto obj = std::make_shared<ETIB::JsonObject>();
    auto coordinates = std::make_shared<ETIB::JsonObject>();

    obj->addValue("caracteristiques", std::make_shared<ETIB::JsonString>(majorSpecs));
    obj->addValue("situe_dans_un_parc_national", std::make_shared<ETIB::JsonNumber>(isNationalPark));
    obj->addValue("identifiant", std::make_shared<ETIB::JsonNumber>(id));

    coordinates->addValue("lat", std::make_shared<ETIB::JsonNumber>(this->coordinates.first));
    coordinates->addValue("lon", std::make_shared<ETIB::JsonNumber>(this->coordinates.second));
    obj->addValue("coordonnees_geographiques", coordinates);

    obj->addValue("appartient_au_patrimoine_mondial", std::make_shared<ETIB::JsonBool>(isWorldHeritage));
    obj->addValue("lieu_majeur", std::make_shared<ETIB::JsonBool>(isMajorPlace));
    obj->addValue("nom_du_lieu_remarquable", std::make_shared<ETIB::JsonString>(name));
    obj->addValue("accroche", std::make_shared<ETIB::JsonString>(locationName));
    obj->addValue("commune", std::make_shared<ETIB::JsonString>(district));
    obj->addValue("code_insee_de_la_commune", std::make_shared<ETIB::JsonNumber>(inseeCode));
    obj->addValue("accessible_mobilite_reduite", std::make_shared<ETIB::JsonBool>(isReducedMobilityAccessible));
    return obj;
}

void ETIB::API::Region::deserialize(const std::shared_ptr<ETIB::JsonValue>& json)
{
    majorSpecs = json->getObjectValue().at("caracteristiques")->getStringValue();
    isNationalPark = json->getObjectValue().at("situe_dans_un_parc_national")->getBoolValue();
    id = json->getObjectValue().at("identifiant")->getNumberValue();
    coordinates.first = json->getObjectValue().at("coordonnees_geographiques")->getObjectValue().at("lat")->getNumberValue();
    coordinates.second = json->getObjectValue().at("coordonnees_geographiques")->getObjectValue().at("lon")->getNumberValue();
    isWorldHeritage = json->getObjectValue().at("appartient_au_patrimoine_mondial")->getBoolValue();
    isMajorPlace = json->getObjectValue().at("lieu_majeur")->getBoolValue();
    name = json->getObjectValue().at("nom_du_lieu_remarquable")->getStringValue();
    district = json->getObjectValue().at("commune")->getStringValue();
    locationName = json->getObjectValue().at("accroche")->getStringValue();
    inseeCode = json->getObjectValue().at("code_insee_de_la_commune")->getNumberValue();
    isReducedMobilityAccessible = json->getObjectValue().at("accessible_mobilite_reduite")->getBoolValue();
}
