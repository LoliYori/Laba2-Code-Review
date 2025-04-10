/* Продолжение задания 1 */
#ifndef STACK_H
#define STACK_H

class Node {
public:
    int data;       
    Node* next;     

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;  

public:
    Stack();  

    void Push(int value);     
    void Pop();               
    void Print() const;       
    Node* GetTop() const;     
    void ClearStack();        

    friend void PushAndPrintNewTopAddress(Stack& stack, int D);  
};

bool IsValidInput(int& value);

#endif  