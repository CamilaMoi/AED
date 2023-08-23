#ifndef ARVOREAVLCHAR_H_INCLUDED
#define ARVOREAVLCHAR_H_INCLUDED

typedef struct NO {
    char valor;
    int altura;
    struct NO* esq;
    struct NO* dir;
} NO;

typedef struct {
    NO* raiz;
} ARVORE_AVL;


#endif // ARVOREAVLCHAR_H_INCLUDED
