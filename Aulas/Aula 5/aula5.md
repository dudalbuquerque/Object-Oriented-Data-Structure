Diferença entre alocação na stack vs heap
Stack:
- memória gerenciada automaticamente pela função ou programa.
Características:
- Armazenamento temporário de variáveis locais e chamadas de funções.
- Cresce e diminui automaticamente com o escopo das funções.
- Memória de acesso rápido.
- Tamanho limitado pelo sistema operacional (geralmente menor que a heap).
- Liberação automática quando o programa sai do escopo da variável.

Heap:
- Uma área de memória gerenciada manualmente pelo programador.
Características:
- Armazenamento de dados dinâmicos que precisam persistir além do escopo da função.
- Deve ser alocada e liberada manualmente.
- Memória geralmente maior e mais flexível, mas mais lenta que a pilha.
- Risco de vazamento de memória caso free não seja usado.