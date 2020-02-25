#ifndef _DLLIMPORT_H_
#define _DLLIMPORT_H_
#include "DllMacros.h"

#include <windows.h>
#include <stdlib.h>

HINSTANCE hlib;
void CloseDll() { FreeLibrary(hlib); }
bool call(bool inc){ return inc; }

#ifdef _DLLMACROS_H_

#define INCLUDED 1
#define MSG "Executando dlls!"
char* DLLFILE1 = "libmcx01.dll";
/* Chame uma função Dll aqui */
retInt(GLOBAL1)(void);
GetDll(GLOBAL1, glob1, GetGlobalInt, DLLFILE1, "GetGlobalInt");
retChar(GLOBAL2)(void);
GetDll(GLOBAL2, glob2, GetGlobalChar, DLLFILE1, "GetGlobalChar");
retCharp(GLOBAL3)(void);
GetDll(GLOBAL3, glob3, GetGlobalStr, DLLFILE1, "GetGlobalStr");
retFloat(GLOBAL4)(void);
GetDll(GLOBAL4, glob4, GetGlobalFloat, DLLFILE1, "GetGlobalFloat");
retBool(GLOBAL5)(void);
GetDll(GLOBAL5, glob5, GetGlobalBool, DLLFILE1, "GetGlobalBool");

retVoid(FUNC1)(void); 
GetDll(FUNC1, func1, HelloWorld, DLLFILE1, "HelloWorld");

retVoid(FUNC2)(char*, int);
GetDll(FUNC2, func2, Contador, DLLFILE1, "Contador");

retInt(FUNC3)(void); 
GetDll(FUNC3, func3, Fatorial, DLLFILE1, "Fatorial");

retInt(FUNC4)(int, int);
GetDll(FUNC4, func4, Adds, DLLFILE1, "Adds");

#else
	
#define INCLUDED 0
#define MSG "A biblioteca dllimp.h nao esta incluida!"

/* Declare a função Dll aqui em caso de erros */

#endif

#endif
