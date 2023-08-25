#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"arquivoDeque.h"

int main()
{
    DEQUE deque;
    int opcao;
    ALUNO novo_alunomain;

    inicializarDeque(&deque);

    ALUNO aluno;

    aluno.nome="moi";
    inserirNoInicio(&deque, aluno);

    aluno.nome="italo";
    inserirNoFim(&deque, aluno);

    aluno.nome="cortez";
    inserirNoFim(&deque, aluno);


     printf("1-inserir no inicio \n 2-inserir no fim \n 3-excluir do inicio \n 5-mostrar lista direta \n 6-mostrar lista indireta\n");
     scanf("%d", &opcao);

     switch()
     {
        case 1:
            printf("noime do aluno:");
            scanf("%s", novo_alunomain);
            inserirNoInicio(&deque, novo_alunomain);
            break;
        case 2:
            printf("noime do aluno:");
            scanf("%s", novo_alunomain);
            inserirNoFim(&deque, novo_alunomain);
            break;
        case 3:
            excluirNoInicio(&deque);
            printf("elem excluido \n");
            break;
        case 4:
            mostrarDequedireto(&deque, "moi");
            break;
        case 5:
            mostrarDequeIndireto(&deque, "italo");
            break;
        default:
            printf("INVALIDO \n")
     }
    reinicializar(&deque);
    return 0;
}
