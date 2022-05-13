#include "Arvore_BST.h"

void inicializar_arvore(Apontador *raiz){
    *raiz = NULL;
}

int criar_no(Apontador *no, int valor) {
    int criou = 0;
    if (*no == NULL) {
        *no = (Apontador) malloc(sizeof(No));
        (*no)->valor = valor;
        (*no)->Esq = NULL;
        (*no)->Dir = NULL;
        criou = 1;
    }
    return criou;
}

void antecessor(Apontador no, Apontador *no_Dir){
    if((*no_Dir)->Dir != NULL){
        antecessor(no, &(*no_Dir)->Dir);
    } else {
        no->valor = (*no_Dir)->valor;
        no = *no_Dir;
        *no_Dir = (*no_Dir)->Esq;
        free(no);
    }
}

int deve_inserir_esquerda(int valor_arvore, int valor_novo) {
    return valor_arvore > valor_novo;
}

int deve_inserir_direita(int valor_arvore, int valor_novo) {
    return valor_arvore < valor_novo;
}

void inserir(Apontador *no, int valor){
    int criou = criar_no(no, valor);

    if(deve_inserir_esquerda((*no)->valor, valor)) {
        inserir(&(*no)->Esq, valor);

    } else if(deve_inserir_direita((*no)->valor, valor)) {
        inserir(&(*no)->Dir, valor);

    } else if (criou == 0){
        printf("\nErro: Registro %d j� existe na �rvore\n", (*no)->valor);
    }
}

void pesquisar(Apontador *no, int valor){
    if(*no == NULL){
        printf("\nChave n�o encontrada\n");

    } else {   
        if((*no)->valor > valor)
            pesquisar(&(*no)->Esq, valor);

        else if((*no)->valor < valor)
            pesquisar(&(*no)->Dir, valor);
        
        else if((*no)->valor == valor){
            printf("\n%d - Chave encontrada\n", (*no)->valor);
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
        printf("\nErro: item n�o existe.\n");
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
            
        } else if((*no)->Esq != NULL) {
            antecessor(*no, &(*no)->Dir);

        } else {
            Aux = *no;
            *no = (*no)->Dir;
            free(Aux);
        }
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