#ifndef BME_PROG2_TICKETS_IDO_H
#define BME_PROG2_TICKETS_IDO_H

#include <iostream>
#include <iomanip>

class Ido {
    int min;
    int hour;

public:
    Ido() : hour(0), min(0) {}
    Ido(int hour, int min) : hour(hour), min(min) {}
    Ido(const Ido& other) : hour(other.hour), min(other.min) {}
    void setHour(int hour) { this->hour = hour; }
    void setMin(int min) { this->min = min; }
    int getHour() const { return hour; }
    int getMin() const { return min; }
/*
    Ido& operator=(const Ido& other) {
        if (this == &other) {
            return *this;
        }
        hour = other.hour;
        min = other.min;
        return *this;
    }*/



};

std::ostream& operator<<(std::ostream& os, const Ido& ido) {
    os << std::setw(2) << std::setfill('0')
    << ido.getHour() << ":"
    << std::setfill('0') << std::setw(2) << ido.getMin();
    return os;
}

#endif //BME_PROG2_TICKETS_IDO_H
