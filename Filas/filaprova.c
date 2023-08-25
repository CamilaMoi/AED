#include <stdio.h>
#include <stdlib.h>
#include"filaprova.h"

void inicializar(FILA *fila)
{
    fila->inicio=NULL;
    fila->fim=NULL;
}

void reinicializar(FILA *fila)
{
    ELEMENTO *apagar;
    ELEMENTO *elem=fila->inicio; //p percorrer a fila no while

    while(elem!=NULL)
    {
        apagar=elem;
        elem=elem->proximo;
        free(apagar);
    }
    fila->inicio=NULL;
}

int inserir(FILA *fila, AVIAO aviao)
{
    ELEMENTO* i;
    i=malloc(sizeof(ELEMENTO));
    if(i==NULL)
    {
        return 0;
    }

    i->aviao=aviao;
    i->proximo=NULL;
    if(fila->inicio==NULL) //se a fila estiver vazia
    {
        fila->inicio=i;
    }
    else
    {
        fila->fim->proximo=i;
    }
    fila->fim=i; //atualizar esse ponteiro pq se n o fim vai ser o antigo fim
    return 1;
}

int excluir(FILA *fila)
{
    if(fila->inicio==NULL)
    {
        return 0;
    }
    ELEMENTO *i=fila->inicio;
    fila->inicio=fila->inicio->proximo;
    free(i);
    return 1;
}

void mostrarfila(FILA *fila)
{
    printf("---------------------------- \n");
    if(fila->inicio==NULL)
    {
        printf("vazia \n");
    }

    ELEMENTO *i=fila->inicio;

    while(i!=NULL)
    {
        printf("id: %d \n", i->aviao.id);
        printf("nome: %s \n", i->aviao.nome);
        i=i->proximo;
    }
}
