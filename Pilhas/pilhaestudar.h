#ifndef PILHAESTUDAR_H_INCLUDED
#define PILHAESTUDAR_H_INCLUDED

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
    ELEMENTO *topo;
}PILHA;

void inicializar(PILHA *pilha);
int pilhacheia(PILHA *pilha);
int inserir(PILHA *pilha, AVIAO novoaviao);
int excluir(PILHA *pilha);
void mostrarpilha(PILHA *pilha);
int numavioes(PILHA *pilha);
int excluirpos(PILHA *pilha, int id)

#endif // PILHAESTUDAR_H_INCLUDED
