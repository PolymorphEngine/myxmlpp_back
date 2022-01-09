/*
** EPITECH PROJECT, 2020
** ParsingException.hpp
** File description:
** header for ParsingException.c
*/

#ifndef MYXMLPP_PARSINGEXCEPTION_HPP
#define MYXMLPP_PARSINGEXCEPTION_HPP

#include "Exception.hpp"

namespace myxmlpp {
    class ParsingException: public Exception {
        protected:
            /**
             * Key of the anted attribute
             */
            std::string mContent;

        public:
            ParsingException(const std::string& content,
                                       const std::string& file,
                                       int line,
                                       const std::string& description="");

            /**
             * Complete error message, ready to log in the console/terminal
             * @return error message
             */
            virtual std::string what();

            virtual ~ParsingException() throw()
            {}
    };
}

#endif //MYXMLPP_PARSINGEXCEPTION_HPP
