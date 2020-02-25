# Project: libmcx01
# Makefile created by FrancisX

#Executables of Compilation Dll
CPP      =   g++.exe
CC       =   gcc.exe
DLLWRAP  =   dllwrap.exe
#Sources and Inclusions to compilation
MAIN     =   DllFunctions.cpp
OBJ      =   DllFunctions.o
LIBS     =  -L"C:/Dev-Cpp/lib" --no-export-all-symbols --add-stdcall-alias 
INCS     =  -I"C:/Dev-Cpp/include" 
CXXINCS  =  -I"C:/Dev-Cpp/lib/gcc/mingw32/3.4.2/include"  -I"C:/Dev-Cpp/include/c++/3.4.2/backward"  -I"C:/Dev-Cpp/include/c++/3.4.2/mingw32"  -I"C:/Dev-Cpp/include/c++/3.4.2"  -I"C:/Dev-Cpp/include" 
CXXFLAGS =   $(CXXINCS) -DBUILDING_DLL=1 
CFLAGS   =   $(INCS) -DBUILDING_DLL=1 
#Output Dlls and Static Libraries Files
BIN      =   libmcx01.dll
RM       =   rm -f
DEFFILE   = $(BIN).def
STATICLIB = $(BIN).a

#Initial Call
.PHONY : all all-before all-after clean clean-custom
all : all-before $(BIN) all-after
#Rotines sequencies execution
clean : clean-custom
	${RM} $(OBJ) $(BIN)

#Rotine that Compile C++ Source-code to Object-Code
$(OBJ) : $(MAIN)
	$(CPP) -c $(MAIN) -o $(OBJ) $(CXXFLAGS)
#Rotine that Compile Object-Code to Libraries Files (.def, .a, .dll)
$(BIN) : $(OBJ)
	$(DLLWRAP) --output-def $(DEFFILE) --driver-name c++ --implib $(STATICLIB) $(OBJ) $(LIBS) -o $(BIN)
