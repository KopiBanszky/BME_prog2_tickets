//
// Created by koppany on 5/15/2024.
//

#ifndef BME_PROG2_TICKETS_VONAT_KEZELES_H
#define BME_PROG2_TICKETS_VONAT_KEZELES_H

#include "input_manage.h"

class VonatKezeles : public InputManage<Vonat>, public Vonat{
public:
    VonatKezeles(List<Vonat>& trains, List<Allomas>& stations) : InputManage<Vonat>(trains, stations) {}

    Vonat getUserData() override {

        Vonat train;
        std::cout << "Adja meg a vonat azonositojat, majd a kocsik szamat kulon sorba: ";
        bool err = false;
        try {
            std::cin >> train;

        } catch (const char* msg) {
            std::cout << "Hibas azonosito, 6 karakter hosszu lehet csak! Adjon meg egy masikat: ";
            std::cin >> train;
            err = true;
        } catch (std::invalid_argument& e) {
            std::cin >> train;
            err = true;
        }
        while (trains.contains(train) || err) {
            err = false;
            try {
                std::cout << "A vonat mar letezik, adjon meg egy masikat, majd a kocsik szamat kulon sorba: ";
                std::cin >> train;
            } catch (const char* msg) {
                std::cout << "Hibas azonosito, 6 karakter hosszu lehet csak! Adjon meg egy masikat: ";
                err = true;
            }
        }

        int i = 0;
        std::cout << "\nAllomasok: " << std::endl;
        for(auto station = InputManage<Vonat>::stations.begin(); station != InputManage<Vonat>::stations.end(); station++) {
            if(*station == Allomas("") || *station == Allomas(" ")) {
                continue;
            }
            std::cout << '[' << i << "] " << *station << std::endl;
            i++;
        }
        std::cout << "\nAdja meg a vonat allomasait (0-vegig, -1: mentes): " << std::endl;
        int index;
        List<int> used;

        while(index != -1) {
            std::cin >> index;
            if(index == -1) {
                break;
            }
            if(used.contains(index)) {
                std::cout << "Ez az allomas mar szerepel, adjon meg egy masikat: ";
                continue;
            }
            Ido time;
            std::cout << "Adja meg az indulas idejet (hh:mm): ";
            try {
                std::cin >> time;
            } catch (std::invalid_argument& e) {
                std::cout << "Hibas input, probalja ujra! " << std::endl;
                continue;
            }
            std::cout << time << std::endl;
            try {
                train.addStation(InputManage<Vonat>::stations[index], time);
                used.push_back(index);
            } catch (std::out_of_range& e) {
                std::cout << "Hibas input, probalja ujra! " << std::endl;
                continue;

            }
            std::cout << "Kovetkezo allomas: ";
        }

        return train;
    }

};

#endif //BME_PROG2_TICKETS_VONAT_KEZELES_H
