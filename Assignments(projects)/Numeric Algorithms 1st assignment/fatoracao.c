#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para fatoração LU
double* fatoracaoLU(double **A, double *B, int N, double precisao) {
    int i, j, k;
    double *X = (double *)malloc(N * sizeof(double));
    if (X == NULL) {
        fprintf(stderr, "Erro ao alocar memória para as soluções.\n");
        return NULL;
    }

    // Matriz L e U
    double **L = (double **)malloc(N * sizeof(double *));
    double **U = (double **)malloc(N * sizeof(double *));
    for (i = 0; i < N; i++) {
        L[i] = (double *)calloc(N, sizeof(double));
        U[i] = (double *)malloc(N * sizeof(double));
    }

    // Inicializa a matriz U como a matriz A
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            U[i][j] = A[i][j];
        }
    }

    // Fatoração LU
    for (i = 0; i < N; i++) {
        L[i][i] = 1.0;
        for (j = i; j < N; j++) {
            for (k = 0; k < i; k++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }
        for (j = i + 1; j < N; j++) {
            for (k = 0; k < i; k++) {
                L[j][i] -= L[j][k] * U[k][i];
            }
            L[j][i] = U[j][i] / U[i][i];
        }
    }

    // Resolução de LY = B para Y
    double *Y = (double *)malloc(N * sizeof(double));
    if (Y == NULL) {
        fprintf(stderr, "Erro ao alocar memória para Y.\n");
        return NULL;
    }
    for (i = 0; i < N; i++) {
        Y[i] = B[i];
        for (j = 0; j < i; j++) {
            Y[i] -= L[i][j] * Y[j];
        }
    }

    // Resolução de UX = Y para X
    for (i = N - 1; i >= 0; i--) {
        X[i] = Y[i];
        for (j = i + 1; j < N; j++) {
            X[i] -= U[i][j] * X[j];
        }
        X[i] /= U[i][i];

    }

    double *residual = (double *)malloc(N * sizeof(double));
    if (residual == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o residual.\n");
        return NULL;
    }
    
    for (i = 0; i < N; i++) {
        residual[i] = B[i];
        for (j = 0; j < N; j++) {
            residual[i] -= A[i][j] * X[j];
        }
    }

    double erroMax = 0;
    for (i = 0; i < N; i++) {
        if (fabs(residual[i]) > erroMax) {
            erroMax = fabs(residual[i]);
        }
    }
    if (erroMax > precisao) {
        printf("\n", erroMax);
    }

    // Liberar memória
    for (i = 0; i < N; i++) {
        free(L[i]);
        free(U[i]);
    }
    free(L);
    free(U);
    free(Y);

    return X;
}
