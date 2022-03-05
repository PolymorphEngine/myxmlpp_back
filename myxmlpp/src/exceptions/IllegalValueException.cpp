/*
** EPITECH PROJECT, 2021
** IllegalValueException.cpp.cc
** File description:
** IllegalValueException.cpp.cc
*/


#include "IllegalValueException.hpp"

#include <utility>

myxmlpp::IllegalValueException::IllegalValueException(std::string legalType,
                                                      std::string key,
                                                      std::string file,
                                                      int line,
                                                      std::string description)
                                                      noexcept
    : mLegalType(std::move(legalType)), mKey(std::move(key)), 
    Exception(std::move(file), line, std::move(description))
{
    build();
}

std::string myxmlpp::IllegalValueException::getKey() const {
    return mKey;
}

std::string myxmlpp::IllegalValueException::getLegalType() const {
    return mLegalType;
}

std::string myxmlpp::IllegalValueException::baseWhat() const noexcept{
    return Exception::baseWhat()
           + std::string(": illegal for attribute ")
           + mKey
           + std::string(", desired type ")
           + mLegalType;
}
