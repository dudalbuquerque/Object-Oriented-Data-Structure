**Linked List**

##### Sequência linear dinâmica de valores do mesmo tipo

### Tipo abstrato de dados (TAD)
Estado(O que armazena) + Operações(O que fazer)

###### Estrutura 
- Struct
    - Node: |element|next|->   
    - next => ponteiro para o próximo node  
- Descrição
    - Head: aponta para o header
    - Tail: 
    - cur: atual
    - NULL: Não existe elemento  
#
###### Operações
__Básicas__ 
```
E => tipo da lista (int, char...)
void Insert(List L, E elemento)
E remove(List L, E )
void clear(List L)
E search(List L, E elemento)
```

```
void MoveToStart(List L)
void MoveToEnd(List L)
void prev(List L) (anterior)
void next(List L)
void MoveToPos(List L, int pos)
```
```
E length(List L)
E currPos(List L)
E getvalue(List L)
```

__OBS: Se o val aponta para o prev e para o next ao mesmo tempo, torna a lista duplamente encadeada__