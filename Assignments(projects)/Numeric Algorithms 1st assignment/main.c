#include <stdio.h>
#include <string.h>
#include "sistemas_lineares.h"

// Trabalho de Algoritmos Numericos 08/2024 feito por:
// Adrian Carsi Pereira
// Lukas Rodrigues Basilio
// Ryan Carlos Sarcinelli
// Os arquivos de texto a1, a2, etc são arquivos com sistemas lineares para fins de teste testar

int main() {
    char nomeArquivo[100];

    // Solicita que o usuário digite o nome do arquivo
    printf("Digite o nome do arquivo: ");
    if (fgets(nomeArquivo, sizeof(nomeArquivo), stdin) == NULL) {
        fprintf(stderr, "Erro ao ler o nome do arquivo.\n");
        return 1;
    }

    // Remove o caractere de nova linha '\n' que fgets captura
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    // Chama a função para ler o arquivo
    lerArquivo(nomeArquivo);

    return 0;
}
