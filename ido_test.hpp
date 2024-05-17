//
// Created by koppany on 5/17/2024.
//

#ifndef BME_PROG2_TICKETS_IDO_TEST_HPP
#define BME_PROG2_TICKETS_IDO_TEST_HPP

#include "ido.h"
#include "gtest_lite.h"
#include <fstream>
#include <sstream>

void ido_test() {
    //@description: Ido class constructor
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
}

#endif //BME_PROG2_TICKETS_IDO_TEST_HPP
