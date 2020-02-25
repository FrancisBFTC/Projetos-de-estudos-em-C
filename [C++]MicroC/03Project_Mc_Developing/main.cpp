#include "header.h"

int main(int argc, char *argv[ ]){
	if(cont(argv[1], ".mc")){
		bool verbose = false;
		bool constdll = false;
		bool extonly = false;
		char *dllfile = "";
		for(int i = 0; i < argc; i++){
			if(strcmp(argv[i], "-verbose") == 0){
				verbose = true;
			}else{
				if(strcmp(argv[i], "-constdll") == 0){
					if(argc > 3){
						if(strcmp(argv[i+1], ".dll") == 0){
							extonly = true;
							constdll = true;
						}else{
							if(cont(argv[i+1], ".dll")){
								constdll = true;
								dllfile = argv[i+1];
							}
						}
					}
				}
			}
		}
		string conversion = returnString(argv[1]).replace(
		returnString(argv[1]).find(".mc"), 3, ".cpp");
		
		string noExt = returnString(argv[1]).replace(
		returnString(argv[1]).find(".mc"), 3, "");
		
		char file[conversion.length()];
        for(int i = 0; i < conversion.length()+1; i++)
             file[i] = conversion[i];
     
	    char *arg = file; 
		
		string output = "";
		char *mcExec = "";
		char *sys = "";
		char *sys1 = "";
		char *rem = "";
		char *del1[4];
		string remove = "";
		string codeCompilation = "";
		string dllCompilation = "";
		
		if(!constdll){
			output = conversion.replace(
			conversion.find(".cpp"), 4, ".exe");
			
			char file1[output.length()];
			for(int i = 0; i < output.length()+1; i++)
				 file1[i] = output[i];
		 
			mcExec = file1; 
			stringstream comp;
			comp << "g++.exe " << arg << " -o " << mcExec;
			comp << " -g3 -I C:\\Dev-Cpp\\lib\\gcc\\mingw32\\3.4.2\\include ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2\\backward ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2\\mingw32 ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2 ";
			comp << "-I C:\\Dev-Cpp\\include\\mc ";
			comp << "-I C:\\Dev-Cpp\\include ";
			comp << "-L C:\\Dev-Cpp\\lib -g3";
			
			codeCompilation = comp.str();
			char compilation[codeCompilation.length()];
			for(int i = 0; i < codeCompilation.length()+1; i++)
				 compilation[i] = codeCompilation[i];
			
			sys = compilation;
			stringstream del;
			del << "del " << arg;
			string remove = del.str();
			char delFile[remove.length()];
			for(int i = 0; i < remove.length()+1; i++)
				 delFile[i] = remove[i];
			 
			rem = delFile;
			del.str("");
		}else{
			if(extonly){
				output = conversion.replace(
				conversion.find(".cpp"), 4, ".dll");
				
				char file1[output.length()];
				for(int i = 0; i < output.length()+1; i++)
					 file1[i] = output[i];
			 
				mcExec = file1; 
			}else{
				mcExec = dllfile;
			}
			stringstream comp;
			comp << "g++.exe -c " << arg << " -o " << noExt << ".o ";
			comp << "-I C:\\Dev-Cpp\\lib\\gcc\\mingw32\\3.4.2\\include ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2\\backward ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2\\mingw32 ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2 ";
			comp << "-I C:\\Dev-Cpp\\include\\mc ";
			comp << "-I C:\\Dev-Cpp\\include ";
			comp << "-DBUILDING_DLL=1";
			
			codeCompilation = comp.str();
			char compilation[codeCompilation.length()];
			for(int i = 0; i < codeCompilation.length()+1; i++)
				 compilation[i] = codeCompilation[i];
			
			sys = compilation;
			
			stringstream comp1;
			comp1 << "dllwrap.exe --output-def " << noExt << ".def ";
			comp1 << "--driver-name c++ --implib " << noExt << ".a ";
			comp1 << noExt << ".o -L C:\\Dev-Cpp\\lib --no-export-all-symbols ";
			comp1 << "--add-stdcall-alias  -o " << mcExec;
			
			dllCompilation = comp1.str();
			char compilation1[dllCompilation.length()];
			for(int i = 0; i < dllCompilation.length()+1; i++)
				 compilation1[i] = dllCompilation[i];
			
			sys1 = compilation1;
			
			stringstream del;
			for(int j = 0; j < 4; j++){
				switch(j){
					case 0: del << "del " << noExt << ".cpp"; break;
					case 1: del << "del " << noExt << ".o";   break;					
					case 2: del << "del " << noExt << ".def"; break;					
					case 3: del << "del " << noExt << ".a";   break;
				}
				
				remove = del.str();
				char delFile[remove.length()];
				for(int i = 0; i < remove.length()+1; i++)
					delFile[i] = remove[i];
				
				del1[j] = delFile;
				del.str("");
			}
			
		}
		
			if(verbose)
				cout << "verbose : converting extension of '" << argv[1] << "' to '" << arg << "';" << endl;
		
		      transpile(argv[1], arg);
		
			if(verbose)
				 cout << "verbose : compilating file '" << arg << "'" << endl;
		
		if(!constdll){
		     compilate(sys, rem);
		}else{
			compilate(sys, "null");
			execute(sys1);
			for(int i = 1; i < 4; i++){
				system(del1[i]);
			}
		}
			if(verbose){
				cout << "compilation : " << codeCompilation << endl;
				if(constdll)
					cout << "compilation : " << dllCompilation << endl;
				
				cout << "verbose : file '" << mcExec << "' was generate in compilation!" << endl;
			}
		
		if(!constdll)
		    execute(mcExec);
	
	    }

	return 0;
}
