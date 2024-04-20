//
// Created by pityu on 2024. 04. 20..
//

#ifndef BME_PROG2_TICKETS_TIME_H
#define BME_PROG2_TICKETS_TIME_H

#include <iostream>

class Ido {
    int hour;
    int min;

public:
    Ido(int h, int m) : hour(h), min(m) {}
    Ido() : hour(0), min(0) {}

    int getHour() const {
        return hour;
    }

    int getMin() const {
        return min;
    }

    void setHour(int h) {
        hour = h;
    }

    void setMin(int m) {
        min = m;
    }

    void print() const {
        std::cout << hour << ":" << min;
    }

    bool operator<(const Ido& rhs) const {
        if (hour < rhs.hour) {
            return true;
        }
        if (hour == rhs.hour) {
            return min < rhs.min;
        }
        return false;
    }

    bool operator==(const Ido& rhs) const {
        return hour == rhs.hour && min == rhs.min;
    }

    bool operator>(const Ido& rhs) const {
        return !(*this < rhs) && !(*this == rhs);
    }

    bool operator<=(const Ido& rhs) const {
        return *this < rhs || *this == rhs;
    }

    bool operator>=(const Ido& rhs) const {
        return *this > rhs || *this == rhs;
    }
};

#endif //BME_PROG2_TICKETS_TIME_H
