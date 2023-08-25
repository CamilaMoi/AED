#include <stdio.h>
#include <stdlib.h>
#include"hashduplo.h"

int main()
{
    tbhash tabela;
    INTEIROS i, *in;

    inicializar(tabela);

    i.num=365;
    inserir(tabela, 365);
    i.num=112;
    inserir(tabela, 112);
    i.num=180;
    inserir(tabela, 180);
    i.num=213;
    inserir(tabela, 213);
    i.num=13;
    inserir(tabela, 13);
    i.num=27;
    inserir(tabela, 27);

    mostrarTabelaHash(tabela);

    return 0;
}
