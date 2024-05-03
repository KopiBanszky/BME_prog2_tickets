#include "allomas.h"

int Allomas::search(const String& name) const {
    for(auto i = name.len(); i >= 4; --i) {
        for (auto j = 0; j < this->name.len(); ++j){
            if (name.str_part(0, j) == this->name.str_part(i, i+j))
                return j;
            else if(name.str_part(name.len()-j, name.len()) == this->name.str_part(i, i+j))
                return j;
        }
    }

    return 0;
}