/*
** EPITECH PROJECT, 2021
** NodeNotFoundException.cpp.cc
** File description:
** NodeNotFoundException.cpp.cc
*/


#include "NodeNotFoundException.hpp"

myxmlpp::NodeNotFoundException::NodeNotFoundException(std::string tag,
        std::string file,
        std::string line,
        std::string description)
    :mTag(tag), Exception(file, line, description)
{}

std::string myxmlpp::NodeNotFoundException::what() {
    return baseWhat()
           + std::string("cannot find node ")
           + mTag
           +details();
}

std::string myxmlpp::NodeNotFoundException::getTag() const {
    return mTag;
}