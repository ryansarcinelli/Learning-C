#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListacDescritor.h"
#define v 50

struct Seq;

typedef struct Filme{
    int id, ano;
    char nome[v];
    struct Seq* seq;
}Filme;

// Função para criar um novo filme
Filme* criarFilme() {
    Filme* f = (Filme*)malloc(sizeof(Filme));
    printf("\nDigite o nome do filme: ");
    fgets(f->nome, v, stdin);
    f->nome[strcspn(f->nome, "\n")] = '\0';

    printf("\nDigite o ano: ");
    scanf("%d", &f->ano);
    getchar();

    f->seq = NULL;

    // Geração de um ID único para o filme
    static int id_unico = 1;
    f->id = id_unico++;
    return f;
}

// Função para imprimir os dados de um filme
void imprimirFilme(Filme* f) {
    printf("\nNome: %s | Ano: %d | Id: %d", f->nome, f->ano, f->id);
}

// Função para alterar o nome de um filme
void alterarNome(Filme* f) {
    printf("\nDigite o novo nome do Filme: ");
    fgets(f->nome, v, stdin);
    f->nome[strcspn(f->nome, "\n")] = '\0';
    fflush(stdin);
}

// Função para alterar o ano de lançamento de um filme
void alterarAno(Filme* f) {
    printf("\nDigite o novo ano de lançamento do Filme:  ");
    scanf("%d", &f->ano);
}

// Função para retornar o ano de lançamento de um filme
int retornaAno(Filme* f) {
    return f->ano;
}