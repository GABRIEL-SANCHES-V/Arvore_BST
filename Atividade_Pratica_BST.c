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

    printf("Notas: %.2f Nome: %s Matricula: %d\n", no->Dados.notas, no->Dados.nome, no->Dados.matricula);

    if(no->Esq != NULL)
        em_ordem_decrescente(no->Esq);
}


