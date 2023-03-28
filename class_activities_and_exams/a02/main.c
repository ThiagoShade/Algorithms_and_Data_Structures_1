#include "casa.h"


int main (){
    
    head *p = NULL;

    p = (head *) malloc(sizeof(head));

    p->inicio = NULL;

    printf("%c\n", 'r'-32);
    
    forma_Instru(p);

    print_Instru_rev(p);
    
    limpa_Instru(p);

    free(p);
    
    
    return 0;
}
