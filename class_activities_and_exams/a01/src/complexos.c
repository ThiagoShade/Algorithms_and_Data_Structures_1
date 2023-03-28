#include <stdio.h>
#include <stdlib.h>
#include "complexos.h"



// Definicao da TAD
struct complexo {

    float re; // Componente real
    float im; // Componente imaginária

};

Complexo *COMPLEXOcria(float real, float imag) {

    Complexo* z = NULL;
    
    z = (Complexo*) malloc(sizeof(Complexo));
    if(!z){
      printf("Erro de alocação.\n");
      exit(1);
    }

    z->re = real;
    z->im = imag;

    return z;
}

void COMPLEXOlibera(Complexo *z) {

    free(z);
}

void COMPLEXOatribui(Complexo *z, float real, float imag) {
  
    z->re = real;
    z->im = imag;

}

void COMPLEXOmostra(Complexo *z) {
    
    notacao_cient(z->re);
    
    if(z->im < 0) printf(" - ");
    else printf(" + ");

    notacao_cient(z->im);
    printf("i\n\n");


}

Complexo *COMPLEXOconjuga(Complexo *z) {

}

Complexo *COMPLEXOadiciona(Complexo *z1, Complexo *z2) {

}

Complexo *COMPLEXOmultiplica(Complexo *z1, Complexo *z2) {

}

Complexo *COMPLEXOpotencia1(Complexo *base, int expoente) {

}

Complexo *COMPLEXOpotencia2(Complexo *base, Complexo *expoente) {

}

float COMPLEXOmagnitude(Complexo *z) {

}

float COMPLEXOangulo(Complexo *z) {

}
