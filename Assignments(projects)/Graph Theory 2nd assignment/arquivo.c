// arquivo.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arquivo.h"

#define ROUND_TO_DOUBLE(x) ((double)round(x))

// Função para calcular a distância entre dois pontos
double calcularDistancia(int x1, int y1, int x2, int y2) {
    double distX = x1 - x2;
    double distY = y1 - y2;
    return sqrt(distX * distX + distY * distY);
}


// Função para criar a matriz de adjacência
double** criarMatrizAdjacencia(Coordenada *coordenadas, int N) {
    double **matrizAdjacencia = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        matrizAdjacencia[i] = (double *)malloc(N * sizeof(double));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                matrizAdjacencia[i][j] = 0.0;
            } else {
                matrizAdjacencia[i][j] = calcularDistancia(coordenadas[i].x, coordenadas[i].y, coordenadas[j].x, coordenadas[j].y);
            }
        }
    }

    return matrizAdjacencia;
}

// Função para liberar a memória da matriz de adjacência
void liberarMatrizAdjacencia(double **matrizAdjacencia, int N) {
    for (int i = 0; i < N; i++) {
        free(matrizAdjacencia[i]);
    }
    free(matrizAdjacencia);
}

// Função para ler coordenadas de um arquivo
Coordenada* leArquivo(const char *nomeArquivo, int *numCoordenadas) {
    FILE *file = fopen(nomeArquivo, "r");

    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return NULL;
    }

    int N;
    if (fscanf(file, "%d", &N) != 1) {
        fprintf(stderr, "Erro ao ler N.\n");
        fclose(file);
        return NULL;
    }

    Coordenada *coordenadas = (Coordenada *)malloc(N * sizeof(Coordenada));
    if (coordenadas == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < N; i++) {
        if (fscanf(file, "%d %d", &coordenadas[i].x, &coordenadas[i].y) != 2) {
            fprintf(stderr, "Erro ao ler o par x e y.\n");
            free(coordenadas);
            fclose(file);
            return NULL;
        }
    }

    *numCoordenadas = N;
    fclose(file);
    return coordenadas;
}
