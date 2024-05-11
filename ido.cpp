#include "ido.h"

void Ido::setTime(int hour, int minute) {
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        throw std::invalid_argument("Invalid time");
    }

    this->hour = hour;
    this->min = minute;
}

void Ido::setHour(int hour) {
    if (hour < 0 || hour > 23) {
        throw std::invalid_argument("Invalid time");
    }

    this->hour = hour;
}

void Ido::setMin(int min) {
    if (min < 0 || min > 59) {
        throw std::invalid_argument("Invalid time");
    }

    this->min = min;
}

Ido Ido::operator+(int min) const {
    Ido newTime = *this;
    newTime += min;
    return newTime;
}

Ido Ido::operator-(int min) const {
    Ido newTime = *this;
    newTime -= min;
    return newTime;
}

Ido& Ido::operator+=(int min) {
    this->hour += (this->min + min) / 60;
    this->min = (this->min + min) % 60;
    this->hour %= 24;
    return *this;
}

Ido& Ido::operator-=(int min) {
    if (this->min < min) {
        this->hour -= 1;
        this->min += 60;
    }

    this->hour -= min / 60;
    this->min -= min % 60;
    if (this->hour < 0) {
        this->hour += 24;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Ido& ido) {
    os << std::setw(2) << std::setfill('0') << ido.getHour() << ":" << std::setw(2) << std::setfill('0') << ido.getMin();
    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Ido& ido) {
    ofs << ido.getHour() << ":" << ido.getMin();
    return ofs;
}

std::istream& operator>>(std::istream& is, Ido& ido) {
    int hour, min;
    char colon;
    is >> hour >> colon >> min;
    if (colon != ':') {
        is.setstate(std::ios_base::failbit);
    } else {
        try{
            ido.setTime(hour, min);
        }
        catch (std::invalid_argument& e) {
            throw std::invalid_argument("Invalid time");
        }
    }

    return is;
}

std::ifstream& operator>>(std::ifstream& ifs, Ido& ido) {
    int hour, min;
    char colon;
    ifs >> hour >> colon >> min;
    if (colon != ':') {
        ifs.setstate(std::ios_base::failbit);
    } else {
        try{
            ido.setTime(hour, min);
        }
        catch (std::invalid_argument& e) {
            throw std::invalid_argument("Invalid time");
        }
    }

    return ifs;
}