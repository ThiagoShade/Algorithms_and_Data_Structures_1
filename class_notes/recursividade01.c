// A versao recursiva pode ser ata mais lenta, devido ao custo de manter as chamadas.
// A versao recursiva nao necessariamente traz economia de memoria. Isto porque os valores processados sao mantidos em pilhas.

#include <stdio.h>

unsigned long int fatorial(int n);

int main() {

    int n = 5, f;

    f = fatorial(n);

    printf("%lu\n", f);

    return 0;
}

unsigned long int fatorial(int n) {

    if(n == 1) return 1;
    else return n*fatorial(n-1);
}
