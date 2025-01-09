#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <string>
#include <vector>
#include <sstream>

template <typename T>
struct LinkedList {

    struct Node {

        T value;
        Node* next;

        Node() : value(), next(nullptr) {}
        Node(const T& value) : value(value), next(nullptr) {}
        Node(const T& value, Node* next) : value(value), next(next) {}

    };

    Node* head;
    Node* last;

    LinkedList() : head(nullptr), last(nullptr) {}

    ~LinkedList() {

        while (this->head != nullptr) {
            Node* temp = this->head->next;
            delete this->head;
            this->head = temp;
        }

    }

    static LinkedList from_vector(const std::vector<T>& values) {

        LinkedList list;

        for (const T& value : values) {
            list.insert_back(value);
        }

        return list;

    }

    friend bool operator==(const LinkedList& left, const LinkedList& right) {

        const Node* lnode = left.head;
        const Node* rnode = right.head;

        while (lnode != nullptr && rnode != nullptr) {

            if (lnode->value != rnode->value) {
                return false;
            }

            lnode = lnode->next;
            rnode = rnode->next;

        }

        return lnode == nullptr && rnode == nullptr;

    }

    Node* insert_front(const T& value) {

        this->head = new Node(value, this->head);

        if (this->last == nullptr) {
            this->last = this->head;
        }

        return this->head;

    }

    Node* insert_back(const T& value) {

        Node* curr = new Node(value);

        if (this->head == nullptr) {
            this->head = curr;
            this->last = curr;
        }
        else {
            this->last->next = curr;
            this->last = curr;
        }

        return curr;

    }

    std::string to_string(const std::string& delimiter = ",") const {

        std::stringstream buffer;
        std::string state = "";

        buffer << "[";
        for (const Node* curr = this->head; curr != nullptr; curr = curr->next) {
            buffer << state << curr->value;
            state = delimiter;
        }
        buffer << "]";

        return buffer.str();

    }

};

#endif // LINKED_LIST_HPP