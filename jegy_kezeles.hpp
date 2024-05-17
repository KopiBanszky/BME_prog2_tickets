//
// Created by koppany on 5/15/2024.
//

#ifndef BME_PROG2_TICKETS_JEGY_KEZELES_HPP
#define BME_PROG2_TICKETS_JEGY_KEZELES_HPP

#include "input_manage.h"
#include "jegy.h"
#include <random>

class Jegy_kezeles : public InputManage<Jegy>{
public:
    Jegy_kezeles(List<Vonat>& trains, List<Allomas>& stations) : InputManage<Jegy>(trains, stations) {}

    Jegy getUserData() override {
        String name;
        Vonat train;
        Allomas startStation;
        Allomas finalStation;
        int carNumber;
        int seatNumber;

        String stationName;
        std::cout << "Adja meg a kezdo allomas nevet: ";
        stationName.getLine();
        List<Allomas&> viableStations;
        int index = 0;
        std::cout << "\nAllomasok: " << std::endl;
        for (auto i = InputManage<Jegy>::stations.begin(); i != InputManage<Jegy>::stations.end(); ++i) {
            Allomas& station = *i;
            try {
                if (station.search(stationName) == -1) {
                    continue;
                }
            } catch (std::invalid_argument& e){}
            viableStations.push_back(station);
            std::cout << '[' << index << "] " << station << std::endl;
            index++;
        }
        if(viableStations.len() == 0) {
            std::cout << "Nincs ilyen allomas!" << std::endl;
            throw std::invalid_argument("Nincs ilyen allomas!");
        }
        std::cout << "\nAdja meg a indulo allomast (0-vegig): ";
        String helperString;
        int startStationIndex;
        int err = true;
        while (err){
            std::cin >> startStationIndex;
            try{
                startStation = viableStations[startStationIndex];
                err = false;
            }
            catch (std::out_of_range& e){
                err = true;
                std::cout << "Hibas input, probalja ujra! " << std::endl;
            }
        }
        viableStations.clear();
        stationName = "";
        std::cout << "\nAdja meg a vegallomas nevet: " << std::endl;
        stationName.getLine(std::cin);
        index = 0;
        for (auto i = InputManage<Jegy>::stations.begin(); i != InputManage<Jegy>::stations.end(); ++i) {
            Allomas& station = *i;
            if (station.search(stationName) == -1) {
                continue;
            }
            viableStations.push_back(station);
            std::cout << '[' << index << "] " << station << std::endl;
            index++;
        }
        if(viableStations.len() == 0) {
            std::cout << "Nincs ilyen allomas!" << std::endl;
            throw std::invalid_argument("Nincs ilyen allomas!");
        }
        std::cout << "\nAdja meg a vegallomast (0-vegig): ";
        int finalStationIndex;
        err = true;
        while (err){
            std::cin >> finalStationIndex;
            try{
                finalStation = viableStations[finalStationIndex];
                err = false;
            }
            catch (std::out_of_range& e){
                err = true;
                std::cout << "Hibas input, probalja ujra! " << std::endl;
            }
        }

        List<Vonat&> viableTrains;

        index = 0;
        for(auto startSi = startStation.getTrains().begin(); startSi != startStation.getTrains().end(); startSi++) {
            String startT = *startSi;
            for(auto finalSi = finalStation.getTrains().begin(); finalSi != finalStation.getTrains().end(); finalSi++) {
                String finalT = *finalSi;
                if(startT == finalT) {
                    size_t i = trains.index(Vonat(startT, 0));
                    viableTrains.push_back(trains[i]);
                    size_t departureIndex = trains[i].stationIndex(startStation);
                    try {
                        std::cout << '[' << index << "] " << trains[i] << trains[i].getDepartures()[departureIndex] << std::endl;

                    }
                    catch (std::out_of_range& e){
                        std::cout << "Nincs ilyen vonat!" << std::endl;
                        break;
                    }
                    break;
                }
            }
        }
        if(viableTrains.len() == 0) {
            std::cout << "Nincs ilyen vonat!" << std::endl;
            throw std::invalid_argument("Nincs ilyen vonat!");
        }


        std::cout << "\nAdja meg a vonatot (0-vegig): ";
        int finalTrainIndex;
        err = true;
        while (err){
            std::cin >> finalTrainIndex;
            try{
                finalStation = viableStations[finalTrainIndex];
                err = false;
            }
            catch (std::out_of_range& e){
                err = true;
                std::cout << "Hibas input, probalja ujra! " << std::endl;
            }
        }



        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(1,train.getCapacity());

        carNumber = distrib(gen); // Generate random number

        distrib = std::uniform_int_distribution<>(1,30);
        seatNumber = distrib(gen);

        std::cout << "\nAdja meg a jegy tulajdonosanak nevet: ";

        err = false;
        while (!err){
            try {
                std::cin >> name;

            }catch (const char* msg){
                err = true;
            }
        }

        return Jegy(
                name,
                train,
                startStation,
                finalStation,
                carNumber,
                seatNumber
                );
    }
};

#endif //BME_PROG2_TICKETS_JEGY_KEZELES_HPP
