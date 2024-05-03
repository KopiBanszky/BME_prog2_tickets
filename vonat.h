#ifndef BME_PROG2_TICKETS_VONAT_H
#define BME_PROG2_TICKETS_VONAT_H

#include "ido.h"
#include "string.h"
#include "allomas.h"

class Vonat {
    String ID; //max length 6
    int capacity;
    List<Allomas> stations;
    List<Ido> departures;

public:



};

#endif //BME_PROG2_TICKETS_VONAT_H
