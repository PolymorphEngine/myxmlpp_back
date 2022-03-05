/*
** EPITECH PROJECT, 2021
** Doc.cpp
** File description:
** Doc.cpp
*/


#include <filesystem>
#include <iostream>
#include "Doc.hpp"
#include "exceptions/FileException.hpp"
#include "ParsingException.hpp"
#include "NoFileException.hpp"
#include "PermissionDeniedException.hpp"

namespace fs = std::filesystem;
using fs::status;

myxmlpp::Doc::Doc(const std::string& filepath, bool keepOpen){
    readFile(filepath, keepOpen);
    _root = std::unique_ptr<Node>(new Node(nullptr, _content));
}

void myxmlpp::Doc::readFile(const std::string& filepath, bool keepOpen) {
    _filepath = filepath;
    std::stringstream strStream;
    _file.exceptions(std::ios::badbit | std::ios::failbit);
    
    try {
        _file.open(filepath.c_str(),
                   keepOpen ? std::ios::in | std::ios::out : std::ios::in);
    } catch (const std::ios_base::failure& e) {
        if (!fs::exists(filepath))
            throw NoFileException(filepath, MYXMLPP_ERROR_LOCATION);
        else if ((keepOpen && ((status(filepath).permissions() & (fs::perms::others_read | fs::perms::others_write)) != (fs::perms::others_read | fs::perms::others_write)))
                || (!keepOpen && ((status(filepath).permissions() & fs::perms::others_read) == fs::perms::none)))
            throw PermissionDeniedException(filepath, MYXMLPP_ERROR_LOCATION);
        throw myxmlpp::FileException(filepath, MYXMLPP_ERROR_LOCATION,
                                     "Cannot open file");
    }        
    strStream << _file.rdbuf();
    _content = strStream.str();
    if (!keepOpen)
        _file.close();
}

const std::string &myxmlpp::Doc::getFilepath() const {
    return _filepath;
}

void myxmlpp::Doc::setMFilepath(const std::string &m_filepath) {
    _filepath = m_filepath;
}