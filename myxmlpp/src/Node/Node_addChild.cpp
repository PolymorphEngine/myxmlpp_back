/*
** EPITECH PROJECT, 2022
** Node_addChild.cpp
** File description:
** Node_addChild.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::addChild(myxmlpp::Node *child) {
    _children.push_back(child);
}

void myxmlpp::Node::addChildren(const std::vector<Node *> &children) {
    _children.insert(_children.end(), children.begin(), children.end());
}

void myxmlpp::Node::addChildByPath(Node *child, const std::string &path,
                                   char delimiter) {
    Node *parent = findChildBySPath(path, delimiter);

    parent->addChild(child);
}

void myxmlpp::Node::addChildrenByPath(const std::vector<Node *> &children,
                                      const std::string &path, char delimiter) {
    Node *parent = findChildBySPath(path, delimiter);

    parent->addChildren(children);
}