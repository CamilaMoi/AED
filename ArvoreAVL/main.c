#include <stdio.h>
#include <stdlib.h>

int main()
{
    ARVORE a;
    inicializar(&a);
    PACIENTE np;

    np.cod_pac=3;
    np.nome="prova";
    criarNo(&a, np);
    return 0;
}
