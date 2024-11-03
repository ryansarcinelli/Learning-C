#ifndef CURVA_H
#define CURVA_H

void calcularAjusteLinear(double t[], double N[], int n, double *intercepto, double *coef_linear);

void calcularAjusteExponencial(double t[], double N[], int n, double *intercepto, double *coef_exponencial);

void calcularAjusteQuadratico(double t[], double N[], int n, double *intercepto, double *coef_linear, double *coef_quadratico);

double calcularCoeficienteR2(double t[], double N[], int n, double (*modelo)(double, double, double, double), double intercepto, double coef_linear, double coef_quadratico);

double modeloLinear(double t, double intercepto, double coef_linear, double coef_quadratico);

double modeloQuadratico(double t, double intercepto, double coef_linear, double coef_quadratico);

double modeloExponencial(double t, double intercepto, double coef_exponencial, double coef_quadratico);

#endif
