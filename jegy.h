#ifndef BME_PROG2_TICKETS_JEGY_H
#define BME_PROG2_TICKETS_JEGY_H

#include "string.h"
#include "vonat.h"
#include "allomas.h"

class Jegy{
    String name;
    Vonat& train;
    Allomas& startStation;
    Allomas& finalStation;
    int carNumber;
    int seatNumber;
public:
    Jegy(
        const String& name, 
        Vonat& train,
        Allomas& startStation,
        Allomas& endStation,
        int carNumber, 
        int seatNumber
        ) : name(name), train(train), startStation(startStation), finalStation(endStation), carNumber(carNumber), seatNumber(seatNumber) {}

    // @brief Getter function for the name of the ticket owner
    // @return name of the ticket owner (String)
    const String& getName() const { return name; }

    // @brief Getter function for the train
    // @return train (Vonat)
    const Vonat& getTrain() const { return train; }

    // @brief Getter function for the start station
    // @return start station (Allomas)
    const Allomas& getStartStation() const { return startStation; }

    // @brief Getter function for the final station
    // @return final station (Allomas)
    const Allomas& getFinalStation() const { return finalStation; }

    int getCarNumber() const { return carNumber; }
    int getSeatNumber() const { return seatNumber; }

    // @brief prints the ticket's owner, the train, the start and final stations, the car number and the seat number
    void print(std::ostream& os = std::cout) const {
        try {
            os << "Jegy tulajdonosa: " << name << std::endl;
            os << "Vonat: " << train << std::endl;
            os << "Indulási állomás: " << startStation.getName() << std::endl;
            os << "Végállomás: " << finalStation.getName() << std::endl;
            os << "Kocsi száma: " << carNumber << std::endl;
            os << "Sor száma: " << seatNumber << std::endl;
        }
        catch (const char* msg) {
            os << msg << std::endl;
        }
    }

};

std::ofstream& operator<<(std::ofstream& ofs, const Jegy& jegy);
std::ifstream& operator>>(std::ifstream& ifs, Jegy& jegy);

#endif //BME_PROG2_TICKETS_JEGY_H
