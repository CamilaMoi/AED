#include <stdio.h>
#include <stdlib.h>

#include "complexo.h"

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