#include <stdio.h>

#define PI 3.1415926535

typedef struct {
    double raio;
    double alt;
} Cil;


double altura(Cil * a);
double raio(Cil * a);
double area_base(Cil * a);
double area_face(Cil * a);
double volume(Cil * a);

int main() {

    Cil c;
    
    printf("Digite o valor do raio: ");
    scanf("%lf", &c.raio);
    printf("Digite o valor da altura: ");
    scanf("%lf", &c.alt);

    printf("A altura do cilindro é: %lf\n", altura(&c));
    printf("O raio do cilindro é: %lf\n",raio(&c));
    printf("A area da base é: %lf\n",area_base(&c));
    printf("A area da face é: %lf\n",area_face(&c));
    printf("O volume do cilindro é: %lf\n",volume(&c));

    return 0;
}



double altura(Cil * a) {
    return a->alt;
}

double raio(Cil * a) {
    return a->raio;
}

double area_base(Cil * a) {
    return (PI*(a->raio*a->raio));
}

double area_face(Cil * a) {
    return (a->alt * (2*PI*a->raio));
}

double volume(Cil * a) {
    return (a->alt*area_base(a));
}


