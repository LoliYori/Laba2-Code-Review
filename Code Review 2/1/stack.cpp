/* Продолжение задания 1 */
#include "stack.h"
#include <iostream>
#include <limits>

Stack::Stack() : top(nullptr) {}

void Stack::Push(int value) {
    if (value < 0) {
        std::cerr << "Ошибка: Невалидное значение. Стек может содержать только положительные числа." << std::endl;
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;

    std::cout << "Элемент " << value << " добавлен в стек." << std::endl;
}

void Stack::Pop() {
    if (top == nullptr) {
        std::cerr << "Ошибка: Стек пуст! Невозможно удалить элемент." << std::endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    std::cout << "Элемент " << temp->data << " удален из стека." << std::endl;
    delete temp;
}

void Stack::Print() const {
    if (top == nullptr) {
        std::cout << "Стек пуст!" << std::endl;
        return;
    }

    Node* current = top;
    std::cout << "Элементы стека: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* Stack::GetTop() const {
    return top;
}

void Stack::ClearStack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    std::cout << "Стек очищен." << std::endl;
}

void PushAndPrintNewTopAddress(Stack& stack, int D) {
    stack.Push(D);
    std::cout << "Адрес новой вершины стека: " << std::hex << stack.GetTop() << std::dec << std::endl;
}

bool IsValidInput(int& value) {
    std::cin >> value;
    if (std::cin.fail()) {  
        std::cin.clear();  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        return false;
    }
    return true;
}