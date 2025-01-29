###### O conceito de uma linked list está a 'Aula 08'

#### **Linked List: Definição da estrutura dos nós (**Link**) e da lista (**List**)**

* **Link** representa um nó (**node**) com um elemento e um ponteiro para o próximo nó.
* **List** armazena ponteiros para o início (**head**), o final (**tail**) e a posição atual (**curr**) da lista, além de um contador (**cnt**).

#### **Funções auxiliares:**

* `create_link(int it, Link* nextval)`: cria um novo nó com um valor e um ponteiro para o próximo.
* `create_next_link(Link* nextval)`: cria um nó sem valor (usado para inicialização da lista).
* `create_list()`: cria uma lista vazia com um nó inicial.
Operações na lista:

* `insert(List* l, int it)`: insere um elemento após a posição atual.
* `moveToStart(List* l)`: move curr para o início.
* `prev(List* l)`: move curr para o nó anterior.
* `next(List* l)`: move curr para o próximo nó.
* `remove(List* l)`: remove o nó após curr e retorna seu valor.
* `getValue(List* l)`: retorna o valor do nó atual.
