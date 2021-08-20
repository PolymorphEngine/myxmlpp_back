/*
** EPITECH PROJECT, 2021
** Exception.cpp.cc
** File description:
** Exception.cpp.cc
*/


#include "Exception.hpp"

myxmlpp::Exception::Exception(const std::string &file, const std::string &line,
                              const std::string &description) :
    mFile(file),
    mLine(line),
    mDescription(description)
{}

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
