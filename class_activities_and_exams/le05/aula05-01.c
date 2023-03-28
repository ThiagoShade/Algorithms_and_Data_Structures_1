#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef long int ld;

typedef struct conj{

    char nome[21]; // Vetor que guarda o nome do vetor.
    ld num[10]; // Vetor que guarda os números do conjunto.
    int card; // Cardinalidade do conjunto.

} conj;


conj * v = NULL; // Vetor de conjuntos que irá guardar todos os conjuntos criados.
int qtd = 0; // Variável que guarda quantos conjuntos estão guardados na vetor v no momento.


int menu_selecao();
void criar_conjunto(); // Totalmente certo
void nomeia_conjunto(conj * a);  // Totalmente certo
void esvazia_conjunto(conj * a); // Totalmente certo
int vazio_conjunto(); // Totalmente certo
int incluir_elemento(); // Totalmente certo
int excluir_elemento(); // Totalmente certo
int cardinalidade(); // Totalmente certo
int qnt_elem_Maiores(); // Totalmente certo
int qnt_elem_menores(); // Totalmente certo
int averiguar_elem_exist(); // Totalmente certo
int conjunto_iguais(); // Totalmente certo
int ident_subconjunto(); // Totalmente certo
int complemento_conjunto(); // Totalmente certo
int uniao(); //
int interseccao(); // Totalmente certo
int conjunto_Ordem();
int copiar_conjunto();
int destruir_conjunto(); // Totalmente certo
void atualiza_conjunto(conj * a);
void print_crescente(conj * a);
void print_decrescente(conj * a);
void copia_vetor(ld *a, ld *b);


