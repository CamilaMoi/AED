#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"

int main() {
    int quantidadeAlunos;
    printf("Digite a quantidade de alunos na turma: ");
    scanf("%d", &quantidadeAlunos);
    
    Turma* turma = criarTurma(quantidadeAlunos);
    
    for (int i = 0; i < quantidadeAlunos; i++) {
        int codigo, idade;
        char nome[50];
        float coef;
        
        printf("\nAluno %d\n", i+1);
        printf("Código: ");
        scanf("%d", &codigo);
        printf("Nome: ");
        scanf(" %[^\n]", nome);
        printf("Idade: ");
        scanf("%d", &idade);
        printf("Coeficiente: ");
        scanf("%f", &coef);
        
        inserirAluno(turma, codigo, nome, idade, coef);
    }
    
   
    int codigoBusca;
    printf("\ndigite o código do aluno para busca iterativa: ");
    scanf("%d", &codigoBusca);
    
    int posicao = buscarAlunoSeq(turma, codigoBusca);
    if (posicao != -1) {
        printf("aluno encontrado:\n");
        imprimirAluno(turma->alunos[posicao]);
    }
    
   
    printf("\ndigite o cod do aluno para busca recursiva: ");
    scanf("%d", &codigoBusca);
    
    buscarAlunoBinarioRecursivo(turma, codigoBusca, 0, turma->quantidade - 1);
    
   
    printf(" alunos da turma:\n");
    imprimirTurma(turma);
    
    liberarTurma(turma);
    
    return 0;
}
