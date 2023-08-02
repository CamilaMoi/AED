#include<stdio.h>
#include<stdlib.h>
#include "ArvoreAVL.h"

void inicializar(ARVORE * a)
{
        a->raiz=NULL;
}

NO * criarNo(PACIENTE *p)
{
        NO* novoNo=malloc(sizeof(NO));
        novoNo->pac=p
        novoNo->h=0
        novoNo->esquerda=NULL;
        novoNo->direita=NULL;
        return novoNo;
}
int maximo(int v1, int v2)
{
    if(v1>v2)
        return v1;
    else
        return v2;
}

/////calculaR altura de cada no
int altura(NO *raiz)
{
    if(!raiz) return (-1);
    else return (raiz->h);
}

////rotacoes da direita

NO *rot_direita(NO *no_desb)
{
    NO* aux;

    aux=no_desb->esquerda;
    no_desb->esquerda=aux->direita;
    aux->direita=no_desb;

    no_desb->h=maximo(altura(no_desb->direita), altura(no_desb->esquerda)) +1;
    aux->h=maximo(altura(aux->esquerda), altura(no_desb))+1;

    return aux;
}

NO *rot_esquerda(NO *no_desb)
{
    NO *aux;

    aux=no_desb->direita;
    no_desb->direita=aux->esquerda;
    aux->esquerda=no_desb;

    no_desb->h=maximo(altura(no_desb->direita), altura(no_desb->esquerda))+1;

    aux->h=maximo(altura(aux->direita), altura(no_desb))+1;

    return aux;
}

NO* rot_esq_direita(NO *no_desb)
{
    no_desb->esquerda=rot_esquerda(no_desb->esquerda);
    return(rot_direita(no_desb));
}

NO *rot_dir_esquerda(NO* no_desb)
{
    no_desb->direita=rot_direita(no_desb->direita);
    return (rot_esquerda(no_desb));
}

NO *inserirAVL(NO* raiz, NO *no)
{
    if(raiz==NULL) return (no);

    if(raiz->pac.cod_pac > no->pac.cod_pac)
    {
        raix->esquerda=inserirAVL(raiz->esquerda, no);
        if((altura(raiz->direita))-(altura(raiz->esquerda))==2)
        {
            if(no->pac.cod_pac < raiz->esquerda->pac.cod_pac)
            {
                raiz=rot_direita(raiz);
            }
            else
                raiz=rot_esq_direita(raiz);
        }

        else
            if(raiz->pac.cod_pac<no->pac.cod_pac)
            {
                raiz->direita=inserirAVL(raiz->direita, no);
                if((altura(raiz->direita)-altura(raiz->esquerda))==2)
                {
                    if(no->pac.cod_pac>raiz->direita->pac.cod_pac)
                    {
                        raiz=rot_esquerda(raiz);
                    }
                    else
                    {
                        raiz=rot_dir_esquerda(raiz);
                    }
                }
            }
        raiz->h=maximo(altura(raiz->esquerda), altura(raiz->direita))+1;
        return (raiz);
    }
}
