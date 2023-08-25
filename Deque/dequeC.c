#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"arquivoDeque.h"

void inicializarDeque(DEQUE*d)
{
    d->cabeca=malloc(sizeof(ELEMENTO));
    d->cabeca->anterior=d->cabeca; //anterior vai ser a cabeca e o proximo tb pq n tem ngm no dque ainda
    d->cabeca->proximo=d->cabeca;
}

void reinicializar(DEQUE *d)
{
    ELEMENTO *apagar;
    ELEMENTO *elem=d->cabeca->proximo;

    while(elem!=d->cabeca)
    {
        apagar=elem;
        elem=elem->proximo;
        free(apagar);

        //apagar vai receber todos os elementos do deque ate chegar ao fim com elem->proximo e apagar com free
    }
    d->cabeca->anterior=d->cabeca;
    d->cabeca->proximo=d->cabeca;

    //anterior e proximo apontam p cabeca como no comeco

}


void mostrarDequedireto(DEQUE *d, char *nomeposicao)
{
    printf("-----------------------\n");
    ELEMENTO*i=d->cabeca->proximo; //pq o looping v ai para qnd chegar na cabeca
     while (i != d->cabeca)
    {
        if (strcmp(i->aluno.nome, nomeposicao) == 0)
        {
            ELEMENTO *cont = i;
            while (cont != d->cabeca)
            {
                printf("------------------\n");
                printf("nome: %s\n", cont->aluno.nome);
                cont = cont->proximo;
            }
            break;
        }
        i = i->proximo;
    }
}

void mostrarDequeIndireto(DEQUE *d, char *nomeposicao)
{
    printf("-----------------------\n");
    ELEMENTO*i=d->cabeca->anterior; //pq o looping v ai para qnd chegar na cabeca
     while (i != d->cabeca)
    {
        if (strcmp(i->aluno.nome, nomeposicao) == 0)
        {
            ELEMENTO *cont = i;
            while (cont != d->cabeca)
            {
                printf("------------------\n");
                printf("nome: %s\n", cont->aluno.nome);
                cont = cont->anterior;
            }
            break;
        }
        i = i->anterior;
    }
}

int inserirNoInicio(DEQUE *d, ALUNO novo_aluno)
{
    //alocar memoria p novo paciente do tipo elemento
    ELEMENTO *i;
    i=(ELEMENTO*) malloc(sizeof(ELEMENTO));
    i->aluno=novo_aluno; //variavel recebe o novo pacinte mas ainda n esta no dequr
    i->proximo=d->cabeca->proximo;
    //o proximo do novo paciente vai receber a o primeiro elemento do antigo deque
    i->anterior=d->cabeca;
    //o anterior do novo i vai ser a cabeca do deque
    d->cabeca->proximo=i;
    //primeira posicao recebe o elemento
    i->proximo=i;

    return 1;
}

int inserirNoFim(DEQUE*d, ALUNO novo_aluno)
{
    ELEMENTO*i;
    //alocar memoria
    i=malloc(sizeof(ELEMENTO));
    i->aluno=novo_aluno;
    i->proximo=d->cabeca;
    //proximo desse elemtno vai rceber cabeca do dequr
    i->anterior=d->cabeca->anterior;
    //anterior de i vai receber o antigo ultimo
    d->cabeca->anterior=i;
    i->proximo=i;

    return 1;
}

int excluirNoInicio(DEQUE* d)
{
    if(d->cabeca->proximo=d->cabeca) return 0;
    //se o prox da cabeca for cabeca o deck ta vazio
    else
    {
        ELEMENTO *i=d->cabeca->proximo;
        //inicializando variavel como o 2 elem do deck
        d->cabeca->proximo=i->proximo;
        //ese proximo vai ser o mesmo segundo elemento inicializado
        i->anterior=d->cabeca;
        //fazendo o anterior so segundo elemtno ser a cabeca
        free(i);
        //apagando i
        return 1;
    }
}

/*int excluirNoFim(DEQUE *d)
{
    if(d->cabeca->proximo==d->cabeca) return 0;
    else
    {
        ELEMENTO *i=d->cabeca->anterior;
        //i recebe o valor do penultilo delemnto do deque
        d->cabeca->anterior=i->anterior;
        //posicao panultima recebe i
        i->anterior->proximo=d->cabeca;
        //fazendo proximo de i apontar p cabeca removendo o elemtno do fim
        free(i);
        //desocupando memoria
        return 1;
    }
}

PACIENTE returnInicio(DEQUE*d)
{
    return d->cabeca->proximo->pac;
}

PACIENTE returnFim(DEQUE *d)
{
    return d->cabeca->anterior->pac;
}
*/
