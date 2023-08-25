#ifndef ARQUIVODEQUE_H_INCLUDED
#define ARQUIVODEQUE_H_INCLUDED

typedef struct
{
    char *nome;
} ALUNO;

typedef struct
{
    ALUNO aluno;
    struct aux* proximo;
    struct aux* anterior;
} ELEMENTO;

typedef struct
{
    ELEMENTO *cabeca;
} DEQUE;

void inicializarDeque(DEQUE *f);
int tamanho(DEQUE* f);
void mostrarDeque(DEQUE *f);
int inserirNoFim(DEQUE *f, PACIENTE novo_paciente);
int inserirNoInicio(DEQUE *f, PACIENTE novo_paciente);
int excluirNoInicio(DEQUE *f);
int excluirNoFim(DEQUE*f);
void reinicializar(DEQUE *f);


#endif // ARQUIVODEQUE_H_INCLUDED
