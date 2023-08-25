#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED
#define N 9

typedef struct
{
    int idade;
    int codigo;
    int flag;
    char* cpf;
    char* nome;
} PACIENTE;

typedef struct
{
    PACIENTE *TBHASH[N];
} TABELA;

void inicializar(TABELA *tab);
int inserir(TABELA* tab, PACIENTE pac);
int inserirflag(TABELA* tab, PACIENTE pac);
PACIENTE *busca(TABELA tab, int cod);
void mostrartabela(TABELA *tab);
void excluir(TABELA *tab, int cod)





#endif // TABELAHASH_H_INCLUDED
