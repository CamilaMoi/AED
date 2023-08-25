#include <stdio.h>
#include <stdlib.h>
#include"pilhaestudar.h"

int main()
{
    PILHA pilhamain;
    AVIAO aviao, *avi;
    int qtd;

    inicializar(&pilhamain);

    aviao.id=9;
    aviao.nome="boioiong";
    inserir(&pilhamain, aviao);

    aviao.id=15;
    aviao.nome="boioiong 2";
    inserir(&pilhamain, aviao);

    mostrarpilha(&pilhamain);

    qtd=numavioes(&pilhamain);
    printf("quant de avioes e %d \n", qtd);

    excluirpos(&pilhamain, 9);
    mostrarpilha(&pilhamain);

    return 0;
}
