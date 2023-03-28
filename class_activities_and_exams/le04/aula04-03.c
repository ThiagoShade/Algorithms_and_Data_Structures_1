#include <stdio.h>

int Ackerman(int m, int n);

int main() {

    int m, n;

    scanf("%d %d", &m, &n); // entrada
    
    printf("%d\n",Ackerman(m, n)); // saida(resultado)
    
    return 0;
}

int Ackerman(int m, int n){

    if (m == 0) return n+1; // Caso trivial 
    
    else if (m > 0 && n == 0) return Ackerman(m-1,1); // se n igual a 0 e m maior que 0

    else if (m > 0 && n > 0) return Ackerman(m-1,Ackerman(m,n-1));// se n e m maiores que 0
    
}
