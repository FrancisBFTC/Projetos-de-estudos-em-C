#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "DllImport.h"



int main(){
	
    if(INCLUDED){
			int fator = Fatorial();
			printf("valor global do fatorial : %d\n", GetGlobalInt());
            Contador("Wenderson", Adds(GetGlobalInt(), 10));
			printf("valor global do Contador : %d\n", GetGlobalInt());
			printf("valor global Char* : %s\n", GetGlobalStr());
            CloseDll();
    }
    getch();
    return 0;
}
