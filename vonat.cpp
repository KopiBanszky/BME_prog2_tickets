#include "vonat.h"

Vonat::Vonat(const char* ID, int capacity = 3) {
    if(strlen(ID) != 6) {
        throw "ID must be 6 characters long";
    }
    this->ID = ID;
    this->capacity = capacity;
}


void Vonat::setID(const String& ID) {
    if(ID.len() != 6) {
        throw "ID must be 6 characters long";
    }
    this->ID = ID;
}

void Vonat::addStation(const Allomas& station, const Ido& departure){
    this->stations.push_back(station);
    this->departures.push_back(departure);
}

void Vonat::removeStation(const Allomas& station){
    for(size_t i = 0; i < stations.len(); i++) {
        if(stations[i] == station) {
            stations.pop(i);
            departures.pop(i);
            return;
        }
    }
}

bool Vonat::isStationIn(const Allomas& station) const {
    for(size_t i = 0; i < stations.len(); i++) {
        if(stations[i] == station) {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Vonat& vonat) {
    os << "Train ID: " << vonat.getID() << std::endl;
    os << "Capacity: " << vonat.getCapacity() << std::endl;
    os << "Stations: " << std::endl;
    for(size_t i = 0; i < vonat.getStations().len(); i++) {
        os << vonat.getStations()[i] << " " << vonat.getDepartures()[i] << std::endl;
    }
    return os;
}