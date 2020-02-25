#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <sstream>
#include <iostream>

using namespace std;

//função que converte char* para string
string returnString(char *str){
	stringstream data1;
	data1 << str;
	return data1.str();
}

//Função pra verificar se contem caracteres
bool cont(char* first, string second)
{
	 int pos = 0;
     pos = returnString(first).find(second);
	 
     if(pos == -1)
         return false;
     else
         return true;    
          
}

/*
* Função pra criar um arquivo .cpp a partir
* do arquivo .mc (microC)
*/
void transpile(char *read, char *write){
	FILE *readFile;
	char ch;
	stringstream concat;
	
	readFile = fopen(read, "r");
	if(readFile != NULL){
		while((ch = fgetc(readFile)) != -1){
			concat << ch;
			
		}
	}
	string code = concat.str();
	char datas[code.length()];
        for(int i = 0; i < code.length()+1; i++)
             datas[i] = code[i];
     
	char *dataWrite = datas;
	FILE *writeFile0, *writeFile;
	writeFile0 = fopen(write, "w");
	writeFile = fopen(write, "a");
	
	fprintf(writeFile, "%s", dataWrite);
	
	concat.str("");
	fclose(readFile);
	fclose(writeFile0);
	fclose(writeFile);
}

/* 
*  Função que recebe como parâmetro o código
*  de compilação e o executa
*/
void compilate(char *code, char *del){
	system(code);
	if(strcmp(del, "null") != 0)
		system(del);
}

/* 
*  Função que recebe como parâmetro 
*  o aplicativo .exe e o executa
*/
void execute(char *code){
	system(code);
}
