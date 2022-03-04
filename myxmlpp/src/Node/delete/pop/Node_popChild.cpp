/*
** EPITECH PROJECT, 2022
** Node_rmChild.cpp
** File description:
** Node_rmChild.cpp
*/

#include "Node.hpp"
#include "NodeNotFoundException.hpp"

std::shared_ptr<myxmlpp::Node>myxmlpp::Node::popChild(const std::string &tag) {
    std::shared_ptr<Node> found;

    for (auto it = _children.begin(); it != _children.end(); ++it) {
        if ((*it)->getTag() == tag) {
            found = *it;
            _children.erase(it);
            return found;
        }
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}