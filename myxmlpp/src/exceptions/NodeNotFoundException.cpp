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
{}

std::string myxmlpp::NodeNotFoundException::what() noexcept {
    return baseWhat()
           + std::string("cannot find node ")
           + mTag
           +details();
}

std::string myxmlpp::NodeNotFoundException::getTag() const noexcept {
    return mTag;
}