/*
** EPITECH PROJECT, 2021
** Exception.cpp.cc
** File description:
** Exception.cpp.cc
*/

#include <iostream>
#include <sstream>
#include "Exception.hpp"

myxmlpp::Exception::Exception(const std::string &file, int line,
                              const std::string &description) :
    mFile(file),
    mDescription(description)
{
    std::ostringstream str;
    str << line;
    mLine = str.str();
}

std::string myxmlpp::Exception::what() {
    return std::string("\nError in ") +
        mFile +
        std::string(" at line ") +
        mLine +
        std::string(": ") +
        details();
}

std::string myxmlpp::Exception::baseWhat() const {
    return std::string("\nError in ") +
           mFile +
           std::string(" at line ") +
           mLine +
           std::string(": ");
}

std::string myxmlpp::Exception::details() const {
    if (mDescription.length())
        return std::string("\nOptionnal details : ")
                + mDescription
                + std::string("\n");
    else
        return std::string("\n");
}

const std::string &myxmlpp::Exception::getFile() const {
    return mFile;
}

const std::string &myxmlpp::Exception::getLine() const {
    return mLine;
}