int main() {

    int a;
    int QualFunc = 99; //Funcao inicializada em 99 para garantir que o while comece
                       //E que nao selecione nenhuma funcao
    char c;
    

    inicio:
    while(QualFunc != -1){
        sleep(1);
        printf("\n//////////////////////////////////////////////\n\n");
        printf("1 - Criar conjunto\n");
        printf("2 - Verificar se o conjunto está vazio\n");
        printf("3 - Incluir elemento\n");
        printf("4 - Excluir elemento\n");
        printf("5 - Checar cardinalidade\n");
        printf("6 - Quantidade de elementos maior que um valor\n");
        printf("7 - Quantidade de elementos menor que um valor\n");
        printf("8 - Averiguar se um elemento pertence ao conjunto\n");
        printf("9 - Verificar se dois conjuntos são identicos \n");
        printf("10 - Identificar se um conjunto é subconjunto de outro\n");
        printf("11 - O complemento de um conjunto em relação a outro conjunto\n");
        printf("12 - A união de dois conjuntos\n");
        printf("13 - A intersecção de dois conjuntos\n");
        printf("14 - Conjunto segundo uma ordem (Crescente/Decrescente)\n");
        printf("15 - Copiar conjunto para outro conjunto\n");
        printf("16 - Destruir conjunto\n");        
        printf("\n//////////////////////////////////////////////\n\n");
        printf("Digite o número da função que você quer usar ou -1 para finalizar o programa: ");
       
        scanf("%d%*c", &QualFunc);
        

        switch (QualFunc)
        {
        case 1:
            while(1) {
                criar_conjunto();
                ERRODIG1:
                printf("Deseja criar mais conjuntos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG1;
            }
            break;
        
        case 2:
            while(1) {
                if(vazio_conjunto() == -1) break;
                ERRODIG2:
                printf("Deseja continuar checando se conjuntos estão vazios? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG2;        
            }
            break;
        
        case 3:
            while(1) {
                //printf("Digite o número correspondente ao conjunto que deseja incluir um ou mais elementos, ou digite -1 para cancelar o processo\n");
                if(incluir_elemento() == -1) break;
                ERRODIG3:
                printf("Deseja continuar incluindo mais elementos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG3;        
            }
            break;
        
        case 4:
            while(1) {
                //printf("Digite o número correspondente ao conjunto que deseja excluir um elemento, ou digite -1 para cancelar o processo\n");
                if(excluir_elemento() == -1) break;
                ERRODIG4:
                printf("Deseja continuar excluindo mais elementos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG4;        
            }
            break;
        case 5:
            while(1) {
                //printf("Digite o número correspondente do conjunto que deseja saber a cardinalidade, ou digite -1 para cancelar o processo\n");
                if(cardinalidade() == -1) break;
                ERRODIG5:
                printf("Deseja continuar calculando a cardinalidade de conjuntos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG5;        
            }
            break;
            
        
        case 6:
            while(1) {
                //printf("Digite o número correspondente do conjunto que deseja analisar quantos elementos maiores que um certo valor existem, ou digite -1 para cancelar o processo\n");
                if(qnt_elem_Maiores() == -1) break;
                ERRODIG6:
                printf("Deseja continuar analisando quantos elementos maiores que um certo valor existem? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG6;        
            }
            break;
            
            
        case 7:
            while(1) {
                //printf("Digite o número correspondente do conjunto que deseja analisar quantos elementos menores que um certo valor existem, ou digite -1 para cancelar o processo\n");
                if(qnt_elem_menores() == -1) break;
                ERRODIG7:
                printf("Deseja continuar analisando quantos elementos menores que um certo valor existem? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG7;        
            }
            break;
            

        case 8:
            while(1) {
                //printf("Digite o número correspondente ao conjunto que deseja averiguar se um elemento está contido, ou digite -1 para cancelar o processo\n");
                if(averiguar_elem_exist() == -1) break;
                ERRODIG8:
                printf("Deseja continuar procurando elementos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG8;        
            }
            break;
            

        case 9:
            while(1) {
                //printf("Digite o número correspondente aos conjuntos que deseja checar se são idênticos, ou digite -1 para cancelar o processo\n");
                if(conjunto_iguais() == -1) break;
                ERRODIG9:
                printf("Deseja continuar comparando conjuntos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG9;        
            }
            break;
                

        case 10:
            while(1) {
                //printf("Digite, respectivamente, os números correspondentes aos conjuntos que deseja: identificar se é subconjunto e do conjunto que deverá ser analisado, ou digite -1 para cancelar o processo\n");
                if(ident_subconjunto() == -1) break;
                ERRODIG10:
                printf("Deseja continuar identificando subconjuntos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG10;        
            }
            break;
        
        case 11:
            while(1) {
                //printf("Digite, respectivamente, os números correspondentes aos conjuntos que deseja: saber o completo e do conjunto ao qual será analisado, ou digite -1 para cancelar o processo\n");
                if(complemento_conjunto() == -1) break;
                ERRODIG11:
                printf("Deseja continuar identificando complementos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Você digitou errado, digite novamente!");
                goto ERRODIG11;        
            }
            break;   

        case 12:
            while(1) {
                //printf("Digite os números correspondentes aos conjuntos que deseja realizar a união, ou digite -1 para cancelar o processo\n");
                if( uniao() == -1) break;
                ERRODIG12:
                printf("Deseja continuar realizando a união entre dois conjuntos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG12;        
            }
            break;         

        case 13:
            while(1) {
                //printf("Digite os números correspondentes aos conjuntos que deseja realizar a intersecção, ou digite -1 para cancelar o processo\n");
                if( interseccao() == -1) break;
                ERRODIG13:
                printf("Deseja continuar realizando a intersecção entre dois conjuntos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG13;        
            }
            break;      
           

      case 14:
            while(1) {
                //printf("Digite o número correspondente ao conjunto que deseja ordenar, ou digite -1 para cancelar o processo\n");
                if( conjunto_Ordem() == -1) break;
                ERRODIG14:
                printf("Deseja continuar ordenando conjuntos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG14;        
            }
            break;      
            

        case 15:
            while(1) {
                // printf("Digite o número correspondente ao conjunto que deseja copiar, ou digite -1 para cancelar o processo\n");
                if( copiar_conjunto() == -1) break;
                ERRODIG15:
                printf("Deseja continuar copiando conjuntos? S ou N\n");
                scanf("%c%*c", &c);conj * v = NULL; // Vetor de conjuntos que irá guardar todos os conjuntos criados.
int qtd = 0;
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG15;        
            }
            break;   
            
       /*   */
        case 16:
            while(1) {
                if(destruir_conjunto() == -1) break;
                ERRODIG16:
                printf("Deseja continuar destruindo conjuntos? S ou N\n");
                scanf("%c%*c", &c);
                if(c == 'N' || c == 'n') break;
                else if (c == 'S' || c == 's') continue;
                else printf("Voce digitou errado, digite novamente!");
                goto ERRODIG16;        
            }
            break;
            
        default: if(QualFunc == 0) return 0;
            break;
        }

        
        
        
        
        // printf("Digite 0 para finalizar o programa ou o número de outra função\n\n");
    }
    
    free(v);

    return 0;
}


/**
 * @brief Função que apresenta um menu com todos os conjuntos existentes até o momento para o usuário selecionar
 * com qual conjunto ele deseja realizar a ação atual.
 * 
 * @return -1 se 
 */
int menu_selecao() {

    int i;
    int num;

    if(qtd == 0) {
        printf("Não há conjuntos para realizar essa operação\n");
        return -1;
    }

    while(1){

        i = 0;
        while(i != qtd) { // Printa todos os nomes dos conjuntos.
            printf("%d - %s\n", i+1, (v+i)->nome);
            i++;
        }

        scanf("%d%*c", &num);
        if(num == -1) return -1; 
        if (num < 1 || num > qtd) {
            printf("Número Inválido\n");
            continue;
        }
        return num;
    }

}

/**
 * @brief Cria um conjunto, alocando memória para ele e para o vetor de números e verificando se o processo foi feito com sucesso.
 * 
 * @return Endereço alocado para o conjunto criado.
 */
void criar_conjunto() {

    v = realloc(v, (1+qtd)*sizeof(conj)); 

    if (!v) { 
        printf("Erro de alocação\n");
        printf("Falha ao criar o conjunto.\n");
        exit(1);
    }
    else {
        esvazia_conjunto(v+qtd); // Coloca -1 em todos os espaços do vetor do conjunto recém criado.
        (v+qtd)->card = 0; // Garante que a variável de cardinalidade do conjunto recém criado é 0.

        nomeia_conjunto(v+qtd);
        qtd++;
        printf("Conjunto criado com sucesso\n");
        
    }
}

/**
 * @brief Dá nome a um conjunto recém criado.
 * 
 * @param a Conjunto a ser nomeado.
 */
void nomeia_conjunto(conj * a) {

    int i = 0;
    char temp[10000];

    while(1){
        printf("Escreva um nome para esse conjunto: (até 20 caracteres)\n");
        scanf("%[^\n]%*c", temp);
        
        if(strlen(temp) > 20 || strlen(temp) < 1) {
            printf("Nome inválido\n");
        }
        else {
            while(temp[i] != '\0') {
                a->nome[i] = temp[i];
                i++;
            }
            a->nome[i] = '\0';

            break;
        }
    
    }
}

/**
 * @brief Coloca -1 em todos os espaços do vetor do conjunto
 * 
 * @param a Endereço do conjunto a ser esvaziado.
 */
void esvazia_conjunto(conj * a){

    int c;
    
    for(c=0;c<10;c++) a->num[c] = -1;
}

/**
 * @brief Verifica se o conjunto está vazio ou não.
 * 
 * @return 0 Se foi checado com sucesso, -1 se houve desistência no processo.
 */
int vazio_conjunto() {

    int n;

    printf("Digite o número do conjunto que você deseja verificar se está vazio, ou digite -1 para cancelar o processo:\n");
    n = menu_selecao();
    if (n == -1) return -1;

    if ((v+n-1)->card == 0) printf("O conjunto está vazio\n");
    else printf("O conjunto não está vazio\n");

    return 0;
}

/**
 * @brief incluir elementos dentro de um conjunto caso ele ja nao esteja;
 *  
 * @return 0 se a opreação foi feita com sucesso, -1 se houve desistência no processo.
 */
int incluir_elemento(){

    long int elemento;
    int n, q, c, falhou=0, contador;
    char carac;
    
    printf("Digite o número do conjunto que você deseja incluir elemento(s), ou digite -1 para cancelar o processo:\n");
    n = menu_selecao();
    if (n == -1) return -1;
    
    while (1) {
        printf("Digite quantos elementos deseja incluir no conjunto, ou digite -1 para cancelar a inclusão:\n");
        scanf("%d%*c",&q);
        if (q <= 0) {
            if (q == -1) return -1;
            else {
                printf("Quantidade de elementos inválidos, digite um número positivo\n");
            }
        }
        if (q > 10) {
            printf("Quantidade de elementos inválidos, o conjunto só suporta no máximo 10 elementos\n");
        }

        break;
    }

    
    for(c=0;c<q;c++){
        
        printf("Digite um elemento a ser incluido, ou digite -1 para cancelar o processo:\n");
        scanf("%ld%*c",&elemento);
        if (elemento == -1) return -1;
        
        if (elemento < 0) {
            printf("Dígito inválido\n");
            printf("O conjunto só aceita números naturais\n");
            c--;
            continue;
        }
        if (elemento > __LONG_MAX__){
            printf("Falha ao realizar a inserção\n");
            printf("Número muito grande\n");
            c--;
            continue;
        }

        for(contador=0;contador<10;contador++){
            
            if(elemento == (v+n-1)->num[contador]){
                printf("O conjunto %s ja possui esse elemento\n", (v+n-1)->nome );
                c--;
                break;
            }
            else if((v+n-1)->num[contador] == -1){
                (v+n-1)->num[c] = elemento;
                (v+n-1)->card++;
                break;
            }
        }
    
    }

    atualiza_conjunto(v+n-1);

    return 0;
}//___________________________________________________________________________________________________________

/**
 * @brief percorrer o conjunto procurando o elemento a ser excluido;
 * 
 * @return 0 se a operação foi realizada com sucesso, -1 se houve desistência no processo.
*/

int excluir_elemento(){

    long int elemento;
    int n, q, c, contador;
    
    printf("Digite o número do conjunto que você deseja excluir elemento(s), ou digite -1 para cancelar o processo\n");
    
    n = menu_selecao();
    if (n == -1) return -1;
    
    if((v+n-1)->card == 0) {
        printf("O conjunto %s está vazio, não há elementos para serem excluídos\n", (v+n-1)->nome);
        return -1;
    }
    

    for(c=0;c<q;c++){

        printf("Os elementos do conjunto %s são:\n", (v+n-1)->nome);
        for(contador = 0; contador < 10; contador++) {
            if ((v+n-1)->num[contador] != -1) {
                printf("%ld ", (v+n-1)->num[contador]);
            }
        }
        
        printf("Digite um dos elementos a ser excluído, ou digite -1 para cancelar o processo:\n");
        scanf("%ld%*c",&elemento);

        if (elemento == -1) return -1;
        if (elemento > __LONG_MAX__){
            printf("Falha ao realizar a remoção\n");
            printf("Número muito grande\n");
            c--;
            continue;
        }
        if (elemento <= 0) {
            printf("Número inválido, digite um número positivo.\n");
            c--;
            continue;
        }
        
        for(contador=0;contador<10;contador++){
            
            if(elemento == (v+n-1)->num[contador]){
                (v+n-1)->num[c] = -1;
                (v+n-1)->card--;
                break;

            }
        }
        if (contador == 10) {
            printf("Falha ao realizar a remoção\n");
            printf("O elemento não está presente no conjunto\n");
            c--;
        }
    
    }

    atualiza_conjunto(v+n-1);

    return 0;
    
} //_____________________________________________________________________________________________


/**
 * @brief Função que printa a cardinalidade de um conjunto selecionado.
 * 
 * @return 0 se a operação foi realizada com sucesso, -1 se houve desistência no processo.
 */
int cardinalidade() {

    int n;

    printf("Digite o número do conjunto que você deseja checar a cardinalidade, ou digite -1 para cancelar o processo:\n");
    n = menu_selecao();
    if (n == -1) return -1;

    printf("A cardinalidade do conjunto %s selecionado é %d\n", (v+n-1)->nome, (v+n-1)->card);
    return 0;
}

/**
 * @brief conta quantos elementos maiores que um certo valor o conjunto possui 
 * 
 * @return 0 se o processo foi feito com sucesso, -1 se houve desistência no processo.
 */
int qnt_elem_Maiores(){

    long int elemento;
    int n, c, q=0;

    printf("Digite o número do conjunto que você deseja verificar, ou digite -1 para cancelar o processo:\n");
    n = menu_selecao();
    if (n == -1) return -1;

    printf("Digite o valor que deseja.\n");

    scanf("%ld%*c", &elemento);
    
    for(c=0;c<10;c++){
        if ((v+n-1)->num[c] == -1) continue;
        if((v+n-1)->num[c] > elemento) q++;
    }

    printf("Há %d elemento(s) maior(es) que %ld no conjunto %s\n", q, elemento, (v+n-1)->nome);
    return 0;
}//____________________________________________________________________________________________________________


/**
 * @brief Função que checa quantos elementos menores que um certo número existe no conjunto.
 * 
 * @return 0 se o processo foi feito com sucesso, -1 se houve desistência no processo
 */
int qnt_elem_menores(){

    long int elemento;
    int n, c, q=0;

    printf("Digite o número do conjunto que você deseja verificar, ou digite -1 para cancelar o processo:\n");
    n = menu_selecao();
    if (n == -1) return -1;


    printf("Digite o valor que deseja analisar:\n");

    scanf("%ld%*c", &elemento);
    for(c=0;c<10;c++){
        if ((v+n-1)->num[c] == -1) break;
        if( (v+n-1)->num[c] < elemento) q++;
    }

    printf("Há %d elemento(s) menores(es) que %ld\n", q, elemento);
}//_________________________________________________________________________________________________________________

/**
 * @brief averiguar se um elemento pertence ao conjunto;
 * 
 * @return 0 se o processo ocorreu com sucesso, -1 se houve desistência no processo.
 */
int averiguar_elem_exist(){

    long int elemento;
    int n, c;

    printf("Digite o número do conjunto que deseja verificar, ou digite -1 para cancelar o processo\n");
    n = menu_selecao();
    if(n == -1) return -1;

    printf("Digite o elemento que deseja encontrar: \n");
    scanf("%ld%*c",&elemento);

    for(c=0;c<10;c++){
       
        if ((v+n-1)->num[c] == -1) break;
        if (elemento == (v+n-1)->num[c]){
            
            printf("O elemento %ld percente ao conjunto %s\n", elemento, (v+n-1)->nome);
            return 0;
        }
    }

    printf("O elemento %ld não pertence ao conjunto %s\n", elemento, (v+n-1)->nome);
    return 0;
}//___________________________________________________________________________________________________________________

/**
 * @brief Função que verifica se dois conjuntos são iguais.
 * 
 * @return 0 se o processo ocorreu com sucesso, -1 se houve desistência no processo.
 */
int conjunto_iguais(){

    int n1, n2, falhou=0, c;

    printf("Digite o primeiro conjunto que será verificada a igualdade, ou digite -1 para cancelar o processo:\n");
    n1 = menu_selecao();
    if (n1 == -1) return -1;
    printf("Digite o segundo conjunto que será verificada a igualdade, ou digite -1 para cancelar o processo:\n");
    n2 = menu_selecao();
    if (n2 == -1) return -1;

    for(c=0;c<10;c++) {
        if((v+n1-1)->num[c] != (v+n2-1)->num[c]) {
            printf("Os conjuntos %s e %s são diferentes\n", (v+n1-1)->nome, (v+n2-1)->nome);
            return 0;
        }
    }

    printf("Os conjuntos %s e %s são indênticos.\n", (v+n1-1)->nome, (v+n2-1)->nome);
    return 0;

}//______________________________________________________________________________________________________________________
/**
 * @brief Identifica se um conjunto é subconjunto do outro.
 * 
 * @return 0 se o processo ocorreu com sucesso, -1 se houve desistência no processo.
 */
int ident_subconjunto(){

    int c, k;
    int n1, n2, contador;
    
    printf("Digite o número do conjunto que você quer verificar se é subconjunto do outro, ou digite -1 para cancelar o processo:\n");
    n1 = menu_selecao();
    if (n1 == -1) return -1;
    printf("Digite o número do conjunto que você quer verificar se o anterior é subconjunto, ou digite -1 para cancelar o processo:\n");
    n2 = menu_selecao();
    if (n2 == -1) return -1;

    for(c=0;c<10;c++){ 
        for(k=0;k<10;k++) {
            if((v+n1-1)->num[c] == (v+n2-1)->num[k]) break;
        }
        if (k == 10) {
            printf("O conjunto %s não é um subconjunto do conjunto %s\n", (v+n1-1)->nome, (v+n2-1)->nome);
            return 0;
        } 
    }

    printf("O conjunto %s é um subconjunto do conjunto %s.\n", (v+n1-1)->nome, (v+n2-1)->nome);
    return 0;
    
}

/**
 * @brief Identifica os complementos de um conjunto em relacao ao outro, printa eles e se desejado salva o conjunto complemento
 * 
 * @return se 0 a funcao rodou normal, -1 se o usuario desistiu 
 */
int complemento_conjunto(){
    conj comp;
    int n1, n2;
    int i, j, c = 0;
    char carac;

    esvazia_conjunto(&comp);

    printf("Digite o numero do conjunto que voce deseja saber o complemento em relacao ao outro, ou digite -1 para cancelar o processo:\n");
    n1 = menu_selecao();
    
    if(n1 == -1) return -1;

    printf("Digite o numero do conjunto que sera complementado em relacao ao anterior, ou digite -1 para cancelar o processo:\n");
    n2 = menu_selecao();

    if(n2 == -1) return -1;

    for(i=0;i<10;i++){
        if((v+n2-1)->num[i] == -1) break;
        for(j=0;j<10;j++){
            if((v+n2-1)->num[i] == (v+n1-1)->num[j]) break;

        }

        if(j == 10){
            comp.num[c] = (v+n2-1)->num[i];
            c++;
            comp.card++;
        }
    }
    
    printf("Conjunto complemento de %s em relacao a %s: ", (v+n1-1)->nome, (v+n2-1)->nome);

    print_crescente(&comp);

    while(1) {
        printf("Deseja salvar o conjunto complemento? S ou N\n");
        scanf("%c%*c", &carac);
        if(c == 'N' || c == 'n') return 0;
        else if (c == 'S' || c == 's') {
            criar_conjunto();
            strcpy(comp.nome,(v+qtd-1)->nome);
            v[qtd-1] = comp;
            return 0;
        }
        else printf("Voce digitou errado, digite novamente!\n");
    }

    atualiza_conjunto(v+qtd-1);


    return 0;
}



/**
 * @brief Função que faz a união de dois conjuntos.

 * 
 * @return 0 se o processo ocorreu com sucesso, -1 se houve erro ou desistência no processo
 */
int uniao(){

    conj uni;

    esvazia_conjunto(&uni);
    int n1, n2;
    int i, j, c = 0;
    char carac;
    
    printf("Digite o numero do primeiro conjunto que voce deseja unir: \n");  
    n1 = menu_selecao();
    if(n1 == -1) return -1;

    printf("Digite o numero do segundo conjunto que voce deseja unir: \n");
    n2 = menu_selecao(); 
    if(n2 == -1) return -1;

    for (i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            if ((v+n1-1)->num[i] == uni.num[j]) break;
        }
        if(j == 10) {
            if(c == 9) {
                printf("Não é possível realizar a operação, o conjunto resultante possui cardinalidade maior que 10\n");
                return 0;
            }
            uni.num[c] = (v+n1-1)->num[i];
            c++;
            uni.card++;
        }
    }

    for (i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            if ((v+n2-1)->num[i] == uni.num[j]) break;
        }
        if(j == 10) {
            if(c == 9) {
                printf("Não é possível realizar a operação, o conjunto resultante possui cardinalidade maior que 10\n");
                return 0;
            }
            uni.num[c] = (v+n2-1)->num[i];
            c++;
            uni.card++;
        }
    }
        
    printf("O conjunto união de %s e %s:\n",(v+n1-1)->nome, (v+n2-1)->nome);
    
    print_crescente(&uni);


    while(1) {
        printf("Deseja salvar o conjunto uniao? S ou N\n");
        scanf("%c%*c", &carac);
        if(carac == 'N' || carac == 'n') return 0;
        else if (carac == 'S' || carac == 's') {
            criar_conjunto();
            strcpy(uni.nome,(v+qtd-1)->nome);
            v[qtd-1] = uni;
            return 0;
        }
        else printf("Voce digitou errado, digite novamente!\n");
    }

    atualiza_conjunto(v+qtd-1);
    
}



/**
 * @brief 13. A interseccao de dois conjuntos. Retorne o conjunto interseccao, inclusive, quando este for
um conjunto vazio.
 * 
 */
int interseccao(){

    conj inter;
    esvazia_conjunto(&inter);

    int n1, n2, c, contador;
    int n = 0;
    char carac;
    
    printf("Digite o numero do primeiro conjunto que voce deseja checar a interseccao: \n");
    n1 = menu_selecao();
    if(n1 == -1) return -1;

    printf("Digite o numero do segundo conjunto que voce deseja checar a interseccao: \n");
    n2 = menu_selecao(); 
    if(n2 == -1) return -1;

    for(c=0;c<10;c++){
        for(contador=0;contador<10;contador++){
            if((v+n1-1)->num[c] == (v+n2-1)->num[contador]){
                inter.num[n] = (v+n1-1)->num[c];
                n++;
                inter.card++;
            }
        }
    }

    printf("O conjunto interseccao de %s e %s:\n",(v+n1-1)->nome, (v+n2-1)->nome);
    
    print_crescente(&inter);

    while(1) {
        printf("Deseja salvar o conjunto interseccao? S ou N\n");
        scanf("%c%*c", &carac);
        if(carac == 'N' || carac == 'n') return 0;
        else if (carac == 'S' || carac == 's') {
            criar_conjunto();
            strcpy(inter.nome,(v+qtd-1)->nome);
            v[qtd-1] = inter;
            return 0;
        }
        else printf("Voce digitou errado, digite novamente!\n");
    }

    atualiza_conjunto(v+qtd-1);
}


int conjunto_Ordem() {

    int n, i;
    

    printf("Digite o número do conjunto que você deseja mostrar, ou digite -1 para cancelar o processo:\n");
    n = menu_selecao();
    if (n == -1) return -1;

    while(1){
        printf("1. Ordem crescente\n");
        printf("2. Ordem decrescente\n");
        scanf("%d%*c", &i);
        if (i != 1 && i != 2) printf("Dígito Inválido\n");
        else break;
    }

    if(i == 1) print_crescente(v+n-1);
    if(i == 2) print_decrescente(v+n-1);
    
}

/**
 * @brief Funcao que copia do primeiro conjunto para o segundo(nao sendo necessario criar um novo conjunto)
 * 
 * @return se 0 a funcao rodou normal, -1 se o usuario desistiu 
 */
int copiar_conjunto(){

    int n1, n2;
    int i;


    printf("Digite o conjunto que voce deseja que seja copiado, ou -1 para cancelar o processo:\n");
    n1 = menu_selecao();
    if (n1 == -1) return -1;

    printf("Digite o conjunto que voce deseja que receba a cópia, ou -1 para cancelar o processo:\n");
    n2 = menu_selecao();
    if (n2 == -1) return -1;

    for(i=0;i<10;i++){
        (v+n2-1)->num[i] = (v+n1-1)->num[i]; 
    }
    
    return 0;
}





/**
 * @brief Destrói um conjunto desalocando seu espaço e verificando se a operação foi feita com sucesso.
 * 
 * @param a Endereço do conjunto a ser desalocado.
 * @return 0 se o conjunto foi destruído com sucesso, 1 se houve algum erro ou desistência no processo.
 */


int destruir_conjunto() {

    int i;
    int n;

    n = menu_selecao();
    if (n == -1) return -1;


    for (i = n; i < qtd; i++) {
        strcpy((v+i-1)->nome, (v+i)->nome);
        copia_vetor((v+i-1)->num, (v+i)->num);
        (v+i-1)->card = (v+i)->card;
    }

    v = realloc(v, sizeof(conj)*(qtd-1));
    qtd--;

    if ((!(v)) && (qtd != 0)) {
        printf("Falha ao destruir o conjunto\n");
        printf("Erro de desalocação\n");
        exit(1);
    }
    

    printf("Conjunto destruído com sucesso\n");
    return 0;
    
}

/**
 * @brief Função que ordena os termos do conjuntos em ordem crescente.
 *
 * @param a Endereço do conjunto a ser organizado.
 */
void atualiza_conjunto(conj * a){
    int c, c1;
    int aux;

    for(c=0; c<10; c++){
        if(a->num[c]==-1){
            for(c1=c+1; c1<10; c1++){
                if(a->num[c1]!=-1){
                    aux=a->num[c1];
                    a->num[c1]=a->num[c];
                    a->num[c]=aux;

                    break;
                }
            }      
        }
    }

    aux=-2;

    for(c=0; c<10; c++){
        if(a->num[c]==-1) break;

        for (c1=c; c1<10; c1++){
            if(a->num[c]>a->num[c1] && a->num[c1]!=-1){
                aux=a->num[c];
                a->num[c]=a->num[c1];
                a->num[c1]=aux;
            }
        }
    }

}

/**
 * @brief Printa o conjunto em ordem crescente, caso o conjunto seja vazio printa "conjunto vazio".
 * 
 * @param a Endereço do conjunto.
 */
void print_crescente(conj * a){
    int c;

    if(a->card==0){
        printf("Conjunto Vazio\n");
    } else {
        printf("{");
        for(c=0; c<10; c++){
            if(a->num[c]==-1) break;
            if(c!=0)printf(", ");
            printf("%ld", a->num[c]);
        }
        printf("}");
    }
    printf("\n");

}

/**
 * @brief Printa o conjunto em ordem crescente, caso o conjunto seja vazio printa "conjunto vazio".
 * 
 * @param a Endereço do conjunto.
 */
void print_decrescente(conj * a){
    int c;

    if(a->card==0){
        printf("Conjunto Vazio\n");
    } else {
        printf("{");
        for(c=9; c>=0; c--){
            if(a->num[c]==-1) continue;
            if(c!=(a->card)-1)printf(", ");
            printf("%ld", a->num[c]);
        }
        printf("}");
    }
    printf("\n");
}

void copia_vetor(ld *a, ld *b){
    int c;

    for(c=0;c<10;c++){
        a[c]=b[c];
    }
}