#ifndef SISTEMAS_LINEARES_H
#define SISTEMAS_LINEARES_H

// Definição da estrutura para armazenar um sistema linear
typedef struct {
    int N;           // Dimensão da matriz
    double **A;      // Matriz quadrada A
    double *B;       // Vetor B
} SistemaLinear;

// Função para ler os sistemas lineares de um arquivo
void lerArquivo(const char *nomeArquivo);

#endif // SISTEMAS_LINEARES_H
