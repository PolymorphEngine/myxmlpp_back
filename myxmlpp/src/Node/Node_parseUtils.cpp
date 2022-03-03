/*
** EPITECH PROJECT, 2022
** Node_parseUtils.cpp
** File description:
** Node_parseUtils.cpp
*/

#include <regex>
#include "Node.hpp"
#include "ParsingException.hpp"

bool myxmlpp::Node::_isEndOfNode(const std::string &str) {
    std::regex rgx("[\r\n\t\f\v ]*(?:(?:<[a-zA-Z0-9_\\-]*(?:[\r\n\t\f\v ].*\"[\r\n\t\f\v ]*?)*\/?>)|(?:<(\/).*>))");
    std::smatch matches;
    bool res = std::regex_search(str, matches, rgx);

    std::cout << "Matches node end : " << std::endl;
    for (size_t i = 0; i < matches.size(); ++i) {
        std::cout << i << ": '" << matches[i].str() << "'\n";
    }
    if (!res)
        throw ParsingException(str, MYXMLPP_ERROR_LOCATION, "no tag end found");
    else if (matches[1].str().empty())
        return false;
    else
        return true;
}

void myxmlpp::Node::_checkEndOfNode(std::string &str) {
    std::regex rgx("<\/(.*)>");
    std::smatch matches;
    bool res = std::regex_search(str, matches, rgx);

    std::cout << "Matches check node end : " << std::endl;
    for (size_t i = 0; i < matches.size(); ++i) {
        std::cout << i << ": '" << matches[i].str() << "'\n";
    }
    if (!res)
        throw ParsingException(str, MYXMLPP_ERROR_LOCATION, "no tag end found");
    else if (matches[1].str() != _tag)
        throw ParsingException(str, MYXMLPP_ERROR_LOCATION, "no tag end found");
    else
        str = matches.suffix().str();
}