/*
Recursão direta:
    Possui uma chamada para si mesma.
    
    Linear:
        Há uma única chamada recursiva a ela.
    Aninhada:
        A chamada recursiva de uma função recebe como argumento outra chamada recursiva à própria função.
    Não linear(em árvore):
        Há duas ou mais chamadas recursivas a ela. A sequência de chamadas se assemelha a uma "árvore".
        
Recursão indireta:
    Possui uma chamada para outra rotina que, por sua vez, possui uma chamada para a rotina anterior.
    O círculo de chamadas deve ser interrompido em algum momento.

*/

#include <stdio.h>

#define n 100

long long int somatorio(long long int vetor[], unsigned int num);

int main(){

    long long int vetor[n] = {0};
    int posicao;
    
    vetor[0] = 1;
    vetor[30] = 21;
    vetor[50] = 30;
    vetor[65] = 4;

    printf("O resultado do somatorio e: %lld\n", somatorio(vetor,n));
                                                     
    return 0;
}

long long int somatorio(long long int vetor[], unsigned int num) {

    if (num == 1) return vetor[0];
    else return vetor[num-1]+somatorio(vetor, num-1);


}