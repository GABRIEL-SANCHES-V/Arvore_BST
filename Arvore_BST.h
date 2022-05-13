#include <stdio.h>
#include <stdlib.h>


typedef struct No * Apontador;

typedef struct No{
    int valor;
    Apontador Esq;
    Apontador Dir;
}No;

void inicializar_arvore(Apontador *raiz);
void criar_no(Apontador *no, int valor);
void antecessor(Apontador no, Apontador *nos_Esq);


void inserir(Apontador *no, int valor);
void pesquisar(Apontador *no, int valor);
void retirar(Apontador *no, int valor);

int altura_da_arvore(Apontador *no);

void percurso_em_ordem(Apontador raiz);
void percurso_pre_ordem(Apontador raiz);
void percurso_pos_ordem(Apontador raiz);