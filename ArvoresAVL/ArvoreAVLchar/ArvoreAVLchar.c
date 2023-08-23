#include<stdio.h>
#include<stdlib.h>
#include"ArvoreAVLchar.h"

void inicializar(ARVORE_AVL* arvore) {
    arvore->raiz = NULL;
}

int altura(NO* no) {
    if (no == NULL) {
        return -1;
    }
    return no->altura;
}

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

NO* criarNO(char valor) {
    NO* novoNO = (NO*)malloc(sizeof(NO));
    novoNO->valor = valor;
    novoNO->altura = 0;
    novoNO->esq = NULL;
    novoNO->dir = NULL;
    return novoNO;
}

NO* rotacionarDireita(NO* y) {
    NO* x = y->esq;
    NO* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = maximo(altura(y->esq), altura(y->dir)) + 1;
    x->altura = maximo(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

NO* rotacionarEsquerda(NO* x) {
    NO* y = x->dir;
    NO* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = maximo(altura(x->esq), altura(x->dir)) + 1;
    y->altura = maximo(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

NO* inserir(NO* no, char valor) {
    if (no == NULL) {
        return criarNO(valor);
    }

    if (valor < no->valor) {
        no->esq = inserir(no->esq, valor);
    } else if (valor > no->valor) {
        no->dir = inserir(no->dir, valor);
    } else {
        // Ignorar valores duplicados
        return no;
    }

    no->altura = 1 + maximo(altura(no->esq), altura(no->dir));

    int balanceamento = altura(no->esq) - altura(no->dir);

    if (balanceamento > 1 && valor < no->esq->valor) {
        return rotacionarDireita(no);
    }
    if (balanceamento < -1 && valor > no->dir->valor) {
        return rotacionarEsquerda(no);
    }
    if (balanceamento > 1 && valor > no->esq->valor) {
        no->esq = rotacionarEsquerda(no->esq);
        return rotacionarDireita(no);
    }
    if (balanceamento < -1 && valor < no->dir->valor) {
        no->dir = rotacionarDireita(no->dir);
        return rotacionarEsquerda(no);
    }

    return no;
}

void listarPreOrdem(NO* no) {
    if (no == NULL) {
        return;
    }
    printf("%c ", no->valor);
    listarPreOrdem(no->esq);
    listarPreOrdem(no->dir);
}

void listarPosOrdem(NO* no) {
    if (no == NULL) {
        return;
    }
    listarPosOrdem(no->esq);
    listarPosOrdem(no->dir);
    printf("%c ", no->valor);
}

void listarInOrdem(NO* no) {
    if (no == NULL) {
        return;
    }
    listarInOrdem(no->esq);
    printf("%c ", no->valor);
    listarInOrdem(no->dir);
}

void percorrerEmNiveis(NO* raiz) {
    if (raiz == NULL) {
        return;
    }

    NO* fila[100];
    int frente = 0;
    int traseira = 0;
    fila[traseira] = raiz;
    traseira++;

    while (frente < traseira) {
        NO* atual = fila[frente];
        frente++;

        printf("%c ", atual->valor);

        if (atual->esq) {
            fila[traseira] = atual->esq;
            traseira++;
        }

        if (atual->dir) {
            fila[traseira] = atual->dir;
            traseira++;
        }
    }
}

int contarNos(NO* no) {
    if (no == NULL) {
        return 0;
    }
    return 1 + contarNos(no->esq) + contarNos(no->dir);
}
