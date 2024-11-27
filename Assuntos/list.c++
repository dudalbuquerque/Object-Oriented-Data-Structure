#include <iostream>
using namespace std;

template <typename E>
class LIST {
public:
    struct myList {
        int maxSize;
        int listSize;
        int curr;
        E* listArray;
    };

    myList* create_list(int size) {
        myList* l = new myList;
        l->maxSize = size;
        l->listSize = 0;
        l->curr = 0;
        l->listArray = new E[size];
        return l;
    }

    void insert(myList* list, E value) {
        if (list->listSize < list->maxSize) {
            list->listArray[list->listSize] = value;
            list->listSize++;
        } else {
            cout << "Lista cheia. Não é possível inserir o valor." << endl;
        }
    }

    void delete_element(myList* list, int index) {
        if (index >= 0 && index < list->listSize) {
            for (int i = index; i < list->listSize - 1; ++i) {
                list->listArray[i] = list->listArray[i + 1];
            }
            list->listSize--;
        } else {
            cout << "Índice inválido." << endl;
        }
    }

    void print_list(myList* list) {
        for (int i = 0; i < list->listSize; ++i) {
            cout << list->listArray[i] << " ";
        }
        cout << endl;
    }

    void delete_list(myList* list) {
        delete[] list->listArray;
        delete list;
    }
};

int main() {
    LIST<int> list;

    int S;
    cout << "Digite o tamanho da lista: ";
    cin >> S;

    LIST<int>::myList* myList = list.create_list(S);

    for (int i = 0; i < S; ++i) {
        int valor;
        cin >> valor;
        list.insert(myList, valor);
    }

    cout << "Lista antes da remoção:" << endl;
    list.print_list(myList);

    int index_to_delete;
    cout << "Digite o índice para remover um elemento: ";
    cin >> index_to_delete;

    list.delete_element(myList, index_to_delete);

    cout << "Lista após a remoção:" << endl;
    list.print_list(myList);

    list.delete_list(myList);

    return 0;
}