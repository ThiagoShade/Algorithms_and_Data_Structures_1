#include <stdio.h>

#define PI 3.1415926535

typedef struct {
    double raio;
} Esf;

double raio(Esf * e);
double area_superficie(Esf * e);
double volume(Esf * e);



int main(){
    
    Esf a;
    
    
    printf("Digite o valor do raio: ");
    scanf("%lfr", &a.raio);


    printf("O raio é: %lf\n", raio(&a));
    printf("O volume é: %lf\n", volume(&a));    
    printf("A area da surperficie é: %lf\n", area_superficie(&a));
      
    return 0;
}




double raio(Esf * e) {
    return e->raio;
}

double area_superficie(Esf * e) {
    return 4 * PI * (e->raio*e->raio);
}

double volume(Esf * e) {
    return (4 * PI * (e->raio*e->raio*e->raio))/3;
}
