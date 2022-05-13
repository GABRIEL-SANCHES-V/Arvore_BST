#include "Arvore_BST.h"

int main()
{    
    No *raiz;
    inicializar_arvore(&raiz);

    inserir(&raiz, 5);
    inserir(&raiz, 3);
    inserir(&raiz, 7);
    inserir(&raiz, 2);
    inserir(&raiz, 4);
    inserir(&raiz, 6);
    inserir(&raiz, 1);
    inserir(&raiz, 5);

    percurso_pre_ordem(raiz);
    printf("\n");
    percurso_em_ordem(raiz);
    printf("\n");
    percurso_pos_ordem(raiz);
    printf("\n");

    retirar(&raiz, 7);

    printf("\n");
    percurso_pre_ordem(raiz);
    printf("\n");
    percurso_em_ordem(raiz);
    printf("\n");
    percurso_pos_ordem(raiz);
    printf("\n");

    pesquisar(&raiz, 7);

    printf("\n");
    printf("Altura da  rvore -> %d\n", altura_da_arvore(&raiz));

    return 0;
}