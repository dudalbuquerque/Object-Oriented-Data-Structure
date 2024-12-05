#include <bits/stdc++.h>
using namespace std;



class Linkedlist{
public:
    typedef struct Node{
        int element;
        Node* next;
    };

    Node *create_list(){
        Node *head = new Node;
        (*head).element = -1;
        (*head).next = NULL;
        return head;        
    }

    void append(Node *head, int val){
        Node *cur = head;
        while (cur->next == NULL){
            cur = cur->next;
        }
    }

};



int main(){

    return 0;
}