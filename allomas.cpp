#include "allomas.h"

Allomas Allomas::search(const String& name) const {
    for(auto i = name.len(); i >= 4; --i) {
        for (auto j = this->name.begin(); j != this->name.end(); ++j){
            if (name.str_part(0, j) == this->name.str_part(i, i+j))
                return Allomas(name.str_part(0, j));
        }
    }

    return Allomas("");
}
