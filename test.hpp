#include "gtest_lite.h"
#include "string.h"
#include "ido.h"
#include "allomas.h"
#include "vonat.h"
#include "jegy.h"
#include "list.hpp"
#include <iostream>
#include <sstream>
#include "memtrace.h"
#include "menu.h"

#define MEMTRACE

#define STRING_TEST true
#define IDO_TEST true
#define ALLOMAS_TEST true
#define VONAT_TEST true
#define JEGY_TEST true
#define LIST_TEST false
#define MENU_TEST true

//#define CPORTA


void run_tests() {
#if STRING_TEST
    TEST(String, Constructor)
        {
            String s1;
            EXPECT_EQ(0, s1.len());
            s1 += "Hello";
            EXPECT_EQ(5, s1.len());
            EXPECT_EQ(true, s1 == "Hello");

            String s2("Hello");
            EXPECT_EQ(5, s2.len());

            String s3(s2);
            EXPECT_EQ(5, s3.len());
            EXPECT_EQ(s2, s3);

            s3 = "World";
            EXPECT_EQ(5, s3.len());
            EXPECT_EQ(true, s3 == "World");

            s3 = s2;
            EXPECT_EQ(5, s3.len());
            EXPECT_EQ(true, s3 == "Hello");

            std::stringstream ss{};
            ss << s3;
            EXPECT_STREQ("Hello", ss.str().c_str());
            ss << '_';
            ss << "World";
            EXPECT_STREQ("Hello_World", ss.str().c_str());

            ss >> s3;
            EXPECT_EQ(11, s3.len());
            EXPECT_EQ(true, s3 == "Hello_World");

            List<String> l1 = s3.split('_');
            EXPECT_EQ(2, l1.len());
            EXPECT_EQ(true, l1[0] == "Hello");
            EXPECT_EQ(String("World"), l1[1]);

            std::ofstream ofs("test.txt", std::ios::app);
            ofs << '\n' << s3 << '\n';
            ofs.close();

            std::ifstream ifs("test.txt");
            String test;
            ifs >> test;
            s2 = "";
            ifs >> s2;
            EXPECT_EQ(3, test.len());
            EXPECT_EQ(String("1:5"), test);
            EXPECT_EQ(11, s3.len());
            EXPECT_EQ(String("Hello_World"), s2);

            String splitTest("Hello_World_");
            List<String> l2 = splitTest.split('_');
            EXPECT_EQ(2, l2.len());
            EXPECT_EQ(String("Hello"), l2[0]);
            EXPECT_EQ(String("World"), l2[1]);

        } ENDM
#endif

#if IDO_TEST
    TEST(Ido, Constructor) {
        Ido i1;
        EXPECT_EQ(0, i1.getHour());
        EXPECT_EQ(0, i1.getMin());

        Ido i2(12, 30);
        EXPECT_EQ(12, i2.getHour());
        EXPECT_EQ(30, i2.getMin());

        Ido i3(i2);
        EXPECT_EQ(12, i3.getHour());
        EXPECT_EQ(30, i3.getMin());

        EXPECT_ANY_THROW(i2.setTime(24, 0));



        std::stringstream ss{};
        ss << i2;
        EXPECT_STREQ("12:30", ss.str().c_str());

        ss >> i1;
        EXPECT_EQ(12, i1.getHour());
        EXPECT_EQ(30, i1.getMin());

        i3.setHour(1);
        EXPECT_EQ(1, i3.getHour());
        i3.setMin(5);
        EXPECT_EQ(5, i3.getMin());

        ss = std::stringstream{};
        ss << i3;
        EXPECT_STREQ("01:05", ss.str().c_str());

        ss >> i1;
        EXPECT_EQ(1, i1.getHour());
        EXPECT_EQ(5, i1.getMin());
        ss.clear();

        std::ofstream ofs("test.txt");
        ofs << i1;
        ofs.close();

        std::ifstream ifs("test.txt");

        ifs >> i2;
        EXPECT_EQ(1, i2.getHour());
        EXPECT_EQ(5, i2.getMin());
        ofs.close();

    } ENDM
#endif

#if ALLOMAS_TEST
    std::ofstream ofs("allomasok.txt");

    TEST(Allomas, Constructor) {
        Allomas a1("Budapest");
        EXPECT_STREQ("Budapest", a1.getName().c_str());

        ofs << a1;

        Allomas a2(a1);
        EXPECT_STREQ("Budapest", a2.getName().c_str());

    } ENDM

    TEST(Allomas, addTrain) {

        Allomas a1("Debrecen");
        a1.addTrain(String("123ABC"));
        EXPECT_EQ(1, a1.getTrains().len());

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
        EXPECT_EQ(0, a1.search("pest"));
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
#endif

#if VONAT_TEST

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
#endif

#if JEGY_TEST
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

#endif

#if LIST_TEST
    TEST(List, Constructor) {
        List<int> l1;
        EXPECT_EQ(l1.len(), 0);

        List<int> l2(l1);
        EXPECT_EQ(l2.len(), 0);
    } ENDM

    TEST(List, push_back) {
        List<int> l1;
        l1.push_back(1);
        EXPECT_EQ(l1.len(), 1);
    } ENDM

    TEST(List, pop_front) {
        List<int> l1;
        l1.push_back(1);
        l1.pop_front();
        EXPECT_EQ(l1.len(), 0);
    } ENDM



    TEST(List, operator=) {
        List<int> l1;
        l1.push_back(1);
        List<int> l2;
        l2 = l1;
        EXPECT_EQ(l2.len(), 1);
    } ENDM

#endif

#if MENU_TEST

    TEST(Menu, getChoice){

    } ENDM

#endif

return;
}