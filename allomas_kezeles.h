//
// Created by koppany on 5/14/2024.
//

#ifndef BME_PROG2_TICKETS_ALLOMAS_KEZELES_H
#define BME_PROG2_TICKETS_ALLOMAS_KEZELES_H

#include "allomas.h"
#include "vonat.h"
#include "list.hpp"

class AllomasKezeles : public Allomas{
    List<Allomas>& stations;
public:
    AllomasKezeles(List<Allomas>& stations) : stations(stations) {}

    Allomas getStationFromUser() {
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
