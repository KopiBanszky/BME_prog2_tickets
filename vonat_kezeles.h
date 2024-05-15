//
// Created by koppany on 5/15/2024.
//

#ifndef BME_PROG2_TICKETS_VONAT_KEZELES_H
#define BME_PROG2_TICKETS_VONAT_KEZELES_H

#include "vonat.h"
#include "list.hpp"
#include "allomas.h"

class VonatKezeles : public Vonat {
    List<Vonat>& trains;
    List<Allomas>& stations;
public:

    Vonat getTrainFromUser() {
        Vonat train;
        std::cout << "Adja meg a vonat azonositojat: ";
        bool err = false;
        try {
            std::cin >> train;

        } catch (const char* msg) {
            std::cout << "Hibas azonosito, 6 karakter hosszu lehet csak! Adjon meg egy masikat: ";
            err = true;
        }
        while (trains.contains(train) || err) {
            err = false;
            try {
                std::cout << "A vonat mar letezik, adjon meg egy masikat: ";
                std::cin >> train;
            } catch (const char* msg) {
                std::cout << "Hibas azonosito, 6 karakter hosszu lehet csak! Adjon meg egy masikat: ";
                err = true;
            }
        }

        int i = 0;
        for(auto station = stations.begin(); station != stations.end(); station++) {
            std::cout << '[' << i << "] " << *station << std::endl;
        }
        std::cout << "Adja meg a vonat allomasait (0-vegig): ";
        int index;
        while(std::cin >> index && index != -1) {
            Ido time;
            std::cout << "Adja meg az indulas idejet: ";
            std::cin >> time;
            train.addStation(stations[index], Ido());
        }

        return train;
    }

};

#endif //BME_PROG2_TICKETS_VONAT_KEZELES_H
