/*
** EPITECH PROJECT, 2020
** FileException.hpp.h
** File description:
** header for FileException.c
*/

#ifndef MYXML_FILEEXCEPTION_HPP
#define MYXML_FILEEXCEPTION_HPP

#include <exception>
#include <string>
#include <utility>
#include "Exception.hpp"

namespace myxmlpp {

    /**
     * Generic exception relative to file manipulation
     */
    class FileException: public myxmlpp::Exception {
        private:
            /**
             * Path of the problematic file
             */
            std::string mFilepath;

        public:
            explicit FileException(const std::string&  filepath,
                                   const std::string&  file,
                                   const std::string& line,
                                   const std::string& description="");

            const std::string &getFilepath() const;

            /**
             * Complete error message, ready to log in the console/terminal
             * @return error message
             */
            virtual std::string what();

            virtual ~FileException() throw()
            {}
    };
}


#endif //MYXML_FILEEXCEPTION_HPP
