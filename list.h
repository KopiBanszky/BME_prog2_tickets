#ifndef BME_PROG2_TICKETS_LIST_H
#define BME_PROG2_TICKETS_LIST_H

#include <iostream>

template<typename T>
class List {
    struct Node {
        T data;
        Node* next;
    };

    Node* head;


public:
    class iterator {
        Node* current;

        public:
        iterator(Node* current = NULL) : current(current) {}

        // @brief Preincrement operator
        // @return reference to the iterator
        iterator& operator++() {
            if(current != NULL)
            current = current->next;
            return *this;
        }

        // @brief Postincrement operator
        // @return copy of the iterator
        iterator operator++(T) {
            iterator temp = *this;
            if(current != NULL)
            current = current->next;
            return temp;
        }

        // @brief Dereference operator
        // @return reference to the data
        T& operator*() const {
            return current->data;
        }

        // @brief Equality operator
        // @return true if the iterators point to the same node
        bool operator==(const iterator& rhs) {
            return current == rhs.current;
        }

        // @brief Inequality operator
        // @return true if the iterators point to different nodes
        bool operator!=(const iterator& rhs) {
            return current != rhs.current;
        }

    };

    List() : head(nullptr) {}

    List(const List& other) {
        head = nullptr;
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    explicit List(const T& data) {
        head = new Node{data, nullptr};
    }

    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // @brief Adds an element to the end of the list
    // @param data element to be added
    void push_back(const T& data) {
        if (head == nullptr) {
            head = new Node{data, nullptr};
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new Node{data, nullptr};
    }

    // @brief Adds an element to the beginning of the list
    // @param data element to be added
    void push_front(const T& data) {
        head = new Node{data, head};
    }

    // @brief gives the length of the list
    // @return length of the list
    size_t len() const {
        size_t length = 0;
        Node* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    // @brief Removes the first element of the list
    void pop_front() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // @brief Removes the last element of the list
    void pop(){}

    // @brief Removes the first occurrence of the given element
    // @param data element to be removed
    void pop(const T& data) {}


    // @brief gives the first element of the list
    // @return first element
    iterator begin() {
        return {head};
    }

    // @brief gives the end of the list
    // @return end of the list
    iterator end() {
        return {nullptr};
    }
};

#endif //BME_PROG2_TICKETS_LIST_H
