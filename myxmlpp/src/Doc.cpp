/*
** EPITECH PROJECT, 2021
** Doc.cpp
** File description:
** Doc.cpp
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include "Doc.hpp"
#include "exceptions/FileException.hpp"

using namespace std;


myxmlpp::Doc::Doc(const std::string& filepath){
    mFile =  new fstream(filepath.c_str());
}

void myxmlpp::Doc::readFile(const string& filepath, bool keepOpen) {
    mFilepath = filepath;
    std::fstream mFile;
    mFile.open(filepath.c_str(), keepOpen ? ios::in | ios::out : ios::in);
    std::stringstream strStream;

    if (!mFile)
        throw myxmlpp::FileException(filepath, MYXMLPP_ERROR_LOCATION,
                                     "Cannot open file");
    strStream << mFile.rdbuf();
    mContent = strStream.str();
    if (!keepOpen)
        mFile.close();
}

const string &myxmlpp::Doc::getMFilepath() const {
    return mFilepath;
}

void myxmlpp::Doc::setMFilepath(const string &m_filepath) {
    mFilepath = m_filepath;
}

int main() {
    return 0;
}