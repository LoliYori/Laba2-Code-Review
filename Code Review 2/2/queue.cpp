/* Продолжение задания 2 */
#include "queue.h"
#include <iostream>
#include <cctype>

using namespace std;

bool IsNumber(const string& str) {
	if (str.empty()) return false;
	int start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	for (int i = start; i < str.length(); ++i) {
		if (!isdigit(str[i])) return false;
	}
	return start < str.length();
}

bool SafeInput(int& value) {
	string input;
	cin >> input;
	if (!IsNumber(input)) {
		cout << "Ошибка ввода. Введите целое число." << endl;
		return false;
	}
	value = stoi(input);
	return true;
}

Queue::Queue() : P1(nullptr), P2(nullptr) {}

Queue::~Queue() {
	int del;
	while (Pop(del));
}

void Queue::Push(int num) {
	Node* newNode = new Node;
	newNode->data = num;
	newNode->next = nullptr;

	if (!P2) {
		P1 = P2 = newNode;
	}
	else {
		P2->next = newNode;
		P2 = newNode;
	}
}

bool Queue::Pop(int& num) {
	if (!P1) return false;

	Node* temp = P1;
	num = P1->data;
	P1 = P1->next;
	if (!P1) P2 = nullptr;

	delete temp;
	return true;
}

void Queue::Show() const {
	Node* temp = P1;
	if (!temp) {
		cout << "Очередь пустая" << endl;
		return;
	}
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void Queue::PopUntilEven() {
	int num;
	while (P1 && P1->data % 2 != 0) {
		if (Pop(num)) {
			cout << num << " ";
		}
	}
	cout << endl;
}

void Queue::PrintP1Data() const {
	if (!P1) {
		cout << "nullptr";
	}
	else {
		cout << P1->data;
	}
}

void Queue::PrintP2Data() const {
	if (!P2) {
		cout << "nullptr";
	}
	else {
		cout << P2->data;
	}
}

Queue::Node* Queue::GetP1() const {
	return P1;
}

Queue::Node* Queue::GetP2() const {
	return P2;
}

