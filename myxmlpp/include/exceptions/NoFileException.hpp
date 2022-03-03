/*
** EPITECH PROJECT, 2020
** NoFileException.hpp.h
** File description:
** header for NoFileException.c
*/

#ifndef MYXMLPP_NOFILEEXCEPTION_HPP
#define MYXMLPP_NOFILEEXCEPTION_HPP

#include "FileException.hpp"

namespace myxmlpp {
    /**
     * Exception to throw when a file does not exist.
     */
    class NoFileException: public myxmlpp::FileException {
        public:
            /**
             * Complete error message, ready to log in the console/terminal
             * @return error message
             */
            virtual std::string what();
    };
}


#endif //MYXMLPP_NOFILEEXCEPTION_HPP
