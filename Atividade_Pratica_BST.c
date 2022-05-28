#include "Atividade_Pratica_BST.h"
char TRUE = 't';
char FALSE = 'f';

void coletar_dados(FILE *file, Aluno *Dados){
    char Aux [100];
    char *pt;
    int contador = 0;

    if (file == NULL)
    {
        printf("Falha ao abrir o arquivo.\n");

    }else{
        fgets(Aux, 100, file);
        pt = strtok(Aux, "-");
        while(pt) {
            if (contador == 0) {
                strcpy(Dados->nome, pt);
                contador++;

            } else if (contador == 1) {
                Dados->matricula = atoi(pt);
                contador++;

            } else if (contador == 2) {
                Dados->notas = atof (pt);
                contador++;
            }

            pt = strtok(NULL, "-");
        }
    }
}

void inicializar_arvore(Apontador *no){
    *no = NULL;
}

char criar_no(Apontador *no, Aluno Dados){
    char criou = FALSE;
    if(*no == NULL){
        *no = (Apontador) malloc(sizeof(No));
        (*no)->Dados.notas = Dados.notas;
        (*no)->Dados.matricula = Dados.matricula;
        strcpy((*no)->Dados.nome, Dados.nome);
        (*no)->Esq = NULL;
        (*no)->Dir = NULL;
        criou = TRUE;
    }
    return criou;
}

int deve_inserir_a_esquerda(int nota_do_no, int nova_nota){
    return nota_do_no >= nova_nota;
}

void inserir(Apontador *no, Aluno dados){

    if(*no == NULL)
    {
        criar_no(no, dados);
    } else {
        if((*no)->Dados.notas >= dados.notas){
            inserir(&(*no)->Esq, dados);

        } else {
            inserir(&(*no)->Dir, dados);
        }
    }
}

void em_ordem_decrescente(Apontador no){

    if(no->Dir != NULL)
        em_ordem_decrescente(no->Dir);

    printf("%.2f - %s - %d\n", no->Dados.notas, no->Dados.nome, no->Dados.matricula);

    if(no->Esq != NULL)
        em_ordem_decrescente(no->Esq);
}

float maior(Apontador no){
    int Maior = 0;
    if(no != NULL) {
        if(no->Dir != NULL){
            Maior = maior(no->Dir);

        } else if(no->Dir == 0) {
            Maior = no->Dados.notas;
        }
    }
    return Maior;
}

float menor(Apontador no){
    int Menor = 0;
    if(no != NULL){
        if(no->Esq != NULL){
            Menor = menor(no->Esq);

        } else if(no->Esq == 0) {
            Menor = no->Dados.notas;
        }
    }
    return Menor;
}

void media(Apontador no, float Media){
    if(no->Dir != NULL) {
        media(no->Dir, Media);
    }

    if (no->Dados.notas >= Media) {
        printf("%.2f - %s - %d\n", no->Dados.notas, no->Dados.nome, no->Dados.matricula);

    }

    if(no->Esq != NULL) {
        media(no->Esq, Media);
    }
}

