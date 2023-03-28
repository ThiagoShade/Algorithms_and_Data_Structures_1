#include "casa.h"

void print_extenso(char *s){
    if (s[0] == '1' && s[1] == '0' && s[2] != '\0' && s[2] == '0') printf("CEM");
    else if(s[1] == '\0'){
        if(s[0] == '0') printf("ZERO");
        else if(s[0] == '1') printf("UM");
        else if(s[0] == '2') printf("DOIS");
        else if(s[0] == '3') printf("TRES");
        else if(s[0] == '4') printf("QUATRO");
        else if(s[0] == '5') printf("CINCO");
        else if(s[0] == '6') printf("SEIS");
        else if(s[0] == '7') printf("SETE");
        else if(s[0] == '8') printf("OITO");
        else if(s[0] == '9') printf("NOVE");
    }
    else if(s[0] == '1' && s[1] != '\0'){
        if(s[1] == '0') printf("DEZ");
        else if(s[1] == '1') printf("ONZE");
        else if(s[1] == '2') printf("DOZE");
        else if(s[1] == '3') printf("TREZE");
        else if(s[1] == '4') printf("QUATORZE");
        else if(s[1] == '5') printf("QUINZE");
        else if(s[1] == '6') printf("DEZESSEIS");
        else if(s[1] == '7') printf("DEZESSETE");
        else if(s[1] == '8') printf("DEZOITO");
        else if(s[1] == '9') printf("DEZENOVE");
    }

    else if(s[0] != '1' && s[1] != '\0'){
        if(s[0] == '2') printf("VINTE"); 
        else if(s[0] == '3') printf("TRINTA"); 
        else if(s[0] == '4') printf("QUARENTA");
        else if(s[0] == '5') printf("CINQUENTA");
        else if(s[0] == '6') printf("SESSENTA"); 
        else if(s[0] == '7') printf("SETENTA");
        else if(s[0] == '8') printf("OITENTA");
        else if(s[0] == '9') printf("NOVENTA");

        if(s[1] == '0') return;
        else if(s[1] == '1') printf(" E UM");
        else if(s[1] == '2') printf(" E DOIS");
        else if(s[1] == '3') printf(" E TRES");
        else if(s[1] == '4') printf(" E QUATRO");
        else if(s[1] == '5') printf(" E CINCO");
        else if(s[1] == '6') printf(" E SEIS");
        else if(s[1] == '7') printf(" E SETE");
        else if(s[1] == '8') printf(" E OITO");
        else if(s[1] == '9') printf(" E NOVE"); 
    }
    
}
