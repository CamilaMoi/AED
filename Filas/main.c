#include <stdio.h>
#include <stdlib.h>
#include"filaprova.h"

int main()
{
    FILA filamain;
    AVIAO aviaomain, *avi;

    inicializar(&filamain);

    aviaomain.id=12;
    aviaomain.nome="moing";
    inserir(&filamain, aviaomain);

    aviaomain.id=15;
    aviaomain.nome="boingers";
    inserir(&filamain, aviaomain);

    mostrarfila(&filamain);

    excluir(&filamain);
    printf("um elemento foi excluido \n");

    mostrarfila(&filamain);

    return 0;
}
