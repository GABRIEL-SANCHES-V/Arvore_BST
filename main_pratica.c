#include "Atividade_Pratica_BST.h"

int main(){

    Aluno Dados;
    FILE *file;
    No *raiz;
    char nome_arquivo [] = "Arquivo_teste.txt";
    int Num_alunos = 0, Maior= 0, Menor = 0;

    inicializar_arvore(&raiz);

    file = fopen(nome_arquivo, "r");

    while(!feof(file)){
        coletar_dados(&(*file), &Dados);
        inserir(&raiz,Dados);
        Num_alunos++;
    }

    fclose(file);

    em_ordem_decrescente(raiz);

    printf("N£mero de Alunos matriculados na disciplina: %d", Num_alunos);



    return 0;
}