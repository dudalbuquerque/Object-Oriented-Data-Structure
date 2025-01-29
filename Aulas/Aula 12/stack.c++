#include <iostream>
#include <cstring>
using namespace std;

class STACK {
public:
    struct Link {
        int element;
        Link* next;
    };

    struct Stack {
        Link* top;
        int size;
    };

    Link* create_link(int it, Link* nextval) {
        Link* n = new Link;
        n->element = it;
        n->next = nextval;
        return n;
    }

    Link* create_next_link(Link* nextval) {
        Link* n = new Link;
        n->next = nextval;
        return n;
    }


    Stack* create_stack() {
        Stack* s = new Stack;
        s->top = nullptr;
        s->size = 0;
        return s;
    }

    void push(Stack* s, int it) {
        s->top = create_link(it, s->top);
        s->size++;
    }

    
    int pop(Stack* s) {
        if (s->top == nullptr) {
            cout << "Pilha vazia!" << endl;
            return -1;
        }
        int it = s->top->element;
        //Link* vpop = s->top;
        s->top = s->top->next;
        //delete vpop;  
        s->size--;
        return it;
    }

    void clear(Stack* s) {
        while (s->top != nullptr) {
            pop(s);
        }
        delete s;
    }
};

int main() {
    STACK stackManager;
    STACK::Stack* mystack = stackManager.create_stack(); 

    int qnt_elements;
    cout << "Digite a quantidade de elementos a serem empilhados: ";
    cin >> qnt_elements;

    int valor;
    for (int i = 0; i < qnt_elements; i++) {
        cout << "Digite o elemento " << i + 1 << ": ";
        cin >> valor;
        stackManager.push(mystack, valor);
    }

    cout << "Desempilhados: ";
    while (mystack->size > 0) {
        cout << stackManager.pop(mystack) << " ";
    }
    cout << endl;

    if (mystack->size == 0) {
        cout << "Pilha vazia" << endl;
    }
    cout << endl;
    
    stackManager.clear(mystack);
    return 0;
}
