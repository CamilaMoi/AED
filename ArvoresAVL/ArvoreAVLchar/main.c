#include<stdio.h>
#include<stdlib.h>
#include"ArvoreAVLchar.h"


int main() {
    ARVORE_AVL arvore;
    inicializar(&arvore);

    arvore.raiz = inserir(arvore.raiz, 'f');
    arvore.raiz = inserir(arvore.raiz, 'b');
    arvore.raiz = inserir(arvore.raiz, 'a');
    arvore.raiz = inserir(arvore.raiz, 'd');
    arvore.raiz = inserir(arvore.raiz, 'e');
    arvore.raiz = inserir(arvore.raiz, 'c');
    arvore.raiz = inserir(arvore.raiz, 'i');
    arvore.raiz = inserir(arvore.raiz, 'h');
    arvore.raiz = inserir(arvore.raiz, 'g');

    printf("�rvore AVL de caracteres:\n");

    printf("In-Ordem: ");
    listarInOrdem(arvore.raiz);
    printf("\n");

    printf("Pr�-Ordem: ");
    listarPreOrdem(arvore.raiz);
    printf("\n");

    printf("P�s-Ordem: ");
    listarPosOrdem(arvore.raiz);
    printf("\n");

    printf("Por N�veis: ");
    percorrerEmNiveis(arvore.raiz);
    printf("\n");

    printf("Quantidade de n�s: %d\n", contarNos(arvore.raiz));

    return 0;
}
