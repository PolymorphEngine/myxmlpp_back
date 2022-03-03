/*
** EPITECH PROJECT, 2020
** IllegalValueException.hpp.h
** File description:
** header for IllegalValueException.c
*/

#ifndef MYXMLPP_ILLEGALVALUEEXCEPTION_HPP
#define MYXMLPP_ILLEGALVALUEEXCEPTION_HPP

#include <string>
#include "Exception.hpp"

namespace myxmlpp {
    /**
     * Exception that can be thrown by setters/getters of attributes value
     * methods
     */
    class IllegalValueException: public Exception {
        protected:
            /**
             * Key of the anted attribute
             */
            std::string mKey;

            /**
             * Legal type for the operation
             */
             std::string mLegalType;

        public:
            IllegalValueException(std::string legalType,
                                  std::string key,
                                  std::string file,
                                  int line,
                                  std::string description="");

            std::string getKey() const;

            std::string getLegalType() const;

            /**
             * Complete error message, ready to log in the console/terminal
             * @return error message
             */
            virtual std::string what();

            virtual ~IllegalValueException() throw()
            {}
    };
}


#endif //MYXMLPP_ILLEGALVALUEEXCEPTION_HPP
