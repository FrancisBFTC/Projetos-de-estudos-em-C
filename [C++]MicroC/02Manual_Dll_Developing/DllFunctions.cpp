/* Including Prototypes of the dlls functions */
#include "DllPrototypes.h"

int globalInt;
char globalChar;
char *globalStr;
float globalFloat;
bool globalBool;

DllFunction int GetGlobalInt(){
	return globalInt;
}
DllFunction char GetGlobalChar(){
	return globalChar;
}
DllFunction char* GetGlobalStr(){
	return globalStr;
}
DllFunction float GetGlobalFloat(){
	return globalFloat;
}
DllFunction bool GetGlobalBool(){
	return globalBool;
}
DllFunction void HelloWorld(){
       printf("Ola mundo\n"); 
}

DllFunction void Contador(char *value, int j){
       for(int i = 0; i < j; i++){
             printf("'%s' : %d\n", value, i);
       } 
	   printf("'%s' : %d\n", value, j);
	   printf("Contagem finalizada!\n");
	   globalStr = value;
	   globalInt = j;
}

DllFunction int Fatorial(){
	int j, i;
	printf("Digite um numero : ");
	scanf("%d", &i);
	int aux = i;
	for(j = i-1; j > 0; j--)
		i = i * j;

	printf("\nO fatorial de %d e = %d\n", aux, i);
	globalInt = i;
	return i;
}

DllFunction int Add(int i, int j){
	int x = (i+j);
	globalInt = x;
	return x;
}
