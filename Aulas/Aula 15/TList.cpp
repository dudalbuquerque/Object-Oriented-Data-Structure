#include <bits/stdc++.h>
using namespace std;

template <typename T>
class List{
public:
	virtual ~List(){}

	int size(){return sz;};
    virtual T get(int pos) = 0;
    virtual void insert(int pos, T val) = 0;
	
    void append(T val){
		insert(size(), val);
	}
	void prepend(T val){
		insert(0, val);
	}

    virtual T remove(int pos) = 0;

protected:
	int sz{0};
};


template <typename T>
class LinkedList : public List<T>{
    struct Node{
        Node(){};
        Node(T v, Node *nxt = nullptr): val{v}, next{nxt}{ }
        ~Node(){
            //cout << "deleting" << endl;
        }
        T val;
        Node *next = nullptr;
    };
public:
    LinkedList(){head = new Node(); this->sz = 0;};
    ~LinkedList(){
        Node *cur = head;
        while (cur != nullptr) {
            Node *next = cur->next;
            delete cur;
            cur = next;
	    }
    }

    T getSize() { //retorna o tamanho
        return this->sz;
    }

    void insert(int pos, T val){
        assert(pos <= this->sz);
        Node *cur = locate(pos);
        Node *new_node = new Node(val);
        new_node->next = cur->next;
        cur->next = new_node;
        this-> sz++;
    }

	T get(int pos){
        assert(pos < this->sz);
        return locate(pos)->next->val;
    }

    T remove(int pos) {
        assert (pos < this->sz);
        Node *cur = locate(pos);
        Node *to_die = cur->next;
        cur->next = to_die->next;
        T ret = to_die->val;
        delete to_die;
        this->sz--;
        return ret;
    }

    void print(){
        for (int i = 0; i < this->sz; i++) {
            cout << (i?", ":"") << get(i);
        }
        cout << endl;
    }

private:
	Node *locate(int pos) {
        Node *cur = head;
        for (int i = 0; i < pos; i++) {
            cur = cur->next;
        }
        return cur;
    }

    Node *head;
};

template <typename T> 
void printList(List<T> *list){
    for (int i = 0; i < list->size(); i++) {
        cout << (i?", ":"") << list->get(i);
    }
    cout << endl;
}

int main()
{
    // Lista de inteiros
    LinkedList<int> list;
    int n = 20;
    for (int i = 0; i < n; i++) {
        list.append(i);
    }
    printList<int>(&list);

    // Lista de doubles
    LinkedList<double> doubleList;
    for (int i = 0; i < n; i++) {
        doubleList.append(i + 0.5);
    }
    printList<double>(&doubleList);

    // Lista de caracteres
    LinkedList<char> charList;
    for (char c = 'a'; c <= 'z'; c++) {
        charList.append(c);
    }
    charList.print();

    List<List<char>*> *all = new LinkedList<List<char>*>();
    for (int i = 0; i < 10; i++) {
        all->append(new LinkedList<char>());
        for (int j = 0; j < 5; j++) {
            all->get(i)->append('a' + (5*i)+j);
        }
    }
    for (int i = 0; i < 10; i++) {
        printList(all->get(i));
    }
    for (int i = 0; i < 10; i++) {
        delete all->remove(0);
    }
    delete all;

/*

    // Imprime as listas de caracteres dentro de 'all'
    for (int i = 0; i < 10; i++) {
        printList<char>(all->get(i));
    }

    // Libera memória corretamente
    for (int i = 0; i < 10; i++) {
        delete all->remove(0);
    }
    delete all;
*/

    return 0;
}
