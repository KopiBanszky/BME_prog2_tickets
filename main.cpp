#include <iostream>
#include "test.hpp"
#include "menu.h"
#include "vonat.h"

//TODO: DELEGATE DEFINITIONS TO .CPP FILES

#define MEMTRACE

int main() {
#ifdef CPORTA
    run_tests();
#else

    //"adatbázis" beolvasása
    List<Vonat> trains;
    List<Allomas> stations;


    std::ifstream ifs2("allomasok.txt");
    if(ifs2.is_open()) {
        while(!ifs2.eof()) {
            Allomas allomas;
            ifs2 >> allomas;
            stations.push_back(allomas);
            std::cout << allomas << std::endl;
        }
        ifs2.close();
    }

    std::ifstream ifs("vonatok.txt");
    if(ifs.is_open()) {
        int i = 0;
        while(!ifs.eof()) {
            try {
                Vonat vonat;
                ifs >> vonat;
                trains.push_back(vonat);
                std::cout << vonat << std::endl;
            }
            catch (const char* msg) {
                std::cout << msg << std::endl;
            }
            /*Vonat vonat;
            ifs >> vonat;
            trains.push_back(vonat);
            std::cout << vonat << std::endl;*/
        }
        ifs.close();
    }

    for(auto station = stations.begin(); station != stations.end(); station++) {
        for (auto train = trains.begin(); train != trains.end(); ++train) {

            Vonat& iter = *train;
            size_t index = iter.stationIndex(*station);
            if(index > -1) {
                iter.getStations()[index] = *station;
            }

        }

    }

    Menu main_menu = Menu("Fomenu");
    main_menu.addOption("Jegyvasarlas", 'j');
    main_menu.addOption("Vonat felvetele", 'n');
    main_menu.addOption("Allomas felvetele", 's');

    main_menu.print();
    char choice = main_menu.getChoice();

    switch (choice) {
        case 'j':
            std::cout << "Jegyvasarlas" << std::endl;
            break;
        case 'n':
            std::cout << "Vonat felvetele" << std::endl;
            std::for_each(trains.begin(), trains.end(), [](Vonat& vonat) { std::cout << vonat << std::endl; });
            break;
        case 's':
            std::ofstream openFile("vonatok.txt", std::ios::app);
            if(openFile.is_open()) {
                Vonat vonat;
                try {
                    std::cin >> vonat;

                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                    std::cin >> vonat;
                }
                openFile << vonat;
                openFile.close();
            }
            break;
    }

#endif

    return 0;
}
