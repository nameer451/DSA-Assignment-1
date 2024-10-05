#include <iostream>
#include <random>
#include <cstdint>

using namespace std;

class Node { // Use PascalCase for class names by convention
public:
    unsigned long long data;
    Node* next;

    // Constructor should properly initialize data
    Node(unsigned long long data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void append(unsigned long long data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode; // Update the tail to the new node
        }
    }

    unsigned long long generate64BitRandom() {
        random_device rd; 
        mt19937_64 gen(rd());
        uniform_int_distribution<unsigned long long> dist(0, numeric_limits<unsigned long long>::max());
        return dist(gen);
    }

    void generate1024bitNumber() {
        for (int i = 0; i < 16; i++) { // Only need 16 segments of 64 bits to make 1024 bits
            unsigned long long newNum = generate64BitRandom();
            append(newNum); // append directly takes unsigned long long
        }
    }

    void printList() { // Utility function to print the list contents
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.generate1024bitNumber();
    list.printList();
    return 0;
}
