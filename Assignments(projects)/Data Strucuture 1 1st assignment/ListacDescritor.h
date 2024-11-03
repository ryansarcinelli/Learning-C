#ifndef LISTACOMDESCRITOR_H
#define LISTACOMDESCRITOR_H

/*
    Este é o cabeçalho da lista com descritor. Ele contém as declarações das estruturas e funções
    utilizadas na implementação dessa lista.
*/

typedef struct Filme Filme;  // Declaração antecipada da estrutura Filme

typedef struct Meio {
    struct Filme* filme;  // Ponteiro para o Filme
    struct Meio* prox;   // Ponteiro para o próximo Meio
} Meio;

typedef struct Topo {
    int n;              // Número de elementos na lista
    struct Meio* prim;  // Ponteiro para o primeiro Meio
    struct Meio* ult;   // Ponteiro para o último Meio
} Topo;

typedef struct Seq {
    struct Seq* prox;    // Ponteiro para o próximo Seq
    struct Seq* ant;     // Ponteiro para o Seq anterior
    struct Filme* filme; // Ponteiro para o Filme
} Seq;

void alteradado(Topo* t, Filme* f); // Função para alterar os dados de um Filme
Meio* alocaMeio(Filme* f);          // Função para alocar memória para um novo Meio
void inserirFilmeOrdenado(Meio** m, Filme* novoFilme, int id); // Função para inserir um Filme ordenadamente na lista
void exibirLista(Meio* m);          // Função para exibir a lista de Filmes
void adicionarFilmeUsuario(Meio** m, int id, Topo* t); // Função para adicionar um novo Filme na lista
void removerFilme(Meio** m, Topo* t); // Função para remover um Filme da lista
void liberarMemoria(Topo* topo);    // Função para liberar a memória utilizada pela lista

#endif // LISTACOMDESCRITOR_H
