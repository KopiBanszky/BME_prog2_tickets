cmake_minimum_required(VERSION 3.26)
project(BME_prog2_tickets)

set(CMAKE_CXX_STANDARD 11)

add_executable(BME_prog2_tickets main.cpp
        ido.h
        jegy.h
        string.h
        vonat.h
        allomas.h
        list.h
        allomas.cpp
        test.cpp
        gtest_lite.h)
