#include "Arvore_BST.h"

void inicializar_arvore(Apontador *raiz){
    *raiz = NULL;
}

void criar_no(Apontador *no, int valor) {
    *no = (Apontador) malloc(sizeof(No));
    (*no)->valor = valor;
    (*no)->Esq = NULL;
    (*no)->Dir = NULL;
}

void antecessor(Apontador no, Apontador *no_Esq){
    Apontador Aux;
    if((*no_Esq)->Dir == NULL){
        antecessor(no, &(*no_Esq)->Dir);
        return;
    }

    no->valor = (*no_Esq)->valor;
    Aux = *no_Esq;
    *no_Esq = (*no_Esq)->Esq;
    free(Aux);
}

void inserir(Apontador *no, int valor){
    if(*no == NULL)
        criar_no(no, valor);
        
    else{
        if((*no)->valor > valor){
            inserir(&(*no)->Esq, valor); 
        } else if((*no)->valor < valor){
            inserir(&(*no)->Dir, valor);
        } else{
            printf("\nErro: Registro j  existe na arvore\n");
        }
    }
}

void pesquisar(Apontador *no, int valor){
    if(*no == NULL){
        printf("\nChave nÆo encontrada\n");
        return;

    }else{   
        if((*no)->valor > valor)
            pesquisar(&(*no)->Esq, valor);

        else if((*no)->valor < valor)
            pesquisar(&(*no)->Dir, valor);
        
        else if((*no)->valor == valor){
            printf("\n%d - Chave encontrada\n", valor);
            return;
        }
    }
}

int altura_da_arvore(Apontador *no){
    if(*no == NULL)
        return -1;

    int he = altura_da_arvore(&(*no)->Esq);
    int hd = altura_da_arvore(&(*no)->Dir);

    if(he < hd)
        return (hd + 1);

    return (he + 1);
}

void retirar(Apontador *no, int valor){
    Apontador Aux;
    if(*no == NULL){
        printf("Erro item nÆo existe");
        return;
    }

    if((*no)->valor > valor)
        retirar(&(*no)->Esq, valor);

    else if((*no)->valor < valor)
        retirar(&(*no)->Dir, valor);
    
    else{
        if((*no)->Dir == NULL){
            Aux = *no;
            *no = (*no)->Esq;
            free(Aux);
            return;
        }if((*no)->Esq != NULL){
            antecessor(*no, &(*no)->Esq);
            return;
        }
        Aux = *no;
        *no = (*no)->Dir;
        free(Aux);
    }
}

void percurso_em_ordem(Apontador raiz){
    if(raiz == NULL)
        return;

    else{
        if(raiz->Esq != NULL)
            percurso_em_ordem(raiz->Esq);

        printf("%d ", raiz->valor);
        
        if(raiz->Dir != NULL)
            percurso_em_ordem(raiz->Dir);
    }
}

void percurso_pre_ordem(Apontador raiz){
    if(raiz == NULL)
        return;

    else{

        printf("%d ", raiz->valor);

        if(raiz->Esq != NULL)
            percurso_pre_ordem(raiz->Esq);

        if(raiz->Dir != NULL)
            percurso_pre_ordem(raiz->Dir);
    }
}

void percurso_pos_ordem(Apontador raiz){
    if(raiz == NULL)
        return;

    else{
        if(raiz->Esq != NULL)
            percurso_pos_ordem(raiz->Esq);
        
        if(raiz->Dir != NULL)
            percurso_pos_ordem(raiz->Dir);

        printf("%d ", raiz->valor);
    }
}