#include <stdio.h>
#include <stdlib.h>
//Funcao que inverte o numero de um vetor, no caso os restos das divisoes
void inverteVetor(int *vetor, int posicoes);

int main() {
    char letras[200]; // vetor que guarda as letras convertidas
    int i, j, pos, entradas; // contadores
    int num, resultadoDivisao, restoDivisao[200]; //numero a ser convertido, resultado da divisao e vetor de restos da divisao
    scanf("%d", &entradas);

    if (entradas > 100 || entradas < 1) exit(1);

    while(entradas--){
        printf("Digite um numero para ser convertido: ");
        scanf("%d", &num);
        pos = 0;
        resultadoDivisao = 1; // isto serve para nao pular o while, em numeros de entradas >1

        //Faz as divisoes e armazena os restos num vetor para fazer a conversao
        while(resultadoDivisao != 0){
            resultadoDivisao = num/4;
            restoDivisao[pos] = num%4;
            num = resultadoDivisao;
            pos++;
        }
        // Inverte os restos
        inverteVetor(restoDivisao,pos);

        //atribui letras para cada numero, conforme o exercicio explica
        for(j = 0;j < pos; j++){
            if(restoDivisao[j] == 0) letras[j] = 'A';
            if(restoDivisao[j] == 1) letras[j] = 'C';
            if(restoDivisao[j] == 2) letras[j] = 'G';
            if(restoDivisao[j] == 3) letras[j] = 'T';
        }

        for(j = 0; j < pos; j++){
            printf("%c", letras[j]);
        }
        printf("\n");
    }
    
    return 0;
}

void inverteVetor(int *vetor, int posicoes){
    int i, j = 0;
    int temp[posicoes];

    for(i = posicoes; i > 0; i--){
        temp[j] = vetor[i-1];
        j++;
    }
    for(i = 0; i < posicoes; i++){
        vetor[i] = temp[i];
    }
}