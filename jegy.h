#ifndef BME_PROG2_TICKETS_JEGY_H
#define BME_PROG2_TICKETS_JEGY_H

#include "string.h"
#include "vonat.h"
#include "allomas.h"

class Jegy{
    String name;
    Vonat* train;
    Allomas* startStation;
    Allomas* finalStation;
    int carNumber;
    int seatNumber;
public:
    Jegy(
        const String& name, 
        Vonat* train, 
        Allomas* startStation, 
        Allomas* endStation, 
        int carNumber, 
        int seatNumber
        ) : name(name), train(train), startStation(startStation), finalStation(endStation), carNumber(carNumber), seatNumber(seatNumber) {}

    // @brief Getter function for the name of the ticket owner
    // @return name of the ticket owner (String)
    const String& getName() const { return name; }

    // @brief Getter function for the train
    // @return train (Vonat)
    const Vonat& getTrain() const { return *train; }

    // @brief Getter function for the start station
    // @return start station (Allomas)
    const Allomas& getStartStation() const { return *startStation; }

    // @brief Getter function for the final station
    // @return final station (Allomas)
    const Allomas& getFinalStation() const { return *finalStation; }

    // @brief prints the ticket's owner, the train, the start and final stations, the car number and the seat number
    void print() const {
        std::cout << "Jegy tulajdonosa: " << name << std::endl;
        std::cout << "Vonat: " << train << std::endl;
        std::cout << "Indulási állomás: " << startStation->getName() << std::endl;
        std::cout << "Végállomás: " << finalStation->getName() << std::endl;
        std::cout << "Kocsi száma: " << carNumber << std::endl;
        std::cout << "Sor száma: " << seatNumber << std::endl;
    }

};

#endif //BME_PROG2_TICKETS_JEGY_H
