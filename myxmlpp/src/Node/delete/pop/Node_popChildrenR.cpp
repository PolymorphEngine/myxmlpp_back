/*
** EPITECH PROJECT, 2022
** Node_popChildrenR.cpp
** File description:
** Node_popChildrenR.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::_popChildrenRecurs(std::vector<std::shared_ptr<Node>> &children,
                                       const std::string &tag,
                                       int depth) {
    if (depth == 0)
        return;
    auto toPopList = _findChildrenIt(tag);

    for (auto it = toPopList.begin(); it != toPopList.end(); ++it) {
        children.push_back(**it);
        _children.erase(*it);
    }
    for (auto it = _children.begin();
         it != _children.end(); ++it)
        (*it)->_popChildrenRecurs(children, tag, depth - 1);
}
/*
void myxmlpp::Node::_popChildrenRecursive(std::vector<std::shared_ptr<Node>> *children,
                                           const std::string &tag,
                                           int depth) {
    bool found = false;

    if (!depth)
        throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
    try {
        findChildren(tag, children);
        found = true;
    } catch (NodeNotFoundException& e) {}
    for (const auto& c : _children) {
        try {
            c->_findChildrenRecursive(children, tag, depth - 1);
            found = true;
        } catch (NodeNotFoundException& e) {}
    }
    if (!found)
        throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}
*/
std::vector<std::shared_ptr<myxmlpp::Node>> myxmlpp::Node::popChildrenR(const std::string &tag,
                                                         int maxDepth) {
    std::vector<std::shared_ptr<Node>> popped;

    _popChildrenRecurs(popped, tag, maxDepth);
    return popped;
}