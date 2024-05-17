//
// Created by koppany on 5/17/2024.
//

#ifndef BME_PROG2_TICKETS_STRING_TEST_HPP
#define BME_PROG2_TICKETS_STRING_TEST_HPP

#include "string.h"
#include "gtest_lite.h"

void string_test() {
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

        String s4;
        std::stringstream ss2{"Hello world"};
        s4.getLine(ss2);
        EXPECT_EQ(11, s4.len());
        EXPECT_EQ(String("Hello world"), s4);


    } ENDM
}

#endif //BME_PROG2_TICKETS_STRING_TEST_HPP
