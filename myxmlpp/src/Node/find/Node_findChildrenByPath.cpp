/*
** EPITECH PROJECT, 2022
** Node_findChildrenByPath.cpp
** File description:
** Node_findChildrenByPath.cpp
*/

#include "Node.hpp"

void myxmlpp::Node::_searchChildren(Node *current,
                                    std::vector<myxmlpp::Node *> *children,
                                    const std::vector<std::string> &tab,
                                    std::vector<std::string>::iterator it) {
    Node *node = nullptr;

    if (it != tab.end()) {
        node = current->findChild(*it);
        _searchChild(node, tab, ++it);
    }

    children->push_back(node);
}

std::vector<myxmlpp::Node *> myxmlpp::Node::findChildrenByPath(
        const std::string &path,
        const std::string &tag,
        char delimiter) {
    std::vector<std::string> tab = _split(path, delimiter);
    auto it = tab.begin();
    std::vector<Node *> children;

    _searchChildren(this, &children, tab, it);
    return children;
}
std::vector<myxmlpp::Node *> myxmlpp::Node::findChildrenBySPath(
        const std::string &path, char delimiter) {
    std::size_t last = path.rfind(delimiter);
    std::string tag = path.substr(last + 1);
    std::string pathCpy(path);

    pathCpy.erase(last);
    return findChildrenByPath(pathCpy, tag, delimiter);
}