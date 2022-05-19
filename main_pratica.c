#include "Atividade_Pratica_BST.h"

int main(){

    Aluno Dados [7];
    No *raiz;

    Dados[0].notas = 7;
    Dados[1].notas = 6;
    Dados[2].notas = 8;
    Dados[3].notas = 9;
    Dados[4].notas = 7;
    Dados[5].notas = 10;
    Dados[6].notas = 2;
    Dados[0].matricula = 556;
    Dados[1].matricula = 557;
    Dados[2].matricula = 558;
    Dados[3].matricula = 559;
    Dados[4].matricula = 555;
    Dados[5].matricula = 554;
    Dados[6].matricula = 553;
    strcpy(Dados[0].nome,"Fernada");
    strcpy(Dados[1].nome,"Carlor");
    strcpy(Dados[2].nome,"Henrique");
    strcpy(Dados[3].nome,"Jo∆o");
    strcpy(Dados[4].nome,"Juliana");
    strcpy(Dados[5].nome,"Gabriel");
    strcpy(Dados[6].nome,"Rodrigo");


    inicializar_arvore(&raiz);

    inserir(&raiz, Dados[0]);
    inserir(&raiz, Dados[1]);
    inserir(&raiz, Dados[2]);
    inserir(&raiz, Dados[3]);
    inserir(&raiz, Dados[4]);
    inserir(&raiz, Dados[5]);
    inserir(&raiz, Dados[6]);

    em_ordem_decrescente(raiz);
    return 0;
}