/*
** EPITECH PROJECT, 2022
** Node_popChildR.cpp
** File description:
** Node_popChildR.cpp
*/

#include "Node.hpp"
#include "NodeNotFoundException.hpp"

std::vector<std::shared_ptr<myxmlpp::Node>>::iterator myxmlpp::Node::_findChildIt(
        const std::string& tag) {
    for (auto it = _children.begin(); it != _children.end(); ++it) {
        if ((*it)->getTag() == tag)
            return it;
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

std::shared_ptr<myxmlpp::Node> myxmlpp::Node::_popChildRecursiveLoopCall(Node *current,
                                                         const std::string &tag,
                                                         int depth) {
    for (auto & it : current->_children) {
        try {
            return _popChildRecursiveCalled(it.get(), tag, depth - 1);
        } catch (NodeNotFoundException &e2) {}
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

std::shared_ptr<myxmlpp::Node> myxmlpp::Node::_popChildRecursiveCalled(Node *current,
                                                       const std::string &tag,
                                                       int depth) {
    try {
        auto itToPop = current->_findChildIt(tag);
        std::shared_ptr<Node> toPop = *itToPop;
        current->_children.erase(itToPop);
        return toPop;
    } catch (NodeNotFoundException& e) {
        if (depth > 0) {
            for (auto & it : current->_children)
                return _popChildRecursiveLoopCall(current, tag, depth);
        }
        throw;
    }
}

std::shared_ptr<myxmlpp::Node> myxmlpp::Node::popChildR(const std::string &tag, int maxDepth) {
    return _popChildRecursiveLoopCall(this, tag, maxDepth);
}