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

        T& operator*() {
            return current->data;
        }

        iterator& operator++() {
            if(current != NULL)
            current = current->next;
            return *this;
        }

        iterator operator++(T) {
            iterator temp = *this;
            if(current != NULL)
            current = current->next;
            return temp;
        }

        T& operator*() const {
            return current->data;
        }

        bool operator==(const iterator& rhs) {
            return current == rhs.current;
        }

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

    void push_front(const T& data) {
        head = new Node{data, head};
    }

    size_t len() {
        size_t length = 0;
        Node* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }



    iterator begin() {
        return {head};
    }
    iterator end() {
        return {nullptr};
    }
};

#endif //BME_PROG2_TICKETS_LIST_H
