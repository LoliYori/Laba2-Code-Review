/* Продолжение задания 4 */
#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

class DoublyLinkedList {
private:
    struct Node {
        int value;        
        Node* prev;       
        Node* next;       
    };

    Node* firstElement;   

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void Initialize();                 
    void Clear();                      
    void AddElement(int value);        
    void PrintList() const;            
    void PrintBetweenMinMax();         

private:
    void FindMinMax(Node*& min, Node*& max);     
    bool CheckOrder(Node* a, Node* b);           
};

#endif