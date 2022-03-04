/*
** EPITECH PROJECT, 2022
** Node_parseUtils.cpp
** File description:
** Node_parseUtils.cpp
*/

#include <regex>
#include "Node.hpp"
#include "ParsingException.hpp"

bool myxmlpp::Node::_isEndOfNode(std::string &str) {
    std::string rgx("[\r\n\t\f\v ]*(?:(?:<[a-zA-Z0-9_\\-]*(?:[\r\n\t\f\v ].*\"[\r\n\t\f\v ]*?)*\/?>)|(?:<(\/).*>))");
    std::smatch matches;
//    bool res = std::regex_search(str, matches, rgx);

//    std::cout << "Matches node end : " << std::endl;
//    for (size_t i = 0; i < matches.size(); ++i) {
//        std::cout << i << ": '" << matches[i].str() << "'\n";
//    }
    if (!performRegex(matches, rgx, str, nullptr))
        throw ParsingException(str, MYXMLPP_ERROR_LOCATION, "no tag end found");
    else if (matches[1].str().empty())
        return false;
    else
        return true;
}

void myxmlpp::Node::_checkEndOfNode(std::string &str, std::string &remaining) {
    std::string rgx("[\r\n\t\f\v ]*<\/(.*)>");
    std::smatch matches;

//    std::cout << "Matches check node end : " << std::endl;
//    for (size_t i = 0; i < matches.size(); ++i) {
//        std::cout << i << ": '" << matches[i].str() << "'\n";
//    }
    
    if (!performRegex(matches, rgx, str, &remaining) || matches[1].str() != _tag)
        throw ParsingException(str, MYXMLPP_ERROR_LOCATION, "no tag end found");
    else
        str = matches.suffix().str();
}

bool myxmlpp::Node::performRegex(std::smatch &matches, std::string &regexStr, 
                         std::string &str, std::string *remaining) {
    std::regex rgx(regexStr);
    std::smatch remainingMatches;
    bool res = std::regex_search(str, matches, rgx);

    if (remaining) {
        if (!std::regex_search(*remaining, remainingMatches, rgx))
            throw myxmlpp::ParsingException(*remaining, MYXMLPP_ERROR_LOCATION,
                                            "Malformated file");
        remaining->replace(remainingMatches.position(),
                           remainingMatches.length(),
                           "");
    }
    return res;
}