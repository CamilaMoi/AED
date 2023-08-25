#ifndef FILAPROVA_H_INCLUDED
#define FILAPROVA_H_INCLUDED

typedef struct
{
    int id;
    char *nome;
} AVIAO;

typedef struct aux
{
    AVIAO aviao;
    struct aux *proximo;
} ELEMENTO;

typedef struct
{
    ELEMENTO *inicio;
    ELEMENTO *fim;
} FILA;

void inicializar(FILA *fila);
void reinicializar(FILA *fila);
int inserir(FILA *fila, AVIAO aviao);
int excluir(FILA *fila);
void mostrarfila(FILA *fila);

#endif // FILAPROVA_H_INCLUDED
