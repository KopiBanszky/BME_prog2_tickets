
#ifndef BME_PROG2_TICKETS_VONAT_H
#define BME_PROG2_TICKETS_VONAT_H


#include "ido.h"
#include "string.h"
#include "list.hpp"
#include "allomas.h"

class Vonat {
    String ID; //max length 6
    int capacity;
    List<Allomas> stations;
    List<Ido> departures;

public:
    Vonat() : ID(), capacity(3) {};
    Vonat(const char* ID, int capacity);
    Vonat(String ID, int capacity);
    Vonat(const Vonat& other) : ID(other.ID), capacity(other.capacity), stations(other.stations), departures(other.departures) {}

    // @brief Getter function for the ID of the train
    // @return ID of the train (String)
    const String& getID() const { return ID; }

    // @brief Getter function for the capacity of the train
    // @return capacity of the train (int)
    int getCapacity() const { return capacity; }
    void setID(const String& ID);
    void setCapacity(int capacity) { this->capacity = capacity; };
    void addStation(const Allomas& station, const Ido& departure);
    void removeStation(const Allomas& station);
    bool isStationIn(const Allomas& station) const;

    size_t stationIndex(const Allomas& station) const;


    const List<Allomas>& getStations() const { return stations; }
    List<Allomas>& getStations() { return stations; }

    // @brief getter function for the list of departures
    // @return list of departures (List<Ido>)
    const List<Ido>& getDepartures() const { return departures; }

    // @brief equality operator, compares the IDs of the trains
    // @param other train
    // @return true if the IDs are equal, false otherwise
    bool operator==(const Vonat& other) const {
        return ID == other.ID;
    }

    // @brief Postincrement operator
    // @return the capacity of the train after the increment
    int operator++(int) {
        return capacity++;
    }

    // @brief Postdecrement operator
    // @return the capacity of the train after the decrement
    int operator--(int) {
        return capacity--;
    }

    // @brief add n to the capacity of the train
    // @param n number to add
    // @return the train with the new capacity
    Vonat operator+=(int n) {
        capacity += n;
        return *this;
    }

    // @brief subtract n from the capacity of the train
    // @param n number to subtract
    // @return the train with the new capacity
    Vonat operator-=(int n) {
        capacity -= n;
        return *this;
    }

    // @brief cpy operator
    // @param other train to copy
    // @return new train
    Vonat operator=(const Vonat& other) {
        if (this == &other) {
            return *this;
        }
        ID = other.ID;
        capacity = other.capacity;
        stations = other.stations;
        departures = other.departures;
        return *this;
    }

    void print(std::ostream& os = std::cout) const;

};
std::ostream& operator<<(std::ostream& os, const Vonat& vonat);
std::ofstream& operator<<(std::ofstream& ofs, const Vonat& vonat);
std::ifstream& operator>>(std::ifstream& ifs, Vonat& vonat);
std::istream& operator>>(std::istream& is, Vonat& vonat);

#endif //BME_PROG2_TICKETS_VONAT_H
