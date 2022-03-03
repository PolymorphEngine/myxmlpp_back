/*
** EPITECH PROJECT, 2022
** NodeGetSet.cpp
** File description:
** NodeGetSet.cpp
*/

#include "Node.hpp"

std::string myxmlpp::Node::getTag() const {
    return _tag;
}

std::string myxmlpp::Node::getData() const {
    return _data;
}

myxmlpp::Node *myxmlpp::Node::getParent() {
    return _parent;
}

void myxmlpp::Node::setTag(const std::string &tag) {
    _tag = tag;
}

void myxmlpp::Node::setData(const std::string &data) {
    _data = data;
}

void myxmlpp::Node::setParent(myxmlpp::Node *parent) {
    _parent = parent;
}

bool myxmlpp::Node::fullEmpty() const {
    return empty() && noAttributes();
}