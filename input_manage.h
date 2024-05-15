//
// Created by koppany on 5/15/2024.
//

#ifndef BME_PROG2_TICKETS_INPUT_MANAGE_H
#define BME_PROG2_TICKETS_INPUT_MANAGE_H
#include "vonat.h"
#include "allomas.h"
#include "list.hpp"

template<typename T>
struct InputManage {
    List<Vonat>& trains;
    List<Allomas>& stations;
    InputManage(List<Vonat>& trains, List<Allomas>& stations) : trains(trains), stations(stations) {}

    virtual T getUserData() = 0;
    virtual ~InputManage() = default;
};

#endif //BME_PROG2_TICKETS_INPUT_MANAGE_H
