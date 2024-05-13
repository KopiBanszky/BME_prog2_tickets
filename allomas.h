#ifndef BME_PROG2_TICKETS_ALLOMAS_H
#define BME_PROG2_TICKETS_ALLOMAS_H

#include "vonat.h"
#include "list.hpp"


class Allomas {
    String name;
    List<Vonat> trains;

public:
    Allomas(const String& name) : name(name) {}
    void addVonat(const Vonat& vonat) { trains.push_back(vonat); }
    const String& getName() const { return name; }
    const List<Vonat>& getTrains() const { return trains; }
    void addTrain(const Vonat& train) { trains.push_back(train); }
    void removeTrain(const Vonat& train) { trains.pop(train); }

    int search(const String& name) const;
    int findTrain(const Ido& time) const;
    int findTrain(const String& ID) const;

    void print()  {
    }

    friend std::ostream& operator<<(std::ostream& os, const Allomas& allomas) {
        os << allomas.getName();
        return os;
    }

    bool operator==(const Allomas& other) const {
        return name == other.name;
    }

};

#endif //BME_PROG2_TICKETS_ALLOMAS_H
