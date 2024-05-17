//
// Created by koppany on 5/17/2024.
//

#ifndef BME_PROG2_TICKETS_LIST_TEST_HPP
#define BME_PROG2_TICKETS_LIST_TEST_HPP

#include "list.hpp"
#include "gtest_lite.h"

void list_test() {
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

    TEST(List, operator[]) {
            List<int> l1;
            l1.push_back(1);
            EXPECT_EQ(l1[0], 1);
        } ENDM

}

#endif //BME_PROG2_TICKETS_LIST_TEST_HPP
