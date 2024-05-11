#ifndef BME_PROG2_TICKETS_IDO_H
#define BME_PROG2_TICKETS_IDO_H

#include <iostream>
#include <iomanip>

class Ido {
    int hour;
    int min;

public:
    // @brief Default constructor, sets the hour and minute to 0
    Ido() : hour(0), min(0) {}
    Ido(int hour, int min) : hour(hour), min(min) {}
    Ido(const Ido& other) : hour(other.hour), min(other.min) {}

    // @brief sets the hour
    // @param hour (int)
    void setHour(int hour) { this->hour = hour; }

    // @brief sets the minute
    // @param min (int)
    void setMin(int min) { this->min = min; }

    // @brief gives the hour
    // @return hour (int)
    int getHour() const { return hour; }

    // @brief gives the minute
    // @return minute (int)
    int getMin() const { return min; }

};

// @brief prints the time to the output stream (format: HH:MM)
// @param os output stream
// @param ido time
// @return output stream
std::ostream& operator<<(std::ostream& os, const Ido& ido);

#endif //BME_PROG2_TICKETS_IDO_H
