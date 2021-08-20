/*
** EPITECH PROJECT, 2021
** PermissionDeniedException.cpp.cc
** File description:
** PermissionDeniedException.cpp.cc
*/


#include "PermissionDeniedException.hpp"

std::string myxmlpp::PermissionDeniedException::what() {
    return baseWhat()
        + std::string("permission denied at the given filepath ")
        + mFilepath
        +details();
}