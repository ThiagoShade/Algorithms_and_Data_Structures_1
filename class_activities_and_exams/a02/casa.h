#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Instru Instru;
typedef struct head head; 

struct Instru {
    char dir;
    char rua[10];
    Instru * prox;
};

struct head{
    Instru *inicio;
};

/**
 * @brief Funcao que le e forma pilha com as instruçoẽs
 * 
 * @param h Head da pilha
 */
void forma_Instru(head * h);

/**
 * @brief Funcao que coloca uma instrucao na pilha
 * 
 * @param h Head da pilha
 * @param dir direção da instrução
 * @param rua rua da instrução
*/
void coloca_Instru(head * h, char dir, char *rua);

/**
 * @brief Printa as intrucoes ao contrario, no caminho natural da pilha, ou seja o caminho da volta
 * 
 * @param h Head da pilha
 */
void print_Instru_rev(head * h);

/**
 * @brief Função que recebe um char 'd' ou 'e', printa ESQUERDA caso seja 'd' e DIREITA caso seja 'e'. Ou seja, a direção contrária.
 * 
 * @param dir char 'd' ou 'e'
 */
void print_dir_rev(char dir);

/**
 * @brief Printa o nome da rua da próxima instrução.
 * 
 * @param i endereço da instrução
 */
void print_rua_prox(Instru * i);

/**
 * @brief Libera a memoria alocada com a instrucoes
 * 
 * @param h Head da pilha
 */
void limpa_Instru(head * h);

/**
 * @brief Funcao que le um numero inteiro e escreve ele por extenso
 * 
 * @param d Numero inteiro
 * @param s Numero por extenso
 */
void print_extenso(char *s);
