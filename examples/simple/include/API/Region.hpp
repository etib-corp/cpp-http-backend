/*
** EPITECH PROJECT, 2025
** hAPIthon
** File description:
** Region
*/

#ifndef REGION_HPP_
#define REGION_HPP_

#include "etibjson.hpp"

namespace ETIB {
    namespace API {
        class Region : public JsonSerializable {
            public:
                Region();
                Region(const std::string& majorSpecs, bool isNationalPark, int id, const std::pair<double, double>& coordinates, bool isWorldHeritage, bool isMajorPlace, const std::string& name, const std::string& district, const std::string& locationName, unsigned int inseeCode, bool isReducedMobilityAccessible);

                std::shared_ptr<ETIB::JsonValue> serialize() override;

                void deserialize(const std::shared_ptr<ETIB::JsonValue>& json) override;

                std::string majorSpecs;
                bool isNationalPark;
                int id;
                std::pair<double, double> coordinates;
                bool isWorldHeritage;
                bool isMajorPlace;
                std::string name;
                std::string district;
                std::string locationName;
                unsigned int inseeCode;
                bool isReducedMobilityAccessible;
        };
    }
}

#endif /* !REGION_HPP_ */
