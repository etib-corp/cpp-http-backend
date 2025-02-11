/*
** EPITECH PROJECT, 2025
** cpp-http-backend
** File description:
** DataBase
*/

#ifndef DATABASE_HPP_
#define DATABASE_HPP_

#include <string>
#include <pqxx/pqxx>

namespace ETIB {
    class DataBase final {
        public:
            DataBase();
            DataBase(const std::string &ip, const std::string &port, const std::string &user, const std::string &password, const std::string &database);
            ~DataBase();

        protected:
            std::string _ip;
            std::string _port;
            std::string _user;
            std::string _password;
            std::string _database;
            pqxx::connection _connection;
            pqxx::work _currentTransaction;
    };
}

#endif /* !DATABASE_HPP_ */
