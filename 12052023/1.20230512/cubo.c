#include<stdio.h>
#include<stdlib.h>

#include "cubo.h"

void preencherdados(Cubo *cubofunc)
{
    printf("lado do cubo: ");
    scanf("%f", &(cubofunc->lado));
}

void calcular(Cubo *cubofunc)
{
    printf("o valor da area e: %.1f", 6*((cubofunc->lado)*(cubofunc->lado)));
    printf("o valor do volume e %.1f", (cubofunc->lado)*(cubofunc->lado)*(cubofunc->lado));
}