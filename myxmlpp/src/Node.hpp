/*
** EPITECH PROJECT, 2020
** Node.hpp.h
** File description:
** header for Node.c
*/

#ifndef MYXMLPP_NODE_HPP
#define MYXMLPP_NODE_HPP

#include <string>
#include <vector>
#include <Attribute.hpp>

namespace myxmlpp {
    /**
     * Core class that represent a XML node with tag, attributes, children...
     */
    class Node {
        private:
            /**
             * Tag of the XML node
             */
            std::string mTag;

            /**
             * Everything inside the node if it is not a child node
             */
            std::string mData;

            /**
             * A reference to the parent node
             */
            Node *mParent;

            /**
             * List of attributes present in the node
             */
            std::vector<Attribute *> mAttributes;

            /**
             * List of child nodes
             */
            std::vector<Node *> mChildren;

            static Node *findChildRecursiveLoopCall(Node *current,
                                                    const std::string &tag,
                                                    int depth);

            /**
             * Method that will be recursively called to find child for
             * findChildR public method. This method will return the first
             * matched node
             * @param current the node to search in
             * @param tag the tag of the node to find
             * @param depth the actual depth
             * @return the found node
             */
            static Node *findChildRecursiveCalled(Node *current,
                                                   const std::string &tag,
                                                   int depth);
            static std::vector<std::string> split(const std::string &str,
                                                  char delim);

            static Node *searchChild(Node *current,
                                     const std::vector<std::string>& tab,
                                     std::vector<std::string>::iterator it);

        public:
            std::string getTag() const;

            std::string getData() const;

            Node *getParent();

            void setTag(const std::string& tag);

            void setData(const std::string& data);

            void setParent(Node *parent);

            /**
             * Method to find an attribute by its name.
             * @param key key of the searched attribute
             * @return the found attribute
             */
            Attribute *findAttribute(const std::string& key);

            /**
             * Method to add an attribute to a node by passing a pointer
             * @param attr pointer to the created attribute
             */
            void addAttribute(Attribute *attr);

            /**
             * Method to add an attribute to a node,
             * this will dynamically allocate an attribute
             * @param key
             * @param value
             */
            void addAttribute(const std::string& key, const std::string& value);

            /**
             * Remove from the attributes list and delete the attribute object
             * @param key key of the attribute to delete
             */
            void rmAttribute(const std::string& key);

            /**
             * Only remove the object from the attributes list
             * @param key tag of the attribute to pop
             */
            Attribute *popAttribute(const std::string& key);

            /**
             * Method to find a child node by its tag (return the first
             * matched). This method will return the first matched node
             * @param tag tag of the child to find
             * @return A pointer to the matched node
             */
            Node *findChild(const std::string& tag);

            /**
             * Method to find a child node by searching recursively,
             * a max depth can be set. This method will return the first
             * matched node
             * @param tag tag of the node to find
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return A pointer to the matched node
             */
            Node *findChildR(const std::string& tag, int maxDepth=-1);

            /**
             * Method to find a child node by a given path. The path is name
             * tags separated by a slash. This method will return the first
             * matched node
             * @param path the path relative to the current node
             * @param tag tag of the node to find
             * @return A pointer to the matched node
             */
            Node *findChildByPath(const std::string& path,
                                  const std::string& tag,
                                  char separator='/');

            /**
             * Method to find all children which have the provided tag
             * @param tag tag of the nodes to find
             * @return tag list of all found nodes
             */
            std::vector<Node *> findChildren(const std::string& tag);

            /**
             * Method to find all children nodes with the same tag by searching
             * recursively, a max depth can be set
             * @param tag tag of the nodes to find
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return A pointer to the matched node
             */
            std::vector<Node *> findChildrenR(const std::string& tag,
                                              int maxDepth=-1);

            /**
             * Method to find all children nodes by a given path. The path is
             * name tags separated by a slash by default if there no specified
             * separator
             * @param path the path relative to the current node
             * @param tag tag of the node to find
             * @return A pointer to the matched node
             */
            std::vector<Node *> findChildrenByPath(const std::string& path,
                                                   const std::string& tag,
                                                   char separator='/');

