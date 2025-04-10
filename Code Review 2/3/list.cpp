/* Продолжение задания 3 */
#include "list.h"
#include <fstream>
#include <iostream>

using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::InsertSorted(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr || head->data < value) {
        newNode->next = head;
        head = newNode;  
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->data > value) {
            current = current->next;  
        }
        newNode->next = current->next;
        current->next = newNode;  
    }
}

void LinkedList::Print() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;  
}

void LinkedList::ReadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    int N;
    file >> N;  
    if (file.fail()) {
        cerr << "Ошибка чтения данных из файла!" << endl;
        file.close();
        return;
    }

    int value;
    for (int i = 0; i < N; ++i) {
        file >> value;
        if (file.fail()) {
            cerr << "Ошибка чтения значения!" << endl;
            file.close();
            return;
        }
        InsertSorted(value);  
    }

    file.close();  
}

void ReadFromFile(LinkedList& list, const string& filename) {
    list.ReadFromFile(filename);
}