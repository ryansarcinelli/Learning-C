#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "arquivo.h"

int leArquivo(const char *nomeArquivo, int ***grafo, int *nVertices){
  
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo. \n");
        return 1;
    }


// Lê o número de vértices
    if (fscanf(file, "%d", nVertices) != 1) {
        fprintf(stderr, "Erro ao ler o número de vértices.\n");
        fclose(file);
        return 1;
    }

// Lê o número de arestas
    int nArestas;
    if (fscanf(file, "%d", &nArestas) != 1) {
        fprintf(stderr, "Erro ao ler o número de arestas.\n");
        fclose(file);
        return 1;
    }


    *grafo = alocaMemoria(*nVertices);
    iniciaGrafo(*grafo, *nVertices);

    int u,v;
    while (fscanf(file,"%d %d", &u, &v) != EOF){
        addAresta(*grafo, u, v, *nVertices);
    }

    fclose(file);
    return 0;

}