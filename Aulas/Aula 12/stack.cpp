#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

class Node {
    friend class Stack;
    friend class Deque;
private:
    int val;
    Node* next;
public:
    Node() : val(-1), next(nullptr) {}  
    Node(int v) : val(v), next(nullptr) {}
};

// LIFO = last-in, first-out
class Stack {
private:
    Node* top;
    int size;    
public:
    Stack() : top(nullptr), size(0) {} 
    ~Stack() { 
        while (top != nullptr) {
            pop();
        }
    }

    int getSize() const {
        return size;
    }

    void push(int val) { 
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop() { 
        if (top == nullptr) {
            cout << "Pilha vazia!" << endl;
            return -1;
        }
        int it = top->val;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return it;
    }

    void clearStack() { 
        while (top != nullptr) {
            pop();
        }
    }

    int topValue() const { 
        return (top != nullptr) ? top->val : -1;
    }
};

int main() {
    Stack mystack;
    
    int qnt_elements;
    cout << "Digite a quantidade de elementos a serem empilhados: ";
    cin >> qnt_elements;
    cout << endl;
    
    int valor;
    for (int i = 0; i < qnt_elements; i++) {
        cout << "Digite o elemento " << i + 1 << ": ";
        cin >> valor;
        mystack.push(valor);
    }

    cout << "Desempilhados: ";
    while (mystack.getSize() > 0) {
        cout << mystack.pop() << " ";
    }
    cout << endl;

    if (mystack.getSize() == 0) {
        cout << "Pilha vazia" << endl;
    }
    cout << endl;
    
    mystack.clearStack();
    return 0;
}