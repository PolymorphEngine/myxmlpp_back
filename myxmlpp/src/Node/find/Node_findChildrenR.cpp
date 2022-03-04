/*
** EPITECH PROJECT, 2022
** Node_findChildrenR.cpp
** File description:
** Node_findChildrenR.cpp
*/

#include "Node.hpp"
#include "NodeNotFoundException.hpp"

void myxmlpp::Node::_findChildrenRecursiveLoopCall(Node *current,
                                                   std::vector<std::shared_ptr<Node>> *children,
                                                   const std::string &tag,
                                                   int depth) {
    for (auto & it : current->_children) {
        try {
            _findChildrenRecursiveCalled(it.get(), children, tag, depth - 1);
        } catch (NodeNotFoundException &e2) {}
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

void myxmlpp::Node::_findChildrenRecursiveCalled(Node *current,
                                                 std::vector<std::shared_ptr<Node>> *children,
                                                 const std::string &tag,
                                                 int depth) {
    try {
        current->findChildren(tag, children);
    } catch (NodeNotFoundException& e) {
        if (depth != 0)
            _findChildrenRecursiveCalled(current, children, tag, depth);
        throw;
    }
}

std::vector<std::shared_ptr<myxmlpp::Node>> myxmlpp::Node::findChildrenR(
        const std::string &tag,
        int maxDepth) {
    std::vector<std::shared_ptr<Node>> children;

    _findChildrenRecursiveLoopCall(this, &children, tag, maxDepth);
    return children;
}