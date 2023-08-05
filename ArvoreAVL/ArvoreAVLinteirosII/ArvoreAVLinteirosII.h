#ifndef ARVOREAVLINTEIROSII_H_INCLUDED
#define ARVOREAVLINTEIROSII_H_INCLUDED

typedef struct No {
    int num;
    struct No *esquerda;
    struct No *direita;
    int h;
} NO;

typedef struct {
    NO *raiz;
} ARVORE;


#endif // ARVOREAVLINTEIROSII_H_INCLUDED
