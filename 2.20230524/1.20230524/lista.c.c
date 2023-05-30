#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

LISTA* criarLista(int tamanho) {
    LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
    lista->vetor = (int*)malloc(tamanho * sizeof(int));
    lista->quantidade = 0;
    lista->tamanho = tamanho;
    return lista;
}

void liberarLista(LISTA* lista) {
    free(lista->vetor);
    free(lista);
}

void inserirElemento(LISTA* lista, int elem) {
    if (lista->quantidade < lista->tamanho) {
        lista->vetor[lista->quantidade] = elem;
        lista->quantidade++;
    }
}

void inserirElementoOrdenado(LISTA* lista, int elem) {
    int i = lista->quantidade - 1;
    while (i >= 0 && lista->vetor[i] > elem) {
        lista->vetor[i + 1] = lista->vetor[i];
        i--;
    }
    lista->vetor[i + 1] = elem;
    lista->quantidade++;
}

void imprimirLista(LISTA* lista) {
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%d ", lista->vetor[i]);
    }
    printf("\n");
}

int buscarElementoSequencial(LISTA* lista, int elem) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->vetor[i] == elem) {
            return i;
        }
    }
    return -1;
}

int buscarElementoSequencialOrdenado(LISTA* lista, int elem) {
    int i = 0;
    while (i < lista->quantidade && lista->vetor[i] < elem) {
        i++;
    }
    if (i < lista->quantidade && lista->vetor[i] == elem) {
        return i;
    }
    return -1;
}

int buscaBinariaIterativa(LISTA* lista, int elem) {
    int esquerda = 0;
    int direita = lista->quantidade - 1;
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (lista->vetor[meio] == elem) {
            return meio;
        }
        if (lista->vetor[meio] < elem) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

int buscaBinariaRecursiva(LISTA* lista, int elem, int esquerda, int direita) {
    if (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (lista->vetor[meio] == elem) {
            return meio;
        }
        if (lista->vetor[meio] < elem) {
            return buscaBinariaRecursiva(lista, elem, meio + 1, direita);
        } else {
            return buscaBinariaRecursiva(lista, elem, esquerda, meio - 1);
        }
    }
    return -1;
}

void imprimirListaRecursiva(LISTA* lista, int indice) {
    if (indice < lista->quantidade) {
        printf("%d ", lista->vetor[indice]);
        imprimirListaRecursiva(lista, indice + 1);
    } else {
        printf("\n");
    }
}

int buscarMaiorElementoIterativo(LISTA* lista) {
    int maior = lista->vetor[0];
    for (int i = 1; i < lista->quantidade; i++) {
        if (lista->vetor[i] > maior) {
            maior = lista->vetor[i];
        }
    }
    return maior;
}

int buscarMaiorElementoRecursivo(LISTA* lista, int indice) {
    if (indice == lista->quantidade - 1) {
        return lista->vetor[indice];
    }
    int maiorRestante = buscarMaiorElementoRecursivo(lista, indice + 1);
    return (lista->vetor[indice] > maiorRestante) ? lista->vetor[indice] : maiorRestante;
}

int buscarMenorElementoIterativo(LISTA* lista) {
    int menor = lista->vetor[0];
    for (int i = 1; i < lista->quantidade; i++) {
        if (lista->vetor[i] < menor) {
            menor = lista->vetor[i];
        }
    }
    return menor;
}

int buscarMenorElementoRecursivo(LISTA* lista, int indice) {
    if (indice == lista->quantidade - 1) {
        return lista->vetor[indice];
    }
    int menorRestante = buscarMenorElementoRecursivo(lista, indice + 1);
    return (lista->vetor[indice] < menorRestante) ? lista->vetor[indice] : menorRestante;
}

int calcularSomaIterativa(LISTA* lista) {
    int soma = 0;
    for (int i = 0; i < lista->quantidade; i++) {
        soma += lista->vetor[i];
    }
    return soma;
}

int calcularSomaRecursiva(LISTA* lista, int indice) {
    if (indice == lista->quantidade) {
        return 0;
    }
    return lista->vetor[indice] + calcularSomaRecursiva(lista, indice + 1);
}

int calcularProdutoIterativo(LISTA* lista) {
    int produto = 1;
    for (int i = 0; i < lista->quantidade; i++) {
        produto *= lista->vetor[i];
    }
    return produto;
}

int calcularProdutoRecursivo(LISTA* lista, int indice) {
    if (indice == lista->quantidade) {
        return 1;
    }
    return lista->vetor[indice] * calcularProdutoRecursivo(lista, indice + 1);
}

