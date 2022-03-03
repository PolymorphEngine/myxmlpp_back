/*
** EPITECH PROJECT, 2022
** Node_popChildrenR.cpp
** File description:
** Node_popChildrenR.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::_popChildrenRecurs(Node *current,
                                       std::vector<myxmlpp::Node *> &children,
                                       const std::string &tag,
                                       unsigned int depth) {
    if (depth == 0)
        return;

    auto toPopList = current->_findChildrenIt(tag);

    for (auto it = toPopList.begin(); it != toPopList.end(); ++it) {
        children.push_back(**it);
        current->_children.erase(*it);
    }
    for (auto it = current->_children.begin();
         it != current->_children.end(); ++it)
        _popChildrenRecurs(current, children, tag, depth - 1);
}

std::vector<myxmlpp::Node *> myxmlpp::Node::popChildrenR(const std::string &tag,
                                                         int maxDepth) {
    std::vector<myxmlpp::Node *> popped;

    _popChildrenRecurs(this, popped, tag, maxDepth);
    return popped;
}