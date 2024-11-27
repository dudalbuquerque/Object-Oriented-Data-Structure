//FIFO = first-in, first-out
#include <iostream>
#include <cstring>
using namespace std;


class QUEUE{
public:
    typedef struct node{
        int element;
        node* next;
    }Node;

    typedef struct queue{
        Node* front; //primeiro
        Node* rear;  //último
        int size;
    }Queue;

    Node* create_link(int it, Node* nextval) {
        Node* n = new Node;
        n->element = it;
        n->next = nextval;
        return n;
    }
    Node* create_next_link(Node* nextval) { // Função para criar um novo link com próximo 'nextval' (sem atribuir valor)
        Node* n = new Node;
        n -> next = nextval;
        return n;
    }

    Queue* create_queue(){
        Queue* q = new Queue;
        q -> front = q -> rear = create_next_link(nullptr);
        q -> size = 0;
        return q;
    }

    void enqueue(Queue* q, int it) {
        q -> rear -> next = create_link(it, nullptr);
        q -> rear = q -> rear -> next;
        q -> size++;
    }

    int dequeue(Queue* q) {
        if (q->size == 0) {  
            return -1; 
        }

        Node* temp = q->front->next;   
        int it = temp->element;        
        q->front->next = temp->next;

        if (q->front->next == nullptr) {  
            q->rear = q->front;  
        }

        delete temp;  
        q->size--;   

        return it;    
    }

    int frontvalue(Queue* q) {
        if (q->size == 0) {
            return -1;  
        }
        return q->front->next->element;  
    }

    int length(Queue* q){
        return q -> size;
    } 
};

int main(){
    QUEUE queue;
    QUEUE::Queue* myqueue = queue.create_queue();

    int qnt_elements;
    cin >> qnt_elements;
    int valor;
    for (int i=0; i < qnt_elements; i++) {
        cin >> valor;
        queue.enqueue(myqueue, valor);
    }
    cout << "first element: " << queue.frontvalue(myqueue) << endl;
    cout << "size: " << queue.length(myqueue) << endl;

    while(myqueue -> size > 0) {
        cout << queue.dequeue(myqueue) << endl;
    }
    cout << endl;

    return 0;
}
