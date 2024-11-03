#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Filme.h"  // Inclusão do arquivo de cabeçalho "Filme.h"
#include "ListaDupEncadeada.h"  // Inclusão do arquivo de cabeçalho "ListaDupEncadeada.h"

typedef struct Filme {
    int id, ano;
    char nome[v];
    struct Seq* seq;  // Ponteiro para a sequência do filme
} Filme;

typedef struct Meio {
    struct Filme* filme;  // Ponteiro para o filme
    struct Meio* prox;  // Ponteiro para o próximo elemento na lista duplamente encadeada
} Meio;

typedef struct Topo {
    int n;  // Número de filmes na lista
    struct Meio* prim;  // Ponteiro para o primeiro elemento da lista
    struct Meio* ult;  // Ponteiro para o último elemento da lista
} Topo;

typedef struct Seq {
    struct Seq* prox;  // Ponteiro para o próximo elemento na sequência
    struct Seq* ant;  // Ponteiro para o elemento anterior na sequência
    struct Filme* filme;  // Ponteiro para o filme na sequência
} Seq;

void alteradado(Topo* t, Filme* f) {
    int num;
    Meio* meio;
    Seq* seq;
    printf("\nDigite o ID do filme que deseja alterar: ");
    scanf("%d", &num);
    getchar();
    for (meio = t->prim; meio != NULL; meio = meio->prox) {
        if (meio->filme->id == num) {
            alterarNome(meio->filme);  // Função para alterar o nome do filme
            alterarAno(meio->filme);  // Função para alterar o ano do filme
            break;
        } else {
            for (seq = meio->filme->seq; seq != NULL; seq = seq->prox) {
                if (seq->filme->id == num) {
                    alterarNome(seq->filme);  // Função para alterar o nome do filme na sequência
                    alterarAno(seq->filme);  // Função para alterar o ano do filme na sequência
                    break;
                }
            }
        }
    }
}

Meio* alocaMeio(Filme* f) {
    Meio* m = (Meio*)malloc(sizeof(Meio));
    if (m == NULL) {
        printf("\nErro ao alocar memória para o meio.\n");
        exit(1);
    }
    m->filme = f;
    m->prox = NULL;
    return m;
}

void inserirFilmeOrdenado(Meio** m, Filme* novoFilme, int id) {
    Meio* novoMeio = (Meio*)malloc(sizeof(Meio));
    novoMeio->filme = novoFilme;
    novoMeio->prox = NULL;

    if (*m == NULL || strcmp(novoFilme->nome, (*m)->filme->nome) < 0) {
        // Inserir no início da lista
        novoMeio->prox = *m;
        *m = novoMeio;
    } else {
        Meio* atual = *m;
        while (atual->prox != NULL && strcmp(novoFilme->nome, atual->prox->filme->nome) > 0) {
            atual = atual->prox;
        }
        novoMeio->prox = atual->prox;
        atual->prox = novoMeio;
    }
}

void exibirLista(Meio* m) {
    printf("\nLista de Filmes:\n");
    for (Meio* atual = m; atual != NULL; atual = atual->prox) {
        printf("Nome: %s | Ano: %d | Id: %d\n", atual->filme->nome, atual->filme->ano, atual->filme->id);
    }
}

void adicionarFilmeUsuario(Meio** m, int id, Topo* t) {
    Filme* novoFilme = criarFilme();  // Função para criar um novo filme
    inserirFilmeOrdenado(m, novoFilme, id);
    printf("\nFilme adicionado com sucesso.");
    t->n++;
}

void removerFilme(Meio** m, Topo* t) {
    int num;
    printf("\nDigite o ID do filme que deseja remover: ");
    scanf("%d", &num);
    getchar();

    Meio* anterior = NULL;

    for (Meio* atual = *m; atual != NULL; anterior = atual, atual = atual->prox) {
        if (num == atual->filme->id) {
            // Remover o filme da sequência
            Seq* seqAtual = atual->filme->seq;
            while (seqAtual != NULL) {
                Seq* seqProx = seqAtual->prox;
                t->n--;
                free(seqAtual);
                seqAtual = seqProx;
            }

            // Remover o filme da lista principal
            if (anterior == NULL) {
                *m = atual->prox;
                t->n--;
            } else {
                anterior->prox = atual->prox;
                t->n--;
            }

            free(atual->filme);
            free(atual);
            printf("\nFilme removido com sucesso.");
            return;
        }
    }

    printf("\nFilme nao encontrado ou nao existe.");
}

void liberarMemoria(Topo* topo) {
    Meio* atual = topo->prim;
    while (atual != NULL) {
        Filme* filme = atual->filme;

        // Liberar a sequência do filme
        Seq* seqAtual = filme->seq;
        while (seqAtual != NULL) {
            Seq* seqProx = seqAtual->prox;
            free(seqAtual);
            seqAtual = seqProx;
        }

        // Liberar o filme
        free(filme);

        // Avançar para o próximo meio
        Meio* prox = atual->prox;
        free(atual);
        atual = prox;
    }

    // Reinicializar o topo
    topo->prim = NULL;
    topo->ult = NULL;
    topo->n = 0;
}