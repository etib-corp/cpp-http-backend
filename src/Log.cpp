/*
** EPITECH PROJECT, 2025
** hAPIthon
** File description:
** Log
*/

#include "Log.hpp"

ETIB::Log::Log(enum Level level, const std::string &message)
{
    switch (level) {
        case INFO:
            std::cout << "[\033[1;34mINFO\033[0m] " << message << std::endl;
            break;
        case WARNING:
            std::cout << "[\033[1;35mWARNING\033[0m] " << message << std::endl;
            break;
        case ERROR:
            std::cerr << "[\033[1;31mERROR\033[0m] " << message << std::endl;
            break;
    }
}

ETIB::Log::~Log()
{
}
