/*
** EPITECH PROJECT, 2020
** attribute.hpp.h
** File description:
** header for Attribute.cpp
*/

#ifndef MYXMLPP_ATTRIBUTE_HPP
#define MYXMLPP_ATTRIBUTE_HPP

#include <string>
#include <Doc.hpp>

namespace myxmlpp {

    typedef enum {OPENRD, OPENWR, OPENRDWR, OPENAPP} openMode_t;
    /**
     * Attribute in a node
     */
    class Attribute {
        private:
            /**
             * Key of the attribute
             */
            std::string mKey;

            /**
             * Value of the attribute
             */
            std::string mValue;

            static std::ios_base::openmode getValueFileOpenMode(
                    openMode_t mode);

        public:
            Attribute(const std::string& key, const std::string& value);

            Attribute(const std::string& fileContent);


            std::string getKey() const;


            void setKey(const std::string& key);


            std::string getValue() const;


            int getValueInt() const;


            float getValueFloat() const;


            bool getValueBool(const std::string& trueElement,
                              const std::string& falseElement) const;

            Doc getValueXmlDoc() const;


            std::fstream *getValueFile(openMode_t mode) const;


            void setValue(const std::string& value);


            void setValueInt(int value);


            void setValueFloat(float value);


            void setValueBool(bool value, const std::string& trueElement,
                              const std::string& falseElement);
    };
}


#endif //MYXMLPP_ATTRIBUTE_HPP
