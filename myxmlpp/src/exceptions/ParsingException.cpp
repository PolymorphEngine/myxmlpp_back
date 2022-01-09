/*
** EPITECH PROJECT, 2021
** ParsingException.cpp
** File description:
** ParsingException.cpp
*/


#include "ParsingException.hpp"

myxmlpp::ParsingException::ParsingException(
        const std::string& content,
        const std::string& file,
        int line,
        const std::string& description)
        :mContent(content), Exception(file, line, description)
{}

std::string myxmlpp::ParsingException::what() {
    return baseWhat()
           + std::string("tag not closed ")
           + mContent
           + details();
}