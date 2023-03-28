#ifndef COMPLEXOS_H
#define COMPLEXOS_H

// Definicao da TAD
typedef struct complexo {

    float re; // Componente real
    float im; // Componente imaginária

} Complexo;


// Prototipos das funcoes
Complexo *COMPLEXOcria(float real, float imag);
void COMPLEXOlibera(Complexo *z);
void COMPLEXOatribui(Complexo *z, float real, float imag);
void COMPLEXOmostra(Complexo *z);
Complexo *COMPLEXOconjuga(Complexo *z);
Complexo *COMPLEXOadiciona(Complexo *z1, Complexo *z2);
Complexo *COMPLEXOmultiplica(Complexo *z1, Complexo *z2);
Complexo COMPLEXOpotencia1(Complexo *base, int expoente);
Complexo *COMPLEXOpotencia2(Complexo *base, Complexo *expoente);
float COMPLEXOmagnitude(Complexo *z);
float COMPLEXOangulo(Complexo *z);
int notacao_cient(float num);
float euler(int pot);
float pi(int pot);
Complexo multiplica(Complexo z1, Complexo z2);
void COMPLEXOinverte(Complexo * z);

#endif
