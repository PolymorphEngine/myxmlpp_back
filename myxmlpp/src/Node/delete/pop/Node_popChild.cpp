/*
** EPITECH PROJECT, 2022
** Node_rmChild.cpp
** File description:
** Node_rmChild.cpp
*/

#include "Node.hpp"
#include "NodeNotFoundException.hpp"

myxmlpp::Node *myxmlpp::Node::popChild(const std::string &tag) {
    myxmlpp::Node *found = NULL;

    for (auto it = _children.begin(); it != _children.end(); ++it) {
        if ((*it)->getTag() == tag) {
            found = *it;
            _children.erase(it);
            return found;
        }
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}