#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

typedef struct aux
{
    int valor;
    int h;
    struct aux* dir;
    struct aux* esq;
} NO;

typedef struct
{
    NO *raiz;
} ARVORE;

#endif // ARVOREAVL_H_INCLUDED
