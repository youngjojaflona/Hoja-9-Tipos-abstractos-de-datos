#include <stdio.h>
#include "matrixTAD.h"

int main(void) {
    // TODO write code to test the TAD

    MatrixTAD *miMatriz;
    miMatriz = creaMatriz(3, 3);
    if (miMatriz == NULL) { printf("Nanai loquete"); return -1; }

    asignaElemento(miMatriz, 0, 1, 7);
    asignaElemento(miMatriz, 1, 1, 8);
    asignaElemento(miMatriz, 2, 1, 7);

    int elem = obtieneElemento(miMatriz, 1, 1);
    printf("elemento: %d\n\n", elem);

    imprimeMatriz(miMatriz);
    printf("\n\n");

    vaciaMatriz(miMatriz);
    imprimeMatriz(miMatriz);

    liberaMatriz(miMatriz);
}