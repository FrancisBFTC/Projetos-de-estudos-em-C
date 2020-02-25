#ifndef _DLL_H_
#define _DLL_H_
#include <stdio.h>
#define DllFunction extern "C" __declspec(dllexport)
         
         DllFunction void HelloWorld();  
         DllFunction void showTill(int);
         DllFunction void input(char*, int);      
#endif /* _DLL_H_ */
