#include <stdio.h>
#include <stdlib.h>

typedef struct NumComplexo {
    double real;
    double imag;
} NumComplexo;

NumComplexo* criar(double real, double imag) {
    NumComplexo* numComplexo = (NumComplexo*)malloc(sizeof(NumComplexo));
    numComplexo->real = real;
    numComplexo->imag = imag;
    return numComplexo;
}

void destruir(NumComplexo* numComplexo) {
    free(numComplexo);
}

NumComplexo* soma(NumComplexo* num1, NumComplexo* num2) {
    double real = num1->real + num2->real;
    double imag = num1->imag + num2->imag;
    return criar(real, imag);
}

NumComplexo* sub(NumComplexo* num1, NumComplexo* num2) {
    double real = num1->real - num2->real;
    double imag = num1->imag - num2->imag;
    return criar(real, imag);
}

NumComplexo* mult(NumComplexo* num1, NumComplexo* num2) {
    double real = (num1->real * num2->real) - (num1->imag * num2->imag);
    double imag = (num1->real * num2->imag) + (num1->imag * num2->real);
    return criar(real, imag);
}

NumComplexo* dividir(NumComplexo* num1, NumComplexo* num2) {
    double denominador = (num2->real * num2->real) + (num2->imag * num2->imag);
    double real = ((num1->real * num2->real) + (num1->imag * num2->imag)) / denominador;
    double imag = ((num1->imag * num2->real) - (num1->real * num2->imag)) / denominador;
    return criar(real, imag);
}

int main() {
    NumComplexo* z1 = criar(3.0, 4.0);
    NumComplexo* z2 = criar(2.0, -1.0);

    // Soma 
    NumComplexo* somac = soma(z1, z2);
    printf("Soma: %.2f + %.2fi\n", soma->real, soma->imag);
    destruir(soma);

    // Subtração
    NumComplexo* diferenca = sub(z1, z2);
    printf("Subtração: %.2f + %.2fi\n", diferenca->real, diferenca->imag);
    destruir(diferenca);

    // Multiplicação 
    NumComplexo* multiplicacao = mult(z1, z2);
    printf("Multiplicação: %.2f + %.2fi\n", produto->real, produto->imag);
    destruir(produto);

    // Divisão 
    NumComplexo* quociente = dividir(z1, z2);
    printf("Divisão: %.2f + %.2fi\n", quociente->real, quociente->imag);
    destruir(quociente);

    destruir(z1);
    destruir(z2);
    
    return 0;
}