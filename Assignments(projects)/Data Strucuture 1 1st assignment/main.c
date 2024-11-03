#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Filme.h"
#include "ListacDescritor.h"
#include "ListaDupEncadeada.h"
#define v 50

void clearScreen() {
    // Função para limpar a tela do console
    printf("\033[2J\033[1;1H");
}

void exibirMenu() {
    // Função para exibir o menu de opções do programa
    printf("\n\n");
    printf("1 - Inserir novo filme\n");
    printf("2 - Alterar dados de um filme\n");
    printf("3 - Remover filme\n");
    printf("4 - Imprimir dados de todos os filmes\n");
    printf("5 - Inserir novo filme na sequencia\n");
    printf("6 - Imprimir lista sequencial de filmes\n");
    printf("7 - Remover filme da sequencia\n");
    printf("8 - Imprimir filme antecessor na saga\n");
    printf("9 - Imprimir filme sucessor na saga\n");
    printf("0 - Sair\n");
}

int main() {
    Topo topo;
    topo.n = 0;
    topo.prim = NULL;
    topo.ult = NULL;
    Filme *filme;

    int idFilmeInicio;
    int idFilmeRemover;
    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); // Limpar o caractere de nova linha do buffer

        switch (opcao) {
            case 1:
                // Opção 1: Inserir novo filme
                adicionarFilmeUsuario(&topo.prim, topo.n, &topo);
                break;
            case 2:
                // Opção 2: Alterar dados de um filme
                alteradado(&topo,filme);
                break;
            case 3:
                // Opção 3: Remover filme
                removerFilme(&topo.prim, &topo);
                break;
            case 4:
                // Opção 4: Imprimir lista de filmes
                exibirLista(topo.prim);
                break;
            case 5:
                // Opção 5: Inserir novo filme na sequência
                inserirFilmeSequencia(&topo.prim, &topo);
                break;
            case 6:
                // Opção 6: Imprimir lista sequencial de filmes
                imprimirListaSequencia(topo.prim);
                break;
            case 7:
                // Opção 7: Remover filme da sequência
                removerFilmeSequencia(&topo.prim, &topo);
                break;
            case 8:
                // Opção 8: Imprimir filme antecessor na saga
                imprimirFilmeAntecessor(topo.prim);
                break;
            case 9:
                // Opção 9: Imprimir filme sucessor na saga
                imprimirFilmeSucessor(topo.prim);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção invalida. Por favor, tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    liberarMemoria(&topo);

    return 0;
}