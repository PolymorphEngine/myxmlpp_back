/*
** EPITECH PROJECTNode 2022
** Node_findChild.cpp
** File description:
** Node_findChild.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "Node.hpp"
#include "NodeNotFoundException.hpp"

Test(Node_findChild, not_find)
{
    myxmlpp::Doc d("tests/files/unit-testing/noChild.xml");
    
    try {
        d.getRoot()->findChild("test");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}