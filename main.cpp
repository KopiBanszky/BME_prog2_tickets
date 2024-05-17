#include <iostream>
#include "test.hpp"
#include "menu.h"
#include "vonat.h"
#include "vonat_kezeles.h"
#include "allomas_kezeles.h"
#include "jegy_kezeles.hpp"

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
        }
        ifs2.close();
        if(stations[stations.len() - 1] == Allomas()) {
            stations.pop();
        }
    }

    std::ifstream ifs("vonatok.txt");
    if(ifs.is_open()) {
        int i = 0;
        while(!ifs.eof()) {
            try {
                Vonat vonat;
                ifs >> vonat;
                trains.push_back(vonat);
            }
            catch (const char* msg) {
                std::cout << msg << std::endl;
            }
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
    main_menu.addOption("Kilepes", 'q');

    main_menu.print();
    char choice = main_menu.getChoice();
    bool running = true;
    while (running) {
        if(choice == 'j') {
            InputManage<Jegy> *jegyKezeles = new Jegy_kezeles(trains, stations);
            Jegy jegy = jegyKezeles->getUserData();
            jegy.print();
            delete jegyKezeles;
        } else if(choice == 's') {
            InputManage<Allomas> *allomasKezeles = new AllomasKezeles(trains, stations);
            Allomas allomas = allomasKezeles->getUserData();
            stations.push_back(allomas);
            allomas.print();
            delete allomasKezeles;
        } else if (choice == 'n') {
            InputManage<Vonat>* kezeles = new VonatKezeles(trains, stations);
            Vonat vonat = kezeles->getUserData();
            trains.push_back(vonat);
            vonat.print(std::cout);
            delete kezeles;
        } else if(choice == 'q') {
            running = false;
            break;
        } else {
            std::cout << "Hibas input" << std::endl;
        }
    }

    std::ofstream ofs("vonatok.txt");
    for(auto i = trains.begin(); i != trains.end(); ++i) {
        ofs << *i;
    }
    ofs.close();

    std::ofstream ofs2("allomasok.txt");
    for(auto i = stations.begin(); i != stations.end(); ++i) {
        ofs2 << *i;
    }

#endif

    return 0;
}
