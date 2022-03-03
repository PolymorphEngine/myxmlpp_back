/*
** EPITECH PROJECT, 2022
** Node_rmChildren.cpp
** File description:
** Node_rmChildren.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::rmChildren(const std::string &tag) {
    auto children = popChildren(tag);

    for (auto it = children.begin(); it != children.end(); ++it)
        delete *it;
}