/*
** EPITECH PROJECT, 2020
** attribute.hpp.h
** File description:
** header for Attribute.cpp
*/

#ifndef MYXMLPP_ATTRIBUTE_HPP
#define MYXMLPP_ATTRIBUTE_HPP

#include <string>

namespace myxmlpp {
    /**
     * Attribute in a node
     */
    class Attribute {
        private:
            /**
             * Key of the attribute
             */
            std::string key;
            std::string value;

        public:
    };
}


#endif //MYXMLPP_ATTRIBUTE_HPP
