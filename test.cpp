#include "gtest_lite.h"
#include "string.h"
#include "ido.h"
#include "allomas.h"
#include "vonat.h"
#include "jegy.h"
#include "list.hpp"

#define STRING_TEST true
#define IDO_TEST true
#define ALLOMAS_TEST true
#define VONAT_TEST true
#define JEGY_TEST true
#define LIST_TEST true


void run_tests() {
#if STRING_TEST
    TEST(String, Constructor) {
        {
            String s1;
            EXPECT_EQ(s1.len(), 0);
            s1 += "Hello";
            EXPECT_EQ(s1.len(), 5);
            EXPECT_EQ(s1 == "Hello", true);

            String s2("Hello");
            EXPECT_EQ(s2.len(), 5);

            String s3(s2);
            EXPECT_EQ(s3.len(), 5);
            EXPECT_STREQ(s3, s2);
        }
#endif

#if IDO_TEST
    TEST(Ido, Constructor) {
        {
            Ido i1;
            EXPECT_EQ(i1.getHour(), 0);
            EXPECT_EQ(i1.getMin(), 0);

            Ido i2(12, 30);
            EXPECT_EQ(i2.getHour(), 12);
            EXPECT_EQ(i2.getMin(), 30);

            Ido i3(i2);
            EXPECT_EQ(i3.getHour(), 12);
            EXPECT_EQ(i3.getMin(), 30);
        }
    }
#endif

#if ALLOMAS_TEST
    TEST(Allomas, Constructor) {
        {
            Allomas a1("Budapest");
            EXPECT_STREQ(a1.getName(), "Budapest");

            Allomas a2(a1);
            EXPECT_STREQ(a2.getName(), "Budapest");
        }
    }

    TEST(Allomas, addTrain) {
        {
            Allomas a1("Budapest");
            Vonat v1("123", 100);
            a1.addTrain(v1);
            EXPECT_EQ(a1.getTrains().len(), 1);
        }
    }
#endif

#if VONAT_TEST
    TEST(Vonat, Constructor) {
        {
            Vonat v1("123", 100);
            EXPECT_STREQ(v1.getID(), "123");
            EXPECT_EQ(v1.getCapacity(), 100);

            Vonat v2(v1);
            EXPECT_STREQ(v2.getID(), "123");
            EXPECT_EQ(v2.getCapacity(), 100);
        }
    }

    TEST(Vonat, addStation) {
        {
            Vonat v1("123", 100);
            Allomas a1("Budapest");
            Ido i1(12, 30);
            v1.addStation(a1, i1);
            EXPECT_EQ(v1.getStations().len(), 1);
            EXPECT_EQ(v1.getDepartures().len(), 1);
        }
    }

    TEST(Vonat, removeStation) {
        {
            Vonat v1("123", 100);
            Allomas a1("Budapest");
            Ido i1(12, 30);
            v1.addStation(a1, i1);
            v1.removeStation(a1);
            EXPECT_EQ(v1.getStations().len(), 0);
            EXPECT_EQ(v1.getDepartures().len(), 0);
        }
    }

    TEST(Vonat, isStationIn) {
        {
            Vonat v1("123", 100);
            Allomas a1("Budapest");
            Ido i1(12, 30);
            v1.addStation(a1, i1);
            EXPECT_EQ(v1.isStationIn(a1), true);
        }
    }

    TEST(Vonat, operator==) {
        {
            Vonat v1("123", 100);
            Vonat v2("123", 100);
            EXPECT_EQ(v1 == v2, true);
        }
    }

    TEST(Vonat, operator++) {
        {
            Vonat v1("123", 100);
            EXPECT_EQ(v1++, 100);
        }
    }

    TEST(Vonat, operator--) {
        {
            Vonat v1("123", 100);
            EXPECT_EQ(v1--, 100);
        }
    }

    TEST(Vonat, operator+=) {
        {
            Vonat v1("123", 100);
            v1 += 10;
            EXPECT_EQ(v1.getCapacity(), 110);
        }
    }

    TEST(Vonat, operator-=) {
        {
            Vonat v1("123", 100);
            v1 -= 10;
            EXPECT_EQ(v1.getCapacity(), 90);
        }
    }

    TEST(Vonat, operator=) {
        {
            Vonat v1("123", 100);
            Vonat v2("456", 200);
            v2 = v1;
            EXPECT_EQ(v2 == v1, true);
        }
    }

    TEST(Vonat, operator<<) {
        {
            Vonat v1("123", 100);
            std::cout << v1;
        }
    }

#endif

#if JEGY_TEST
    TEST(Jegy, Constructor) {
        {
            String name("Test Elek");
            Vonat v1("123ABC", 100);
            Allomas a1("Budapest");
            Allomas a2("Debrecen");
            Jegy j1(name, &v1, &a1, &a2, 1, 2);
            EXPECT_STREQ(j1.getName(), "Test Elek");
            EXPECT_EQ(j1.getTrain() == v1, true);
            EXPECT_EQ(j1.getStartStation() == a1, true);
            EXPECT_EQ(j1.getFinalStation() == a2, true);
        }
    }

    TEST(Jegy, print) {
        {
            String name("Test Elek");
            Vonat v1("123", 100);
            Allomas a1("Budapest");
            Allomas a2("Debrecen");
            Jegy j1(name, &v1, &a1, &a2, 1, 2);
            j1.print();
        }
    }

#endif

#if LIST_TEST
    TEST(List, Constructor) {
        {
            List<int> l1;
            EXPECT_EQ(l1.len(), 0);

            List<int> l2(l1);
            EXPECT_EQ(l2.len(), 0);
        }
    }

    TEST(List, push_back) {
        {
            List<int> l1;
            l1.push_back(1);
            EXPECT_EQ(l1.len(), 1);
        }
    }

    TEST(List, pop_front) {
        {
            List<int> l1;
            l1.push_back(1);
            l1.pop_front();
            EXPECT_EQ(l1.len(), 0);
        }
    }



    TEST(List, operator=) {
        {
            List<int> l1;
            l1.push_back(1);
            List<int> l2;
            l2 = l1;
            EXPECT_EQ(l2.len(), 1);
        }
    }

    TEST(List, operator<<) {
        {
            List<int> l1;
            l1.push_back(1);
            std::cout << l1;
        }
    }

#endif
};