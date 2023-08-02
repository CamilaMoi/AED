#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

typedef struct
{
    int cod_pac;
    char nome[50];
    char cpf[11];
    int idade;
} PACIENTE;

typedef struct
{
    PACIENTE pac;
    aux *esquerda;
    aux *direita;
    int h;
} NO;

typedef struct
{
    NO * raiz;
}ARVORE;


#endif // ARVOREAVL_H_INCLUDED
