#include <stdio.h>
#include <stdlib.h>

typedef struct Celula Celula;
typedef struct head head;

struct Celula {
    int abre; // Ã­ndice que o parÃªntese foi aberto.
    int fecha; // Ã­ndice que o parÃªntese foi fechado. -1 caso nÃ£o tenha sido fechado ainda.

    Celula *prox; // EndereÃ§o do prÃ³ximo parÃªntese. 
};

struct head {
    Celula* inicio;
};

void abreParenteses(int c, head *n);
/**
 * @brief funÃ§Ã£o que cria uma cÃ©lula,que representa um parÃªntese que foi aberto na lista de head n.
 * 
 * @param c Ã­ndice da string em que o parÃªntese foi aberto.
 * @param n endereÃ§o do head da lista do parÃªntese.
 */
void fechaParenteses(int c, head *n);
/**
 * @brief FunÃ§Ã£o que confirma que um parÃªntese foi fechado ao encontrar o parÃªntese mais recente que nÃ£o foi fechado.
 * 
 * @param c Ã­ndice da string em que o parÃªntese foi fechado.
 * @param n endereÃ§o do head da lista do parÃªntese.
 */
void checkParenteses(head *n);
/**
 * @brief FunÃ§Ã£o que verifica se apÃ³s todas as operaÃ§Ãµes de abre e fecha nÃ£o sobraram parÃªnteses sem fechar.
 * 
 * @param n endereÃ§o do head da lista do parÃªntese.
 */
void finalizaLista(head *n);
/**
 * @brief FunÃ§Ã£o que libera a memÃ³ria de todas as cÃ©lulas da lista.
 * 
 */

int main(){
    char e[1000];
    int c;
    head n; 

    n.inicio=NULL;

    scanf("%[^\n]%*c", e);

    for(c=0; e[c]!='\0'; c++){
        if(e[c]=='(') abreParenteses(c, &n); 
        if(e[c]==')') fechaParenteses(c, &n); 
    }

    checkParenteses(&n); // Garantindo que a lista seja desalocada.

    return 0;
}



void abreParenteses(int c, head *n){
    
    Celula *t;

    if(n->inicio == NULL){ // Caso essa seja a primeira cÃ©lula a ser colocada.
        n->inicio = (Celula*) malloc(sizeof(Celula)); // AlocaÃ§Ã£o
        if(!(n->inicio)) { // Verificando alocaÃ§Ã£o
            printf("Erro de alocaÃ§Ã£o\n");
            exit(1);
        }

        n->inicio->abre = c;
        n->inicio->fecha = -1; // PadrÃ£o que indica que o parÃªntese ainda nÃ£o foi fechado.
        n->inicio->prox = NULL; 

    } else{
        t = n->inicio;
        n->inicio = (Celula*) malloc(sizeof(Celula)); // AlocaÃ§Ã£o
        if(!(n->inicio)) { // Verificando alocaÃ§Ã£o
            printf("Erro de alocaÃ§Ã£o\n");
            exit(1);
        }

        n->inicio->abre = c;
        n->inicio->fecha = -1; // PadrÃ£o que indica que o parÃªntese ainda nÃ£o foi fechado.
        n->inicio->prox = t; // O t guardava o valor da antiga primeira cÃ©lula, que agora passa a ser a prÃ³xima da nova primeira cÃ©lula.

    }

    
}

void fechaParenteses(int c, head *n){

    Celula *t;

    if(n->inicio==NULL){ // Caso nÃ£o haja nenhum parÃªntese.
        printf("incorreta\n");
        finalizaLista(n); // Como jÃ¡ foi identificada como incorreta, jÃ¡ finaliza a lista e o programa
    }
    if(n->inicio->fecha==-1){ // Caso o primeiro parÃªntese seja o que serÃ¡ fechado.
        n->inicio->fecha=c;
    } else{
        t = n->inicio->prox;
        while(t!=NULL){ // Percorre toda a lista atÃ© achar o parÃªntese aberto mais recente.
            if(t->fecha==-1) {   
                t->fecha = c;
                return;
            }
            t = t->prox;
        }
        printf("incorreta\n");
        finalizaLista(n); // Como jÃ¡ foi identificada como incorreta, jÃ¡ finaliza a lista e o programa
    }


}

void checkParenteses(head *n){

    Celula *t;

    if(n->inicio->fecha==-1){ // Caso o primeiro parÃªntese nÃ£o tenha sido fechado.
        printf("incorreta\n");
        finalizaLista(n); // Como jÃ¡ foi identificada como incorreta, jÃ¡ finaliza a lista e o programa
    } else{ // Caso qualquer outro parÃªntese nÃ£o tenha sido fechado.
        t = n->inicio->prox;
        while(t!=NULL){ // Percorre toda a lista procurando algum parÃªntese que nÃ£o tenha sido fechada.
            if(t->fecha==-1){
                printf("incorreta\n");
                finalizaLista(n); // Como jÃ¡ foi identificada como incorreta, jÃ¡ finaliza a lista e o programa
            }
            t=t->prox;
        }
        printf("correta\n");
        finalizaLista(n); 
    }

}

void finalizaLista(head *n){

    Celula *t, *i;

    i=n->inicio;

    while(i!=NULL){ //Percorre toda a lista desalocando cada cÃ©lula.
        t=i->prox;

        free(i);

        i=t;
    }
    exit(0);
}
