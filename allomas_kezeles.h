//
// Created by koppany on 5/14/2024.
//

#ifndef BME_PROG2_TICKETS_ALLOMAS_KEZELES_H
#define BME_PROG2_TICKETS_ALLOMAS_KEZELES_H

#include "input_manage.h"

class AllomasKezeles : public InputManage<Allomas>, public Allomas{
public:
    AllomasKezeles(List<Vonat>& trains ,List<Allomas>& stations) : InputManage<Allomas>(trains, stations) {}

    Allomas getUserData() override {
        Allomas station;
        std::cout << "Adja meg az allomas nevet: ";
        std::cin >> station;
        while (stations.contains(station)) {
            std::cout << "Az allomas mar letezik, adjon meg egy masikat: ";
            std::cin >> station;
        }

        return station;
    }

};

#endif //BME_PROG2_TICKETS_ALLOMAS_KEZELES_H
