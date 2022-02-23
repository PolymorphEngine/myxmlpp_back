/*
** EPITECH PROJECT, 2021
** Doc.cpp
** File description:
** Doc.cpp
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include "Doc.hpp"
#include "exceptions/FileException.hpp"
#include "ParsingException.hpp"


myxmlpp::Doc::Doc(const std::string& filepath, bool keepOpen){
    readFile(filepath, keepOpen);
    auto firstTag = _content.find('<');
    std::string tmpContent = _content;
    
    if (firstTag != std::string::npos){
        tmpContent.erase(firstTag);
        _root = std::unique_ptr<Node>(new Node(nullptr, tmpContent));
    } else 
        throw ParsingException(_content, MYXMLPP_ERROR_LOCATION, 
                               "No node found");
}

void myxmlpp::Doc::readFile(const std::string& filepath, bool keepOpen) {
    _filepath = filepath;
    _file = std::fstream(filepath.c_str(), 
                         keepOpen ? std::ios::in | std::ios::out : std::ios::in);
    std::stringstream strStream;

    if (!_file)
        throw myxmlpp::FileException(filepath, MYXMLPP_ERROR_LOCATION,
                                     "Cannot open file");
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