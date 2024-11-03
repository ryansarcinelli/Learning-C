#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "arquivo.h"

void iniciaGrafo(int **grafo, int nVertices){
    for( int i = 0; i < nVertices; i++){
        for (int j = 0; j < nVertices; j++){
            grafo[i][j] = 0;
    
    }
}
}

void addAresta(int **grafo, int inicio, int fim, int nVertices){
    if (inicio >= 0 && inicio <= nVertices && fim >= 0 && fim <= nVertices){
    grafo[inicio-1][fim-1] = 1;
    grafo[fim-1][inicio-1] = 1;
} else {
     fprintf(stderr, "Aresta invalida: %d %d\n", inicio, fim);
     
}
}

void printGrafo(int **grafo, int nVertices){
    for(int i = 0; i < nVertices; i++){
        for(int j = 0; j < nVertices; j++){
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }
}



int **alocaMemoria(int nVertices) {
    int **matrix = (int **)malloc(nVertices * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a matriz.\n");
        exit(1);
    }
    for (int i = 0; i < nVertices; i++) {
        matrix[i] = (int *)malloc(nVertices * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Erro ao alocar memória para a linha da matriz.\n");
            exit(1);
        }
    }
    return matrix;
}

void liberarGrafo (int **grafo, int nVertices){
    for (int i = 0; i < nVertices; i++){
        free(grafo[i]);
    }
    free(grafo);
}

// Função de busca em profundidade
void buscaProfundidade(int **grafo, int nVertices, int vertice, int *visitados){
    visitados[vertice] = 1;
    for (int i = 0; i < nVertices; i++){
        if (grafo[vertice][i] == 1 && !visitados[i]){
            buscaProfundidade(grafo, nVertices, i, visitados);
        }
    }
}

// Função para contar componentes conexas no grafo
int contarComponentesConexas(int **grafo, int nVertices){
    int *visitados = (int *)malloc(nVertices * sizeof(int));
    if (visitados == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o vetor de visitados.\n");
        exit(1);
    }
    for(int i = 0; i < nVertices; i++){
        visitados[i] = 0;
    }

    int componentesConexas = 0;
    for(int i = 0; i < nVertices; i++){
        if(visitados[i] == 0){
            buscaProfundidade(grafo, nVertices, i, visitados);
            componentesConexas++;
        }
    }

    free(visitados);
    return componentesConexas;
}