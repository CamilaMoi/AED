#include <stdio.h>
#include <stdlib.h>
#include "pilhaestudar.h"

void inicializar(PILHA *pilha)
{
    pilha->topo=NULL;
}

int pilhacheia(PILHA *pilha)
{
    ELEMENTO *e=malloc(sizeof(ELEMENTO));
    if(e==NULL)
    {
        return 0; //se e for igual null n conseguiu alocar memoria, ent ta cheia retornando 0 q e fracasso
    }
    else
    {
        return 1;
    }
}

int inserir(PILHA *pilha, AVIAO novoaviao)
{
    ELEMENTO *i=malloc(sizeof(ELEMENTO));
    if(i==NULL)
    {
        printf("erro ao alocar memoria");
    }

    i->aviao=novoaviao;
    i->proximo=pilha->topo;
    pilha->topo=i;
    return 1;
}

int excluir(PILHA *pilha)
{
    if(pilha->topo==NULL) //se a pilha estiver vazia
    {
        return 0;
    }
    else
    {
        ELEMENTO *i=pilha->topo;
        pilha->topo=pilha->topo->proximo; //topo da çpilha vai receber oq estiver embaixo
        free(i); //liberar a memoria do elkemento que se quer excluir
        return 1;
    }
}

void mostrarpilha(PILHA *pilha)
{
    printf("---------------------------------- \n");
    if(pilha->topo==NULL)
    {
        printf("pilha vazia");
    }

    ELEMENTO* e=pilha->topo;
    while(e!=NULL)
    {
        printf("%d ", e->aviao.id);
        printf("%s \n", e->aviao.nome);
        e=e->proximo;
    }
    printf("\n");

}

int numavioes(PILHA *pilha)
{
    ELEMENTO *i=pilha->topo;
    int count=0;

    while(i!=NULL)
    {
        count++;
        i=i->proximo;
    }
    return count;
}

int excluirpos(PILHA *pilha, int id)
{
    ELEMENTO *atual=pilha->topo;
    ELEMENTO *anterior;
    while(atual!=NULL)
    {
        if(atual->aviao.id==id)
        {
            if(anterior==NULL)
            {
                pilha->topo=atual->proximo;
            }
            else
            {
                anterior->proximo=atual->proximo; //o elemento atual vai ser substituido pelo proximo dele que é o que esta de baixo
            }
            free(atual);
        }
        anterior=atual;
        atual=atual->proximo;
    }

}
