#include <stdio.h>
#include <stdlib.h>

#include "complexo.h"

int main() {
    NumComplexo* z1 = criar(3.0, 4.0);
    NumComplexo* z2 = criar(2.0, -1.0);

   
    NumComplexo* somac = soma(z1, z2);
    printf("Soma: %.2f + %.2fi\n", soma->real, soma->imag);
    destruir(soma);


    NumComplexo* diferenca = sub(z1, z2);
    printf("Subtração: %.2f + %.2fi\n", diferenca->real, diferenca->imag);
    destruir(diferenca);

    
    NumComplexo* multiplicacao = mult(z1, z2);
    printf("Multiplicação: %.2f + %.2fi\n", produto->real, produto->imag);
    destruir(produto);


    NumComplexo* quociente = dividir(z1, z2);
    printf("Divisão: %.2f + %.2fi\n", quociente->real, quociente->imag);
    destruir(quociente);

    destruir(z1);
    destruir(z2);
    
    return 0;
}