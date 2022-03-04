/*
** EPITECH PROJECT, 2021
** Node.cpp.cc
** File description:
** Node.cpp.cc
*/


#include "exceptions/AttributeNotFoundException.hpp"
#include "exceptions/NodeNotFoundException.hpp"
#include "exceptions/ParsingException.hpp"
#include <sstream>
#include <regex>
//#include <string.h>
#include "Node.hpp"

myxmlpp::Node::Node(myxmlpp::Node *parent, const std::string &tag,
                    const std::string &data) {

}

myxmlpp::Node::Node(myxmlpp::Node *parent, const std::string &tag,
                    std::vector<Node *> children) {

}

myxmlpp::Node::Node(myxmlpp::Node *parent, const std::string &tag,
                    std::vector<Attribute *> attributes,
                    std::vector<Node *> children) {

}

void myxmlpp::Node::_extractAttributes(std::string &str) {
    std::regex rgx("[\r\n\t\f\v ]*([a-zA-Z0-9_]+)=\"([^\"]*)\"");
    std::smatch matches;
    
    while (std::regex_search(str, matches, rgx)) {
        _attributes.push_back(
                std::unique_ptr<Attribute>(new Attribute(matches[1], matches[2]))
        );
        str = matches.suffix().str();
    }
}

myxmlpp::Node::Node(myxmlpp::Node *parent, std::string &str, std::string &remaining) : _parent(parent) {
    std::string rgx("[\r\n\t\f\v ]*(<([a-zA-Z0-9_\\-]*)(?:[\r\n\t\f\v ](.*\")[\r\n\t\f\v ]*?)*(\/?)>)");
    std::smatch matches;

    if (!performRegex(matches, rgx, str, &remaining))
        throw myxmlpp::ParsingException(remaining, MYXMLPP_ERROR_LOCATION, "No tag found");
//        std::cout << "Match found\n";

//        for (size_t i = 0; i < matches.size(); ++i) {
//            std::cout << i << ": '" << matches[i].str() << "'\n";
//        }
    _tag = matches[2].str();
    if (!matches[3].str().empty()) {
        std::string attributes = matches[3].str();
        _extractAttributes(attributes);
    }
    str = matches.suffix().str();
    if (matches[4].str().empty()) {
        while (!_isEndOfNode(str)) {
            addChild(std::shared_ptr<Node>(new Node(this, str, remaining)));
        }
        _checkEndOfNode(str, remaining);
    }
}

myxmlpp::Node::Node(myxmlpp::Node *parent, std::string &str) : _parent(parent) {
    std::string rgx("[\r\n\t\f\v ]*(<([a-zA-Z0-9_\\-]*)(?:[\r\n\t\f\v ](.*\")[\r\n\t\f\v ]*?)*(\/?)>)");
    std::string remaining = str;
    std::smatch matches;
    
    if (!performRegex(matches, rgx, str, &remaining))
        throw myxmlpp::ParsingException(remaining, MYXMLPP_ERROR_LOCATION, "No tag found");

//        std::cout << "Match found\n";

//        for (size_t i = 0; i < matches.size(); ++i) {
//            std::cout << i << ": '" << matches[i].str() << "'\n";
//        }
    _tag = matches[2].str();
    if (!matches[3].str().empty()) {
        std::string attributes = matches[3].str();
        _extractAttributes(attributes);
    }
    str = matches.suffix().str();
    if (matches[4].str().empty()) {
        while (!_isEndOfNode(str)) {
            addChild(std::shared_ptr<Node>(new Node(this, str, remaining)));
        }
        _checkEndOfNode(str, remaining);
    }
    if (!remaining.empty())
        throw myxmlpp::ParsingException(remaining, MYXMLPP_ERROR_LOCATION, "bullshit in file");
}