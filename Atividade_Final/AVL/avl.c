// Ana Clara Guarizi de Souza - UVV 2024/2 CC4N - Matrícula 202309136

#include <stdio.h>
#include <stdlib.h>

// estrutura do nó da árvore AVL
typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
    int altura;  // altura do nó
} No;

// função para criar um novo nó
No* novoNoAVL(int dado) {
    No* no = (No*)malloc(sizeof(No));
    no->dado = dado;
    no->esquerda = no->direita = NULL;
    no->altura = 1;
    return no;
}

// função para obter a altura de um nó
int altura(No* no) {
    return (no == NULL) ? 0 : no->altura;
}

// função para calcular o fator de balanceamento
int fatorDeBalanceamento(No* no) {
    return (no == NULL) ? 0 : altura(no->esquerda) - altura(no->direita);
}

// função para rotação à esquerda
No* rotacaoEsquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;
    
    // realizando a rotação
    y->esquerda = x;
    x->direita = T2;
    
    // atualizando as alturas
    x->altura = 1 + (altura(x->esquerda) > altura(x->direita) ? altura(x->esquerda) : altura(x->direita));
    y->altura = 1 + (altura(y->esquerda) > altura(y->direita) ? altura(y->esquerda) : altura(y->direita));
    
    return y;
}

// função para rotação à direita
No* rotacaoDireita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;
    
    // realizando a rotação
    x->direita = y;
    y->esquerda = T2;
    
    // atualizando as alturas
    y->altura = 1 + (altura(y->esquerda) > altura(y->direita) ? altura(y->esquerda) : altura(y->direita));
    x->altura = 1 + (altura(x->esquerda) > altura(x->direita) ? altura(x->esquerda) : altura(x->direita));
    
    return x;
}

// função para inserir na árvore AVL
No* inserirAVL(No* no, int dado) {
    // 1. realizar a inserção na árvore binária de busca normal
    if (no == NULL) {
        return novoNoAVL(dado);
    }

    if (dado < no->dado) {
        no->esquerda = inserirAVL(no->esquerda, dado);
    } else if (dado > no->dado) {
        no->direita = inserirAVL(no->direita, dado);
    } else {
        return no;  // se o dado já existe, não adiciona
    }

    // 2. atualizar a altura do nó atual
    no->altura = 1 + (altura(no->esquerda) > altura(no->direita) ? altura(no->esquerda) : altura(no->direita));

    // 3. verificar o fator de balanceamento e realizar rotações se necessário
    int balance = fatorDeBalanceamento(no);

    // se o nó estiver desbalanceado, existem 4 casos

    // caso 1: desbalanceamento à esquerda
    if (balance > 1 && dado < no->esquerda->dado) {
        return rotacaoDireita(no);
    }

    // caso 2: desbalanceamento à direita
    if (balance < -1 && dado > no->direita->dado) {
        return rotacaoEsquerda(no);
    }

    // caso 3: desbalanceamento à esquerda-direita
    if (balance > 1 && dado > no->esquerda->dado) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    // caso 4: desbalanceamento à direita-esquerda
    if (balance < -1 && dado < no->direita->dado) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

// função para imprimir a árvore
void emOrdemAVL(No* raiz) {
    if (raiz != NULL) {
        emOrdemAVL(raiz->esquerda);
        printf("%d ", raiz->dado);
        emOrdemAVL(raiz->direita);
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
        raiz = inserirAVL(raiz, arr[i]);
    }

    printf("\n\nÁrvore avl em ordem:\n");
    emOrdemAVL(raiz);
    printf("\n");

    return 0;
}
