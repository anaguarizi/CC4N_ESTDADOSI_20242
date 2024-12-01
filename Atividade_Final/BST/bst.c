// árvore bst

#include <stdio.h>
#include <stdlib.h>

// estrutura do nó da árvore
typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

// função para criar um novo nó
No* novoNo(int dado) {
    No* no = (No*)malloc(sizeof(No));
    no->dado = dado;
    no->esquerda = no->direita = NULL;
    return no;
}

// função para inserir na árvore BST
No* inserirBST(No* raiz, int dado) {
    if (raiz == NULL) {
        return novoNo(dado);
    }
    if (dado < raiz->dado) {
        raiz->esquerda = inserirBST(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = inserirBST(raiz->direita, dado);
    }
    // se o dado já existe, não adiciona
    return raiz;
}

// função para imprimir a árvore (em ordem)
void emOrdemBST(No* raiz) {
    if (raiz != NULL) {
        emOrdemBST(raiz->esquerda);
        printf("%d ", raiz->dado);
        emOrdemBST(raiz->direita);
    }
}

// função principal
int main() {
    No* raiz = NULL;
    int i, arr[50];
    
    // gerando um array aleatório de 50 elementos
    printf("Array aleatório de 50 elementos:\n");
    for (i = 0; i < 50; i++) {
        arr[i] = rand() % 100;  // número aleatório entre 0 e 99
        printf("%d ", arr[i]);
        raiz = inserirBST(raiz, arr[i]);
    }

    printf("\n\nÁrvore bst em ordem:\n");
    emOrdemBST(raiz);
    printf("\n");

    return 0;
}
