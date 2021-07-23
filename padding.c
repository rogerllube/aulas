#include <stdio.h>
#include <stdlib.h>


int main(){

    int altura, largura, tamanho_borda;
    int** imagem;
    int** nova_imagem;


    //alocacao da matrize para a imagem
    scanf("%d %d", &largura, &altura);
    imagem = malloc(altura + 5 * sizeof(int*));
    for (int i = 0; i < altura; i++) {
        imagem[i] = malloc(largura + 5 * sizeof(int));
    }
    

    //leitura da matriz
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            scanf("%d", &imagem[i][j]);
        }
    }
    
    //alocacao da matriz para imagem com padding
    scanf("%d", &tamanho_borda);
    nova_imagem = malloc(altura + 5 +(tamanho_borda * 2) * sizeof(int*));
    for (int i = 0; i < altura + (tamanho_borda * 2) ; i++) {
        nova_imagem[i] = malloc(largura + 5 +(tamanho_borda * 2) * sizeof(int));
    }
    

    //geracao de uma matriz zerada para inserir a imagem
    for (int i = 0; i <  altura + (tamanho_borda * 2); i++) {
        for (int j = 0; j < largura + (tamanho_borda * 2); j++) {
            nova_imagem[i][j] = 0;
        }
    }

    //insercao da imagem original na matriz zerada
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            nova_imagem[i + tamanho_borda][j + tamanho_borda] = imagem[i][j];
        }
    }


    for (int i = 0; i <  altura + (tamanho_borda * 2); i++) {
        for (int j = 0; j < largura + (tamanho_borda * 2); j++) {
            printf("%d", nova_imagem[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");

    
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            printf("%d", imagem[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < altura; i++) {
        free(imagem[i]);
    }
    free(imagem);

    for (int i = 0; i < altura + (tamanho_borda * 2) - 1; i++) {
        free(nova_imagem[i]);
    }
    free(nova_imagem);


    return 0;
}