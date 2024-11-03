#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para executar o método de Gauss-Jacobi
double* gaussJacobi(double **A, double *B, int N, double tol) {
    double *X = (double *)malloc(N * sizeof(double));
    double *X_new = (double *)malloc(N * sizeof(double));
    int i, j, k;
    double sum, error;

    // Inicializar X com 0
    for (i = 0; i < N; i++) {
        X[i] = 0.0;
    }

    k = 0;
    do {
        error = 0.0;
        for (i = 0; i < N; i++) {
            sum = B[i];
            for (j = 0; j < N; j++) {
                if (i != j) {
                    sum -= A[i][j] * X[j];
                }
            }
            X_new[i] = sum / A[i][i];
            error += fabs(X_new[i] - X[i]);
        }

        // Atualizar o vetor X
        for (i = 0; i < N; i++) {
            X[i] = X_new[i];
        }

        k++;
    } while (error > tol);

    free(X_new);
    return X;  // Retornar as soluções
}

