/*
** EPITECH PROJECT, 2022
** Node_findChildR.cpp
** File description:
** Node_findChildR.cpp
*/

#include "Node.hpp"
#include "NodeNotFoundException.hpp"

std::shared_ptr<myxmlpp::Node> myxmlpp::Node::_findChildRecursiveLoopCall(Node *current,
                                                          const std::string &tag,
                                                          int depth) {
    for (auto & it : current->_children) {
        try {
            return _findChildRecursiveCalled(it.get(), tag, depth - 1);
        } catch (NodeNotFoundException &e2) {}
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

std::shared_ptr<myxmlpp::Node> myxmlpp::Node::_findChildRecursiveCalled(
                                                        Node *current,
                                                        const std::string &tag,
                                                        int depth) {
    try {
        return current->findChild(tag);
    } catch (NodeNotFoundException& e) {
        if (depth != 0)
            return _findChildRecursiveCalled(current, tag, depth);
        throw;
    }
}

std::shared_ptr<myxmlpp::Node> myxmlpp::Node::findChildR(const std::string &tag,
                                         int maxDepth) {
    return _findChildRecursiveLoopCall(this, tag, maxDepth);
}