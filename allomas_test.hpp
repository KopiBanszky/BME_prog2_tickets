//
// Created by koppany on 5/17/2024.
//

#ifndef BME_PROG2_TICKETS_ALLOMAS_TEST_HPP
#define BME_PROG2_TICKETS_ALLOMAS_TEST_HPP

#include "allomas_kezeles.h"
#include "gtest_lite.h"
#include <fstream>
#include <sstream>


void allomas_test() {
    std::ofstream ofs("allomasok.txt");

    //@description: Allomas class constructor test
    TEST(Allomas, Constructor) {
            Allomas a1("Budapest");
            EXPECT_STREQ("Budapest", a1.getName().c_str());

            ofs << a1;

            Allomas a2(a1);
            EXPECT_STREQ("Budapest", a2.getName().c_str());

        } ENDM

    //@description: Allomas class addTrain test
    //              Add a train to the station
    //              Check if the train is added
    //              Check if the train ID is correct
    TEST(Allomas, addTrain) {

            Allomas a1("Debrecen");
            a1.addTrain(String("123ABC"));
            EXPECT_EQ(1, a1.getTrains().len());
            EXPECT_EQ(String("123ABC"),a1[0]);

            ofs << a1;

        } ENDM

    TEST(Allomas, removeTrain) {
            Allomas a1("Budapest");
            a1.addTrain(String("123ABC"));
            a1.removeTrain(String("123ABC"));
            EXPECT_EQ(0, a1.getTrains().len());
        } ENDM

    TEST(Allomas, search) {
            Allomas a1("Budapest");
            EXPECT_EQ(4, a1.search("pest"));
        } ENDM

    TEST(Allomas, findTrain) {
            Allomas a1("Budapest");
            a1.addTrain(String("123ABC"));
            EXPECT_EQ(0, a1.findTrain("123ABC"));
        } ENDM

    TEST(Allomas, operator<<) {
            Allomas a1("Budapest");
            std::stringstream ss{};
            ss << a1;
            EXPECT_STREQ("Budapest", ss.str().c_str());
        } ENDM

    TEST(Allomas, operator==) {
            Allomas a1("Budapest");
            Allomas a2("Budapest");
            EXPECT_EQ(a1 == a2, true);
        } ENDM

    TEST(Allomas, operator[]) {
            Allomas a1("Szeged");
            a1.addTrain(String("123ABC"));
            a1.addTrain(String("456DEF"));
            a1.addTrain(String("789GHI"));
            EXPECT_EQ(a1[1], String("456DEF"));

            ofs << a1;
        } ENDM
    ofs.close();

    std::ifstream ifs("allomasok.txt");

    TEST(Allomas, readFromFile)
        {
            Allomas a1;
            ifs >> a1;
            EXPECT_STREQ("Budapest", a1.getName().c_str());
            EXPECT_EQ(0, a1.getTrains().len());

            Allomas a2;
            ifs >> a2;
            EXPECT_STREQ("Debrecen", a2.getName().c_str());
            EXPECT_EQ(1, a2.getTrains().len());

            Allomas a3;
            ifs >> a3;
            EXPECT_STREQ("Szeged", a3.getName().c_str());
            EXPECT_EQ(3, a3.getTrains().len());


        } ENDM
    ifs.close();

    TEST(AllomasKezeles, getUserData) {
            List<Vonat> trains;
            List<Allomas> stations;
            AllomasKezeles ak(trains, stations);
            std::stringstream ss{};
            ss << "Budapest";
            std::cin.rdbuf(ss.rdbuf());
            Allomas a1 = ak.getUserData();
            EXPECT_STREQ("Budapest", a1.getName().c_str());
        } ENDM


}

#endif //BME_PROG2_TICKETS_ALLOMAS_TEST_HPP
