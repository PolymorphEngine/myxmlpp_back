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


void myxmlpp::Doc::readFile(const string& filepath, bool keepOpen) {
    mFilepath = filepath;
    mFile.open(filepath.c_str(), keepOpen ? ios::in | ios::out : ios::in);
    std::stringstream strStream;

    if (!mFile)
        throw myxmlpp::FileException(filepath, "Cannot open file");
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