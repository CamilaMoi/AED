#include <stdio.h>
#include <stdlib.h>
#include"arvorebinaria.h"

int main()
{
        ARVORE arvore;
        inicializar(&arvore);

        int Nmain;

        Nmain=24;
        ELEMENTO * novo1=criarNo(Nmain);
        adicionar(&arvore, novo1);

        Nmain=10;
        ELEMENTO * novo2=criarNo(Nmain);
        adicionar(&arvore, novo2);

        Nmain=32;
        ELEMENTO * novo3=criarNo(Nmain);
        adicionar(&arvore, novo3);

        Nmain=5;
        ELEMENTO * novo4=criarNo(Nmain);
        adicionar(&arvore, novo4);

        Nmain=12;
        ELEMENTO * novo5=criarNo(Nmain);
        adicionar(&arvore, novo5);

        Nmain=29;
        ELEMENTO * novo6=criarNo(Nmain);
        adicionar(&arvore, novo6);

        Nmain=35;
        ELEMENTO * novo7=criarNo(Nmain);
        adicionar(&arvore, novo7);

        listararvore(&arvore);

        int num=Contador(arvore.raiz);
        printf(" \n quantidade de elementos na arvore: %d", num);

        printf("\n pré-ordem: \n");
        listarPreOrdem(arvore.raiz);

        printf("\n pós orem: \n");
        listarPosOrdem(arvore.raiz);
        return 0;
}
