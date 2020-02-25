#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <sstream>
#include <iostream>

using namespace std;

/*
*	Função que gera a lib/Sintax do MicroC para 
*   inclusão somente durante a compilação
*/
void GenerateSintax(char *fileLang){
	stringstream sintax;
	sintax << "#ifndef _MICROC_LIB_" << endl;
	sintax << "#define _MICROC_LIB_" << endl; 
	sintax << "#pragma once" << endl;
	sintax << "#include <stdlib.h>" << endl;
	sintax << "#include <string.h>" << endl;
	sintax << "#include <stdio.h>" << endl;
	sintax << "#include <conio.h>" << endl;
	sintax << "#include <stdbool.h>" << endl;
	sintax << "#include <sstream>" << endl;
	sintax << "#include <iostream>" << endl;
	sintax << "#include <windows.h>" << endl << endl;

	sintax << "#ifdef _USE_LIB_" << endl << endl;
	sintax << "#define win(TYP) (WINAPI *TYP)" << endl;
	sintax << "#define retVoid(TYPE) typedef void win(TYPE)" << endl;
	sintax << "#define retInt(TYPE) typedef int win(TYPE)" << endl;
	sintax << "#define retIntp(TYPE) typedef int* win(TYPE)" << endl;
	sintax << "#define retChar(TYPE) typedef char win(TYPE)" << endl;
	sintax << "#define retCharp(TYPE) typedef char* win(TYPE)" << endl;
	sintax << "#define retFloat(TYPE) typedef float win(TYPE)" << endl;
	sintax << "#define retFloatp(TYPE) typedef float* win(TYPE)" << endl;
	sintax << "#define retStr(TYPE) typedef string win(TYPE)" << endl;
	sintax << "#define retBool(TYPE) typedef bool win(TYPE)" << endl;
	sintax << "#define GetDllFunc(Id, Type, nameFunc, dll, func) HINSTANCE Id = LoadLibrary(dll);Type nameFunc = (Type) GetProcAddress((HMODULE)Id, func)" << endl;
	sintax << "#define GetDllVar(Id, Type, nameFunc, dll, func) HINSTANCE Id = LoadLibrary(dll);Type nameFunc = (Type) GetProcAddress((HMODULE)Id, func) " << endl << endl;

	sintax << "#define program(_MC_) int main(_MC_){" << endl;
	sintax << "#define endprog return 0;}" << endl;
	sintax << "#define uselib _USE_LIB_" << endl;
	
	sintax << "uselib std;" << endl;
	sintax << "#define show(_MC_) (cout << _MC_)" << endl;
	sintax << "#define showl(_MC_) (cout << _MC_ << endl)" << endl;
	sintax << "#define input(_MC_) getline(cin, _MC_)" << endl;
	sintax << "#define scan(_MC_) scanf(" << '"' << "%d"<< '"' << ", &_MC_)" << endl;
	sintax << "#define pause (getch())" << endl;
	sintax << "#define stop break" << endl << endl;

	sintax << "#define begin {" << endl;
	sintax << "#define islt(m,c) if(m < c) begin" << endl;
	sintax << "#define isgt(m,c) if(m > c) begin" << endl;
	sintax << "#define iscmp(m,c) if(m == c) begin" << endl;
	sintax << "#define isdif(m,c) if(m != c) begin" << endl;
	sintax << "#define is(_MC_) if(_MC_) begin" << endl;
	sintax << "#define isn(_MC_) if(!_MC_) begin" << endl;
	sintax << "#define iscont(_M_, _C_) if(cont(_M_, _C_)) begin" << endl;
	sintax << "#define isncont(_M_, _C_) if(!cont(_M_, _C_)) begin" << endl;
	sintax << "#define isequal(_M_, _C_) if(_M_ == _C_) {" << endl;
	sintax << "#define isnequal(_M_, _C_) if(!(_M_ == _C_)) begin" << endl;
	sintax << "#define select(_MC_) switch(_MC_){" << endl;
	sintax << "#define endis }" << endl;
	sintax << "#define endsel endis" << endl;
	sintax << "#define isnot endis else begin" << endl;
	sintax << "#define endlt endis" << endl;
	sintax << "#define endgt endis" << endl;
	sintax << "#define enddif endis" << endl;
	sintax << "#define endcmp endis" << endl;
	sintax << "#define endcont endis" << endl;
	sintax << "#define endequal endis" << endl;
	sintax << "#define endfunc endis" << endl;
	sintax << "#define $(_MC_) _MC_.str()" << endl;
	sintax << "#define loop(_MC_) while(_MC_) begin" << endl;
	sintax << "#define endloop endis" << endl;
	sintax << "#define rep(_MC_) for(_MC_) begin" << endl;
	sintax << "#define endrep endis" << endl;
	sintax << "#define repeat do begin" << endl;
	sintax << "#define till(_MC_) endis while(_MC_)" << endl;
	sintax << "#define receive return" << endl << endl;

	sintax << "#define noth void" << endl;
	sintax << "#define num int" << endl;
	sintax << "#define word string" << endl;
	sintax << "#define text stringstream" << endl;
	sintax << "#define npointer int*" << endl;
	sintax << "#define wpointer char*" << endl;
	sintax << "#define doub float" << endl;
	sintax << "#define logic bool" << endl << endl;

	sintax << "logic File(word, word, word);" << endl;
	sintax << "word returnWord(wpointer);" << endl;
	sintax << "logic cont(word, word);" << endl << endl;
	
	sintax << "#define n(_MC_) !_MC_" << endl;
	sintax << "#define add(m,c) ((m)+(c))" << endl;
	sintax << "#define sub(m,c) ((m)-(c))" << endl;
	sintax << "#define mul(m,c) ((m)*(c))" << endl;
	sintax << "#define div(m,c) ((m)/(c))" << endl;
	sintax << "#define zrlt(_MC_) ((_MC_) < (0))" << endl;
	sintax << "#define zrgt(_MC_) ((_MC_) > (0))" << endl;
	sintax << "#define zrcp(_MC_) ((_MC_) == (0))" << endl;
	sintax << "#define zrdf(_MC_) ((_MC_) != (0))" << endl;
	sintax << "#define zr(_MC_) _MC_ = 0" << endl;
	sintax << "#define isdiv(_M_, _C_) (((_M_) % (_C_)) == 0)" << endl;
	sintax << "#define to =" << endl;
	sintax << "#define inc(_MC_) _MC_ ++" << endl;
	sintax << "#define dec(_MC_) _MC_ --" << endl << endl;
	
	sintax << "#define with <<" << endl;
	sintax << "#define withl << endl <<" << endl;
	sintax << "#define repl(_M_, _C_, _X_) _M_.replace(_M_.find(_C_), _C_.length(), _X_)" << endl;
	sintax << "#define toword(_MC_)       returnWord(_MC_)" << endl << endl;

	sintax << "#define DllFunc extern " << '"' << "C" << '"' << " __declspec(dllexport)" << endl;
	sintax << "#define in_char(_MC_) 		retChar(_MC_)" << endl;
	sintax << "#define in_num(_MC_) 		retInt(_MC_)" << endl;
	sintax << "#define in_noth(_MC_) 		retVoid(_MC_)" << endl;
	sintax << "#define in_logic(_MC_)  	retBool(_MC_)" << endl;
	sintax << "#define in_doub(_MC_)  		retFloat(_MC_)" << endl;
	sintax << "#define in_word(_MC_)  		refStr(_MC_)" << endl;
	sintax << "#define in_npointer(_MC_)  	retIntp(_MC_)" << endl;
	sintax << "#define in_wpointer(_MC_)  	retCharp(_MC_)" << endl;
	sintax << "#define in_dpointer(_MC_)  	retFloatp(_MC_)" << endl;
	sintax << "#define with_args (" << endl;
	sintax << "#define declare(Instance, Type, Function, DllFile, FuncDll) );GetDllFunc(Instance, Type, Function, DllFile, FuncDll)" << endl;
	sintax << "#define declare_var(Instance, Type, Function, DllFile, FuncDll) ;GetDllVar(Instance, Type, Function, DllFile, FuncDll)" << endl;
	sintax << "#define unload(_MC_)  		FreeLibrary(_MC_)" << endl;
	sintax << "#define cmd(_MC_) 	  		system(_MC_)" << endl << endl;

	sintax << "logic File(word file, word texts, word mode)" << endl;
	sintax << "begin" << endl;
	sintax << "char file1[file.length()];" << endl;
	sintax << "rep(num i to 0; i < file.length()+1; inc(i))" << endl;
	sintax << "file1[i] to file[i];" << endl;
	sintax << "endrep" << endl;
	sintax << "wpointer write to file1;" << endl;
	sintax << "char text1[texts.length()];" << endl;
	sintax << "rep(num i to 0; i < texts.length()+1; inc(i))" << endl;
	sintax << "text1[i] = texts[i];" << endl;
	sintax << "endrep" << endl;
	sintax << "wpointer text2 = text1;" << endl;
	sintax << "FILE* writer;" << endl;
	sintax << "isequal(mode, " << '"' << "write" << '"' << ")" << endl;
	sintax << "writer to fopen(write, " << '"' << "a" << '"' << ");" << endl;
	sintax << "iscmp(writer, NULL)" << endl;
	sintax << "receive false;" << endl;
	sintax << "endis" << endl;
	sintax << "endis" << endl;
	sintax << "iscmp(mode, " << '"' << "create" << '"' << ")" << endl;
	sintax << "writer to fopen(write, " << '"' << "w" << '"' << ");" << endl;
	sintax << "iscmp(writer, NULL)" << endl;
	sintax << "receive false;" << endl;
	sintax << "endis" << endl;
	sintax << "endis" << endl;
	sintax << "fprintf(writer, " << '"' << "%s" << '"' << ", text2);" << endl;
	sintax << "fclose(writer);" << endl;
	sintax << "receive true;" << endl;
	sintax << "endfunc" << endl << endl;

	sintax << "word returnWord(wpointer str)" << endl;
	sintax << "begin" << endl;
	sintax << "text data1;" << endl;
	sintax << "data1 with str;" << endl;
	sintax << "receive $(data1);" << endl;
	sintax << "endfunc" << endl << endl;

	sintax << "logic cont(word first, word second)" << endl;
	sintax << "begin" << endl;
	sintax << "zr(num pos);" << endl;
	sintax << "pos to first.find(second);" << endl;
	sintax << "iscmp(pos, -1)" << endl;
	sintax << "receive false;" << endl;
	sintax << "isnot" << endl;
	sintax << "receive true;" << endl;
	sintax << "endcmp" << endl;
	sintax << "endfunc" << endl << endl;
	
	sintax << "#endif" << endl;
	sintax << "#endif" << endl;
	
	FILE *generateFile;
	generateFile = fopen(fileLang, "w");
	
	string sintaxCode = sintax.str();
	char libTransfer[sintaxCode.length()];
        for(int i = 0; i < sintaxCode.length()+1; i++)
             libTransfer[i] = sintaxCode[i];
     
	char *dataCode = libTransfer;
	
	fprintf(generateFile, "%s", dataCode);
	fclose(generateFile);
}

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
