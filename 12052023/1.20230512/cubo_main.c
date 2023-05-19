#include<stdio.h>
#include<stdlib.h>

#include "cubo.h"

int main()
{
    Cubo *cubomain=(Cubo *) malloc(sizeof(cubomain));
    preencherdados(cubomain);
    valores(cubomain);
}