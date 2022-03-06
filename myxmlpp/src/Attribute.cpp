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
        : _key(key), _value(value)
    {}

    std::string Attribute::_extractAttributeStr(std::string& s) 
    {
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

    std::vector<std::string> Attribute::_splitAttributeStr(std::string s) {
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

    Attribute::Attribute(std::string &fileContent)
    {
        std::string extracted = _extractAttributeStr(fileContent);
        std::vector<std::string> parts = _splitAttributeStr(extracted);
        std::string value = parts[1];

        if (value[0] != '"' || value[value.length() - 1] != '"')
            throw ParsingException(value,
                                   MYXMLPP_ERROR_LOCATION,
                                   "Attribute value not wrapped in quotes");
        this->_key = std::string(parts[0]);
        this->_value = std::string(value.substr(1, value.length() - 1));
    }

    std::string Attribute::getKey() const {
        return _key;
    }

    void Attribute::setKey(const std::string &value) {
        _key = value;
    }

    std::string Attribute::getValue() const {
        return _value;
    }

    int Attribute::getValueInt() const {
        char *rest;
        int toReturn = (int) strtol(_value.c_str(), &rest, 10);

        if (*rest)
            throw IllegalValueException("Int", _key,
                                        MYXMLPP_ERROR_LOCATION,
                                        _value);
        return toReturn;
    }

    float Attribute::getValueFloat() const {
        char *rest;
        float toReturn = strtof(_value.c_str(), &rest);

        if (*rest)
            throw IllegalValueException("Float", _key,
                                        MYXMLPP_ERROR_LOCATION,
                                        _value);
        return toReturn;
    }

    bool Attribute::getValueBool(const std::string &trueElement,
                                 const std::string &falseElement) const {
        if (_value == trueElement)
            return true;
        else if (_value == falseElement)
            return false;
        else
            throw IllegalValueException("Float", _key,
                                        MYXMLPP_ERROR_LOCATION,
                                        _value);
    }

    Doc Attribute::getValueXmlDoc() const {
        Doc test(_value);
        return test;
    }

    std::ios_base::openmode Attribute::_getValueFileOpenMode(
            openMode_t mode) {
        switch (mode) {
            case OPENRD:
                return std::fstream::in;
            case OPENWR:
                return std::fstream::out;
            case OPENRDWR:
                return std::fstream::in | std::fstream::out;
            case OPENAPP:
                return std::fstream::in | std::fstream::out | std::fstream::app;
            default:
                return std::fstream::in;
        }
    }

    std::fstream Attribute::getValueFile(openMode_t mode) const {
        std::ios_base::openmode openMode = _getValueFileOpenMode(mode);

        try {
            return std::fstream(_value.c_str(), openMode);
        } catch (std::ios_base::failure &e) {
            throw FileException(_value, MYXMLPP_ERROR_LOCATION);
        }

    }

    void Attribute::setValue(const std::string &value) {
        _value = value;
    }

    void Attribute::setValueInt(int value) {
        std::stringstream ss;
        ss << value;
        _value = ss.str();
    }

    void Attribute::setValueFloat(float value) {
        std::stringstream ss;
        ss << value;
        _value = ss.str();
    }

    void Attribute::setValueBool(bool value,
                                 const std::string &trueElement,
                                 const std::string &falseElement) {
        setValue(value ? trueElement : falseElement);
    }
}