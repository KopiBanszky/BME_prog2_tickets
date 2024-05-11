#ifndef BME_PROG2_TICKETS_LIST_HPP
#define BME_PROG2_TICKETS_LIST_HPP

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
    void pop() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    
    };

    // @brief Removes the first occurrence of the given element
    // @param data element to be removed
    void pop(const T& data) {
        if (head == nullptr) {
            return;
        }

        if (head->data == data) {
            pop_front();
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    
    };

    void pop(size_t index) {
        if (index == 0) {
            pop_front();
            return;
        }

        Node* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

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

    // @brief indexer operator
    // @param index index of the element
    // @return element at the given index
    T& operator[](size_t index) {
        Node* current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    
    };

    // @brief indexer operator
    // @param index index of the element
    // @return element at the given index
    T& operator[](size_t index) const {
        Node* current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    };
};

#endif //BME_PROG2_TICKETS_LIST_HPP
