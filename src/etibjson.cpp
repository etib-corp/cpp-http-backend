/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** etibjson
*/

#include "etibjson.hpp"

std::shared_ptr<ETIB::JsonValue> ETIB::JsonValue::operator[](const std::string& key)
{
    if (_type != ETIB::JSON_OBJECT) {
        return nullptr;
    }
    return dynamic_cast<ETIB::JsonObject *>(this)->getValue()[key];
}

std::shared_ptr<ETIB::JsonValue> ETIB::JsonValue::operator[](const size_t& index)
{
    if (_type != ETIB::JSON_ARRAY) {
        return nullptr;
    }
    return dynamic_cast<ETIB::JsonArray *>(this)->getValue()[index];
}

double ETIB::JsonValue::getNumberValue()
{
    if (_type != ETIB::JSON_NUMBER) {
        return 0.0;
    }
    return dynamic_cast<ETIB::JsonNumber *>(this)->getValue();
}

std::string ETIB::JsonValue::getStringValue()
{
    if (_type != ETIB::JSON_STRING) {
        return "";
    }
    return dynamic_cast<ETIB::JsonString *>(this)->getValue();
}

std::vector<std::shared_ptr<ETIB::JsonValue>> ETIB::JsonValue::getArrayValue()
{
    if (_type != ETIB::JSON_ARRAY) {
        return {};
    }
    return dynamic_cast<ETIB::JsonArray *>(this)->getValue();
}

std::map<std::string, std::shared_ptr<ETIB::JsonValue>> ETIB::JsonValue::getObjectValue()
{
    if (_type != ETIB::JSON_OBJECT) {
        return {};
    }
    return dynamic_cast<ETIB::JsonObject *>(this)->getValue();
}

bool ETIB::JsonValue::getBoolValue()
{
    if (_type != ETIB::JSON_BOOL) {
        return false;
    }
    return dynamic_cast<ETIB::JsonBool *>(this)->getValue();
}

std::string ETIB::JsonValue::writeObject()
{
    std::string res = "{";
    auto objectValue = dynamic_cast<ETIB::JsonObject *>(this)->getValue();
    for (auto it = objectValue.begin(); it != objectValue.end(); it++) {
        res += "\"" + it->first + "\":" + it->second->writeValue();
        if (std::next(it) != objectValue.end())
            res += ",";
    }
    res += "}";
    return res;
}

std::string ETIB::JsonValue::writeArray()
{
    std::string res = "[";
    auto arraySize = dynamic_cast<ETIB::JsonArray *>(this)->getValue().size();
    for (size_t i = 0; i < arraySize; i++) {
        res += dynamic_cast<ETIB::JsonArray *>(this)->getValue()[i]->writeValue();
        if (i + 1 < dynamic_cast<ETIB::JsonArray *>(this)->getValue().size())
            res += ",";
    }
    res += "]";
    return res;
}

std::string ETIB::JsonValue::writeString()
{
    return "\"" + dynamic_cast<ETIB::JsonString *>(this)->getValue() + "\"";
}

std::string ETIB::JsonValue::writeNumber()
{
    return std::to_string(dynamic_cast<ETIB::JsonNumber *>(this)->getValue());
}

std::string ETIB::JsonValue::writeBool()
{
    return dynamic_cast<ETIB::JsonBool *>(this)->getValue() ? "true" : "false";
}

std::string ETIB::JsonValue::writeNull()
{
    return "null";
}