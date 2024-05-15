//
// Created by koppany on 5/14/2024.
//

#ifndef BME_PROG2_TICKETS_MENU_H
#define BME_PROG2_TICKETS_MENU_H

#include "string.h"
#include "list.hpp"

//@brief Menu class
//@details A class that represents a menu with options and hotkeys, it can be printed and the user can choose an option
class Menu {
    List<String> options;
    List<char> hotkeys;
    String title;
public:
    Menu(const String& title) : title(title) {}

    // @brief Adds an option to the menu
    // @param option the text of the option
    // @param hotkey the hotkey of the option
    void addOption(const String& option, char hotkey) {
        options.push_back(option);
        hotkeys.push_back(hotkey);
    }

    // @brief prints the menu to the console
    void print() const {

        std::cout << "\n\n" << title << "\n" << std::endl;
        for (int i = 0; i < options.len(); i++) {
            std::cout << '[' << hotkeys[i] << "] - " << options[i] << std::endl;
        }
        std::cout << std::endl;
    }

    // @brief gets the choice of the user, gets the last character from the input before enter
    // @return the hotkey of the chosen option
    char getChoice() const {
        char choice;
        std::cin >> choice;
        return choice;
    }


    Menu& operator=(const Menu& other) {
        options = other.options;
        hotkeys = other.hotkeys;
        title = other.title;
        return *this;
    }

    Menu& operator=(const String& title) {
        this->title = title;
        return *this;
    }

    Menu& operator=(const char* title) {
        this->title = title;
        return *this;
    }
};

#endif //BME_PROG2_TICKETS_MENU_H
