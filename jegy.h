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
    Jegy(const String& name, Vonat* train, Allomas* startStation, Allomas* endStation, int carNumber, int seatNumber) : name(name), train(train), startStation(startStation), finalStation(endStation), carNumber(carNumber), seatNumber(seatNumber) {}
    const String& getName() const { return name; }
    const Vonat& getTrain() const { return *train; }
    const Allomas& getStartStation() const { return *startStation; }
    const Allomas& getFinalStation() const { return *finalStation; }

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
