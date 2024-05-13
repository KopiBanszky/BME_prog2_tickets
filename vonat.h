#ifndef BME_PROG2_TICKETS_VONAT_H
#define BME_PROG2_TICKETS_VONAT_H

#include "ido.h"
#include "string.h"
#include "allomas.h"
#include "list.hpp"

class Vonat {
    Vonat(const char *ID, int capacity);

    String ID; //max length 6
    int capacity;
    List<Allomas> stations;
    List<Ido> departures;

public:
    Vonat(String ID, int capacity = 3) : ID(ID), capacity(capacity) {
        if(ID.len() != 6) {
            throw "ID must be 6 characters long";
        }
        this->ID = ID;
        this->capacity = capacity;
    }
    Vonat(const Vonat& other) : ID(other.ID), capacity(other.capacity), stations(other.stations), departures(other.departures) {}
    const String& getID() const { return ID; }
    int getCapacity() const { return capacity; }
    void setID(const String& ID);
    void setCapacity(int capacity) { this->capacity = capacity; }
    void addStation(const Allomas& station, const Ido& departure);
    void removeStation(const Allomas& station);
    bool isStationIn(const Allomas& station) const;
    const List<Allomas>& getStations() const { return stations; }
    const List<Ido>& getDepartures() const { return departures; }


    bool operator==(const Vonat& other) const {
        return ID == other.ID;
    }

    int operator++(int) {
        return capacity++;
    }
    int operator--(int) {
        return capacity--;
    }
    Vonat operator+=(int n) {
        capacity += n;
        return *this;
    }
    Vonat operator-=(int n) {
        capacity -= n;
        return *this;
    }
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
std::ostream& operator<<(std::ostream& os, const Vonat& vonat);

#endif //BME_PROG2_TICKETS_VONAT_H
