/*
** EPITECH PROJECT, 2021
** Node.cpp.cc
** File description:
** Node.cpp.cc
*/


#include <AttributeNotFoundException.hpp>
#include "Node.hpp"

std::string myxmlpp::Node::getTag() const {
    return mTag;
}

std::string myxmlpp::Node::getData() const {
    return mData;
}

myxmlpp::Node *myxmlpp::Node::getParent() {
    return mParent;
}

void myxmlpp::Node::setTag(const std::string &tag) {
    mTag = tag;
}

void myxmlpp::Node::setData(const std::string &data) {
    mData = data;
}

void myxmlpp::Node::setParent(myxmlpp::Node *parent) {
    mParent = parent;
}

myxmlpp::Attribute *myxmlpp::Node::findAttribute(const std::string& key) {
    for (std::vector<myxmlpp::Attribute *>::iterator it = mAttributes.begin();
    it != mAttributes.end(); ++it) {
        if ((*it)->getKey() == key)
            return *it;
    }
    throw myxmlpp::AttributeNotFoundException(key, MYXMLPP_ERROR_LOCATION);
}

void myxmlpp::Node::addAttribute(const std::string& key, const std::string& value) {
    Attribute *toAdd = new Attribute(key, value);

    mAttributes.push_back(toAdd);
}

void myxmlpp::Node::addAttribute(Attribute *attr) {
    mAttributes.push_back(attr);
}

void myxmlpp::Node::rmAttribute(const std::string& key) {
    delete popAttribute(key);
}

myxmlpp::Attribute *myxmlpp::Node::popAttribute(const std::string& key) {
    Attribute *found = NULL;
    for (std::vector<myxmlpp::Attribute *>::iterator it = mAttributes.begin();
         it != mAttributes.end(); ++it) {
        if ((*it)->getKey() == key) {
            found = *it;
            mAttributes.erase(it);
            return found;
        }
    }
    throw myxmlpp::AttributeNotFoundException(key, MYXMLPP_ERROR_LOCATION);
}

