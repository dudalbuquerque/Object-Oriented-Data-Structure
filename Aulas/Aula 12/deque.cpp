#include <iostream>
#include <bits/stdc++.h>
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

class Deque {
public:
    Deque() : front(nullptr), rear(nullptr), size(0) {} 

    ~Deque() { clearDeque(); }

    void enqueueFront(int it) { // Adiciona um elemento no início da deque
        Node* newNode = new Node(it);
        if (size == 0) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front = newNode;
        }
        size++;
    }

    void enqueueRear(int it) { // Adiciona um elemento no final da deque
        Node* newNode = new Node(it);
        if (size == 0) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeueFront() { // Remove e retorna o elemento do início da deque
        if (size == 0) return -1;
        
        Node* temp = front;
        int it = temp->val;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        size--;
        return it;
    }

    int dequeueRear() { // Remove e retorna o último elemento da deque
        if (size == 0) return -1;

        Node* temp = rear;
        int it = temp->val;

        if (front == rear) { // Apenas um elemento na deque
            delete rear;
            front = rear = nullptr;
        } else {
            Node* prev = front;
            while (prev->next != rear) {
                prev = prev->next;
            }
            delete rear;
            rear = prev;
            rear->next = nullptr;
        }
        size--;
        return it;
    }

    int frontValue() const { // Retorna o valor do início da deque
        return (size == 0) ? -1 : front->val;
    }

    int rearValue() const { // Retorna o valor do final da deque
        return (size == 0) ? -1 : rear->val;
    }

    int getSizeQueue() const { // Retorna o tamanho da deque
        return size;
    }

    void clearDeque() { // Esvazia a deque
        while (size > 0) {
            dequeueFront();
        }
    }
private:
    Node* front;
    Node* rear;
    int size;

};

