#include <stdio.h>

typedef struct {
    float lado;
} Cubo;


void inicializar(Cubo *c, float lado) {
    c->lado = lado;
}


float tamLado(Cubo *c) {
    return c->lado;
}


float area(Cubo *c) {
    return 6 * c->lado * c->lado;
}


float volume(Cubo *c) {
    return c->lado * c->lado * c->lado;
}

int main() {
    Cubo cubomain;
    float lado;

    printf("Digite o tamanho do lado do cubo: ");
    scanf("%f", &lado);

    inicializarCubo(&cubomain, lado);

    printf("Tamanho de cada lado do cubo: %.2f\n", tamLado(&cubomain));
    printf("Área do cubo: %.2f\n", area(&cubomain));
    printf("Volume do cubo: %.2f\n", volume(&cubomain));

    return 0;
}
