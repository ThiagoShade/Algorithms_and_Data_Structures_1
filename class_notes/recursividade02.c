#include <stdio.h>

double potencia_exp_positivo(double b, int e);

int main() {
    

    double num;
    int exp;
//    long long int potencia;

    printf("Numero da base e exponencial positivo: ");
    
    scanf("%lf %d", &num, &exp);
    
//    potencia = potencia_inteira(num, exp);

    printf("%.2lf\n", potencia_exp_positivo(num, exp));
    printf("EU TE ODEIO TRUCO GOIANO\n");
    
    return 0;
}

double potencia_exp_positivo(double b, int e) {

    if (e == 0) return 1;
    else return b*potencia_exp_positivo(b, e-1); 
}