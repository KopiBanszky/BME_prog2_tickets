#include "vonat.h"

Vonat::Vonat(const char* ID, int capacity = 3) {
    if(strlen(ID) != 6) {
        throw "ID must be 6 characters long";
    }
    this->ID = ID;
    this->capacity = capacity;
}

Vonat::Vonat(String ID, int capacity = 3) {
    if(ID.len() != 6) {
        throw "ID must be 6 characters long";
    }
    this->ID = ID;
    this->capacity = capacity;
}


void Vonat::setID(const String& ID) {
    if(ID.len() != 6) {
        throw "ID must be 6 characters long";
    }
    this->ID = ID;
}

void Vonat::addStation(const Allomas& station, const Ido& departure){
    this->stations.push_back(station);
    this->departures.push_back(departure);
}

void Vonat::removeStation(const Allomas& station){
    for(size_t i = 0; i < stations.len(); i++) {
        if(stations[i] == station) {
            stations.pop(i);
            departures.pop(i);
            return;
        }
    }
}

void Vonat::print(std::ostream& os) const  {
    os << "Vonat ID: " << ID << std::endl;
    os << "Kapacitás: " << capacity << std::endl;
    os << "Allomások: ";
    for (size_t i = 0; i < stations.len(); ++i) {
        os << stations[i].getName() << " ";
    }
    std::cout << std::endl;
    std::cout << "Indulások: ";
    for (size_t i = 0; i < departures.len(); ++i) {
        std::cout << departures[i] << " ";
    }
    std::cout << std::endl;

}

bool Vonat::isStationIn(const Allomas& station) const {
    for(size_t i = 0; i < stations.len(); i++) {
        if(stations[i] == station) {
            return true;
        }
    }
    return false;
}

size_t Vonat::stationIndex(const Allomas& station) const {
    for(size_t i = 0; i < stations.len(); i++) {
        if(stations[i] == station) {
            return i;
        }
    }
    return -1;
}

std::ostream& operator<<(std::ostream& os, const Vonat& vonat) {
    os << vonat.getID();
    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Vonat& vonat) {
    ofs << vonat.getID() << '.' << vonat.getCapacity() << '-';
    for (size_t i = 0; i < vonat.getStations().len(); ++i) {
        ofs << vonat.getStations()[i].getName() << '_' << vonat.getDepartures()[i];
            ofs << ';';
    }
    ofs << '\n';
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Vonat& vonat){
    String line;
    ifs >> line;
    List<String> splitByLine = line.split('-');
    List<String> metadata = splitByLine[0].split('.');
    vonat.setID(metadata[0]);
    vonat.setCapacity(metadata[1].toInt());
    if(splitByLine.len() < 2)
        return ifs;
    List<String> stations = splitByLine[1].split(';');
    for(size_t i = 0; i < stations.len(); i++) {
        List<String> stationAndTime = stations[i].split('_');
        vonat.addStation(Allomas(stationAndTime[0]), Ido(stationAndTime[1]));
    }
    return ifs;
}

std::istream& operator>>(std::istream& is, Vonat& vonat) {
    String ID;
    int capacity;
    is >> ID;
    if(ID.len() != 6) {
        throw "ID must be 6 characters long";
    }
    std::cout << "Kapacitas: ";
    is >> capacity;
    vonat.setID(ID);
    vonat.setCapacity(capacity);
    return is;
}
