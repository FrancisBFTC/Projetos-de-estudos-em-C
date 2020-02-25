# Test MakeFile
#Vars of Compilators, Sources and Inclusions
CPP  =   g++.exe
GCC  =   gcc.exe
INCL =  -g3 -I "C:/Dev-Cpp/lib/gcc/mingw32/3.4.2/include"
BACK =  -I "C:/Dev-Cpp/include/c++/3.4.2/backward"
MING =  -I "C:/Dev-Cpp/include/c++/3.4.2/mingw32"
VERS =  -I "C:/Dev-Cpp/include/c++/3.4.2"
LIB  =  -I "C:/Dev-Cpp/include" -L "C:/Dev-Cpp/lib" -g3
INC  =   $(INCL) $(BACK) $(MING) $(VERS) $(LIB)
MAIN = 	 execDll.cpp
BIN  = 	 Prog.exe
RM 	 =   rm -f
#Initial Calls
.PHONY: all all-before all-after clean clean-custom
all: all-before $(BIN) all-after
#Sequencies Rotines Execution
clean: clean-custom
	${RM} $(BIN)
#Rotine of compilation	   
$(BIN): $(MAIN)
	$(CPP) $(MAIN) -o $(BIN) $(INC)