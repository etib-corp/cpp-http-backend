/*
** EPITECH PROJECT, 2025
** hAPIthon
** File description:
** Log
*/

#ifndef LOG_HPP_
#define LOG_HPP_

#include <iostream>
#include <string>

#include <stdlib.h>

namespace ETIB {
    class Log {
        public:
            enum Level {
                INFO,
                WARNING,
                ERROR
            };

            Log(enum Level level, const std::string &message);
            ~Log();
    };
}

#endif /* !LOG_HPP_ */
