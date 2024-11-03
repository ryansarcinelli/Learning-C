#include "curva.h"
#include <stdio.h>
#include <math.h>


void calcularAjusteLinear(double t[], double N[], int n, double *intercepto, double *coef_linear) {
    double soma_t = 0, soma_N = 0, soma_tN = 0, soma_t2 = 0;

    for (int i = 0; i < n; i++) {
        soma_t += t[i];
        soma_N += N[i];
        soma_tN += t[i] * N[i];
        soma_t2 += t[i] * t[i];
    }

    *coef_linear = (n * soma_tN - soma_t * soma_N) / (n * soma_t2 - soma_t * soma_t);
    *intercepto = (soma_N - (*coef_linear) * soma_t) / n;
}

void calcularAjusteExponencial(double t[], double N[], int n, double *intercepto, double *coef_exponencial) {
    double soma_t = 0, soma_lnN = 0, soma_tlnN = 0, soma_t2 = 0;

    for (int i = 0; i < n; i++) {
        soma_t += t[i];
        soma_lnN += log(N[i]);
        soma_tlnN += t[i] * log(N[i]);
        soma_t2 += t[i] * t[i];
    }

    *coef_exponencial = (n * soma_tlnN - soma_t * soma_lnN) / (n * soma_t2 - soma_t * soma_t);
    *intercepto = exp((soma_lnN - (*coef_exponencial) * soma_t) / n);
}

double calcularCoeficienteR2(double t[], double N[], int n, double (*modelo)(double, double, double, double), double intercepto, double coef_linear, double coef_quadratico) {
    double ss_tot = 0, ss_res = 0, media_N = 0;

    for (int i = 0; i < n; i++) {
        media_N += N[i];
    }
    media_N /= n;

    for (int i = 0; i < n; i++) {
        double N_pred = modelo(t[i], intercepto, coef_linear, coef_quadratico);
        ss_tot += pow(N[i] - media_N, 2);
        ss_res += pow(N[i] - N_pred, 2);
    }

    return 1 - (ss_res / ss_tot);
}

double modeloLinear(double t, double intercepto, double coef_linear, double coef_quadratico) {
    return intercepto + coef_linear * t;
}

double modeloQuadratico(double t, double intercepto, double coef_linear, double coef_quadratico) {
    return intercepto + coef_linear * t + coef_quadratico * t * t;
}

double modeloExponencial(double t, double intercepto, double coef_exponencial, double coef_quadratico) {
    return intercepto * exp(coef_exponencial * t);
}

void calcularAjusteQuadratico(double t[], double N[], int n, double *intercepto, double *coef_linear, double *coef_quadratico) {
    double soma_t = 0, soma_t2 = 0, soma_t3 = 0, soma_t4 = 0;
    double soma_N = 0, soma_tN = 0, soma_t2N = 0;

    for (int i = 0; i < n; i++) {
        soma_t += t[i];
        soma_t2 += t[i] * t[i];
        soma_t3 += t[i] * t[i] * t[i];
        soma_t4 += t[i] * t[i] * t[i] * t[i];
        soma_N += N[i];
        soma_tN += t[i] * N[i];
        soma_t2N += t[i] * t[i] * N[i];
    }

    double A[3][3] = {
        {n, soma_t, soma_t2},
        {soma_t, soma_t2, soma_t3},
        {soma_t2, soma_t3, soma_t4}
    };

    double B[3] = {soma_N, soma_tN, soma_t2N};

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            double razao = A[j][i] / A[i][i];
            for (int k = i; k < 3; k++) {
                A[j][k] -= razao * A[i][k];
            }
            B[j] -= razao * B[i];
        }
    }

    *coef_quadratico = B[2] / A[2][2];
    *coef_linear = (B[1] - A[1][2] * (*coef_quadratico)) / A[1][1];
    *intercepto = (B[0] - A[0][1] * (*coef_linear) - A[0][2] * (*coef_quadratico)) / A[0][0];
}