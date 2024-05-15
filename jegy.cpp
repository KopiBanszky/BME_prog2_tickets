//
// Created by koppany on 5/14/2024.
//
#include "jegy.h"

std::ofstream& operator<<(std::ofstream& ofs, const Jegy& jegy) {
    ofs << jegy.getTrain().getID() << '-' << jegy.getStartStation().getName() << '-' << jegy.getFinalStation().getName() << '-' << jegy.getCarNumber() << '-' << jegy.getCarNumber() << '\n';
    return ofs;
}
