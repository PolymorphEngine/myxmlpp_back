/*
** EPITECH PROJECT, 2022
** Node_rmChildrenByPath.cpp
** File description:
** Node_rmChildrenByPath.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::rmChildrenByPath(const std::string &path,
                                     const std::string &tag,
                                     char delimiter) {
    auto children = popChildrenByPath(path, tag, delimiter);

    for (auto it = children.begin(); it != children.end(); ++it)
        delete *it;
}


void myxmlpp::Node::rmChildrenBySPath(const std::string &path,
                                      char delimiter) {
    auto children = popChildrenBySPath(path, delimiter);

    for (auto it = children.begin(); it != children.end(); ++it)
        delete *it;
}