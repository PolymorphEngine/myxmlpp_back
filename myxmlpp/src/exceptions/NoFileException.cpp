/*
** EPITECH PROJECT, 2021
** NoFileException.cpp.cc
** File description:
** NoFileException.cpp.cc
*/

#include <string>
#include "NoFileException.hpp"

std::string myxmlpp::NoFileException::what() {
    return baseWhat()
           + std::string("no file at the given filepath ")
           + mFilepath
           +details();
}