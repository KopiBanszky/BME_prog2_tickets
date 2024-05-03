#ifndef BME_PROG2_TICKETS_VONAT_H
#define BME_PROG2_TICKETS_VONAT_H

#include "ido.h"
#include "string.h"
#include "allomas.h"
#include "list.h"

class Vonat {
    String ID; //max length 6
    int capacity;
    List<Allomas> stations;
    List<Ido> departures;

public:
    Vonat(String ID, int capacity) : ID(ID), capacity(capacity) {}
    Vonat(const Vonat& other) : ID(other.ID), capacity(other.capacity), stations(other.stations), departures(other.departures) {}
    const String& getID() const { return ID; }
    int getCapacity() const { return capacity; }
    void setID(const String& ID) { this->ID = ID; } //TODO: limit length to 6
    void setCapacity(int capacity) { this->capacity = capacity; }
    void addStation(const Allomas& station, const Ido& departure) { stations.push_back(station); departures.push_back(departure); }
    void removeStation(const Allomas& station) { stations.pop(station); } //TODO: remove departure time as well
    bool isStationIn(const Allomas& station) const { return stations.search(station) != -1; }
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
std::ostream& operator<<(std::ostream& os, const Vonat& vonat) {
    os << vonat.getID();
    return os;
}

#endif //BME_PROG2_TICKETS_VONAT_H
