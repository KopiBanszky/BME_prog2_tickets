#include "gtest_lite.h"
#include <iostream>
#include <sstream>
#include "memtrace.h"
#include "menu.h"
#include "string_test.hpp"
#include "ido_test.hpp"
#include "allomas_test.hpp"
#include "vonat_test.hpp"
#include "jegy_test.hpp"
#include "list_test.hpp"


#define MEMTRACE

#define STRING_TEST true
#define IDO_TEST true
#define ALLOMAS_TEST true
#define VONAT_TEST true
#define JEGY_TEST true
#define LIST_TEST true
#define MENU_TEST true

#define CPORTA


void run_tests() {
#if STRING_TEST
    string_test();
#endif

#if IDO_TEST
    ido_test();
#endif

#if ALLOMAS_TEST
    allomas_test();
#endif

#if VONAT_TEST
    vonat_test();
#endif

#if JEGY_TEST
    jegy_test();
#endif

#if LIST_TEST
    list_test();
#endif

#if MENU_TEST

    TEST(Menu, getChoice){
        Menu m("Test");
        m.addOption("Option1", '1');
        m.addOption("Option2", '2');
        m.addOption("Option3", '3');
        m.addOption("Option4", '4');
        std::stringstream ss;
        m.print(ss);

        std::string expected = "\n\nTest\n\n[1] - Option1\n[2] - Option2\n[3] - Option3\n[4] - Option4\n\n";
        EXPECT_STREQ(expected.c_str(), ss.str().c_str());
    } ENDM


#endif
}