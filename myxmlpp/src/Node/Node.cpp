/*
** EPITECH PROJECT, 2021
** Node.cpp.cc
** File description:
** Node.cpp.cc
*/


#include "exceptions/AttributeNotFoundException.hpp"
#include "exceptions/ParsingException.hpp"
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

myxmlpp::Node::Node(myxmlpp::Node *parent, std::string &str, std::string &remaining) : _parent(parent) {
    parseNodeString(str, remaining);
}

myxmlpp::Node::Node(myxmlpp::Node *parent, std::string &str) : _parent(parent) {
    std::string remaining = str;
    
    parseNodeString(str, remaining);
    if (!remaining.empty())
        throw myxmlpp::ParsingException(remaining, MYXMLPP_ERROR_LOCATION, "bullshit in file");
}