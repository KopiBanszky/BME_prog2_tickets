#ifndef BME_PROG2_TICKETS_ALLOMAS_H
#define BME_PROG2_TICKETS_ALLOMAS_H
#include "string.h"
#include "list.hpp"
#include "ido.h"
#include <iostream>
#include <fstream>

class Allomas{
    String name;
    List<String> trainsID;

public:
    Allomas() : name() {}
    Allomas(const String& name) : name(name) {}

    // @brief Getter function for the name of the station
    // @return name of the station
    const String& getName() const { return name; }

    // @brief Setter function for the name of the station
    // @param name of the station
    void setName(const String& name) { this->name = name; }

    void setName(const char* name) { this->name = name; }

    // @brief Getter function for the trains that stop at the station
    // @return list of train IDs
    const List<String>& getTrains() const { return trainsID; }

    // @brief Adds a train to the list of trains that stop at the station
    // @param trainID ID of the train (String)
    void addTrain(const String& trainID/*, const Ido& departureTime*/);

    // @brief Removes a train from the list of trains that stop at the station
    // @param trainID ID of the train (String)
    void removeTrain(const String& trainID);

    // @brief searches for a match in the name of the station
    // @param name of the station (String)
    // @return index of the match
    int search(const String& name) const;

    // @brief searches for a train that stops at the station
    // @param time departure time of the train (Ido)
    // @return index of the train
//    int findTrain(const Ido& time) const;

    // @brief searches for a train that stops at the station
    // @param ID of the train (String)
    // @return index of the train
    int findTrain(const String& ID) const;


    // @brief prints the station's name and the trains' ID that stop at the station
    // @return void
    void print() const;

    // @brief equality operator, compares the names of the stations
    // @param rhs station
    // @return true if the names are equal, false otherwise
    bool operator==(const Allomas& rhs) const;

    // @brief inequality operator, compares the names of the stations
    // @param rhs station
    // @return true if the names are not equal, false otherwise
    bool operator!=(const Allomas& rhs) const;

    // @brief indexer operator
    // @param index index of the train
    // @return train ID
    String& operator[](size_t index) {
        return trainsID[index];
    }

    // @brief indexer operator
    // @param index index of the train
    // @return train ID
    String& operator[](size_t index) const {
        return trainsID[index];
    }
};

std::ostream& operator<<(std::ostream& os, const Allomas& allomas);
std::ofstream& operator<<(std::ofstream& ofs, const Allomas& allomas);
std::istream& operator>>(std::istream& is, Allomas& allomas);
std::ifstream& operator>>(std::ifstream& ifs, Allomas& allomas);

#endif //BME_PROG2_TICKETS_ALLOMAS_H
