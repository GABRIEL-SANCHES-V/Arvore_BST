#include "Atividade_Pratica_BST.h"

int main(){

    Aluno Dados;
    FILE *file;
    No *raiz;
    char nome_arquivo [] = "Arquivo_teste.txt";
    int Num_alunos = 0;
    float Maior = 0, Menor = 0, Media = 0, nota_max = 25;

    inicializar_arvore(&raiz);

    file = fopen(nome_arquivo, "r");

    while(!feof(file)){
        coletar_dados(&(*file), &Dados);
        inserir(&raiz,Dados);
        Num_alunos++;
    }

    fclose(file);

    em_ordem_decrescente(raiz);

    Maior = maior(raiz);
    Menor = menor(raiz);

    printf("\nN£mero de Alunos: %d\nMaior nota: %.2f\nMenor nota: %.2f\n\n", Num_alunos, Maior, Menor);

    Media = nota_max * 0.6;

    printf("Alunos que atingiram a m‚dia:\n");
    media(raiz, Media);





    return 0;
}