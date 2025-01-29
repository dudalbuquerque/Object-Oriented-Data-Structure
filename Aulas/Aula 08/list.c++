#include <bits/stdc++.h>
using namespace std;


struct Node{
    int element;
    Node* next;
};
typedef struct Node Node;

Node *create_list(){
    Node *head = new Node;
    (*head).element = -1;
    (*head).next = NULL;
    return head;        
}

void append(Node *head, int element){
    Node *cur = head;
    while (cur->next != NULL){
        cur = cur->next;
    }
    Node* tail = new Node;
    tail->element = element;
    tail->next = NULL;
    cur->next = tail;
}

Node *find_pos(Node *head, size_t pos){
    Node *cur = head;
    size_t i = 0;
    while (i < pos && cur->next != NULL){
        cur = cur->next;
        i++;
    }
    return cur;
} 
Node *insert_at(Node *head, size_t pos, int element){
    Node *cur = find_pos(head, pos);
    //Node *new_node = create_node(element);
    //new_node->next = cur->next;
    //cur->next = new_node;
    return cur;
}

Node *find_element(Node *head, int element){
    Node *cur = head;
    while (cur->next->element != element && cur->next != NULL){
        cur = cur->next;
    }
    return cur;
}

Node *remove(Node *cur){
    Node *to_die = cur->next;
    cur->next = to_die->next;
    free(to_die);
    return cur;
    
}

int main() {
    Node *head = create_list();
    printf("%d\n", (*head).element);    
    append(head, 2);
    append(head, 3);
    append(head, 5);
    append(head, 7);


    int pos = 4;
    Node *node = find_pos(head, pos);
    if(node->next != NULL){
        printf("list[%d] = %d\n", pos, node->next->element);
    }else{
        printf("Out of bounds\n");
    }

    int element = 5;
    node = find_element(head, element);
    if(node->next != NULL){
        printf("node element %d = %d\n", element, node->next->element);
    }else{
        printf("not found\n");
    }
}