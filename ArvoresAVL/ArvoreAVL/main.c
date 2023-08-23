#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main()
{
    ARVORE a;

    inicializar(&a);

    inserirARV2(&a, 1);
    inserirARV2(&a, 2);
    inserirARV2(&a, 3);
    inserirARV2(&a, 4);
    inserirARV2(&a, 5);
    inserirARV2(&a, 6);
    inserirARV2(&a, 7);
    inserirARV2(&a, 15);
    inserirARV2(&a, 14);
    inserirARV2(&a, 13);
    inserirARV2(&a, 12);
    inserirARV2(&a, 11);
    inserirARV2(&a, 10);
    inserirARV2(&a, 9);
    inserirARV2(&a, 8);


    printf("---------printar arvore-----------\n");
    listarINORDEM(a.raiz);
    printf("\n");

    printf("-----------altura-------- \n");
    int alturamain=alturaBIN(a.raiz);
    printf("a altura da arvore e %d \n", alturamain);

    printf("--------------buscar no----------- \n");
    NO *resultado_busca=buscaARV(&a, 14);
    printf("numero %d encontrado na árvore \n", resultado_busca->valor);

    printf("-------percorrer por nivel-----------\n");
    PerccorerEmLargura(a.raiz);

    printf(" \nraiz:");
    printf("%d", a.raiz->valor);

}