            /**
             * Remove from the children list and delete the matching node
             * object. This method will remove the first matched node
             * @param tag tag of the node to remove
             */
            void rmChild(const std::string& tag);

            /**
             * Method to remove a node by searching recursively, a max depth
             * can be set. This method will remove the first matched node
             * @param tag tag of the node to remove
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             */
            void rmChildR(const std::string& tag, int maxDepth=-1);

            /**
             * Remove a node from the children list of a child node.
             * The path is name tags separated by a slash. This method will
             * remove the first matched node.
             * This method is equivalent to findChildByPath and then rmChild
             * @param path the path relative to the current node
             * @param tag tag of the node to remove
             */
            void rmChildByPath(const std::string& path,
                               const std::string& tag);

            /**
             * Method to remove all children which have the provided tag
             * @param tag tag of the nodes to remove
             */
            void rmChildren(const std::string& tag);

            /**
             * Method to remove all children nodes with the same tag by
             * searching recursively, a max depth can be set
             * @param tag tag of the nodes to remove
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             */
            void rmChildrenR(const std::string& tag, int maxDepth=-1);

            /**
             * Method to find remove children nodes by a given path. The path
             * is name tags separated by a slash
             * @param path the path relative to the current node
             * @param tag tag of the node to remove
             */
            void rmChildrenByPath(const std::string& path,
                                  const std::string& tag);

            /**
            * Method to only remove the object from the children list.
            * This method will pop the first matched node.
            * @param key tag of the node to pop
            * @return the popped node
            */
            Node *popChild(const std::string& tag);

            /**
             * Method to pop a node by searching recursively, a max depth
             * can be set. This method will pop the first matched node.
             * @param tag tag of the node to remove
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return the popped node
             */
            Node *popChildR(const std::string& tag, int maxDepth=-1);

            /**
             * Pop a node from the children list of a child node.
             * The path is name tags separated by a slash. This method will
             * pop the first matched node. This method is equivalent to
             * findChildByPath and then popChild.
             * @param path the path relative to the current node
             * @param tag tag of the node to pop
             * @return the popped node
             */
            Node *popChildByPath(const std::string& path,
                                 const std::string& tag);

            /**
             * Method to pop all children which have the provided tag
             * @param tag tag of the nodes to pop
             * @return a list of the popped nodes
             */
            std::vector<Node *> popChildren(const std::string& tag);

            /**
             * Method to pop all children nodes with the same tag by
             * searching recursively, a max depth can be set
             * @param tag tag of the nodes to pop
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return a list of the popped nodes
             */
            std::vector<Node *> popChildrenR(const std::string& tag,
                                             int maxDepth=-1);

            /**
             * Method to find pop children nodes by a given path. The path
             * is name tags separated by a slash
             * @param path the path relative to the current node
             * @param tag tag of the node to pop
             * @return a list of the popped nodes
             */
            std::vector<Node *> popChildrenByPath(const std::string& path,
                                                  const std::string& tag);

            /**
             * Count the number of children of the node, only one level
             * @return the number of children of the node
             */
            unsigned int getNbChildren() const;

            /**
             * Count the number of children of the node, at all levels
             * @return the number of children of the node and all sub nodes
             */
            unsigned int getNbChildrenR() const;

            /**
             * Count the number of attributes of the node, only one level
             * @return the number of attributes of the node
             */
            unsigned int getNbAttributes() const;

            /**
             * Count the number of attributes of the node, at all levels
             * @return the number of attributes of the node and all sub nodes
             */
            unsigned int getNbAttributesR() const;

            /**
             * Check if the node has children
             * @return true if there is no child
             */
            bool empty() const;

            /**
             * Check if the node has attributes
             * @return true if there is no attributes
             */
            bool noAttributes() const;

            /**
             * Combination of empty and noAttributes method
             * @return true if there is no child and no attribute
             */
            bool fullEmpty() const;
    };
}

#endif //MYXMLPP_NODE_HPP
