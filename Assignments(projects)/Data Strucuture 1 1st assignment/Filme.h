#ifndef FILME_H
#define FILME_H
#define v 50

// Definição da estrutura Filme
typedef struct Filme Filme;

// Função para criar um novo filme
Filme* criarFilme();

// Função para imprimir os dados de um filme
void imprimirFilme(Filme* f);

// Função para alterar o nome de um filme
void alterarNome(Filme* f);

// Função para alterar o ano de lançamento de um filme
void alterarAno(Filme* f);

// Função para retornar o ano de lançamento de um filme
int retornaAno(Filme* f);

#endif // FILME_H
