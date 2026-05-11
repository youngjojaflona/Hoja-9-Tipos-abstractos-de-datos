//
// Created by Raúl Martín on 08/04/2026.
// And improved by Jonathan Flores on 11/05/2026.
//

#include "matrixTAD.h"

#include <stdio.h>
#include <stdlib.h>

// TODO: Implement the TAD
typedef struct MatrixTAD {
    int **datos;
    int filas, columnas;
} MatrixTAD;

MatrixTAD *creaMatriz(int filas, int columnas) {

    // Reserva de la estructura
    MatrixTAD *matriz = (MatrixTAD *) malloc(sizeof(MatrixTAD));
    if (matriz == NULL) { return NULL; }

    // Rellenar lo que sabemos
    matriz->filas = filas;
    matriz->columnas = columnas;

    // Reserva del tamaño del doble puntero "datos" del struct
    matriz->datos = (int **) calloc(filas, sizeof(int *));
    if (matriz->datos == NULL) { free(matriz); return NULL; }

    // Reserva de cada fila
    for (int i = 0; i < filas; i++) {
        matriz->datos[i] = (int *) calloc(columnas, sizeof(int));
        if (matriz->datos[i] == NULL) {
            for (int j = 0; j < i; j++) { free(matriz->datos[i]); }
            free(matriz->datos);
            free(matriz);
            return NULL;
        }
    }

    // Devolvemos bien la estructura
    return matriz;
}

int asignaElemento(MatrixTAD *miMatriz, int fila, int columna, int valor) {

    // Comprobación de matriz válida
    if (miMatriz == NULL) { return -1; }

    // Comprobación de coordenada válida
    int numFilas = miMatriz->filas;
    int numColumnas = miMatriz->columnas;

    if (fila >= numFilas || columna >= numColumnas || fila < 0 || columna < 0) { return -1; }

    // Almacenar el valor
    miMatriz->datos[fila][columna] = valor;

    return 0;
}

int obtieneElemento(MatrixTAD *miMatriz, int fila, int columna) {

    // Comprobación de matriz válida
    if (miMatriz == NULL) { return -1; }

    // Comprobación de coordenada válida
    int numFilas = miMatriz->filas;
    int numColumnas = miMatriz->columnas;

    if (fila >= numFilas || columna >= numColumnas || fila < 0 || columna < 0) { return -1; }

    return miMatriz->datos[fila][columna];
}

void imprimeMatriz(MatrixTAD *miMatriz) {

    // Comprobación de matriz válida
    if (miMatriz == NULL) { printf("MatrixTAD is NULL\n"); return; }

    for (int i = 0; i < miMatriz->filas; i++) {
        for (int j = 0; j < miMatriz->columnas; j++) {
            printf("%d ", miMatriz->datos[i][j]);
        }
        printf("\n");
    }
}

void vaciaMatriz(MatrixTAD *miMatriz) {

    // Comprobación de matriz válida
    if (miMatriz == NULL) { printf("MatrixTAD is NULL\n"); return; }

    for (int i = 0; i < miMatriz->filas; i++) {
        for (int j = 0; j < miMatriz->columnas; j++) {
            miMatriz->datos[i][j] = 0;
        }
    }
}

void liberaMatriz(MatrixTAD *miMatriz) {

    // Comprobación de matriz válida
    if (miMatriz == NULL) { printf("MatrixTAD is NULL\n"); return; }

    for (int i = 0; i < miMatriz->filas; i++) {
        free(miMatriz->datos[i]);
    }
    free(miMatriz->datos);
    free(miMatriz);
}