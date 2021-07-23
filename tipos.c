#include <stdio.h>
#include <stdlib.h>

typedef struct Ataque {
    int poder;
    int tipo;
    float dano;
}ataque;


int main(){

    int tamanho_matriz, tipo_oponente;
    int numero_ataques = 0;
    float** matriz;
    ataque* ataques;


    // Leitura da matriz
    scanf("%d", &tamanho_matriz);
    matriz = malloc(tamanho_matriz * sizeof(float*));
    for (int i = 0; i < tamanho_matriz; i++) {
        matriz[i] = malloc(tamanho_matriz * sizeof(float));
    }
    for (int i = 0; i < tamanho_matriz; i++) {
        for (int j = 0; j < tamanho_matriz; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    // Leitura dos ataques
    ataques = malloc(sizeof(ataque));
    while(1) {
        ataques = realloc(ataques, (numero_ataques + 2) * sizeof(ataque));
        scanf("%d", &ataques[numero_ataques].poder);
        if (ataques[numero_ataques].poder == -1) {
            break;
        }
        scanf("%d", &ataques[numero_ataques].tipo);
        numero_ataques++;
    }

    scanf("%d", &tipo_oponente);

    // Calculo de dano dos ataques
    for (int i = 0; i < numero_ataques; i++) {
        ataques[i].dano = ataques[i].poder * matriz[ataques[i].tipo][tipo_oponente];
    }
    int maior = 0;
    for (int i = 0; i < numero_ataques; i++) {
        if (ataques[i].dano > ataques[maior].dano) {
            maior = i;
        }
    }
    printf("O melhor ataque possui indice %d e dano %.2f", maior, ataques[maior].dano);


    free(ataques);
    for (int i = 0; i < tamanho_matriz; i++) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}