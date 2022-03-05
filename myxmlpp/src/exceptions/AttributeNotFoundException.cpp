/*
** EPITECH PROJECT, 2021
** AttributeNotFoundException.cpp.cc
** File description:
** AttributeNotFoundException.cpp.cc
*/


#include "AttributeNotFoundException.hpp"

myxmlpp::AttributeNotFoundException::AttributeNotFoundException(
        const std::string& key,
        const std::string& file,
        int line,
        const std::string& description) noexcept
    :mKey(key), Exception(file, line, description)
{
    build();
}

std::string myxmlpp::AttributeNotFoundException::baseWhat() const noexcept {
    return Exception::baseWhat()
           + std::string(" : cannot find attribute ")
           + mKey;
}

std::string myxmlpp::AttributeNotFoundException::getKey() const {
    return mKey;
}