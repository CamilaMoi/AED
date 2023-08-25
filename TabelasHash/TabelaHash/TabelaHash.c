#include <stdio.h>
#include <stdlib.h>
#include"tabelahash.h"

void inicializar(TABELA* tab)
{
    int i;
    for(i = 0; i < N; i++)
    {
        tab->TBHASH[i] = NULL;
    }
}

int m_hash(int cod)
{
    return(cod%N);
}

int inserir(TABELA* tab, PACIENTE pac)
{
    int h = m_hash(pac.codigo);

    while (tab->TBHASH[h] != NULL) {
        if (tab->TBHASH[h]->codigo == pac.codigo) {

            return 0; // Código de retorno para indicar falha (código já existente)
        }
        h = (h + 1) % N;
    }

    // A posição está vazia, então podemos inserir o novo paciente
    tab->TBHASH[h] = malloc(sizeof(PACIENTE));
    *(tab->TBHASH[h]) = pac;
    return 1; // Código de retorno para indicar sucesso
}

int inserirflag(TABELA* tab, PACIENTE pac)
{
    int h = m_hash(pac.codigo);

    while (tab->TBHASH[h] != NULL) {
        if (tab->TBHASH[h]->codigo == pac.codigo)
        {
            if(tab->TBHASH->flag==1)
            {
                *(tab->TBHASH[i])=pac;
                tab->TBHASH[i]->flag=0; //p indicar q foi preenchido
                printf("paciente substituido");
                return 0;
            }
            else
            {
                printf("paciente na lista");
            }
        }
        h = (h + 1) % N;
    }
    if(tab->TBHASH[i]==NULL || tab->TBHASH[i]->flag==1)
    {
        tab->TBHASH[h] = malloc(sizeof(PACIENTE));
        *(tab->TBHASH[h]) = pac;
        tab->TBHASH[i]->flag=0 //marca o paciente como dentro
    }
    return 1; // Código de retorno para indicar sucesso
}

PACIENTE *busca(TABELA tab, int cod)
{
    int h=m_hash(cod);

    while(tab.TBHASH[h]!=NULL)
    {
        if(tab.TBHASH[h]->codigo==cod)
        {
            return tab.TBHASH[h];
        }
    h=(h+1)%N;
    }
    return NULL;
}

void mostrartabela(TABELA *tab)
{
    int i;
    for(i=0; i<N; i++)
    {
        if(tab->TBHASH[i]!=NULL)
        {
            printf("paciente: %d \n", i);
            printf("nome: %s\n", tab->TBHASH[i]->nome);
            printf("cpf: %s \n", tab->TBHASH[i]->cpf);
            printf("idade %d \n", tab->TBHASH[i]->idade);
            printf("codigo %d \n", tab->TBHASH[i]->codigo);
        }
        else
        {
            printf("paciente:%d NULL \n", i);
        }
        printf("\n");
    }
}

void excluir(TABELA *tab, int cod)
{
    int i=m_hash(cod);

    while(tab->TBHASH[i]!=NULL && tab->TBHASH[i].codigo!=cod)
    {
        if(tab->TBHASH[i].codigo==cod)
        {
            tab->TBHASH[i]->flag=1;
        }
        i++;
    }
}
