#include <stdio.h>
#include "ArvoreAVLinteirosII.h"

int main() {
    ARVORE a;
    inicializar(&a);

    int i;
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8};

    for (i = 0; i < 15; i++) {
        inserirAVL(&(a.raiz), vetor[i]);
    }

    imprimirEmOrdem(a.raiz);
    printf("\n");

    return 0;
}
