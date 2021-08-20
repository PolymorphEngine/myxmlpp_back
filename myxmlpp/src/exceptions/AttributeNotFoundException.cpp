/*
** EPITECH PROJECT, 2021
** AttributeNotFoundException.cpp.cc
** File description:
** AttributeNotFoundException.cpp.cc
*/


#include "AttributeNotFoundException.hpp"

myxmlpp::AttributeNotFoundException::AttributeNotFoundException(
        std::string key,
        std::string file,
        std::string line,
        std::string description)
    :mKey(key), Exception(file, line, description)
{}

std::string myxmlpp::AttributeNotFoundException::what() {
    return baseWhat()
           + std::string("cannot find attribute ")
           + mKey
           +details();
}

std::string myxmlpp::AttributeNotFoundException::getKey() const {
    return mKey;
}