/*
** EPITECH PROJECT, 2020
** FileException.cpp.c
** File description:
** FileException.cpp.c
*/

#include "FileException.hpp"

myxmlpp::FileException::FileException(const std::string &filepath,
                                      const std::string &file,
                                      const std::string &line,
                                      const std::string &description)
    :mFilepath(filepath), Exception(file, line, description)
{}

const std::string &myxmlpp::FileException::getFilepath() const {
    return mFilepath;
}

std::string myxmlpp::FileException::what() {
    return this->baseWhat()
        + std::string("error while interacting with file ")
        + mFilepath
        +details();
}