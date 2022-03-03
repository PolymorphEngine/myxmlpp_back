/*
** EPITECH PROJECT, 2022
** Node_rmChildrenR.cpp
** File description:
** Node_rmChildrenR.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::rmChildrenR(const std::string &tag,
                                int maxDepth) {
    auto children = popChildrenR(tag, maxDepth);

    for (auto it = children.begin(); it != children.end(); ++it)
        delete *it;
}