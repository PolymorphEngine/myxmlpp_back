/*
** EPITECH PROJECT, 2022
** Node_attribute.cpp
** File description:
** Node_attribute.cpp
*/

#include <memory>

#include "Node.hpp"
#include "AttributeNotFoundException.hpp"

std::shared_ptr<myxmlpp::Attribute> myxmlpp::Node::findAttribute(const std::string& key) {
    for (auto & mAttribute : _attributes) {
        if (mAttribute->getKey() == key)
            return mAttribute;
    }
    throw myxmlpp::AttributeNotFoundException(key, MYXMLPP_ERROR_LOCATION);
}

void myxmlpp::Node::addAttribute(const std::string& key,
                                 const std::string& value) {
    auto toAdd = std::make_shared<Attribute>(key, value);

    _attributes.push_back(toAdd);
}

void myxmlpp::Node::addAttribute(std::shared_ptr<Attribute> attr) {
    _attributes.push_back(attr);
}

void myxmlpp::Node::rmAttribute(const std::string& key) {
    popAttribute(key).reset();
}

std::shared_ptr<myxmlpp::Attribute> myxmlpp::Node::popAttribute(const std::string& key) {
    std::shared_ptr<Attribute> found;
    for (auto it = _attributes.begin();
         it != _attributes.end(); ++it) {
        if ((*it)->getKey() == key) {
            found = *it;
            _attributes.erase(it);
            return found;
        }
    }
    throw myxmlpp::AttributeNotFoundException(key, MYXMLPP_ERROR_LOCATION);
}

unsigned int myxmlpp::Node::getNbAttributes() const {
    return _attributes.size();
}

unsigned int myxmlpp::Node::getNbAttributesR() const {
    size_t total = _attributes.size();

    for (auto it = _children.begin(); it != _children.end(); ++it)
        total += (*it)->getNbAttributesR();
    return total;
}

bool myxmlpp::Node::noAttributes() const {
    return _attributes.empty();
}