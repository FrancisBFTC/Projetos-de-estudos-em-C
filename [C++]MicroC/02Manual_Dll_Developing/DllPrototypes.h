#ifndef _DLLPROTOTYPES_H_
#define _DLLPROTOTYPES_H_
#include <stdio.h>
#include <stdlib.h>
#define DllFunction extern "C" __declspec(dllexport)
         
DllFunction void HelloWorld(); 
DllFunction void Contador(char*, int);
DllFunction int Fatorial();
DllFunction int Add(int, int); 
DllFunction char GetGlobalChar();
DllFunction char* GetGlobalString();
DllFunction float GetGlobalFloat();
DllFunction int GetGlobalInt();
DllFunction bool GetGlobalBool();    
#endif /* _DLL_H_ */
