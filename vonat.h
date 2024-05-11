
#ifndef BME_PROG2_TICKETS_VONAT_H
#define BME_PROG2_TICKETS_VONAT_H


#include "ido.h"
#include "string.h"
#include "list.hpp"
#include "allomas.h"


class Vonat{
    String ID; //max length 6
    int capacity;
    List<Allomas> stations;
    List<Ido> departures;

public:
    // @brief Constructor, sets the ID and the capacity. Stations and departures are empty.
    Vonat(String ID, int capacity);
    Vonat(char const* ID, int capacity);
    Vonat(const Vonat& other) : ID(other.ID), capacity(other.capacity), stations(other.stations), departures(other.departures) {}

    // @brief Getter function for the ID of the train
    // @return ID of the train (String)
    const String& getID() const { return ID; }

    // @brief Getter function for the capacity of the train
    // @return capacity of the train (int)
    int getCapacity() const { return capacity; }

    // @brief Setter function for the ID of the train
    // @param ID ID of the train (String)
    void setID(const String& ID);

    // @brief Setter function for the capacity of the train
    // @param capacity capacity of the train (int)
    void setCapacity(int capacity) { this->capacity = capacity; }

    // @brief Adds a station to the list of stations and a departure time to the list of departures. Both are added to the end of the lists.
    // @param station station to add (Allomas)
    // @param departure departure time to add (Ido)
    void addStation(const Allomas& station, const Ido& departure);

    // @brief Removes a station from the list of stations and the corresponding departure time from the list of departures.
    // @param station station to remove (Allomas)
    void removeStation(const Allomas& station);

    // @brief Searches for a station in the list of stations
    // @param station station to search for Allomas by name
    // @return true if the station is in the list, false otherwise
    bool isStationIn(const Allomas& station) const;

    // @brief getter function for the list of stations
    // @return list of stations (List<Allomas>)
    const List<Allomas>& getStations() const { return stations; }

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
};

// @brief prints the ID of the train to the output stream
// @param os output stream
// @param vonat train
// @return output stream
std::ostream& operator<<(std::ostream& os, const Vonat& vonat);

#endif //BME_PROG2_TICKETS_VONAT_H
