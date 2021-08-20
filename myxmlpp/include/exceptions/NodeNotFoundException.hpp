/*
** EPITECH PROJECT, 2020
** NodeNotFoundException.hpp.h
** File description:
** header for NodeNotFoundException.c
*/

#ifndef MYXMLPP_NODENOTFOUNDEXCEPTION_HPP
#define MYXMLPP_NODENOTFOUNDEXCEPTION_HPP

#include <string>
#include <Exception.hpp>

namespace myxmlpp {
    /**
     * Exception to throw when a node is not found in findChild* methods
     */
    class NodeNotFoundException: public Exception {
        protected:
            /**
             * Tag of the wanted node
             */
            std::string mTag;

        public:
            NodeNotFoundException(std::string tag, std::string file,
                                  std::string line, std::string description);

            std::string getTag() const;

            /**
             * Complete error message, ready to log in the console/terminal
             * @return error message
             */
            virtual std::string what();

            virtual ~NodeNotFoundException() throw()
            {}
    };
}


#endif //MYXMLPP_NODENOTFOUNDEXCEPTION_HPP
