//
// Created by koppany on 5/14/2024.
//
#include "jegy.h"

std::ofstream& operator<<(std::ofstream& ofs, const Jegy& jegy) {
    ofs << jegy.getTrain().getID() << '-' << jegy.getStartStation().getName() << '-' << jegy.getFinalStation().getName() << '-' << jegy.getCarNumber() << '-' << jegy.getCarNumber() << '\n';
    return ofs;
}

void Jegy::print(std::ostream& os) const {
    try {
        os << "Jegy tulajdonosa: " << name << std::endl;
        os << "Vonat: " << train << std::endl;
        os << "Indul�si �llom�s: " << startStation.getName() << std::endl;
        os << "V�g�llom�s: " << finalStation.getName() << std::endl;
        os << "Kocsi sz�ma: " << carNumber << std::endl;
        os << "Sor sz�ma: " << seatNumber << std::endl;
    }
    catch (const char* msg) {
        os << msg << std::endl;
    }
}