#ifndef HASHDUPLO_H_INCLUDED
#define HASHDUPLO_H_INCLUDED
#define N 11

typedef struct
{
    int chave;
    int num;
} INTEIROS;

typedef INTEIROS *tbhash[N];

void inicializar(tbhash tab);
int hash1(int num);
int hash2(int num);
int hashduplo(int num, int tentativa)
void mostrarTabelaHash(tbhash tab); //preferivel
void mostrarhash(tbhash tab);
int inserir(tbhash tab, int num);

#endif // HASHDUPLO_H_INCLUDED
