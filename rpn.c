#include <stdio.h>
#include <stdlib.h>

double* push(double* pilha, int* topoDaPilha, double input){
    pilha = realloc(pilha, (*topoDaPilha + 1) * sizeof(double));
    pilha[*topoDaPilha] = input;
    *topoDaPilha += 1;

    return pilha;
}

double* pop(double* pilha, int* topoDaPilha){
    pilha[*topoDaPilha - 1] = 0;
    pilha = realloc(pilha, ((*topoDaPilha) - 1) * sizeof(double));
    (*topoDaPilha) -= 1; 
    return pilha;
}




int main() {

double* pilha = NULL;
int topoDaPilha = 0;
char leitor;
double leitorNumerico, resultadoOperacao;

while (1) {
    scanf("%c", &leitor);
    if (leitor == EOF) {
        break;
    }
    else if (leitor > 47 && leitor < 58) {
        ungetc(leitor, stdin);
        scanf("%lf", &leitorNumerico);
        pilha = push(pilha, &topoDaPilha, leitorNumerico);
    }
    else if (leitor == '+') {
        resultadoOperacao = pilha[topoDaPilha - 2] + pilha[topoDaPilha - 1];
        pilha = pop(pilha, &topoDaPilha);
        pilha = pop(pilha, &topoDaPilha);
        pilha = push(pilha, &topoDaPilha, resultadoOperacao);
    }
    else if (leitor == '-') {
        resultadoOperacao = pilha[topoDaPilha - 2] - pilha[topoDaPilha - 1];
        pilha = pop(pilha, &topoDaPilha);
        pilha = pop(pilha, &topoDaPilha);
        pilha = push(pilha, &topoDaPilha, resultadoOperacao);
    }
    else if (leitor == '*') {
        resultadoOperacao = pilha[topoDaPilha - 2] * pilha[topoDaPilha - 1];
        pilha = pop(pilha, &topoDaPilha);
        pilha = pop(pilha, &topoDaPilha);
        pilha = push(pilha, &topoDaPilha, resultadoOperacao);
    }
    else if (leitor == '/') {
        resultadoOperacao = pilha[topoDaPilha - 2] / pilha[topoDaPilha - 1];
        pilha = pop(pilha, &topoDaPilha);
        pilha = pop(pilha, &topoDaPilha);
        pilha = push(pilha, &topoDaPilha, resultadoOperacao);
    }
}
printf("Resultado: %.6lf", pilha[topoDaPilha - 1]);
free(pilha);
return 0;
}