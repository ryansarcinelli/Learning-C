#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Filme.h"  // Inclui o cabeçalho "Filme.h"
#include "ListacDescritor.h"  // Inclui o cabeçalho "ListacDescritor.h"

typedef struct Filme {
    int id, ano;
    char nome[v];
    struct Seq* seq;
} Filme;

Seq* criarlista() {
    return NULL;
}

int estavazia(Seq** l) {
    return (*l == NULL);
}

void inserirFilmeSequencia(Meio** m, Topo* t) {
    // Função para inserir um Filme na sequência de um Filme específico
    int num;
    printf("\nDigite o ID do filme que inicia a sequencia: ");
    scanf("%d", &num);
    getchar();

    Filme* novoFilme = criarFilme();  // Cria um novo Filme

    // Percorre a lista de Filmes
    for (Meio* atual = *m; atual != NULL; atual = atual->prox) {
        if (atual->filme->id == num) {
            Seq* novaSeq = (Seq*)malloc(sizeof(Seq));  // Aloca memória para a nova sequência
            novaSeq->filme = novoFilme;
            novaSeq->ant = NULL;
            novaSeq->prox = NULL;

            if (atual->filme->seq == NULL) {
                atual->filme->seq = novaSeq;
            } else {
                Seq* ultimaSeq = atual->filme->seq;
                while (ultimaSeq->prox != NULL) {
                    ultimaSeq = ultimaSeq->prox;
                }
                ultimaSeq->prox = novaSeq;
                novaSeq->ant = ultimaSeq;
            }
            t->n++;
            return;
        }
    }
    printf("\nFilme com identificador %d nao encontrado na sequencia.\n", num);
}

void imprimirListaSequencia(Meio* m) {
    // Função para imprimir a sequência de Filmes a partir de um Filme específico
    int num;
    printf("\nDigite o Id do filme que inicia a sequencia: ");
    scanf("%d", &num);
    getchar();

    for (Meio* atual = m; atual != NULL; atual = atual->prox) {
        if (atual->filme->id == num) {
            Seq* seqAtual = atual->filme->seq;
            printf("\nSequencia de filmes:\n");
            while (seqAtual != NULL) {
                imprimirFilme(seqAtual->filme);
                seqAtual = seqAtual->prox;
            }
            return;
        }
    }

    printf("\nFilme com identificador %d nao encontrado na sequencia.\n", num);
}

void removerFilmeSequencia(Meio** m, Topo* t) {
    // Função para remover um Filme da sequência de um Filme específico
    int num, n;
    printf("\nDigite o ID do filme que inicia a sequencia: ");
    scanf("%d", &num);
    getchar();

    Meio* Atual = *m;
    for (; Atual != NULL; Atual = Atual->prox) {
        if (Atual->filme->id == num) {
            printf("\nDigite o ID do filme que deseja remover: ");
            scanf("%d", &n);

            Seq* seqAtual = Atual->filme->seq;
            for (; seqAtual != NULL; seqAtual = seqAtual->prox) {
                if (seqAtual->filme->id == n) {
                    // Remover o filme da sequência
                    if (seqAtual->ant == NULL) {
                        Atual->filme->seq = seqAtual->prox;
                    } else {
                        seqAtual->ant->prox = seqAtual->prox;
                    }
                    if (seqAtual->prox != NULL) {
                        seqAtual->prox->ant = seqAtual->ant;
                    }
                    free(seqAtual);
                    printf("\nFilme com identificador %d removido da sequencia.\n", n);
                    t->n--;
                    return;
                }
            }
            printf("\nFilme com identificador %d nao encontrado na sequencia.\n", n);
            return;
        }
    }

    printf("\nFilme com identificador %d nao encontrado na sequencia.\n", num);
}

void imprimirFilmeAntecessor(Meio* m) {
    // Função para imprimir o filme antecessor de um Filme específico na sequência
    int num;
    printf("\nDigite o ID do filme: ");
    scanf("%d", &num);
    getchar();

    for (Meio* atual = m; atual != NULL; atual = atual->prox) {
        Seq* seqAtual = atual->filme->seq;
        while (seqAtual != NULL) {
            if (seqAtual->filme->id == num) {
                Seq* antecessor = seqAtual->ant;
                if (antecessor != NULL) {
                    printf("\nAntecessor do filme %d na sequencia: \n", num);
                    imprimirFilme(antecessor->filme);
                    return;
                } else {
                    printf("\nO filme %d nao possui um antecessor na sequencia.\n", num);
                    return;
                }
            }
            seqAtual = seqAtual->prox;
        }
    }

    printf("\nFilme com identificador %d nao encontrado na sequencia.\n", num);
}

void imprimirFilmeSucessor(Meio* m) {
    // Função para imprimir o filme sucessor de um Filme específico na sequência
    int num;
    printf("\nDigite o ID do filme: ");
    scanf("%d", &num);
    getchar();

    for (Meio* atual = m; atual != NULL; atual = atual->prox) {
        if (atual->filme->id == num) {
            Seq* seqAtual = atual->filme->seq;
            printf("\nSucessor do filme %d na sequencia:\n", num);
            imprimirFilme(seqAtual->filme);
            return;
        } else {
            Seq* seqAtual = atual->filme->seq;
            for (Seq* aux = seqAtual; aux != NULL; aux = aux->prox) {
                if (aux->filme->id == num) {
                    Seq* sucessor = aux->prox;
                    if (sucessor != NULL) {
                        printf("\nSucessor do filme %d na sequencia:\n", num);
                        imprimirFilme(sucessor->filme);
                        return;
                    } else {
                        printf("\nO filme %d nao possui um sucessor na sequencia.\n", num);
                        return;
                    }
                }
            }
        }
    }
}