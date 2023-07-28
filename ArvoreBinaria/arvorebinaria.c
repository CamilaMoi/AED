#include<stdio.h>
#include<stdlib.h>
#include "arvorebinaria.h"

void inicializar(ARVORE * a)
{
        a->raiz=NULL;
}

ELEMENTO * criarNo(ELEMENTO * num)
{
        ELEMENTO* novoElemento=malloc(sizeof(ELEMENTO));
        novoElemento->valores=num;
        novoElemento->esquerda=NULL;
        novoElemento->direita=NULL;
        return novoElemento;
}

int adicionar( ARVORE *a, ELEMENTO *novo)
{
    a->raiz=inserir(a->raiz, novo);
    return 1;
}

 int inserir(ELEMENTO * raiz, ELEMENTO* novo)
 {
        //criar um no p inserir o num
        if(raiz==NULL)  return(novo);

        if(raiz->valores > novo->valores)
        {
            raiz->esquerda=inserir(raiz->esquerda, novo);
        }
        else
        {
            raiz->direita=inserir(raiz->direita, novo);
        }
        return (raiz);

 }

 void listarNOS(ELEMENTO *raiz)
 {
     if(raiz!=NULL)
     {
         listarNOS(raiz->esquerda);
         //printf("n esquerda: %d \n", raiz->esquerda);
         //printf("n direita: %d \n", raiz->direita);
         printf(" %d  ", raiz->valores);
         listarNOS(raiz->direita);
     }
 }

 void listarPreOrdem(ELEMENTO *raiz)
 {
     if(raiz!=NULL)
     {
         printf(" %d  ", raiz->valores);
         listarPreOrdem(raiz->esquerda);
         listarPreOrdem(raiz->direita);
     }
 }

 void listarPosOrdem(ELEMENTO *raiz)
 {
     if(raiz!=NULL)
     {
         listarPosOrdem(raiz->esquerda);
         listarPosOrdem(raiz->direita);
         printf(" %d  ", raiz->valores);
     }
 }

  void listararvore(ARVORE *a)
  {
        listarNOS(a->raiz);
  }


int Contador(ELEMENTO *raiz)
{
    int count=0;

    if(raiz!=NULL)
    {
        int c1=Contador(raiz->esquerda);
        int c2=Contador(raiz->direita);
        count=c1+c2+1;
        return count;
    }
}

