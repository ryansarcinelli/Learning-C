#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arquivo.h"
#include "algoritmo.h"

int main() {
    char nomeArquivo[100];
    int numCoordenadas;

    // Solicita o nome do arquivo ao usuário
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

    // Chama a função para ler o arquivo e obter as coordenadas
    Coordenada *coordenadas = leArquivo(nomeArquivo, &numCoordenadas);
    if (coordenadas == NULL) {
        return 1; // Se houver erro na leitura do arquivo
    }

    // Cria a matriz de adjacência com base nas coordenadas lidas
    double **matrizAdjacencia = criarMatrizAdjacencia(coordenadas, numCoordenadas);

    // Exibe a matriz de adjacência (opcional, apenas para visualização)
    printf("\nMatriz de Adjacencia (distancias):\n");
    for (int i = 0; i < numCoordenadas; i++) {
        for (int j = 0; j < numCoordenadas; j++) {
            printf("%.2f ", matrizAdjacencia[i][j]);
        }
        printf("\n");
    }

    // Executa o algoritmo de Borůvka
    boruvka(matrizAdjacencia, numCoordenadas);

    // Libera a memória alocada
    for (int i = 0; i < numCoordenadas; i++) {
        free(matrizAdjacencia[i]);
    }
    free(matrizAdjacencia);
    free(coordenadas);

    return 0;
}
