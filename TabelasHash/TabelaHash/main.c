#include <stdio.h>
#include <stdlib.h>
#include"tabelahash.h"

int main()
{
    TABELA *tabhash;
    PACIENTE pac, *paci;

    inicializar(&tabhash);

    pac.codigo=9;
    pac.cpf=002003004;
    pac.idade=12;
    pac.nome="camila";
    inserir(&tabhash, pac);

    pac.codigo=90;
    pac.cpf=002003005;
    pac.idade=15;
    pac.nome="cortez";
    inserir(&tabhash, pac);

    pac.codigo=110;
    pac.cpf=002003007;
    pac.idade=19;
    pac.nome="italo";
    inserir(&tabhash, pac);

    mostrartabela(&tabhash);
    excluir(&tabhash, 110);
    mostrar(&tabhash);


}
