//
// Created by koppany on 5/17/2024.
//

#ifndef BME_PROG2_TICKETS_VONAT_TEST_HPP
#define BME_PROG2_TICKETS_VONAT_TEST_HPP

#include "vonat.h"
#include "gtest_lite.h"
#include "vonat_kezeles.h"

void vonat_test() {

    std::ofstream vofs("vonatok.txt");

    TEST(Vonat, Constructor) {
            Vonat v1("123ABC", 100);
            EXPECT_STREQ(v1.getID().c_str(), "123ABC");
            EXPECT_EQ(v1.getCapacity(), 100);

            vofs << v1;

            Vonat v2(v1);
            EXPECT_STREQ(v2.getID().c_str(), "123ABC");
            EXPECT_EQ(v2.getCapacity(), 100);
        } ENDM

    TEST(Vonat, addStation) {
            Vonat v1("567EFG", 100);
            Allomas a1("Budapest");
            Ido i1(12, 30);
            v1.addStation(a1, i1);
            EXPECT_EQ(v1.getStations().len(), 1);
            EXPECT_EQ(v1.getDepartures().len(), 1);

            vofs << v1;
        } ENDM

    TEST(Vonat, removeStation) {
            Vonat v1("789HIJ", 100);
            Allomas a1("Debrecen");
            Ido i1(12, 30);
            v1.addStation(a1, i1);
            Allomas a2("Budapest");
            Ido i2(3, 4);
            v1.addStation(a2, i2);
            vofs << v1;
            v1.removeStation(a1);
            v1.removeStation(a2);
            EXPECT_EQ(v1.getStations().len(), 0);
            EXPECT_EQ(v1.getDepartures().len(), 0);

        } ENDM

    TEST(Vonat, isStationIn)
        {
            Vonat v1("123ABC", 100);
            Allomas a1("Budapest");
            Ido i1(12, 30);
            v1.addStation(a1, i1);
            EXPECT_EQ(v1.isStationIn(a1), true);
        } ENDM

    TEST(Vonat, operator==) {
            Vonat v1("123ABC", 100);
            Vonat v2("123ABC", 100);
            EXPECT_EQ(v1 == v2, true);
        } ENDM

    TEST(Vonat, operator++) {
            Vonat v1("123ABC", 100);
            EXPECT_EQ(v1++, 100);
        } ENDM

    TEST(Vonat, operator--) {
            Vonat v1("123ABC", 100);
            EXPECT_EQ(v1--, 100);
        } ENDM

    TEST(Vonat, operator+=) {
            Vonat v1("123ABC", 100);
            v1 += 10;
            EXPECT_EQ(v1.getCapacity(), 110);
        } ENDM

    TEST(Vonat, operator-=) {
            Vonat v1("123ABC", 100);
            v1 -= 10;
            EXPECT_EQ(v1.getCapacity(), 90);
        } ENDM

    TEST(Vonat, operator=) {
            Vonat v1("123ABC", 100);
            Vonat v2("456DEF", 200);
            v2 = v1;
            EXPECT_EQ(v2 == v1, true);
        } ENDM

    TEST(Vonat, operator<<) {
            Vonat v1("123ABC", 100);
            std::stringstream ss{};
            ss << v1;
            EXPECT_STREQ("123ABC", ss.str().c_str());

            v1.print();

        } ENDM

    vofs.close();

    std::ifstream vifs("vonatok.txt");

    TEST(Vonat, readFromFile){
            Vonat v1;
            vifs >> v1;
            EXPECT_STREQ("123ABC", v1.getID().c_str());
            EXPECT_EQ(0, v1.getStations().len());

            Vonat v2;
            vifs >> v2;
            EXPECT_STREQ("567EFG", v2.getID().c_str());
            EXPECT_EQ(1, v2.getStations().len());

            Vonat v3;
            vifs >> v3;
            EXPECT_STREQ("789HIJ", v3.getID().c_str());
            EXPECT_EQ(2, v3.getStations().len());
        } ENDM
    vifs.close();
}

#endif //BME_PROG2_TICKETS_VONAT_TEST_HPP
