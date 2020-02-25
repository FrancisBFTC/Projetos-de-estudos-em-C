#ifndef _DLLMACROS_H_
#define _DLLMACROS_H_

#include <stdio.h>
#define win(TYP) (WINAPI *TYP)
#define retVoid(TYPE) typedef void win(TYPE)
#define retInt(TYPE) typedef int win(TYPE)
#define retIntp(TYPE) typedef int* win(TYPE)
#define retChar(TYPE) typedef char win(TYPE)
#define retCharp(TYPE) typedef char* win(TYPE)
#define retFloat(TYPE) typedef float win(TYPE)
#define retFloatp(TYPE) typedef float* win(TYPE)
#define retStr(TYPE) typedef String win(TYPE)
#define retBool(TYPE) typedef bool win(TYPE)
#define Function(TYPE, function) TYPE function(char *dll, char *func) { TYPE exec; hlib = LoadLibrary(dll);exec = (TYPE) GetProcAddress((HMODULE)hlib, func);return exec;}
#define GetDll(Type, Func, nameFunc, file, phr) Function(Type, Func) Type nameFunc = Func(file, phr)

#endif
