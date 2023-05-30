#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    float coef;
} Aluno;

typedef struct {
    Aluno* alunos;
    int quantidade;
} Turma;

