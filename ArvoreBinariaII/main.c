#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main()
{
    ARVORE a;
    //NO nomain;

    inicializar(&a);

    inserirARV2(&a, 9);
    inserirARV2(&a, 8);
    inserirARV2(&a, 5);
    inserirARV2(&a, 3);
    inserirARV2(&a, 10);
    inserirARV2(&a, 12);



    printf("-------------listar arvore pre ordem------------ \n");
    listarPREORDEM(a.raiz);
    printf("\n in-ordem: \n");
    listarINORDEM(a.raiz);
    printf("\n pos ordem: \n");
    listarPOSORDEM(a.raiz);

    printf("------------------------------------- \n");

    printf("-------------buscando---------------- \n");
    NO* busca_resultado=buscaARV(&a, 12);

    printf("valor %d encontrado \n", busca_resultado->valor);

    printf("------------------------------------- \n");

    int qtdnos=contarNOS(a.raiz);
    printf("a arvore tem %d nos \n", qtdnos);

    printf("----------------------------- \n");
    int alturaarv=altura(a.raiz);
    printf("a altura da arvore e %d \n",alturaarv);

    int profundidade = profundidadeNO(a.raiz, 12);
    if (profundidade != -1) {
        printf("Profundidade do no %d: %d\n", 12, profundidade);
    } else {
        printf("No %d nao encontrado na arvore.\n", 12);
    }

    printf("---------------------apagando numero %d----------------- \n", 5);
    if(excluirno(a.raiz, 5)==1)
    {
        printf("numero %d excluido \n", 5);
        printf("------------nova arvore------------ \n");
        listarPREORDEM(a.raiz);
    }
    else
    {
        printf("exclusão mal sucedida");
    }



    return 0;

}
