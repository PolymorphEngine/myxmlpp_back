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
            std::string mTag;

        public:
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
