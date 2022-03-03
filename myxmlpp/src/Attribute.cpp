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
#include <cstring>
#include "Attribute.hpp"
#include "Doc.hpp"
#include "AttributeGlobal.hpp"
#include "ParsingException.hpp"

namespace myxmlpp {

    Attribute::Attribute(const std::string &key,
                         const std::string &value)
        : mKey(key), mValue(value)
    {}

    std::string Attribute::extractAttributeStr(std::string& s) {
        ssize_t shortest = -1;
        ssize_t found = -1;
        std::string out;

        for (size_t i = 0; endOfStr[i] != '\0' ; ++i) {
            found = s.find(endOfStr[i]);
            if (found != std::string::npos &&
            (found < shortest || shortest == -1))
                shortest = found;
        }
        if (shortest == -1)
            throw ParsingException(s, MYXMLPP_ERROR_LOCATION);
        out = s.substr(0, shortest);
        s.erase(0, shortest + 1);
        return out;
    }

    std::vector<std::string> Attribute::splitAttributeStr(std::string s) {
        std::vector<std::string> arr;
        char *elem = std::strtok(const_cast<char *>(s.c_str()), delimiter);

        while (elem) {
            arr.push_back(std::string(elem));
            elem = std::strtok(nullptr, delimiter);
        }
        if (arr.size() != 2)
            throw ParsingException(s,
                                   MYXMLPP_ERROR_LOCATION,
                                   "No '={value}' part");
        return arr;
    }

    Attribute::Attribute(std::string &fileContent) {
        std::string extracted = extractAttributeStr(fileContent);
        std::vector<std::string> parts = splitAttributeStr(extracted);
        std::string value = parts[1];

        if (value[0] != '"' || value[value.length() - 1] != '"')
            throw ParsingException(value,
                                   MYXMLPP_ERROR_LOCATION,
                                   "Attribute value not wrapped in quotes");
        this->mKey = std::string(parts[0]);
        this->mValue = std::string(value.substr(1, value.length() - 1));
    }

    std::string Attribute::getKey() const {
        return mKey;
    }

    void Attribute::setKey(const std::string &value) {
        mKey = value;
    }

    std::string Attribute::getValue() const {
        return mValue;
    }

    int Attribute::getValueInt() const {
        char *rest;
        int toReturn = (int) strtol(mValue.c_str(), &rest, 10);

        if (*rest)
            throw IllegalValueException("Int", mKey,
                                                 MYXMLPP_ERROR_LOCATION,
                                                 mValue);
        return toReturn;
    }

    float Attribute::getValueFloat() const {
        char *rest;
        float toReturn = strtof(mValue.c_str(), &rest);

        if (*rest)
            throw IllegalValueException("Float", mKey,
                                         MYXMLPP_ERROR_LOCATION,
                                        mValue);
        return toReturn;
    }

    bool Attribute::getValueBool(const std::string &trueElement,
                                 const std::string &falseElement) const {
        if (mValue == trueElement)
            return true;
        else if (mValue == falseElement)
            return false;
        else
            throw IllegalValueException("Float", mKey,
                                         MYXMLPP_ERROR_LOCATION,
                                         mValue);
    }

    Doc Attribute::getValueXmlDoc() const {
        Doc test(mValue);
        return test;
    }

    std::ios_base::openmode Attribute::getValueFileOpenMode(
            openMode_t mode) {
        switch (mode) {
            case OPENRD:
                return std::fstream::in;
            case OPENWR:
                return std::fstream::out;
            case OPENRDWR:
                return std::fstream::in | std::fstream::out;
            case OPENAPP:
                return std::fstream::in | std::fstream::out;
            default:
                return std::fstream::in | std::fstream::out;
        }
    }

    std::fstream *Attribute::getValueFile(openMode_t mode) const {
        std::ios_base::openmode openMode = getValueFileOpenMode(mode);

        try {
            return new std::fstream(mValue.c_str(), openMode);
        } catch (std::ios_base::failure &e) {
            throw FileException(mValue, MYXMLPP_ERROR_LOCATION);
        }

    }

    void Attribute::setValue(const std::string &value) {
        mValue = value;
    }

    void Attribute::setValueInt(int value) {
        std::stringstream ss;
        ss << value;
        mValue = ss.str();
    }

    void Attribute::setValueFloat(float value) {
        std::stringstream ss;
        ss << value;
        mValue = ss.str();
    }

    void Attribute::setValueBool(bool value,
                                 const std::string &trueElement,
                                 const std::string &falseElement) {
        setValue(value ? trueElement : falseElement);
    }
}