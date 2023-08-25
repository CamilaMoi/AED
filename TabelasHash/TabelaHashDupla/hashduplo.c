#include <stdio.h>
#include <stdlib.h>
#include "hashduplo.h"

void inicializar(tbhash tab)
{
    int i;

    for(i=0; i<N; i++)
    {
        tab[i]=NULL;
    }
}

int hash1(int num)
{
    return(num%N);
}

int hash2(int num)
{
    return(7-(num%7));
}

int hashduplo(int num, int tentativa)
{
    int pos1, pos2, posduplo;
    pos1=hash1(num);
    pos2=hash2(num);

    posduplo=(pos1+(tentativa*pos2)%N);

    return posduplo;
}

int inserir(tbhash tab, int num) {
    int posicao = hash1(num);
    int tentativa = 0;

    while (tab[posicao]!= NULL) {
        posicao = hashduplo(num, tentativa);

        // Verifica se já percorreu toda a tabela sem encontrar posição vazia
        if (tentativa >= N) {
            return 0; // Falha ao inserir elemento
        }

        tentativa++;
    }

    tab[posicao] =  num;
    return 1; // Sucesso ao inserir elemento
}

void mostrarTabelaHash(tbhash tab) {
    printf("Tabela Hash:\n");
    for (int i = 0; i < N; i++) {
        printf("Posição %d: ", i);
        if (tab[i] != NULL) {
            printf("%d", tab[i]);
        } else {
            printf("NULL");
        }
        printf("\n");
    }
}


void mostrarhash(tbhash tab)
{
    int i;

    for(i=0; i<N; i++)
    {
        if(tab[i]!=NULL)
        {
            printf("posicao %d \n", i);
            printf("numero: %d flag\n", tab[i]->num);
        }
        else
        {
            printf("posicao %d: NULL \n", i);
        }
    }
}


