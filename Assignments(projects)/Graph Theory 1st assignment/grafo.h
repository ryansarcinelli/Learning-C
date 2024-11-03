#ifndef GRAFO_H
#define GRAFO_H

void iniciaGrafo(int **grafo, int num_vertices);
void addAresta(int **grafo, int inicio, int fim, int nVertices);
void printGrafo(int **grafo, int nVertices);
int **alocaMemoria(int nVertices);
void liberarGrafo(int **grafo, int nVertices);
void buscaProfundidade(int **grafo, int nVertices, int vertice, int *visitados);
int contarComponentesConexas(int **grafo, int nVertices);

#endif // GRAFO_H