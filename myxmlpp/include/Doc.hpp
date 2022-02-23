/*
** EPITECH PROJECT, 2020
** Doc.hpp
** File description:
** header for Doc.cpp
*/

#ifndef MYXML_DOC_HPP
#define MYXML_DOC_HPP

#include <string>
#include <fstream>
#include <memory>
#include "Node.hpp"

namespace myxmlpp {

    /**
     * Main class of the xml structure, used to store all the nodes
     */
    class Doc {
        private:
            /**
             * The string filepath correspond to the filepath of the xml file
             */
            std::string _filepath;

            /**
             * The string content of the file
             */
            std::string _content;

            /**
             * The file stream to red/write structure into file
             */
            std::fstream _file;
            
            std::unique_ptr<Node> _root;

            /**
             * @param filepath path of the xml file
             * @param keepOpen keep the file stream opened
             */
            void readFile(const std::string& filepath, bool keepOpen);

        public:
            /**
             * Constructor by filepath
             * @param filepath path to the xml file 
             * @param keepOpen keep the file stream opened
             */
            Doc(const std::string& filepath, bool keepOpen = false);
            
            const std::string &getFilepath() const;
            void setMFilepath(const std::string &m_filepath);
    };

}

#endif //MYXML_DOC_HPP
