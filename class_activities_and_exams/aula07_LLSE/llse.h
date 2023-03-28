#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define FALHA -1
#define CHAVE_INVALIDA 0

typedef struct Celula *ApontadorCelula;

typedef struct Celula{
    unsigned int chave;
    unsigned int dado;
    ApontadorCelula prox;
}Celula;

int LLSEcriarListaVazia(ApontadorCelula *p);
int LLSEcriarListaChave(ApontadorCelula *p, Celula celula);
int LLSEinserirInicio(ApontadorCelula *p, Celula celula);
int LLSEinserirFinal(ApontadorCelula *p, Celula celula);
int LLSEremoverInicio(ApontadorCelula *p);
int LLSEremoverFinal(ApontadorCelula *p);
int LLSEtamanhoLista(ApontadorCelula p);
int LLSEconcatenarListas(ApontadorCelula p, ApontadorCelula q, ApontadorCelula *lista);
void LLSEmostraLista(ApontadorCelula p);
