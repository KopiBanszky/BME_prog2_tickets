#ifndef BME_PROG2_TICKETS_ALLOMAS_H
#define BME_PROG2_TICKETS_ALLOMAS_H

#include "vonat.h"
#include "list.h"


class Allomas {
    String name;
    List<Vonat> vonatok;

public:
    Allomas(const String& name) : name(name) {}
    void addVonat(const Vonat& vonat) { vonatok.push_back(vonat); }
    const String& getName() const { return name; }
    const List<Vonat>& getVonat() const { return vonatok; }

    Allomas search(const String& name) const;

    friend std::ostream& operator<<(std::ostream& os, const Allomas& allomas) {
        os << allomas.getName();
        return os;
    }
};

#endif //BME_PROG2_TICKETS_ALLOMAS_H
