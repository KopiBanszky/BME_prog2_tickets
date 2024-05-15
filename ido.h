#ifndef BME_PROG2_TICKETS_IDO_H
#define BME_PROG2_TICKETS_IDO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "string.h"

class Ido {
    int hour;
    int min;

public:
    // @brief Default constructor, sets the hour and minute to 0
    Ido() : hour(0), min(0) {}
    Ido(int hour, int min) : hour(hour), min(min) {}
    Ido(const Ido& other) : hour(other.hour), min(other.min) {}
    Ido(String str);

    // @brief sets the hour
    // @param hour (int)
    void setHour(int hour);

    // @brief sets the minute
    // @param min (int)
    void setMin(int min);

    // @brief gives the hour
    // @return hour (int)
    int getHour() const { return hour; }

    // @brief gives the minute
    // @return minute (int)
    int getMin() const { return min; }

    // @brief sets the time
    // @param hour (int)
    // @param minute (int)
    void setTime(int hour, int minute);

    //@brief equality operator
    // @param other Ido
    // @return true if the hours and minutes are equal
    bool operator==(const Ido& other) const { return hour == other.hour && min == other.min; }

    // @brief inequality operator
    // @param other Ido
    // @return true if the hours and minutes are not equal
    bool operator!=(const Ido& other) const { return hour != other.hour || min != other.min; }

    // @brief add operator, adds the minutes to the time, if needed, increases the hour
    // @param min minutes to add
    // @return new time
    Ido operator+(int min) const;

    // @brief subtract operator, subtracts the minutes from the time, if needed, decreases the hour, it is not possible to subtract more than the current time
    // @param min minutes to subtract
    // @return new time
    Ido operator-(int min) const;

    // @brief add equal operator, adds the minutes to the time, if needed, increases the hour
    // @param min minutes to add
    // @return reference to the new time
    Ido& operator+=(int min);

    // @brief subtract equal operator, subtracts the minutes from the time, if needed, decreases the hour, it is not possible to subtract more than the current time
    // @param min minutes to subtract
    // @return reference to the new time
    Ido& operator-=(int min);
};

// @brief prints the time to the output stream (format: HH:MM)
// @param os output stream
// @param ido time
// @return output stream
std::ostream& operator<<(std::ostream& os, const Ido& ido);

// @brief prints this time to the ofstream (format: HH:MM)
// @param ofs output file stream
// @return void
std::ofstream& operator<<(std::ofstream& ofs, const Ido& ido);

// @brief reads the time from the input stream (format: hour:minute)
// @param is input stream
// @param ido time
// @return input stream
std::istream& operator>>(std::istream& is, Ido& ido);

// @brief reads the time from the input file stream (format: hour:minute)
// @param ifs input file stream
// @param ido time
// @return input file stream
std::ifstream& operator>>(std::ifstream& ifs, Ido& ido);


#endif //BME_PROG2_TICKETS_IDO_H
