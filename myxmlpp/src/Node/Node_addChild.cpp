/*
** EPITECH PROJECT, 2022
** Node_addChild.cpp
** File description:
** Node_addChild.cpp
*/

#include <utility>

#include "Node.hpp"

void myxmlpp::Node::addChild(const std::shared_ptr<Node>& child) {
    _children.push_back(child);
}

void myxmlpp::Node::addChildren(const std::vector<std::shared_ptr<Node>> &children) {
    _children.insert(_children.end(), children.begin(), children.end());
}

void myxmlpp::Node::addChildByPath(std::shared_ptr<Node> child, const std::string &path,
                                   char delimiter) {
    std::shared_ptr<Node> parent = findChildBySPath(path, delimiter);

    parent->addChild(child);
}

void myxmlpp::Node::addChildrenByPath(const std::vector<std::shared_ptr<Node>> &children,
                                      const std::string &path, char delimiter) {
    std::shared_ptr<Node> parent = findChildBySPath(path, delimiter);

    parent->addChildren(children);
}