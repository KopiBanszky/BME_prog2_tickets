//
// Created by koppany on 5/14/2024.
//

#include "string.h"


// @brief prints the string to the output stream
// @param os output stream
// @param str string
// @return output stream
std::ostream &operator<<(std::ostream &os, const String &str) {
    os << str.c_str();
    return os;
}

std::ofstream &operator<<(std::ofstream &ofs, const String &str) {
    str.forEach([&ofs](char c) {
        ofs << c;
    });
    return ofs;
}

// @brief reads the string from the input stream by line
// @describe it has a limitation, it can't read lines longer than 100 same characters
// @param is input stream
// @param str string
// @return input stream
std::ifstream &operator>>(std::ifstream &ifs, String &str) {
    char buffer[100];
    int i = 1;
    char c;
    c = ifs.get();
    buffer[0] = c;
    while (c != '\n' || ifs.eof() || ifs.fail() || ifs.bad() || c == '\0' || c == '\r' || c==EOF) {
        str += c;

        c = ifs.get();
        if(buffer[0] != c){
            i = 0;
        } else if(i == 100) {
            str = "";
            break;
        }
        buffer[i] = c;
        i++;
    }
    std::cout << "String: " << str << std::endl;
    return ifs;
}

// @brief reads the string from the input stream by word
// @param is input stream
// @param str string
// @return input stream
std::istream &operator>>(std::istream &is, String &str) {
    char ch;
    str = String("");            // üres string, ehhez fűzünk hozzá
    std::ios_base::fmtflags fl = is.flags(); // eltesszük a régi flag-eket
    is.setf(std::ios_base::skipws);            // az elején eldobjuk a ws-t
    while (is >> ch) {
        is.unsetf(std::ios_base::skipws);    // utána pedig már nem
        if (isspace(ch)) {
            is.putback(ch);             // na ezt nem kérjük
            break;
        } else {
            str += ch;               // végére fűzzük a karaktert
        }
    }
    is.setf(fl);                        // visszaállítju
    return is;
}

