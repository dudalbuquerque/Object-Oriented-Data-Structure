#include <bits/stdc++.h>
#include <iostream>

class Node{
public:
    friend class LinkedList; //a mesma função da linha 7
    Node (int element);
    //Node *getnext(){return next;} //apenas para poder utilizar nas outras classes, poderia apenas colocar no public
private:
    int element;
    Node *next;
};

Node::Node(int element){
    element = element;
    next = nullptr;
}

class LinkedList{
public:
    LinkedList(){
        head = new Node(-1);
    };

    void append(int element){
        Node *cur = head;
        while (cur -> next != nullptr){
            cur = cur->next;
        }
        Node* tail = new Node(element);
        cur->next = tail;
        sz++;
    }
    
    int operator()(){return sz;}

    int operator[](int pos){
        Node *cur = head;
        size_t i = 0;
        while (i < pos && cur->next != NULL){
            cur = cur->next;
            i++;
        }
        return cur->next->element;
    }

private:
    Node *head;
    int sz = 0;
};

int main(){
    LinkedList list;
    list.append(2);
    list.append(5);
    list.append(6);
    list.append(7);

    for (int i = 0; i < list(); i++){
        cout <<  list[i];
    }

    return 0;
}