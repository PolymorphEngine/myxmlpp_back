/*
** EPITECH PROJECT, 2022
** Node_findChildren.cpp
** File description:
** Node_findChildren.cpp
*/

#include <criterion/criterion.h>
#include "Doc.hpp"
#include "NodeNotFoundException.hpp"

Test(Node_findChildrenR, not_found)
{
    myxmlpp::Doc d("tests/files/unit-testing/find/findChildrenR/noChildren.xml");

    try {
        d.getRoot()->findChildrenR("child");
        cr_expect(0);
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(1);
    }
}

Test(Node_findChildrenR, one_level)
{
    myxmlpp::Doc d("tests/files/unit-testing/find/findChildrenR/oneLevel.xml");

    try {
        auto children = d.getRoot()->findChildrenR("child");
        
        cr_expect_eq(children.size(), 1);
        cr_expect(children[0]->getTag() == "child");
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildrenR, many_found_without_depth)
{
    myxmlpp::Doc d("tests/files/unit-testing/find/findChildrenR/manyLevels.xml");

    try {
        auto children = d.getRoot()->findChildrenR("childToFind");

        cr_expect_eq(children.size(), 5);
        cr_expect(children[0]->getTag() == "childToFind");
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildrenR, many_found_overkill_depth)
{
    myxmlpp::Doc d("tests/files/unit-testing/find/findChildrenR/manyLevels.xml");

    try {
        auto children = d.getRoot()->findChildrenR("childToFind", 50);

        cr_expect_eq(children.size(), 5);
        cr_expect(children[0]->getTag() == "childToFind");
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildrenR, many_found_depth5)
{
    myxmlpp::Doc d("tests/files/unit-testing/find/findChildrenR/manyLevels.xml");

    try {
        auto children = d.getRoot()->findChildrenR("childToFind", 5);

        
        std::cerr << children.size() << std::endl;
        cr_expect_eq(children.size(), 4);
        cr_expect(children[0]->getTag() == "childToFind");
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildrenR, many_found_depth4)
{
    myxmlpp::Doc d("tests/files/unit-testing/find/findChildrenR/manyLevels.xml");

    try {
        auto children = d.getRoot()->findChildrenR("childToFind", 4);

        cr_expect_eq(children.size(), 3);
        cr_expect(children[0]->getTag() == "childToFind");
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}

Test(Node_findChildrenR, many_found_no_search_depth)
{
    myxmlpp::Doc d("tests/files/unit-testing/find/findChildrenR/manyLevels.xml");

    try {
        auto children = d.getRoot()->findChildrenR("childToFind", 0);

        cr_expect(children.empty());
    } catch (myxmlpp::NodeNotFoundException &e) {
        cr_expect(0);
    }
}