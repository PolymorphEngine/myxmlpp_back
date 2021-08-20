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
        mDescription +
        std::string("\n");
}

std::string myxmlpp::Exception::baseWhat() const {
    return std::string("\nError in ") +
           mFile +
           std::string(" at line ") +
           mLine +
           std::string(": ");
}

const std::string &myxmlpp::Exception::getFile() const {
    return mFile;
}

const std::string &myxmlpp::Exception::getLine() const {
    return mLine;
}
