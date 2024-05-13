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

