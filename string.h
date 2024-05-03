#ifndef BME_PROG2_TICKETS_STRING_H
#define BME_PROG2_TICKETS_STRING_H

#include <iostream>
#include <cstring>

class String {
    char* data;
    size_t length;
public:
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

    size_t len() const {
        return length;
    }

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

    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }

    String operator+=(const String& other) const {
        size_t new_length = length + other.length;
        char* new_data = new char[new_length + 1];
        strcpy(new_data, data);
        strcat(new_data, other.data);
        return String(new_data);
    }
    String operator+=(const char* other) const {
        size_t other_length = strlen(other);
        size_t new_length = length + other_length;
        char* new_data = new char[new_length + 1];
        strcpy(new_data, data);
        strcat(new_data, other);
        return String(new_data);
    }

    class iterator {
        char *current;
    public:
        iterator(char *current = NULL) : current(current) {}

        char& operator*() {
            return *current;
        }

        iterator& operator++() {
            if(current != NULL)
                current++;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            if(current != NULL)
                current++;
            return temp;
        }

        iterator operator--() {
            if(current != NULL)
                current--;
            return *this;
        }

        iterator operator--(int) {
            iterator temp = *this;
            if(current != NULL)
                current--;
            return temp;
        }

        char& operator*() const {
            return *current;
        }

        bool operator==(const iterator& rhs) {
            return current == rhs.current;
        }

        bool operator!=(const iterator& rhs) {
            return current != rhs.current;
        }
    };

    char operator[](size_t index) const {
        return data[index];
    }

    String str_part(size_t begin, size_t end) const {
        size_t size = end - begin;
        String result = "";
        for (size_t i = 0; i < size; i++) {
            result += data[begin + i];
        }
        return result;
    }



    iterator begin() const {
        return iterator(data);
    }

    iterator end() const {
        return iterator(data + length);
    }
};

#endif //BME_PROG2_TICKETS_STRING_H
