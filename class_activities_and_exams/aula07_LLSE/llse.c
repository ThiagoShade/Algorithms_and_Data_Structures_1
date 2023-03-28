#include "llse.h"

int nchave = 0;

/**
 * @brief  A função cria uma lista vazia. (Garante que o conteúdo do apontador é nulo)
 * 
 * 
 * @param p Endereço que aponta para a lista vazia. 
 * @return Retorna 1 caso o processo seja realizado corretamente.
 */
int LLSEcriarListaVazia(ApontadorCelula *p){
    (*p) = (ApontadorCelula) NULL; // lista vazia , aponta para NULL.

    return(SUCESSO);  // processo realizado corretamente;
}


/**
 * @brief A função cria uma lista com uma celula inicial.
 * 
 * @param p Endereço do apontador inicial de célula.
 * @param celula Celula inicial.
 * @return Retorna 1 caso o processo seja realizado corretamente.
 */
int LLSEcriarListaChave(ApontadorCelula *p, Celula celula){
    (*p) = (ApontadorCelula) NULL;

    return(LLSEinserirInicio(p, celula));
}


/**
 * @brief Função que insere uma célula no inicio de uma lista.
 * 
 * @param p Endereço do apontador inicial de célula.
 * @param celula Célula a ser inserida.
 * @return Retorna 1 caso o processo seja realizado corretamente. 
 */
int LLSEinserirInicio(ApontadorCelula *p, Celula celula){
    ApontadorCelula q; // Novo ponteiro, que no futuro apontará para o próximo nó

    q = (ApontadorCelula) malloc(sizeof(Celula)); // Alocando novo ponteiro com tamanho da struct
    if(q == NULL){
        return(FALHA); //Falha na alocação
    }
    else{ // Sucesso na alocação
        q->chave = celula.chave;
        /*
        printf("Sua celula recebeu a chave %d\n", nchave);
        printf("Digite o numero do dado que voce quer guardar: ");
        scanf("%d", &celula.dado);
        */
        q->dado = celula.dado;
        
        q->prox = (ApontadorCelula) (*p); // Apontando o ponteiro q para a proxima celula
        (*p) = q; // Trocando p por q, já que agora q é a mais nova celula
    }

    return (SUCESSO);
}


/**
 * @brief Função que insere uma célula no final de uma lista.
 * 
 * @param p Endereço do apontador inicial de célula.
 * @param celula Célula a ser inserida.
 * @return Retorna 1 caso o processo seja realizado corretamente. 
 */
int LLSEinserirFinal(ApontadorCelula *p, Celula celula){
    ApontadorCelula q, r;
    
    if((*p) == NULL) 
        LLSEinserirInicio(p,celula); // caso a lista esteja vazia primeiro incluimos o seu elemnto inicial;
    else{
        
        q = (ApontadorCelula) malloc(sizeof(Celula)); // aloca o espaço em que o elemento será inserido;
        if(q == NULL){
            return (FALHA);
        }
        else{                       
            q->chave = celula.chave;        // recebe indentificação do elemento;
            q->dado = celula.dado;          // recebe conteúdo - elemento em si;
            q->prox = (ApontadorCelula) NULL; // define como sendo o último elemento pois seu próximo será null;
            r = (*p);   // variavel que recebe o endereço do primeiro elemento da lista;
        
        while(r->prox != NULL){ //percorre a lista toda até identificar o último;
            r = r->prox;  
        }

        r->prox = q; // o proximo do último recebe o novo elemento que passará a ser o último.

        return(SUCESSO);
        }
    }
}


/**
 * @brief Função que remove uma célula no inicio de uma lista.
 * 
 * @param p Endereço do apontador inicial de célula.
 * @return Retorna 1 caso o processo seja realizado corretamente. 
 */
int LLSEremoverInicio(ApontadorCelula *p){

    Celula * q; // ponteiro auxiliar;

    if((*p) == NULL) {
        return(FALHA); // lista vazia;
    } else {
        q = (*p);          // q salva o conteudo do primeiro elemento;
        (*p) = (*p)->prox; // p que agora passa a ser o proximo elemento da lista ;
        free(q);           // remove oque era o primeiro elemento da lista; 
    }

    return (SUCESSO);
    

}


/**
 * @brief Função que remove uma célula no final de uma lista. 
 * 
 * @param p Endereço do apontador inicial de célula.
 * @return Retorna 1 caso o processo seja realizado corretamente. 
 */
int LLSEremoverFinal(ApontadorCelula *p){

    Celula * q, * t;

    if((*p) == NULL) {
        return (FALHA); // lista ainda não contém elementos;
    } else {
        q = (*p);        // variavel auxiliar recebe o conteudo do primeiro elemento;
        while(q->prox != NULL) {  // percorre a lista ate chegar no ultimo elemento;
            t = q;              // salva o endereço do antepenultimo elemento que passará a ser o ultimo no final do processo; 
            q = q->prox;       // pula de elemento em elemento checando se é nulo;
        }
        t->prox = NULL;    // garante que o antepenultimo apontara para null e então passa a ser o ultimo;
        free(q);           // remove de fato o ultimo elemento.
    }
    
    return (SUCESSO);

}


/**
 * @brief Função que calcula a quantidade de células em uma lista.
 * 
 * @param p Endereço do apontador inicial de célula.
 * @return inteiro com o valor igual o tamanho da lista
 */
int LLSEtamanhoLista(ApontadorCelula p){
    int i = 0;

    if(p == NULL){
        return (0);  // lista está vazia;
    }

    while(p != NULL){ // pula de elemento em elemento checando se é nulo;
        p = p->prox;  
        i++;         // conta quantos elementos estão na lista;
    }

    return (i);   // retorna o tamanho total da lista.
}


/**
 * @brief Função que cria a concatenação de duas listas.
 * 
 * @param p Lista 1 a ser concatenada.
 * @param q Lista 2 a ser concatenada.
 * @param lista Endereço que aponta para o apontador que aponta para o primeiro termo da concatenação das duas listas, o apontador recebe NULL caso as duas listas estejam vazias.
 * @return 
 */
int LLSEconcatenarListas(ApontadorCelula p, ApontadorCelula q, ApontadorCelula *lista){
    
    ApontadorCelula a;

    if (p == NULL && q == NULL) {  // Caso as duas listas estejam vazias.
        (*lista) = NULL;
        return (SUCESSO);
    }
    if(p == NULL) { // Caso a lista p esteja vazia
        a = q;
        LLSEcriarListaChave(lista, (*a)); // Criando a lista concatenada com a primeira célula de q.
        while(a != NULL){
            LLSEinserirFinal(lista, (*a)); // Inserindo uma a uma as células de lista q.
            a = a->prox;
        }
        
        return (SUCESSO);
    }
    else {
        
        a = p;
        LLSEcriarListaChave(lista, (*a)); // Criando a lista concatenada com a primeira célula de p.
        while(a != NULL){
            LLSEinserirFinal(lista, (*a)); // Inserindo uma a uma as células de lista p.
            a = a->prox;
        }
        
        a = q;
        while(a != NULL){
            LLSEinserirFinal(lista, (*a)); // Inserindo uma a uma as células de lista q.
            a = a->prox;
        }
        return (SUCESSO);
    } 

}

/**
 * @brief Função que printa a lista.
 * 
 * @param p Lista a ser mostrada.
 */
void LLSEmostraLista(ApontadorCelula p){
    ApontadorCelula a = NULL;
    
    printf("Lista:");
    if (p != NULL) {
        a = p;
        while(a != NULL) {
            printf(" %d", a->dado);
            a = a->prox;
        }
    }
    printf("\n");

}
