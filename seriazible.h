//
// Created by koppany on 5/14/2024.
//

#ifndef BME_PROG2_TICKETS_SERIAZIBLE_H
#define BME_PROG2_TICKETS_SERIAZIBLE_H

#include <iostream>

struct Serializable {
    virtual void write(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
};

#endif //BME_PROG2_TICKETS_SERIAZIBLE_H
