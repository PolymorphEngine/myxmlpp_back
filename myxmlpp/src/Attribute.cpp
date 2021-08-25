/*
** EPITECH PROJECT, 2021
** attribute.cpp.cc
** File description:
** attribute.cpp.cc
*/

#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <IllegalValueException.hpp>
#include <FileException.hpp>
#include "Attribute.hpp"

myxmlpp::Attribute::Attribute(const std::string& key, const std::string& value)
    :mKey(key), mValue(value)
{}

myxmlpp::Attribute::Attribute(const std::string& fileContent) {

}

std::string myxmlpp::Attribute::getKey() const {
    return mKey;
}

void myxmlpp::Attribute::setKey(const std::string& value) {
    mKey = value;
}

std::string myxmlpp::Attribute::getValue() const {
    return mValue;
}

int myxmlpp::Attribute::getValueInt() const {
    char *rest;
    int toReturn = (int)strtol(mValue.c_str(), &rest, 10);

    if (*rest)
        throw myxmlpp::IllegalValueException("Int", mKey,
             MYXMLPP_ERROR_LOCATION, mValue);
    return toReturn;
}

float myxmlpp::Attribute::getValueFloat() const {
    char *rest;
    float toReturn = strtof(mValue.c_str(), &rest);

    if (*rest)
        throw myxmlpp::IllegalValueException("Float", mKey,
                                             MYXMLPP_ERROR_LOCATION, mValue);
    return toReturn;
}

bool myxmlpp::Attribute::getValueBool(const std::string &trueElement,
                                      const std::string &falseElement) const {
    if (mValue == trueElement)
        return true;
    else if (mValue == falseElement)
        return false;
    else
        throw myxmlpp::IllegalValueException("Float", mKey,
        MYXMLPP_ERROR_LOCATION, mValue);
}

myxmlpp::Doc myxmlpp::Attribute::getValueXmlDoc() const {
    myxmlpp::Doc test(mValue);
    return test;
}

std::ios_base::openmode myxmlpp::Attribute::getValueFileOpenMode(
        openMode_t mode) {
    switch (mode) {
        case myxmlpp::OPENRD:
            return std::fstream::in;
        case myxmlpp::OPENWR:
            return std::fstream::out;
        case myxmlpp::OPENRDWR:
            return std::fstream::in | std::fstream::out;
        case myxmlpp::OPENAPP:
            return std::fstream::in | std::fstream::out;
        default:
            return std::fstream::in | std::fstream::out;
    }
}

std::fstream *myxmlpp::Attribute::getValueFile(openMode_t mode) const {
    std::ios_base::openmode openMode = getValueFileOpenMode(mode);
    
    try {
        return new std::fstream(mValue.c_str(), openMode);
    } catch (std::ios_base::failure &e) {
        throw myxmlpp::FileException(mValue, MYXMLPP_ERROR_LOCATION);
    }

}

void myxmlpp::Attribute::setValue(const std::string& value) {
    mValue = value;
}

void myxmlpp::Attribute::setValueInt(int value) {
    std::stringstream ss;
    ss << value;
    mValue = ss.str();
}

void myxmlpp::Attribute::setValueFloat(float value) {
    std::stringstream ss;
    ss << value;
    mValue = ss.str();
}

void myxmlpp::Attribute::setValueBool(bool value,
        const std::string& trueElement, const std::string& falseElement) {
    setValue(value ? trueElement : falseElement);
}