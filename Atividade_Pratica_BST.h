#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No * Apontador;

typedef struct Aluno{
    int notas;
    char nome [60];
    int matricula;
}Aluno;

typedef struct No{
    Aluno Dados;
    Apontador Esq;
    Apontador Dir;
}No;

void inicializar_arvore(Apontador *no);
void inserir(Apontador *no, Aluno dados);

void em_ordem_decrescente(Apontador no);
