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
#include <memory>
#include <regex>

namespace myxmlpp {
    /**
     * Core class that represent a XML node with tag, attributes, children...
     */
    class Node {
        private:
            /**
             * Tag of the XML node
             */
            std::string _tag;

            /**
             * Everything inside the node if it is not a child node
             */
            std::string _data;

            /**
             * A reference to the parent node
             */
            Node *_parent;

            /**
             * List of attributes present in the node
             */
            std::vector<std::shared_ptr<Attribute>> _attributes;

            /**
             * List of child nodes
             */
            std::vector<std::shared_ptr<Node>> _children;

            static std::shared_ptr<Node> _findChildRecursiveLoopCall(Node *current,
                                                     const std::string &tag,
                                                     int depth);

            static std::shared_ptr<Node> _popChildRecursiveLoopCall(
                    Node *current,
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
            static std::shared_ptr<Node> _findChildRecursiveCalled(Node *current,
                                                   const std::string &tag,
                                                   int depth);

            void _findChildrenRecursive(std::vector<std::shared_ptr<Node>> *children,
                                        const std::string &tag,
                                        int depth);


            static std::shared_ptr<Node> _popChildRecursiveCalled(
                    Node *current,
                    const std::string &tag,
                    int depth);

            static std::vector<std::string> _split(const std::string &str,
                                                   char delim);

            static std::shared_ptr<Node> _searchChild(Node *current,
                                      const std::vector<std::string>& tab,
                                      std::vector<std::string>::iterator it);

            static void _searchChildren(Node *current,
                    std::vector<std::shared_ptr<Node>> *children,
                    const std::vector<std::string> &tab,
                    std::vector<std::string>::iterator it);

            std::vector<std::shared_ptr<Node>>::iterator _findChildIt(
                    const std::string &tag);

            std::vector<std::vector<std::shared_ptr<Node>>::iterator>
                    _findChildrenIt(const std::string &tag);

            static void _popChildrenRecurs(Node *current,
                                           std::vector<std::shared_ptr<Node>> &children,
                                           const std::string &tag,
                                           unsigned int depth);
            
            void _extractAttributes(std::string &str);
            
            static bool _isEndOfNode(std::string &str);
            
            void _checkEndOfNode(std::string &str, std::string &remaining);

            /**
             * Private constructor to create a node by parsing a xml file in string format.
             * @param str the source string.
             * @param remaining the remaining characters that could not be parsed
             */
            explicit Node(Node *parent, std::string& str, std::string &remaining);
            
            void _parseNodeString(std::string &str, std::string &remaining);
            
            static bool _performRegex(std::smatch &matches,
                                      std::string &regexStr,
                                      std::string &str,
                                      std::string *remaining = nullptr);

        public:
            /**
             * Method to create a node with its tag.
             * @param parent parent of the node.
             * Can be set to null if the node has not parent
             * @param tag the tag of the node.
             * @return the created node.
             */
            Node(Node *parent);

            /**
             * Method to create a node with its tag and its children.
             * @param parent parent of the node.
             * Can be set to null if the node has not parent
             * @param tag the tag of the node.
             * @param children a vector with the children nodes.
             * @return the created node.
             */
            Node(Node *parent, std::string tag,
                 std::vector<std::shared_ptr<Node>> children);

            /**
             * Method to create a node with its tag, children and attributes.
             * @param parent parent of the node.
             * Can be set to null if the node has not parent
             * @param tag the tag of the node.
             * @param attributes a vector of attributes for the node.
             * @param children a vector of the children nodes.
             * @return the created node.
             */
            Node(Node *parent, const std::string &tag,
                 std::vector<std::shared_ptr<Attribute>> attributes,
                 std::vector<std::shared_ptr<Node>> children = {});

            /**
             * Method to create a node by parsing a xml file in string format.
             * @param str the source string.
             * @return the created node.
             * @throws ParsingException if parsing fails.
             */
            explicit Node(Node *parent, std::string& str);

            /**
             * @return the tag of the XML node
             */
            std::string getTag() const;

            /**
             * @return the data of the xml node 
             */
            std::string getData() const;

            /**
             * @returns a pointer to the XML parent node
             */
            Node *getParent();

            /**
             * A method to change the tag of the XML node
             * @param tag the new tag 
             */
            void setTag(const std::string& tag);

            /**
             * A method to change the data of the XML node
             * @param tag the new data 
             */
            void setData(const std::string& data);

            /**
             * A method to change the parent of the XML node
             * @param tag the new parent 
             */
            void setParent(Node *parent);

            /**
             * Method to find an attribute by its name.
             * @param key key of the searched attribute
             * @return the found attribute
             * @throws AttributeNotFoundException if the attribute is not found
             */
            std::shared_ptr<Attribute> findAttribute(const std::string& key);

            /**
             * Method to add an attribute to a node by passing a pointer
             * @param attr pointer to the created attribute
             */
            void addAttribute(const std::shared_ptr<Attribute>& attr);

            /**
             * Method to add an attribute to a node,
             * this will dynamically allocate an attribute
             * @param key the key of the attribute
             * @param value the value of the attribute
             */
            std::shared_ptr<Attribute> addAttribute(const std::string& key, const std::string& value);

            /**
             * Remove from the attributes list and delete the attribute object
             * @param key key of the attribute to delete
             */
            void rmAttribute(const std::string& key);

            /**
             * Only remove the object from the attributes list
             * @param key key of the attribute to pop
             */
            std::shared_ptr<Attribute> popAttribute(const std::string& key);

            /**
             * Method to find a child node by its tag.
             * This method will return the first matched node
             * @param tag tag of the child to find
             * @return A pointer to the matched node
             */
            std::shared_ptr<Node> findChild(const std::string& tag);

            /**
             * Method to find a child node by searching recursively,
             * a max depth can be set. This method will return the first
             * matched node
             * @param tag tag of the node to find
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return A pointer to the matched node
             */
            std::shared_ptr<Node> findChildR(const std::string& tag, int maxDepth=-1);

            /**
             * Method to find a child node by a given path. The path is name
             * tags separated by a slash. This method will return the first
             * matched node
             * @param path the path relative to the current node
             * @param tag tag of the node to find
             * @param delimiter the separator used in path to delimit nodes
             * @return A pointer to the matched node
             */
            std::shared_ptr<Node> findChildByPath(const std::string& path,
                                                  const std::string& tag,
                                                  char delimiter='/');

            /**
             * Method to find a child node by a given path. The path is name
             * tags separated by a slash. The last tag name if the tag of 
             * the node to find This method will return the first matched node
             * @param path the path relative to the current node
             * @param delimiter the separator used in path to delimit nodes
             * @return A pointer to the matched node
             */
            std::shared_ptr<Node> findChildBySPath(const std::string& path,
                                   char delimiter='/');

            /**
             * Method to find all children which have the provided tag
             * @param tag tag of the nodes to find
             * @return tag list of all found nodes
             */
            std::vector<std::shared_ptr<Node>> findChildren(const std::string& tag);

            /**
             * Method to find all children which have the provided tag. The
             * difference is that this method fills a provided vector instead
             * of returning a created one
             * @param tag tag of the nodes to find
             * @param node list of all found nodes
             */
            void findChildren(const std::string& tag,
                              std::vector<std::shared_ptr<Node>> *children);

            /**
             * Method to find all children nodes with the same tag by searching
             * recursively, a max depth can be set
             * @param tag tag of the nodes to find
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return A pointer to the matched node
             */
            std::vector<std::shared_ptr<Node>> findChildrenR(const std::string& tag,
                                              int maxDepth=-1);

            /**
             * Method to find all children nodes by a given path. The path is
             * name tags separated by a slash by default if there no specified
             * separator
             * @param path the path relative to the current node
             * @param tag tag of the node to find
             * @param delimiter the separator used in path to delimit nodes
             * @return A pointer to the matched node
             */
            std::vector<std::shared_ptr<Node>> findChildrenByPath(
                    const std::string& path,
                    const std::string& tag,
                    char delimiter='/');

            /**
             * Method to find all children nodes by a given path. The path is
             * name tags separated by a slash by default if there no specified
             * separator
             * @param path the path relative to the current node
             * @param delimiter the separator used in path to delimit nodes
             * @return A pointer to the matched node
             */
            std::vector<std::shared_ptr<Node>> findChildrenBySPath(const std::string& path,
                                                    char delimiter='/');

            /**
             * Method to add a Node to the children list
             * @param child the Node to add
             */
            void addChild(const std::shared_ptr<Node>& child);

            /**
             * Method to add children nodes to the children list.
             * @param children a vector of nodes to add
             */
            void addChildren(const std::vector<std::shared_ptr<Node>> &children);

            /**
             * Method to add a child to a node referenced by its given path.
             * The path is name tags separated by a slash by default if there
             * no specified separator
             * @param child a Node pointer to the child to add
             * @param path the path relative to the future parent node
             * @param delimiter the separator used in path to delimit nodes
             */
            void addChildByPath(std::shared_ptr<Node> child, const std::string& path,
                                char delimiter='/');

            /**
             * Method to add children to a node referenced by its given path.
             * The path is name tags separated by a slash by default if there
             * no specified separator
             * @param children a vector of Node pointers to the children to add
             * @param path the path relative to the future parent node
             * @param delimiter the separator used in path to delimit nodes
             */
            void addChildrenByPath(const std::vector<std::shared_ptr<Node>> &children,
                                   const std::string &path,
                                   char delimiter='/');

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
             * @param delimiter the separator used in path to delimit nodes
             */
            void rmChildByPath(const std::string& path,
                               const std::string& tag,
                               char delimiter='/');

            /**
             * Remove a node from the children list of a child node.
             * The path is name tags separated by a slash. This method will
             * remove the first matched node.
             * This method is equivalent to findChildByPath and then rmChild
             * @param path the path relative to the current node
             * @param delimiter the separator used in path to delimit nodes
             */
            void rmChildBySPath(const std::string& path,
                                char delimiter='/');

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
             * @param delimiter the separator used in path to delimit nodes
             */
            void rmChildrenByPath(const std::string& path,
                                  const std::string& tag,
                                  char delimiter='/');

            /**
             * Method to find remove children nodes by a given path. The path
             * is name tags separated by a slash
             * @param path the path relative to the current node
             * @param delimiter the separator used in path to delimit nodes
             */
            void rmChildrenBySPath(const std::string& path,
                                   char delimiter='/');

            /**
            * Method to only remove the object from the children list.
            * This method will pop the first matched node.
            * @param key tag of the node to pop
            * @return the popped node
            */
            std::shared_ptr<Node> popChild(const std::string& tag);

            /**
             * Method to pop a node by searching recursively, a max depth
             * can be set. This method will pop the first matched node.
             * @param tag tag of the node to remove
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return the popped node
             */
            std::shared_ptr<Node> popChildR(const std::string& tag, int maxDepth=-1);

            /**
             * Pop a node from the children list of a child node.
             * The path is name tags separated by a slash. This method will
             * pop the first matched node. This method is equivalent to
             * findChildByPath and then popChild.
             * @param path the path relative to the current node
             * @param tag tag of the node to pop
             * @param delimiter the separator used in path to delimit nodes
             * @return the popped node
             */
            std::shared_ptr<Node> popChildByPath(const std::string& path,
                                 const std::string& tag,
                                 char delimiter='/');

            /**
            * Pop a node from the children list of a child node.
            * The path is name tags separated by a slash. This method will
            * pop the first matched node. This method is equivalent to
            * findChildByPath and then popChild.
            * @param path the path relative to the current node
            * @param delimiter the separator used in path to delimit nodes
            * @return the popped node
            */
            std::shared_ptr<Node> popChildBySPath(const std::string& path,
                                                  char delimiter='/');

            /**
             * Method to pop all children which have the provided tag
             * @param tag tag of the nodes to pop
             * @return a list of the popped nodes
             */
            std::vector<std::shared_ptr<Node>> popChildren(const std::string& tag);

            /**
             * Method to pop all children nodes with the same tag by
             * searching recursively, a max depth can be set
             * @param tag tag of the nodes to pop
             * @param maxDepth [optionnal] max depth to search, no limit is -1
             * @return a list of the popped nodes
             */
            std::vector<std::shared_ptr<Node>> popChildrenR(const std::string& tag,
                                             int maxDepth=-1);

            /**
             * Method to find pop children nodes by a given path. The path
             * is name tags separated by a slash
             * @param path the path relative to the current node
             * @param tag tag of the node to pop
             * @param delimiter the separator used in path to delimit nodes
             * @return a list of the popped nodes
             */
            std::vector<std::shared_ptr<Node>> popChildrenByPath(const std::string& path,
                                                  const std::string& tag,
                                                  char delimiter='/');

            /**
             * Method to find pop children nodes by a given path. The path
             * is name tags separated by a slash
             * @param path the path relative to the current node
             * @param delimiter the separator used in path to delimit nodes
             * @return a list of the popped nodes
             */
            std::vector<std::shared_ptr<Node>> popChildrenBySPath(const std::string& path,
                                                   char delimiter='/');

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

            /**
             * Move the current node as a child of the provided node
             * @param newParent the future parent node 
             */
            void move(Node &newParent);
    };
}

#endif //MYXMLPP_NODE_HPP
