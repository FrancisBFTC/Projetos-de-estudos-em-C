/* Replace "dll.h" with the name of your header */
#include "dll.h"

DllFunction void HelloWorld(){
       printf("Ola mundo\n");     
}

DllFunction void showTill(int j){
        for(int i = 0; i <= j; i++){
              printf("%d\n", i);        
        }    
        printf("Executando outra funcao!\n");        
}

DllFunction void input(char *value, int j){
       for(int i = 0; i < j; i++){
             printf("Valor repetido : %s\n", value);
       }     
}
