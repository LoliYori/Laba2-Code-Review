/* Продолжение задания 3 */
#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList();  
    ~LinkedList();  

    void InsertSorted(int value);  
    void Print() const;  
    void ReadFromFile(const string& filename);  

    friend void ReadFromFile(LinkedList& list, const string& filename);  
};

#endif