/* Продолжение задания 4 */
#include "double_list.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList() : firstElement(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    Clear();
}

void DoublyLinkedList::Initialize() {
    firstElement = nullptr;
}

void DoublyLinkedList::Clear() {
    Node* current = firstElement;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    firstElement = nullptr;
}

void DoublyLinkedList::AddElement(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (firstElement == nullptr) {
        firstElement = newNode;
    }
    else {
        Node* current = firstElement;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void DoublyLinkedList::PrintList() const {
    Node* current = firstElement;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyLinkedList::PrintBetweenMinMax() {
    Node* min = nullptr;
    Node* max = nullptr;
    FindMinMax(min, max);

    if (min == nullptr || max == nullptr || min == max) {
        cout << "Нет элементов для вывода!" << endl;
        return;
    }

    bool minFirst = CheckOrder(min, max);
    Node* start = minFirst ? min : max;
    Node* end = minFirst ? max : min;

    cout << "Элементы между " << min->value << " и " << max->value << ": ";
    Node* current = start->next;
    bool hasElements = false;

    while (current != nullptr && current != end) {
        cout << current->value << " ";
        hasElements = true;
        current = current->next;
    }

    if (!hasElements) cout << "Отсутствуют";
    cout << endl;
}

void DoublyLinkedList::FindMinMax(Node*& min, Node*& max) {
    if (firstElement == nullptr) return;

    min = max = firstElement;
    Node* current = firstElement->next;

    while (current != nullptr) {
        if (current->value < min->value) min = current;
        if (current->value > max->value) max = current;
        current = current->next;
    }
}

bool DoublyLinkedList::CheckOrder(Node* a, Node* b) {
    Node* current = firstElement;
    while (current != nullptr) {
        if (current == a) return true;
        if (current == b) return false;
        current = current->next;
    }
    return false;
}