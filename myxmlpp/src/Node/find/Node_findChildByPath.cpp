/*
** EPITECH PROJECT, 2022
** Node_findChildByPath.cpp
** File description:
** Node_findChildByPath.cpp
*/

#include <sstream>
#include "Node.hpp"

std::vector<std::string> myxmlpp::Node::_split(const std::string &str,
                                               char delim) {
    std::vector<std::string> result;
    std::stringstream ss (str);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

myxmlpp::Node *myxmlpp::Node::_searchChild(Node *current,
                                           const std::vector<std::string> &tab,
                                           std::vector<std::string>::iterator it) {
    Node *node = current->findChild(*it);

    if (it != tab.end())
        return _searchChild(node, tab, ++it);
    return node;
}

myxmlpp::Node * myxmlpp::Node::findChildByPath(
        const std::string &path,
        const std::string &tag,
        char delimiter) {
    std::vector<std::string> tab = _split(path, delimiter);
    auto it = tab.begin();

    return _searchChild(this, tab, it);
}

myxmlpp::Node * myxmlpp::Node::findChildBySPath(
        const std::string &path, char delimiter) {
    std::size_t last = path.rfind(delimiter);
    std::string tag = path.substr(last + 1);
    std::string pathCpy(path);

    pathCpy.erase(last);
    return findChildByPath(pathCpy, tag, delimiter);
}