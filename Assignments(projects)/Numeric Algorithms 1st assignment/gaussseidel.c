#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para executar o método de Gauss-Seidel
double* gaussSeidel(double **A, double *B, int N, double tol) {
    double *X = (double *)malloc(N * sizeof(double));
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
            double newValue = sum / A[i][i];
            error += fabs(newValue - X[i]);
            X[i] = newValue;
        }

        k++;
    } while (error > tol);

    return X;  // Retornar as soluções
}