#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "arquivo.h"

int leArquivo(const char *nomeArquivo, int ***grafo, int *nVertices);

int main(){
    
    char nomeArquivo[100];

    printf("Digite o nome do arquivo: ");
    if (fgets(nomeArquivo, sizeof(nomeArquivo), stdin) == NULL) {
        fprintf(stderr, "Erro ao ler o nome do arquivo.\n");
        return 1;
    }

    // Remove a nova linha do final do nome do arquivo
    size_t len = strlen(nomeArquivo);
    if (len > 0 && nomeArquivo[len - 1] == '\n') {
        nomeArquivo[len - 1] = '\0';
    }

    int **grafo;
    int nVertices;
    //int nArestas;

    if (leArquivo(nomeArquivo, &grafo, &nVertices) != 0) {
        fprintf(stderr, "Erro ao ler o arquivo.\n");
        return 1;
    }

    printf("Matriz de Adjacencia:\n");
    printGrafo(grafo,nVertices);
    int x = contarComponentesConexas(grafo, nVertices);
    if(x == 1){
        printf("PROMESSA CUMPRIDA!!!\n");
    } else {
        printf("FALTAM %d ESTRADAS!!!\n", x-1);
    }

    liberarGrafo(grafo, nVertices);

    return 0;

}