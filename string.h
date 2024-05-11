#ifndef BME_PROG2_TICKETS_STRING_H
#define BME_PROG2_TICKETS_STRING_H

#include <iostream>
#include <cstring>

class String {
    char* data;
    size_t length;
public:
    String() {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }

    String(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    String(const String& other) {
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

    // @brief cpy operator
    // @param other string to copy
    // @return reference to the new string
    String& operator=(const String& other) {
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
    String& operator=(const char* other) {
        delete[] data;
        length = strlen(other);
        data = new char[length + 1];
        strcpy(data, other);
        return *this;
    }

    // @brief prints the string to the output stream
    // @param os output stream
    // @param str string
    // @return output stream
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }

    // @brief adds two strings, the rhs is added to the end of the lhs
    // @param other string to add
    // @return new string
    String& operator+=(const String& other) {
        size_t new_length = length + other.length;
        char* newStr = new char[new_length + 1];
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
    String& operator+=(const char* other) {
        size_t other_length = strlen(other);
        size_t new_length = length + other_length;
        char* new_data = new char[new_length + 1];
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
        char* new_data = new char[new_length + 1];
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
    bool operator==(const String& other) const {
        return strcmp(data, other.data) == 0;
    }

    // @brief compares a string to a char array
    // @param other char array to compare
    // @return true if the strings are equal, false otherwise
    bool operator==(const char* other) const {
        return strcmp(data, other) == 0;
    }

    // @brief compares two strings
    // @param other string to compare
    // @return true if the strings are not equal, false otherwise
    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    // @brief compares a string to a char array
    // @param other char array to compare
    // @return true if the strings are not equal, false otherwise
    bool operator!=(const char* other) const {
        return !(*this == other);
    }

    // @brief index operator
    // @param index index of the character
    // @return character at the given index
    char operator[](size_t index) const {
        return data[index];
    }

    // @brief index operator
    // @param index index of the character
    // @return character at the given index
    char operator[](size_t index) {
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
    const char* c_str() const {
        return data;
    }

};

#endif //BME_PROG2_TICKETS_STRING_H
