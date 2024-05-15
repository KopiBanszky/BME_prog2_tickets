cmake_minimum_required(VERSION 3.26)
project(BME_prog2_tickets)

set(CMAKE_CXX_STANDARD 11)

add_executable(BME_prog2_tickets main.cpp
        ido.h
        jegy.h
        string.h
        vonat.h
        allomas.h
        allomas.cpp
        gtest_lite.h
        ido.cpp
        list.hpp
        memtrace.cpp
        memtrace.h
        test.hpp
        vonat.cpp
        menu.h
        allomas_kezeles.h
        seriazible.h
        jegy.cpp
        string.cpp
        vonat_kezeles.h
        input_manage.h
        jegy_kezeles.h
        exeptions.h
)
