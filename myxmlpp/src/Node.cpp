/*
** EPITECH PROJECT, 2021
** Node.cpp.cc
** File description:
** Node.cpp.cc
*/


#include <AttributeNotFoundException.hpp>
#include <NodeNotFoundException.hpp>
#include <sstream>
#include <string.h>
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
    for (auto & mAttribute : mAttributes) {
        if (mAttribute->getKey() == key)
            return mAttribute;
    }
    throw myxmlpp::AttributeNotFoundException(key, MYXMLPP_ERROR_LOCATION);
}

void myxmlpp::Node::addAttribute(const std::string& key,
                                 const std::string& value) {
    auto *toAdd = new Attribute(key, value);

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
    for (auto it = mAttributes.begin();
         it != mAttributes.end(); ++it) {
        if ((*it)->getKey() == key) {
            found = *it;
            mAttributes.erase(it);
            return found;
        }
    }
    throw myxmlpp::AttributeNotFoundException(key, MYXMLPP_ERROR_LOCATION);
}

myxmlpp::Node *myxmlpp::Node::findChild(const std::string& tag) {
    for (auto & it : mChildren) {
        if (it->getTag() == tag)
            return it;
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

/*
 *************************** findChildR methods *******************************
 */
myxmlpp::Node* myxmlpp::Node::findChildRecursiveLoopCall(Node *current,
        const std::string &tag,
        int depth) {
    for (auto & it : current->mChildren) {
        try {
            return findChildRecursiveCalled(it, tag, depth-1);
        } catch (NodeNotFoundException &e2) {}
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

myxmlpp::Node *myxmlpp::Node::findChildRecursiveCalled(Node *current,
                                                       const std::string &tag,
                                                       int depth) {
    try {
        return current->findChild(tag);
    } catch (NodeNotFoundException& e) {
        if (depth != 0)
            return findChildRecursiveCalled(current, tag, depth);
        throw;
    }
}

myxmlpp::Node *myxmlpp::Node::findChildR(const std::string &tag,
                                         int maxDepth) {
    return findChildRecursiveLoopCall(this, tag, maxDepth);
}

/*
 ******************* End of findChildR methods ********************************
 */
/*
 ************************* findChildByPath methods ****************************
 */

std::vector<std::string> myxmlpp::Node::split(const std::string &str,
                                              char delim) {
    std::vector<std::string> result;
    std::stringstream ss (str);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

myxmlpp::Node *myxmlpp::Node::searchChild(Node *current,
        const std::vector<std::string> &tab,
        std::vector<std::string>::iterator it) {
    Node *node = current->findChild(*it);

    if (it != tab.end())
        return searchChild(node, tab, ++it);
    return node;
}

myxmlpp::Node * myxmlpp::Node::findChildByPath(
        const std::string &path,
        const std::string &tag,
        char delimiter) {
    std::vector<std::string> tab = split(path, delimiter);
    auto it = tab.begin();

    return searchChild(this, tab, it);
}

myxmlpp::Node * myxmlpp::Node::findChildBySPath(
        const std::string &path, char delimiter) {
    std::size_t last = path.rfind(delimiter);
    std::string tag = path.substr(last + 1);
    std::string pathCpy(path);

    pathCpy.erase(last);
    return findChildByPath(pathCpy, tag, delimiter);
}

/*
 ************************* End of findChildByPath methods ********************
 */

/*
 ************************* findChildren methods ********************
 */
std::vector<myxmlpp::Node *> myxmlpp::Node::findChildren(
        const std::string &tag) {
    std::vector<myxmlpp::Node *> list;

    for (auto & it : mChildren) {
        if (it->getTag() == tag)
            list.push_back(it);
    }
    if (list.empty())
        throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
    return list;
}

void myxmlpp::Node::findChildren(
        const std::string &tag,
        std::vector<myxmlpp::Node *> *children) {
    std::size_t backupSize = children->size();

    for (auto & it : mChildren) {
        if (it->getTag() == tag)
            children->push_back(it);
    }
    if (children->size() == backupSize)
        throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);

}

/*
 ************************* End of findChildren methods ********************
 */

/*
 ************************* findChildrenR methods ********************
 */

void myxmlpp::Node::findChildrenRecursiveLoopCall(Node *current,
        std::vector<myxmlpp::Node*> *children,
        const std::string &tag,
        int depth) {
    for (auto & it : current->mChildren) {
        try {
            findChildrenRecursiveCalled(it, children, tag, depth-1);
        } catch (NodeNotFoundException &e2) {}
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

void myxmlpp::Node::findChildrenRecursiveCalled(Node *current,
        std::vector<Node *> *children,
        const std::string &tag,
        int depth) {
    try {
        current->findChildren(tag, children);
    } catch (NodeNotFoundException& e) {
        if (depth != 0)
            findChildrenRecursiveCalled(current, children, tag, depth);
        throw;
    }
}

std::vector<myxmlpp::Node *> myxmlpp::Node::findChildrenR(
        const std::string &tag,
        int maxDepth) {
    std::vector<Node *> children;

    findChildrenRecursiveLoopCall(this, &children, tag, maxDepth);
    return children;
}

/*
 ************************* End of findChildrenR methods ********************
 */

/*
 ************************* findChildrenByPath methods ********************
 */

void myxmlpp::Node::searchChildren(Node *current,
        std::vector<myxmlpp::Node *> *children,
        const std::vector<std::string> &tab,
        std::vector<std::string>::iterator it) {
    Node *node = nullptr;

    if (it != tab.end()) {
        node = current->findChild(*it);
        searchChild(node, tab, ++it);
    }

    children->push_back(node);
}

std::vector<myxmlpp::Node *> myxmlpp::Node::findChildrenByPath(
        const std::string &path,
        const std::string &tag,
        char delimiter) {
    std::vector<std::string> tab = split(path, delimiter);
    auto it = tab.begin();
    std::vector<Node *> children;

    searchChildren(this, &children, tab, it);
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
/*
 ************************* End of findChildrenByPath methods ******************
 */

myxmlpp::Node *myxmlpp::Node::popChild(const std::string &tag) {
    myxmlpp::Node *found = NULL;

    for (auto it = mChildren.begin(); it != mChildren.end(); ++it) {
        if ((*it)->getTag() == tag) {
            found = *it;
            mChildren.erase(it);
            return found;
        }
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

void myxmlpp::Node::rmChild(const std::string &tag) {
    delete popChild(tag);
}

/*
 ******************************* popChildR methods ***************************
 */
std::vector<myxmlpp::Node *>::iterator myxmlpp::Node::findChildIt(
        const std::string& tag) {
    for (auto it = mChildren.begin(); it != mChildren.end(); ++it) {
        if ((*it)->getTag() == tag)
            return it;
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}



myxmlpp::Node* myxmlpp::Node::popChildRecursiveLoopCall(Node *current,
        const std::string &tag,
        int depth) {
    for (auto & it : current->mChildren) {
        try {
            return popChildRecursiveCalled(it, tag, depth-1);
        } catch (NodeNotFoundException &e2) {}
    }
    throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
}

myxmlpp::Node *myxmlpp::Node::popChildRecursiveCalled(Node *current,
        const std::string &tag,
        int depth) {
    try {
        auto itToPop = current->findChildIt(tag);
        Node *toPop = *itToPop;
        current->mChildren.erase(itToPop);
        return toPop;
    } catch (NodeNotFoundException& e) {
        if (depth > 0) {
            for (auto & it : current->mChildren)
                return popChildRecursiveLoopCall(current, tag, depth);
        }
        throw;
    }
}

myxmlpp::Node *myxmlpp::Node::popChildR(const std::string &tag, int maxDepth) {
    return popChildRecursiveLoopCall(this, tag, maxDepth);
}
/*
 **************************** End of popChildR methods ************************
 */

void myxmlpp::Node::rmChildR(const std::string &tag, int maxDepth) {
    delete popChildR(tag, maxDepth);
}

myxmlpp::Node *myxmlpp::Node::popChildByPath(const std::string &path,
                                             const std::string &tag,
                                             char delimiter) {
    Node *childParent = findChildBySPath(path, delimiter);
    return childParent->popChild(tag);
}

void myxmlpp::Node::rmChildByPath(const std::string &path,
                                  const std::string &tag,
                                  char delimiter) {
    delete popChildByPath(path, tag, delimiter);
}

myxmlpp::Node *myxmlpp::Node::popChildBySPath(const std::string &path,
                                              char delimiter) {
    std::size_t last = path.rfind(delimiter);
    std::string tag = path.substr(last + 1);
    std::string pathCpy(path);

    pathCpy.erase(last);
    return popChildByPath(pathCpy, tag, delimiter);
}

void myxmlpp::Node::rmChildBySPath(const std::string &path,
                                  char delimiter) {
    delete popChildBySPath(path, delimiter);
}

/*
 ****************************** popChildren methods ***************************
 */
std::vector<std::vector<myxmlpp::Node *>::iterator>
myxmlpp::Node::findChildrenIt(const std::string &tag) {
    std::vector<std::vector<myxmlpp::Node *>::iterator> list;

    for (auto it = mChildren.begin(); it != mChildren.end(); ++it) {
        if ((*it)->getTag() == tag)
            list.push_back(it);
    }
    if (list.empty())
        throw NodeNotFoundException(tag, MYXMLPP_ERROR_LOCATION);
    return list;
}

std::vector<myxmlpp::Node *> myxmlpp::Node::popChildren(
        const std::string& tag) {
    std::vector<std::vector<myxmlpp::Node *>::iterator> toPopList =
            findChildrenIt(tag);
    std::vector<myxmlpp::Node *> toPopNodes;

    for (auto it = toPopList.begin(); it != toPopList.end(); ++it) {
        toPopNodes.push_back(**it);
        mChildren.erase(*it);
    }
    return toPopNodes;
}
/*
 *************************** End of popChildren methods ***********************
 */

void myxmlpp::Node::rmChildren(const std::string &tag) {
    auto children = popChildren(tag);

    for (auto it = children.begin(); it != children.end(); ++it)
        delete *it;
}

/*
 ****************************** popChildrenR methods **************************
 */
void myxmlpp::Node::popChildrenRecurs(Node *current,
                                     std::vector<myxmlpp::Node *> &children,
                                     const std::string &tag,
                                     unsigned int depth) {
    if (depth == 0)
        return;

    auto toPopList = current->findChildrenIt(tag);

    for (auto it = toPopList.begin(); it != toPopList.end(); ++it) {
        children.push_back(**it);
        current->mChildren.erase(*it);
    }
    for (auto it = current->mChildren.begin();
            it != current->mChildren.end(); ++it)
        popChildrenRecurs(current, children, tag, depth - 1);
}

std::vector<myxmlpp::Node *> myxmlpp::Node::popChildrenR(const std::string &tag,
                                                         int maxDepth) {
    std::vector<myxmlpp::Node *> popped;

    popChildrenRecurs(this, popped, tag, maxDepth);
    return popped;
}
/*
 *************************** End of popChildrenR methods ***********************
 */

void myxmlpp::Node::rmChildrenR(const std::string &tag,
                                int maxDepth) {
    auto children = popChildrenR(tag, maxDepth);

    for (auto it = children.begin(); it != children.end(); ++it)
        delete *it;
}

std::vector<myxmlpp::Node *> myxmlpp::Node::popChildrenByPath(
        const std::string &path, const std::string &tag, char delimiter) {
    Node *childrenParent = findChildBySPath(path, delimiter);

    return childrenParent->popChildren(tag);
}

void myxmlpp::Node::rmChildrenByPath(const std::string &path,
                                    const std::string &tag,
                                    char delimiter) {
    auto children = popChildrenByPath(path, tag, delimiter);

    for (auto it = children.begin(); it != children.end(); ++it)
        delete *it;
}

std::vector<myxmlpp::Node *> myxmlpp::Node::popChildrenBySPath(
        const std::string &path, char delimiter) {
    std::size_t last = path.rfind(delimiter);
    std::string tag = path.substr(last + 1);
    std::string pathCpy(path);

    pathCpy.erase(last);
    return popChildrenByPath(pathCpy, tag, delimiter);
}

void myxmlpp::Node::rmChildrenBySPath(const std::string &path,
                                       char delimiter) {
    auto children = popChildrenBySPath(path, delimiter);

    for (auto it = children.begin(); it != children.end(); ++it)
        delete *it;
}


unsigned int myxmlpp::Node::getNbChildren() const {
    return mChildren.size();
}

unsigned int myxmlpp::Node::getNbChildrenR() const {
    size_t total = mChildren.size();

    for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
        total += (*it)->getNbChildrenR();
    return total;
}

unsigned int myxmlpp::Node::getNbAttributes() const {
    return mAttributes.size();
}



unsigned int myxmlpp::Node::getNbAttributesR() const {
    size_t total = mAttributes.size();

    for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
        total += (*it)->getNbAttributesR();
    return total;
}

bool myxmlpp::Node::empty() const {
    return mChildren.empty();
}

bool myxmlpp::Node::noAttributes() const {
    return mAttributes.empty();
}

bool myxmlpp::Node::fullEmpty() const {
    return empty() && noAttributes();
}