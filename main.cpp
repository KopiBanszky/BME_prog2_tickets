#include <iostream>
#include "ido.h"

//TODO: DELEGATE DEFINITIONS TO .CPP FILES

int main() {
    std::cout << "Hello, World!" << std::endl;

    Ido test[3] = {Ido(12, 30), Ido(13, 45), Ido(14, 0)};

    for (auto i = std::begin(test); i != std::end(test); ++i) {
        std::cout << *i << std::endl;
    }

    return 0;
}
