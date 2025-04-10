/* Продолжение задания 2 */

#ifndef QUEUE_H
#define QUEUE_H

#include <string>

class Queue {
private:
	struct Node {
		int data;
		Node* next;
	};

	Node* P1; 
	Node* P2; 

public:
	Queue();
	~Queue();

	void Push(int num);             
	bool Pop(int& num);            
	void Show() const;             
	void PopUntilEven();          

	void PrintP1Data() const;     
	void PrintP2Data() const;     

	Node* GetP1() const;          
	Node* GetP2() const;          
};


bool IsNumber(const std::string& str);

bool SafeInput(int& value);

#endif 