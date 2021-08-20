/*
** EPITECH PROJECT, 2021
** IllegalValueException.cpp.cc
** File description:
** IllegalValueException.cpp.cc
*/


#include "IllegalValueException.hpp"

myxmlpp::IllegalValueException::IllegalValueException(std::string legalType,
        std::string key,
        std::string file,
        std::string line,
        std::string description)
    :mLegalType(legalType), mKey(key), Exception(file, line, description)
{}

std::string myxmlpp::IllegalValueException::getKey() const {
    return mKey;
}

std::string myxmlpp::IllegalValueException::getLegalType() const {
    return mLegalType;
}

std::string myxmlpp::IllegalValueException::what() {
    return baseWhat()
           + std::string("illegal for attribute ")
           + mKey
           + std::string(", desired type ")
           + mLegalType
           + details();
}
