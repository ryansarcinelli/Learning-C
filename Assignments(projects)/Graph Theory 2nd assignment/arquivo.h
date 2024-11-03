// arquivo.h
#ifndef ARQUIVO_H
#define ARQUIVO_H

typedef struct {
    int x, y;
} Coordenada;

Coordenada* leArquivo(const char *nomeArquivo, int *numCoordenadas);
double** criarMatrizAdjacencia(Coordenada *coordenadas, int N);
void liberarMatrizAdjacencia(double **matrizAdjacencia, int N);

#endif // ARQUIVO_H
