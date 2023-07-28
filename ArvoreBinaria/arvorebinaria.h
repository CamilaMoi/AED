#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED

typedef struct
{
    int valores;
    struct aux * direita;
    struct aux * esquerda;

} ELEMENTO;


typedef struct{
    ELEMENTO* raiz;
} ARVORE;


#endif // ARVOREBINARIA_H_INCLUDED
