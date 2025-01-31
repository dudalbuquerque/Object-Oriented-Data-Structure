#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    friend class Queue;
private:
    int val;
    Node* next;
public:
    Node(int v) : val(v), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() { 
        while (size > 0) {
            dequeue();
        }
        front = nullptr; // Evita erro ao deletar já desalocado
    }

    void enqueue(int it) {
        Node* newNode = new Node(it);
        if (size == 0) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (size == 0) {
            return -1;
        }

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

    int frontValue() const {
        return (size == 0) ? -1 : front->val;
    }

    int length() const {
        return size;
    }
};

int main() {
    Queue myQueue;
    int qnt_elements;
    cin >> qnt_elements;
    int valor;

    for (int i = 0; i < qnt_elements; i++) {
        cin >> valor;
        myQueue.enqueue(valor);
    }
    
    cout << "First element: " << myQueue.frontValue() << endl;
    cout << "Size: " << myQueue.length() << endl;

    while (myQueue.length() > 0) {
        cout << myQueue.dequeue() << " ";
    }
    cout << endl;

    return 0;
}
