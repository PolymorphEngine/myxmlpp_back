/*
** EPITECH PROJECT, 2021
** Exception.cpp.cc
** File description:
** Exception.cpp.cc
*/


#include "exceptions/Exception.hpp"

myxmlpp::Exception::Exception(const std::string &file, const std::string &line,
                              const std::string &description) :
    mFile(file),
    mLine(line),
    mDescription(description)
{}

std::string myxmlpp::Exception::what() {
    return std::string("Error in ") +
        mFile +
        std::string(" at line ") +
        mLine +
        std::string(": ") +
        mDescription;
}

const std::string &myxmlpp::Exception::getFile() const {
    return mFile;
}

const std::string &myxmlpp::Exception::getLine() const {
    return mLine;
}
