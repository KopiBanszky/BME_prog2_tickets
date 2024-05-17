//
// Created by koppany on 5/17/2024.
//

#ifndef BME_PROG2_TICKETS_JEGY_TEST_HPP
#define BME_PROG2_TICKETS_JEGY_TEST_HPP

#include "jegy.h"
#include "gtest_lite.h"
#include "jegy_kezeles.hpp"

void jegy_test() {
    TEST(Jegy, Constructor) {
            String name("Test Elek");
            Vonat v1("123ABC", 100);
            Allomas a1("Budapest");
            Allomas a2("Debrecen");
            Jegy j1(name, v1, a1, a2, 1, 2);
            EXPECT_STREQ(j1.getName().c_str(), "Test Elek");
            EXPECT_EQ(j1.getTrain() == v1, true);
            EXPECT_EQ(j1.getStartStation() == a1, true);
            EXPECT_EQ(j1.getFinalStation() == a2, true);
        } ENDM

    TEST(Jegy, print) {
            String name("Test Elek");
            Vonat v1("123ABC", 100);
            Allomas a1("Budapest");
            Allomas a2("Debrecen");
            Jegy j1(name, v1, a1, a2, 1, 2);
            std::stringstream ss{};
            j1.print(ss);
            EXPECT_STREQ("Jegy tulajdonosa: Test Elek\nVonat: 123ABC\nIndulási állomás: Budapest\nVégállomás: Debrecen\nKocsi száma: 1\nSor száma: 2\n", ss.str().c_str());
        } ENDM
}

#endif //BME_PROG2_TICKETS_JEGY_TEST_HPP
