#include <stdio.h>
#include <stdlib.h>
#include"tabelahashII.h"

void inicializar(TABELA *tab)
{
    int i;

    for(i=0; i<N; i++)
    {
        tab->TBHASH[i]=NULL;
    }
}

int m_hash(int cod)
{
    return(cod%N);
}

/*int inserir(TABELA *tab, PACIENTE pac)
{
    int h=m_hash(pac.codigo);
    ELEMENTO *anterior=NULL;
    ELEMENTO *e=tab->TBHASH[h];
    while(e!=NULL)
    {
        if(e->pac->codigo==pac.codigo) //p qnd o cod ja estier na lista
        {
            return 0;
        }
        anterior=e;
        e=e->proximo;
    }

    e=malloc(sizeof(ELEMENTO));
    e->pac=pac;
    e->proximo=NULL;

    if(e==NULL)
    {
        return 0;
    }
    if(anterior==NULL) //qnd for inserir na prim posicao da lista
    {
        tab->TBHASH[h]=e;
    }
    else //inserir em qualquer outra posicao da lsta
    {
        anterior->proximo=e;
    }
    return 1;
}*/

int inserir(TABELA* tab, PACIENTE pac)
{
    int h = m_hash(pac.codigo);
    ELEMENTO* e = malloc(sizeof(ELEMENTO));
    if (e == NULL) {
        printf("Erro ao alocar memória para o novo elemento.\n");
        return;
    }

    e->pac = malloc(sizeof(PACIENTE));
    if (e->pac == NULL) {
        printf("Erro ao alocar memória para o paciente.\n");
        free(e);
        return;
    }

    *(e->pac) = pac;
    e->proximo = NULL;

    if (tab->TBHASH[h] == NULL) {
        tab->TBHASH[h] = e;
    } else {
        ELEMENTO* atual = tab->TBHASH[h];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = e;
    }
    return 1;
}


PACIENTE *busca(TABELA *tab, int cod)
{
    int h=m_hash(cod);
    ELEMENTO *e=tab->TBHASH[h];
    while(e!=NULL)
    {
        if(e->pac->codigo==cod)
        {
            return (e->pac);
        }
        e=e->proximo;
    }
    return NULL;
}

void mostrarhash(TABELA *tab) //passndo parametro por ponteiro vai usar seta, tem q pasar por ponteiro pq vai mudar os valores de dentro da funcao
{
    ELEMENTO *e;
    int i;
    for(i=0; i<N; i++)
    {
        if(tab->TBHASH[i]!=NULL)
        {
            e=tab->TBHASH[i];
            printf("paciente: %d", i);
            while(e!=NULL)
            {
                /*printf("codigo: %d \n", e->pac->codigo );//tab->TBHASH[i]->codigo);
                printf("idade: %d \n", e->pac->idade  );//tab->TBHASH[i]->idade);
                printf("cpf: %s \n",   e->pac->cpf);//tab->TBHASH[i]->cpf);*/
                printf("nome: %s \n",  e->pac->nome );//tab->TBHASH[i]->nome);
                e=e->proximo;
            }
        printf("\n");
        }
        else
        {
            printf("PACIENTE: %d NULL \n", i);
        }
    }
}

void excluir(TABELA *tab, int cod)
{
    int h=m_hash(cod);
    ELEMENTO *atual=tab->TBHASH[h];
    ELEMENTO *anterior=NULL;

    while(atual!=NULL && atual->pac->codigo!=cod)
    {
        anterior=atual;
        atual=atual->proximo;
    }

    if(atual==NULL)
    {
        printf("nao encontrado");
    }

    if(anterior==NULL) //qnd for o primeiro elemento da lista
    {
        tab->TBHASH[h]=atual->proximo; //pq oatual é o elemento que se quer excluir
    }
    else //#pprt
    {
        anterior->proximo=atual->proximo;
    }
    free(atual);
}
