#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"

Turma* criarTurma(int quantidadeAlunos) {
    Turma* turma = (Turma*)malloc(sizeof(Turma));
    turma->alunos = (Aluno*)malloc(quantidadeAlunos * sizeof(Aluno));
    turma->quantidade = 0;
    return turma;
}

void liberarTurma(Turma* turma) {
    free(turma->alunos);
    free(turma);
}

void inserirAluno(Turma* turma, int codigo, char* nome, int idade, float coef) {
    if (turma->quantidade < sizeof(turma->alunos)) {
        Aluno aluno;
        aluno.codigo = codigo;
        strcpy(aluno.nome, nome);
        aluno.idade = idade;
        aluno.coef = coef;
        turma->alunos[turma->quantidade] = aluno;
        turma->quantidade++;
    } else {
        printf("Turma cheia, não é possível inserir mais alunos.\n");
    }
}

int buscarAlunoSeq(Turma* turma, int codigo) {
    for (int i = 0; i < turma->quantidade; i++) {
        if (turma->alunos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void imprimirAluno(Aluno aluno) {
    printf("cod: %d\n", aluno.codigo);
    printf("nome: %s\n", aluno.nome);
    printf("idade: %d\n", aluno.idade);
    printf("coef: %.2f\n", aluno.coef);
}

void buscarAlunoBinarioRecursivo(Turma* turma, int codigo, int esquerda, int direita) {
    if (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (turma->alunos[meio].codigo == codigo) {
            imprimirAluno(turma->alunos[meio]);
            return;
        }
        if (turma->alunos[meio].codigo < codigo) {
            buscarAlunoBinarioRecursivo(turma, codigo, meio + 1, direita);
        } else {
            buscarAlunoBinarioRecursivo(turma, codigo, esquerda, meio - 1);
        }
    } 
}

void imprimirTurma(Turma* turma) {
    for (int i = 0; i < turma->quantidade; i++) {
        printf("Código: %d\n", turma->alunos[i].codigo);
        printf("Nome: %s\n", turma->alunos[i].nome);
        printf("\n");
    }
}

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
    
