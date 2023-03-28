#include "llse.h"

int main(){

    Celula q;
    ApontadorCelula *p = NULL, *t = NULL, *r = NULL;
    

    p = (ApontadorCelula*) malloc(sizeof(ApontadorCelula));
    t = (ApontadorCelula*) malloc(sizeof(ApontadorCelula)); 
    r = (ApontadorCelula*) malloc(sizeof(ApontadorCelula)); 

    LLSEcriarListaVazia(p); // Func criar lista vazia
    LLSEcriarListaVazia(t);
    LLSEcriarListaVazia(r);

    LLSEmostraLista(*p);
    LLSEmostraLista(*t);
    LLSEmostraLista(*r);

    q.chave = 0;
    q.dado = 20;
    LLSEcriarListaChave(p, q);
    LLSEmostraLista(*p);

    q.chave = 1;
    q.dado = 54;
    LLSEinserirInicio(p, q);
    LLSEmostraLista(*p);

    q.chave = 2;
    q.dado = 95;
    LLSEinserirInicio(p, q);
    LLSEmostraLista(*p);

    q.chave = 3;
    q.dado = 548;
    LLSEinserirFinal(p, q);
    LLSEmostraLista(*p);

    q.chave = 4;
    q.dado = 11;
    LLSEinserirFinal(p, q);
    LLSEmostraLista(*p);

    LLSEremoverInicio(p);
    LLSEremoverFinal(p);
    LLSEmostraLista(*p);

    printf("Tamanho Lista 1: %d\n", LLSEtamanhoLista(*p));
    printf("Tamanho Lista 2: %d\n", LLSEtamanhoLista(*t));
    printf("Tamanho Lista 3: %d\n", LLSEtamanhoLista(*r));

    q.chave = 8;
    q.dado = 845;
    LLSEinserirFinal(t, q);
    LLSEmostraLista(*t);

    q.chave = 7;
    q.dado = 48;
    LLSEinserirInicio(t, q);
    LLSEmostraLista(*t);

    LLSEconcatenarListas(*p, *t, r);
    LLSEmostraLista(*r);


    free(p), free(t), free(r);

    return (0);
}
