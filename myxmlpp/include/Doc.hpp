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
            
            /*
             * The ml root tag
             */
            std::shared_ptr<Node> _root;
            
            /**
             * Check commons file openning errors and throw the correct exception
             * @throws NoFileException if the required file does not exists
             * @throws PermissionDeniedException if there is not enough permissions to work with the file
             * @throws FileException Default exception for other errors
             */
             static void _throwOpenError(const std::string &filepath, 
                                  bool keepOpen) ;

            /**
             * Open the file and put its content to _content property
             * @param filepath path of the xml file
             * @param keepOpen keep the file stream opened
             * @copydetails _throwOpenError
             */
            void _readFile(const std::string& filepath, bool keepOpen);

        public:
            /**
             * Constructor by filepath
             * @param filepath path to the xml file 
             * @param keepOpen keep the file stream opened
             * @throws NoFileException if the required file does not exists
             * @throws PermissionDeniedException if ther is not enough permissions to work with the file
             * @throws FileException Default exception for other errors
             * @throws ParsingException If the file is not correctly formatted
             */
            Doc(const std::string& filepath, bool keepOpen = false);
            
            /**
             * Get the current filepath
             * @returns the current filepath
             */
            const std::string &getFilepath() const;
            
            /**
             * Set the filepath
             * @param filepath the new filepath 
             */
            void setFilepath(const std::string &filepath);
            
            /**
             * Get the root node of the document.
             * @return the XML root node 
             */
            std::shared_ptr<Node> getRoot() const;
    };

}

#endif //MYXML_DOC_HPP
