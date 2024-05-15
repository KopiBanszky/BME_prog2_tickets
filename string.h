#ifndef BME_PROG2_TICKETS_STRING_H
#define BME_PROG2_TICKETS_STRING_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "list.hpp"

class String {
    char *data;
    size_t length;
public:
    String() {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }

    String(const char *str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    String(const String &other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    ~String() {
        delete[] data;
    }

    // @brief Returns the length of the string
    // @return length of the string (size_t)
    size_t len() const {
        return length;
    }

    String& toLowerCase() {
        for (size_t i = 0; i < length; i++) {
            if (data[i] >= 'A' && data[i] <= 'Z') {
                data[i] += 32;
            }
        }
        return *this;
    }

    String& toUpperCase() {
        for (size_t i = 0; i < length; i++) {
            if (data[i] >= 'a' && data[i] <= 'z') {
                data[i] -= 32;
            }
        }
        return *this;
    }

    // @brief cpy operator
    // @param other string to copy
    // @return reference to the new string
    String &operator=(const String &other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
        return *this;
    }

    // @brief cpy operator
    // @param other string to copy
    // @return reference to the new string
    String &operator=(const char *other) {
        delete[] data;
        length = strlen(other);
        data = new char[length + 1];
        strcpy(data, other);
        return *this;
    }


    // @brief adds two strings, the rhs is added to the end of the lhs
    // @param other string to add
    // @return new string
    String &operator+=(const String &other) {
        size_t new_length = length + other.length;
        char *newStr = new char[new_length + 1];
        strcpy(newStr, data);
        strcat(newStr, other.data);

        length = new_length;
        delete[] data;
        data = newStr;

        return *this;
    }

    // @brief adds a string to the end of the current string
    // @param other string to add
    // @return new string
    String &operator+=(const char *other) {
        size_t other_length = strlen(other);
        size_t new_length = length + other_length;
        char *new_data = new char[new_length + 1];
        strcpy(new_data, data);
        strcat(new_data, other);

        length = new_length;
        delete[] data;
        data = new_data;

        return *this;
    }

    // @brief adds a character to the end of the current string
    // @param c character to add
    // @return new string
    String operator+=(char c) {
        size_t new_length = length + 1;
        char *new_data = new char[new_length + 1];
        strcpy(new_data, data);
        new_data[new_length - 1] = c;
        new_data[new_length] = '\0';

        length = new_length;
        delete[] data;
        data = new_data;

        return *this;
    }

    // @brief compares two strings
    // @param other string to compare
    // @return true if the strings are equal, false otherwise
    bool operator==(const String &other) const {
        return strcmp(data, other.data) == 0;
    }

    // @brief compares a string to a char array
    // @param other char array to compare
    // @return true if the strings are equal, false otherwise
    bool operator==(const char *other) const {
        return strcmp(data, other) == 0;
    }

    // @brief compares two strings
    // @param other string to compare
    // @return true if the strings are not equal, false otherwise
    bool operator!=(const String &other) const {
        return !(*this == other);
    }

    // @brief compares a string to a char array
    // @param other char array to compare
    // @return true if the strings are not equal, false otherwise
    bool operator!=(const char *other) const {
        return !(*this == other);
    }

    // @brief index operator
    // @param index index of the character
    // @return character at the given index
    char operator[](size_t index) const {
        if(index >= length)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    // @brief index operator
    // @param index index of the character
    // @return character at the given index
    char operator[](size_t index) {
        if(index >= length)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    // @brief returns a substring of the string
    // @param begin beginning of the substring
    // @param end  end of the substring
    String str_part(size_t begin, size_t end) const {
        size_t size = end - begin;
        String result = "";
        for (size_t i = 0; i < size; i++) {
            result += data[begin + i];
        }
        return result;
    }

    // @brief gives the c string
    // @return c string
    char *c_str() const {
        return data;
    }

    // @brief cycle through the string
    // @param pred function to apply to each character
    template<typename T>
    void forEach(T pred) const {
        for (size_t i = 0; i < length; i++) {
            pred(data[i]);
        }
    }

    List<String> split(char divider) const {
        List<String> result;
        String current = "";
        for (size_t i = 0; i < length; i++) {
            if (data[i] == divider || i == length - 1) {
                if (i == length - 1) {
                    if(data[i] != divider)
                        current += data[i];
                }
                result.push_back(current);
                current = "";
            } else {
                current += data[i];
            }
        }
        if (result.len() == 0) {
            result.push_back(current);
        }
        return result;
    }

    bool isEmpty() const {
        return length == 0 || data[0] == '\0' || data == nullptr || (data[0] == '\n' && length == 1);
    }

    // @brief converts the string to an integer.
    // @describe It removes all non digit characters from the string and converts the remaining part to an integer.
    // @return integer
    int toInt() const {
        int result = 0;
        for (size_t i = 0; i < length; i++) {
            if (data[i] >= '0' && data[i] <= '9') {
                result = result * 10 + (data[i] - '0');
            }
        }
        return result;
    }

};

std::ostream &operator<<(std::ostream &os, const String &str);
std::istream &operator>>(std::istream &is, String &str);
std::ofstream &operator<<(std::ofstream &ofs, const String &str);
std::ifstream &operator>>(std::ifstream &ifs, String &str);

#endif //BME_PROG2_TICKETS_STRING_H
