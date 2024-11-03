#ifndef LISTADUPENCADEADA_H
#define LISTADUPENCADEADA_H

typedef struct Topo Topo;
typedef struct Seq Seq;
typedef struct Meio Meio;
typedef struct Filme Filme;

// Cria uma nova lista vazia
Seq* criarlista();

// Verifica se a lista está vazia
int estavazia(Seq** s);

// Insere um novo filme na sequência de filmes
void inserirFilmeSequencia(Meio** m, Topo* t);

// Imprime a sequência de filmes a partir de um filme específico
void imprimirListaSequencia(Meio* m);

// Remove um filme da sequência de filmes
void removerFilmeSequencia(Meio** m, Topo* t);

// Imprime o filme antecessor na sequência de filmes
void imprimirFilmeAntecessor(Meio* m);

// Imprime o filme sucessor na sequência de filmes
void imprimirFilmeSucessor(Meio* m);

#endif // LISTADUPENCADEADA_H