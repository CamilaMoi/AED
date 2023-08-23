#include "ArvoreBinaria.h"
#include<stdio.h>
#include<stdlib.h>

void inicializar(ARVORE *a)
{
    a->raiz=NULL;
}

NO *criarNO(int num)
{
    NO * novoNO=malloc(sizeof(NO));

    novoNO->valor=num;
    novoNO->esq=NULL;
    novoNO->dir=NULL;

    return novoNO;
}

NO *inserir(NO *raiz, NO* novoNO)
{
    if(raiz==NULL) return novoNO;

    if(novoNO->valor<raiz->valor)
    {
        raiz->esq=inserir(raiz->esq, novoNO);
    }
    if(novoNO->valor>raiz->valor)
    {
        raiz->dir=inserir(raiz->dir, novoNO);
    }

    return (raiz);
}

int inserirARV(ARVORE *a, NO *novo)
{
    a->raiz=inserir(a->raiz, novo);

    return 1;
}

NO* inserirARV2(ARVORE *a, int num) {
    NO *novoNO = criarNO(num);
    inserirARV(a, novoNO);
    return novoNO;
}

NO *busca(NO *raiz, int num)
{
    if(raiz==NULL) return NULL;
    if(raiz->valor==num) return (raiz);

    if(num<raiz->valor)
    {
        return busca(raiz->esq, num);
    }
    else if(num>raiz->valor)
    {
        return busca(raiz->dir, num);
    }
}

NO* buscaARV(ARVORE* a, int num)
{
    return (busca(a->raiz, num));
}

void listarARV(ARVORE* a)
{
    listarINORDEM(a->raiz);
}

/*void listarPREORDEM(NO* raiz)
{
    printf("%d ", raiz->valor);
    listarPREORDEM(raiz->esq);
    listarPREORDEM(raiz->dir);
}*/

void listarPREORDEM(NO* raiz) {
    if (raiz == NULL) {
        return;
    }

    printf("%d ", raiz->valor);
    listarPREORDEM(raiz->esq);
    listarPREORDEM(raiz->dir);
}


void listarPOSORDEM(NO* raiz)
{
    if (raiz == NULL) {
        return;
    }

    listarPOSORDEM(raiz->esq);
    listarPOSORDEM(raiz->dir);
    printf("%d ", raiz->valor);
}

void listarINORDEM(NO* raiz)
{
    if (raiz == NULL) {
        return;
    }

    listarINORDEM(raiz->esq);
    printf("%d ", raiz->valor);
    listarINORDEM(raiz->dir);
}

int contarNOS(NO* raiz)
{
    if (raiz == NULL) {
        return 0;
    }

    return 1 + contarNOS(raiz->esq) + contarNOS(raiz->dir);
}

int altura(NO* raiz)
{
    if(raiz==NULL) return -1;

    else
    {
        int esq=altura(raiz->esq);
        int dir=altura(raiz->dir);
        if(esq>dir) ///pq � o maior caminho entre a raiz e um no folha
        {
            return esq+1;
        }
        else
        {
            return dir+1;
        }
    }
}

void percorrernivel(NO* raiz, int nivelatual)
{
    if(raiz==NULL)
    {
        return;
    }

    if(nivelatual==1)
    {
        printf("%d", raiz->valor);
    }
    if(nivelatual>1)
    {
        percorrernivel(raiz->esq, nivelatual-1);
        percorrernivel(raiz->dir, nivelatual-1);
    }
}

void percorrerniveis(NO* raiz)
{
    int h=altura(raiz); ///altura total da arvore p tds as itera��es
    int i;

    for(i=0; i<=h; i++)
    {
        percorrernivel(raiz, i);
    }
}

int profundidadeNO(NO *raiz, int num) ///tstar
{
    int count=0;

    if(raiz==NULL) return -1;
    if(raiz->valor==num) return 0;

    if(num<raiz->valor)
    {
        int esquerda= profundidadeNO(raiz->esq, num);
        if(esquerda!=-1)
        {
            return esquerda+1;
        }
    }
    else if(num>raiz->valor)
    {
        int direita= profundidadeNO(raiz->dir, num);
        if(direita!=-1)
        {
            return direita +1;
        }
    }

    return -1; //no nqo encontrado
}

///excluir elemento

NO* buscaNO(NO* raiz, int num, NO**pai)
{
    //bb nao recursiva

    NO *atual=raiz;
    *pai=NULL;

    printf("Pai: ", pai);

    while(atual)
    {
        if(atual->valor==num) return atual;
        *pai=atual;
        if(num<atual->valor) atual=atual->esq;
        else atual=atual->dir;
    }

    return (NULL);
}

int excluirno(NO *raiz, int num)
{
    NO *no;
    NO *pai;
    NO *pai_do_nosub;
    NO *no_sub;

    no=buscaNO(raiz, num, &pai);

    if(no==NULL) return (0);

    if(!no->esq || !no->dir)
    {
        if(!no->esq) no_sub=no->dir;
        else no_sub=no->esq;
    }
    else
    {
        ///tem os dois descendentes
        pai_do_nosub=no;
        no_sub=no->esq;
        while(no_sub->dir)
        {
            pai_do_nosub=no_sub;
            no_sub=no_sub->dir;
        }
        if(pai_do_nosub!=no)
        {
            pai_do_nosub->dir=no_sub->esq;
            no_sub->esq=no->esq;
        }
        no_sub->dir=no->dir;
    }
    if(!pai)
    {
        free(no);
        return 1;
    }

    if(num<pai->valor) pai->esq=no_sub;
    else pai->dir=no_sub;
    free(no);
    return 1;
}
