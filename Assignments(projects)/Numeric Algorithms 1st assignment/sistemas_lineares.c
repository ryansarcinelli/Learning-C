#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gauss.h"
#include "fatoracao.h"
#include "gaussjacobi.h"
#include "gaussseidel.h"
#include <time.h>

// Função para imprimir o sistema linear
void imprimirSistema(double **A, double *B, int N, int sistemaIndex) {
    printf("Sistema %d:\n", sistemaIndex);
    printf("Matriz A:\n");
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            printf("%lf ", A[j][k]);
        }
        printf("\n");
    }
    printf("Vetor B:\n");
    for (int j = 0; j < N; j++) {
        printf("%lf ", B[j]);
    }
    printf("\n");
}

// Função para liberar a memória alocada para o sistema
void liberarSistema(double **A, int N) {
    for (int j = 0; j < N; j++) {
        free(A[j]);
    }
    free(A);
}

void liberarVetorB(double *B) {
    free(B);
}

void resolverESalvarTempo(double **A, double *B, int N, double precisao, const char *nomeAlgoritmo, double* (*algoritmo)(double**, double*, int, double)) {
    clock_t start = clock(); // Início da contagem de tempo
    double *solucoes = algoritmo(A, B, N, precisao);
    clock_t end = clock(); // Fim da contagem de tempo
    double tempoGasto = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nAlgoritmo: %s\n", nomeAlgoritmo);
    if (solucoes == NULL) {
        printf("O sistema e impossivel ou nao tem soluçao unica.\n");
    } else {
        printf("Solucoes:\n");
        for (int j = 0; j < N; j++) {
            printf("x%d = %lf\n", j + 1, solucoes[j]);
        }
        free(solucoes);
    }
    printf("Tempo de execucao: %f segundos\n", tempoGasto);
}

// Função para ler o arquivo e carregar os sistemas lineares
void copiarMatriz(double **destino, double **origem, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            destino[i][j] = origem[i][j];
        }
    }
}

void lerArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int quantidadeSistemas;
    fscanf(arquivo, "%d", &quantidadeSistemas);

    // Ler a dimensão N e a precisão (assumindo que todos os sistemas têm a mesma matriz A)
    int N;
    double precisao;
    fscanf(arquivo, "%d %lf", &N, &precisao);

    // Alocar memória para a matriz A
    double **A = (double **)malloc(N * sizeof(double *));
    for (int j = 0; j < N; j++) {
        A[j] = (double *)malloc(N * sizeof(double));
    }

    // Ler os valores da matriz A (que será a mesma para todos os vetores B)
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            fscanf(arquivo, "%lf", &A[j][k]);
        }
    }

    // Alocar memória para uma cópia da matriz A
    double **A_copia = (double **)malloc(N * sizeof(double *));
    for (int j = 0; j < N; j++) {
        A_copia[j] = (double *)malloc(N * sizeof(double));
    }

    for (int i = 0; i < quantidadeSistemas; i++) {
        // Alocar memória para o vetor B
        double *B = (double *)malloc(N * sizeof(double));

        // Ler os valores do vetor B
        for (int j = 0; j < N; j++) {
            fscanf(arquivo, "%lf", &B[j]);
        }

        // Copiar a matriz A para A_copia
        copiarMatriz(A_copia, A, N);

        // Imprimir os dados do sistema
        imprimirSistema(A_copia, B, N, i + 1);

        // Resolver o sistema para o vetor B atual usando a cópia de A
        resolverESalvarTempo(A_copia, B, N, precisao, "Metodo de Gauss", gaussSolver);
        resolverESalvarTempo(A_copia, B, N, precisao, "Fatoracao LU", fatoracaoLU);
        resolverESalvarTempo(A_copia, B, N, precisao, "Gauss Jacobi", gaussJacobi);
        resolverESalvarTempo(A_copia, B, N, precisao, "Gauss Seidel", gaussSeidel);
        printf("\n\n");

        // Liberar memória do vetor B após o uso
        liberarVetorB(B);
    }

    // Liberar memória da matriz A e A_copia após o uso
    liberarSistema(A, N);
    liberarSistema(A_copia, N);

    fclose(arquivo);
}