// algoritmo.c
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "arquivo.h"

#define INFINITO DBL_MAX

typedef struct {
    int u, v;
    double peso;
} Aresta;

typedef struct {
    int pai;
    int rank;
} Subconjunto;

// Função para encontrar o representante de um subconjunto
int encontrar(Subconjunto subconjuntos[], int i) {
    if (subconjuntos[i].pai != i)
        subconjuntos[i].pai = encontrar(subconjuntos, subconjuntos[i].pai);
    return subconjuntos[i].pai;
}

// Função para unir dois subconjuntos
void unir(Subconjunto subconjuntos[], int x, int y) {
    int raizX = encontrar(subconjuntos, x);
    int raizY = encontrar(subconjuntos, y);

    if (raizX != raizY) {
        if (subconjuntos[raizX].rank < subconjuntos[raizY].rank)
            subconjuntos[raizX].pai = raizY;
        else if (subconjuntos[raizX].rank > subconjuntos[raizY].rank)
            subconjuntos[raizY].pai = raizX;
        else {
            subconjuntos[raizY].pai = raizX;
            subconjuntos[raizX].rank++;
        }
    }
}

// Função para executar o algoritmo de Borůvka
void boruvka(double **grafo, int n) {
    Aresta *arestas = malloc((n * (n - 1) / 2) * sizeof(Aresta));
    int numArestas = 0;

    // Criação da lista de arestas
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (grafo[i][j] > 0) {
                arestas[numArestas].u = i;
                arestas[numArestas].v = j;
                arestas[numArestas].peso = grafo[i][j];
                numArestas++;
            }
        }
    }

    Subconjunto *subconjuntos = malloc(n * sizeof(Subconjunto));
    for (int i = 0; i < n; i++) {
        subconjuntos[i].pai = i;
        subconjuntos[i].rank = 0;
    }

    Aresta *resultado = malloc(n * sizeof(Aresta));
    int numArestasMST = 0;
    double custoTotal = 0.0;

    while (numArestasMST < n - 1) {
        int *melhorAresta = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            melhorAresta[i] = -1;
        }

        // Encontrar a melhor aresta para cada árvore
        for (int i = 0; i < numArestas; i++) {
            int x = encontrar(subconjuntos, arestas[i].u);
            int y = encontrar(subconjuntos, arestas[i].v);

            if (x != y) {
                if (melhorAresta[x] == -1 || arestas[melhorAresta[x]].peso > arestas[i].peso) {
                    melhorAresta[x] = i;
                }
                if (melhorAresta[y] == -1 || arestas[melhorAresta[y]].peso > arestas[i].peso) {
                    melhorAresta[y] = i;
                }
            }
        }

        // Adicionar as melhores arestas ao MST
        for (int i = 0; i < n; i++) {
            if (melhorAresta[i] != -1) {
                int u = arestas[melhorAresta[i]].u;
                int v = arestas[melhorAresta[i]].v;

                if (encontrar(subconjuntos, u) != encontrar(subconjuntos, v)) {
                    resultado[numArestasMST++] = arestas[melhorAresta[i]];
                    custoTotal += arestas[melhorAresta[i]].peso;
                    unir(subconjuntos, u, v);
                }
            }
        }

        free(melhorAresta);
    }

    // Exibir o resultado
    printf("Arestas no MST:\n");
    for (int i = 0; i < numArestasMST; i++) {
        printf("%d - %d: %.2f\n", resultado[i].u, resultado[i].v, resultado[i].peso);
    }
    printf("Custo total do MST: %.2f\n", custoTotal);

    free(arestas);
    free(subconjuntos);
    free(resultado);
}
