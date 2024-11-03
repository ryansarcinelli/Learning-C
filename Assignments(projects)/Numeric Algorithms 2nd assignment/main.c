#include "curva.h"
#include <stdio.h>
#include <math.h>

// Trabalho de Algoritmos Numericos por:
// Adrian Carsi Pereira
// Lukas Rodrigues Basilio
// Ryan Carlos Sarcinelli

int main() {
    double t[] = {77, 119, 205, 260, 343, 415, 425, 438, 502, 580, 604, 675, 696, 770, 802, 822, 897, 965, 970, 1027, 1094, 1156, 1192, 1282, 1345, 1405, 1429, 1493, 1516, 1597, 1678, 1721, 1724, 1812, 1873, 1947, 1950, 2012, 2047, 2127, 2153, 2157, 2210, 2298, 2332, 2358, 2449, 2503};
    
    double N[] = {50870643080, 46297918240, 38282822421, 34080460561, 28088573347, 24175635810, 23588757299, 22718540971, 19736321394, 16655820340, 15956176275, 13458062313, 13121778454, 10939070444, 10054385447, 9824068939, 8451625483, 7251508116, 7118718866, 6316609405, 5464716073, 4511225310, 4322167723, 3709676790, 3226060519, 2761872970, 2553745475, 2220343372, 2046714895, 1667362442, 1648561844, 1167013186, 1211599434, 1291077808, 1099297084, 791212548, 662664385, 721592837, 501015203, 536033559, 510953997, 583955494, 403003225, 574150933, 412508389, 131844628, 330342316, 326167250};

    int n = sizeof(t) / sizeof(t[0]);

    double intercepto, coef_linear, coef_quadratico;

    calcularAjusteLinear(t, N, n, &intercepto, &coef_linear);
    double r2_linear = calcularCoeficienteR2(t, N, n, modeloLinear, intercepto, coef_linear, 0);

    calcularAjusteQuadratico(t, N, n, &intercepto, &coef_linear, &coef_quadratico);
    double r2_quadratico = calcularCoeficienteR2(t, N, n, modeloQuadratico, intercepto, coef_linear, coef_quadratico);

    calcularAjusteExponencial(t, N, n, &intercepto, &coef_linear);
    double r2_exponencial = calcularCoeficienteR2(t, N, n, modeloExponencial, intercepto, coef_linear, 0);

    printf("R^2 Linear: %f\n", r2_linear);
    printf("R^2 Quadratico: %f\n", r2_quadratico);
    printf("R^2 Exponencial: %f\n", r2_exponencial);

    if (r2_linear > r2_quadratico && r2_linear > r2_exponencial) {
        printf("O modelo linear e o mais adequado.\n");
    } else if (r2_quadratico > r2_linear && r2_quadratico > r2_exponencial) {
        printf("O modelo quadrático e o mais adequado.\n");
    } else {
        printf("O modelo exponencial e o mais adequado.\n");
    }

    return 0;
}