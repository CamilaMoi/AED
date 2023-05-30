#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "lista.c"

int main() {
    LISTA* lista = criarLista(10);
    
   
    inserirElemento(lista, 5);
    inserirElemento(lista, 10);
    inserirElemento(lista, 2);
    inserirElemento(lista, 8);
    inserirElemento(lista, 3);
    
    
    inserirElementoOrdenado(lista, 7);
    
  
    imprimirLista(lista);
    
  
    int posicao = buscarElementoSequencial(lista, 8);
    if (posicao != -1) {
        printf("elem encontrado na posicao %d\n", posicao);
    } 
   
    posicao = buscarElementoSequencialOrdenado(lista, 7);
    if (posicao != -1) {
        printf("elem encontrado na posicao %d\n", posicao);
    }
    
    
    posicao = buscaBinariaIterativa(lista, 10);
    if (posicao != -1) {
        printf("elem encontrado na posicao %d\n", posicao);
    } 
  
    posicao = buscaBinariaRecursiva(lista, 3, 0, lista->quantidade - 1);
    if (posicao != -1) {
        printf("elem encontrado na pos %d\n", posicao);
    } 
    
    
    imprimirListaRecursiva(lista, 0);
    
   
    int maior = buscarMaiorElementoIterativo(lista);
    printf("maior elem: %d\n", maior);
    
   
    maior = buscarMaiorElementoRecursivo(lista, 0);
    printf("maior elem: %d\n", maior);
    
   
    int menor = buscarMenorElementoIterativo(lista);
    printf("menor elem: %d\n", menor);
    
   
    menor = buscarMenorElementoRecursivo(lista, 0);
    printf("menor elem: %d\n", menor);
    
    
    int soma = calcularSomaIterativa(lista);
    printf("soma: %d\n", soma);
    
  
    soma = calcularSomaRecursiva(lista, 0);
    printf("soma: %d\n", soma);
    
  
    int produto = calcularProdutoIterativo(lista);
    printf("produto: %d\n", produto);
    
  
    produto = calcularProdutoRecursivo(lista, 0);
    printf("produto: %d\n", produto);
    
    liberarLista(lista);
    
    return 0;
}
