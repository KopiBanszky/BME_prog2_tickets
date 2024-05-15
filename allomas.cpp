#include "allomas.h"

int Allomas::search(const String& name) const {
    for(size_t i = name.len(); i >= 4; --i) {
        for (size_t j = 0; j < this->name.len(); ++j){
            if (name.str_part(0, j) == this->name.str_part(i, i+j))
                return j;
            else if(name.str_part(name.len()-j, name.len()) == this->name.str_part(i, i+j))
                return j;
        }
    }

    return 0;
}

void Allomas::addTrain(const String& trainID) {
    trainsID.push_back(trainID);
}

void Allomas::removeTrain(const String& trainID) {
    trainsID.pop(trainID);
}

int Allomas::findTrain(const String& trainID) const {
    for (size_t i = 0; i < trainsID.len(); ++i) {
        if (trainsID[i] == trainID) {
            return i;
        }
    }

    return -1;
}

void Allomas::print() const {
    std::cout << name << ": ";
    for (size_t i = 0; i < trainsID.len(); ++i) {
        std::cout << trainsID[i];
        if(i != trainsID.len()-1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

bool Allomas::operator==(const Allomas& rhs) const {
    return name == rhs.name;
}

std::ostream& operator<<(std::ostream& os, const Allomas& allomas) {
    os << allomas.getName();
    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const Allomas& allomas) {
    ofs << allomas.getName() << '-';
    for (size_t i = 0; i < allomas.getTrains().len(); ++i) {
        ofs << allomas.getTrains()[i];
        ofs << ',';
    }
    ofs << '\n';
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Allomas& allomas) {
    String line;
    ifs >> line;
    List<String> splitByLine = line.split('-');
    allomas.setName(splitByLine[0]);
    if(splitByLine.len() < 2)
        return ifs;
    List<String> stations = splitByLine[1].split(',');
    for(auto i = stations.begin(); i != stations.end(); ++i) {
        allomas.addTrain(*i);
    }
    return ifs;
}

std::istream& operator>>(std::istream& is, Allomas& allomas) {
    String temp;
    is >> temp;
    allomas.setName(temp);
    /* Nem tudom miért csináltam ezt meg
    List<String> stations;
    is >> temp;
    while (!temp.isEmpty()) {
        stations.push_back(temp);
        is >> temp;
    }
    for(auto i = stations.begin(); i != stations.end(); ++i) {
        allomas.addTrain(*i);
    } */
    return is;
}