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

namespace myxmlpp {

    /**
     * test exception
     */
    class FileException: public std::exception{
        private:
            std::string mFilepath;
            std::string mDescription;
            int mSeverity;

        public:
            explicit FileException(const std::string&  filepath, const std::string&  description="", int severity=1) throw()
                :mFilepath(filepath), mDescription(description), mSeverity(severity)
                {}

            std::string getError() {
                return mDescription + " in " + mFilepath;
            };

            std::string getFilePath() {
                return mFilepath;
            }

            std::string getDescription() {
                return mDescription;
            }

            int getSeverity() {
                return mSeverity;
            }

            virtual ~FileException() throw()
            {}
    };
int level = node->findAttribute("name")->getValueInt()
}


#endif //MYXML_FILEEXCEPTION_HPP
