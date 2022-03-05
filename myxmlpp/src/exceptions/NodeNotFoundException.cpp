/*
** EPITECH PROJECT, 2021
** NodeNotFoundException.cpp.cc
** File description:
** NodeNotFoundException.cpp.cc
*/


#include "NodeNotFoundException.hpp"

myxmlpp::NodeNotFoundException::NodeNotFoundException(const std::string& tag,
        const std::string& file,
        int line,
        const std::string& description) noexcept
    :mTag(tag), Exception(file, line, description)
{
    build();
}

std::string myxmlpp::NodeNotFoundException::baseWhat() const noexcept {
    return Exception::baseWhat()
           + std::string(": cannot find node ")
           + mTag;
}

std::string myxmlpp::NodeNotFoundException::getTag() const noexcept {
    return mTag;
}