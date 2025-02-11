/*
** EPITECH PROJECT, 2025
** cpp-http-backend
** File description:
** DataBase
*/

#include "DataBase.hpp"

ETIB::DataBase::DataBase()
{
    this->_ip = "localhost";
    this->_port = "5432";
    this->_user = "postgres";
    this->_password = "root";
    this->_database = "postgres";
}

ETIB::DataBase::DataBase(const std::string &ip, const std::string &port, const std::string &user, const std::string &password, const std::string &database)
{
    this->_ip = ip;
    this->_port = port;
    this->_user = user;
    this->_password = password;
    this->_database = database;
}

ETIB::DataBase::~DataBase()
{
}

