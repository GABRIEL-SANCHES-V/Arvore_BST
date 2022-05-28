#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct No * Apontador;

typedef struct Aluno{
    float notas;
    char nome [60];
    int matricula;
}Aluno;

typedef struct No{
    Aluno Dados;
    Apontador Esq;
    Apontador Dir;
}No;

void coletar_dados(FILE *file, Aluno *Dados);

void inicializar_arvore(Apontador *no);
void inserir(Apontador *no, Aluno dados);

void em_ordem_decrescente(Apontador no);

float maior(Apontador no);
float menor(Apontador no);

void media(Apontador no, float media);
