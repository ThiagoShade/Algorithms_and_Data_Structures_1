#include <stdio.h>

int main(){
     
    int transposta=0;
    char sinal;
    int linhas, colunas, ml, nc, aux;
   
    scanf("%d %d",&ml, &nc);
    
    int primeira[100][100];
    int segunda[100][100];
    int resultado=0;
    
    for(linhas=0;linhas<ml;linhas++){
		for(colunas=0;colunas<nc;colunas++)scanf("%d",&primeira[linhas][colunas]);
	}
    
    scanf("%s",&sinal);
   
    if(sinal == 'x' && ml != nc){
        transposta = 5;
        for(linhas=0;linhas<ml;linhas++){
            for(colunas=0;colunas<nc;colunas++)scanf("%d",&segunda[colunas][linhas]);
        }

    }
    else{
        for(linhas=0;linhas<ml;linhas++){
            for(colunas=0;colunas<nc;colunas++)scanf("%d",&segunda[linhas][colunas]);
        }
    }
    if(sinal == '+'){
         for(linhas=0;linhas<ml;linhas++){
            for(colunas=0;colunas<nc;colunas++)printf("%d ",segunda[linhas][colunas]+primeira[linhas][colunas]);
            printf("\n");
        }   
    }

    else if(sinal == 'x'){

        for(linhas=0; linhas<ml; linhas++){  

            for(aux=0; aux<ml; aux++){   

                for(colunas=0;colunas<nc; colunas++){

                    resultado += (primeira[linhas][colunas] * segunda[colunas][aux]);
                }
                printf("%d ",resultado);
                resultado = 0;
            }
            printf("\n");
            }
        if(transposta == 5)printf("TRANSPOSICAO\n");
    }

    return 0;
}
