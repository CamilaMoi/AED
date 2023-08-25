#include <stdio.h>
#include <stdlib.h>
#include"tabelahashII.h"
#define N 9
int main()
{
    TABELA tabhash;
    PACIENTE pac, *p;

    inicializar(&tabhash);

    pac.codigo=1291;
    pac.cpf="002003004";
    pac.idade=9;
    pac.nome="moi";
    inserir(&tabhash, pac);

    pac.codigo=1191;
    pac.cpf="002003005";
    pac.idade=18;
    pac.nome="italo";
    inserir(&tabhash, pac);

    pac.codigo=1089;
    pac.cpf="005006007";
    pac.idade=19;
    pac.nome="cortezz";
    inserir(&tabhash, pac);

    mostrarhash(&tabhash);
    excluir(&tabhash, 1191);
    mostrarhash(&tabhash);

    return 0;
}
