#ifndef TABELAHASHII_H_INCLUDED
#define TABELAHASHII_H_INCLUDED
#define N 9

typedef struct
{
    int idade;
    int codigo;
    char* cpf;
    char* nome;
} PACIENTE;

typedef struct aux
{
    struct aux *proximo;
    PACIENTE *pac;
}ELEMENTO;

typedef struct
{
    PACIENTE *TBHASH[N];
} TABELA;

void inicializar(TABELA *tab);
int m_hash(int cod);
int inserir(TABELA *tab, PACIENTE pac);
PACIENTE *busca(TABELA *tab, int cod);
void mostrarhash(TABELA *tab);
void excluir(TABELA *tab, int cod);

#endif // TABELAHASHII_H_INCLUDED
