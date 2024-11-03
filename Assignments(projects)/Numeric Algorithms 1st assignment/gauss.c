#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* gaussSolver(double **A, double *b, int n, double precisao) {
    int i, j, k, m;
    double *X = (double *)malloc(n * sizeof(double));

    if (X == NULL) {
        fprintf(stderr, "Erro ao alocar memória para as solucoes.\n");
        return NULL;
    }

    // ETAPA DE ESCALONAMENTO
    for (k = 0; k < n - 1; k++) {
        double max = fabs(A[k][k]);
        int maxIndex = k;

        // Procura o maior k-ésimo coeficiente em módulo
        for (i = k + 1; i < n; i++) {
            if (max < fabs(A[i][k])) {
                max = fabs(A[i][k]);
                maxIndex = i;
            }
        }

        if (maxIndex != k) {
            // Troca a equação k pela equação com o maior k-ésimo coeficiente em módulo
            for (j = 0; j < n; j++) {
                double temp = A[k][j];
                A[k][j] = A[maxIndex][j];
                A[maxIndex][j] = temp;
            }
            double temp = b[k];
            b[k] = b[maxIndex];
            b[maxIndex] = temp;
        }

        // Se A[k][k] é zero, então a matriz dos coeficientes é singular
        if (A[k][k] == 0) {
            printf("A matriz dos coeficientes e singular\n");
            free(X);
            return NULL;
        } else {
            // Realiza o escalonamento
            for (m = k + 1; m < n; m++) {
                double F = -A[m][k] / A[k][k];
                A[m][k] = 0; // Evita uma iteração
                b[m] = b[m] + F * b[k];
                for (j = k + 1; j < n; j++) {
                    A[m][j] = A[m][j] + F * A[k][j];
                }
            }
        }
    }

    // ETAPA DE RESOLUÇÃO DO SISTEMA
    for (i = n - 1; i >= 0; i--) {
        X[i] = b[i];
        for (j = i + 1; j < n; j++) {
            X[i] = X[i] - X[j] * A[i][j];
        }
        X[i] = X[i] / A[i][i];
    }


     double erroMax = 0;
    for (i = 0; i < n; i++) {
        double erro = fabs(A[i][i] * X[i] - b[i]);
        if (erro > erroMax) {
            erroMax = erro;
        }
    }
    if (erroMax > precisao) {
        printf("\n");
    }


    return X;
}
