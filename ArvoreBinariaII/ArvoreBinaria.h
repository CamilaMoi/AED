#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

typedef struct aux
{
    int valor;
    struct aux* dir;
    struct aux* esq;
}NO;

typedef struct
{
    NO* raiz;
} ARVORE;



#endif // ARVOREBINARIA_H_INCLUDED
