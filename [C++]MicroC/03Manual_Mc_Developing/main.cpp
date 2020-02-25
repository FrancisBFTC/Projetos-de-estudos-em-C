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
		
		if(!constdll){
			output = conversion.replace(
			conversion.find(".cpp"), 4, ".exe");
			
			char file1[output.length()];
			for(int i = 0; i < output.length()+1; i++)
				 file1[i] = output[i];
		 
			char *mcExec = file1; 
			stringstream comp;
			comp << "g++.exe " << arg << " -o " << mcExec;
			comp << " -g3 -I C:\\Dev-Cpp\\lib\\gcc\\mingw32\\3.4.2\\include ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2\\backward ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2\\mingw32 ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2 ";
			comp << "-I C:\\Dev-Cpp\\include\\mc ";
			comp << "-I C:\\Dev-Cpp\\include ";
			comp << "-L C:\\Dev-Cpp\\lib -g3";
			
			string codeCompilation = comp.str();
			char compilation[codeCompilation.length()];
			for(int i = 0; i < codeCompilation.length()+1; i++)
				 compilation[i] = codeCompilation[i];
			
			char *sys = compilation;
			stringstream del;
			del << "del " << arg;
			string remove = del.str();
			char delFile[remove.length()];
			for(int i = 0; i < remove.length()+1; i++)
				 delFile[i] = remove[i];
			 
			char *rem = delFile;
			del.str("");
			
			if(verbose){
				cout << endl;
				cout << "*************************************************" << endl << endl;
				cout << "GENERATOR OF EXECUTABLE FILE WITH MICROC	 " << endl << endl;
				cout << "*************************************************" << endl << endl;
			}
			
			if(verbose)
				cout << "verbose : converting extension of '" << argv[1] << "' to '" << arg << "';" << endl;
			
			char *lang = "C:\\Dev-Cpp\\include\\mc0xlang.hmc";
			GenerateSintax(lang);
			transpile(argv[1], arg);
		
			if(verbose)
				cout << "verbose : compilating file '" << arg << "'" << endl;
			
			compilate(sys, rem);
			
			del << "del " << lang;
			remove = del.str();
			char delLang[remove.length()];
			for(int i = 0; i < remove.length()+1; i++)
				 delLang[i] = remove[i];
			 
			char *delLang1 = delLang;
			system(delLang1);
			del.str("");
			
			if(verbose){
				cout << "compilation : " << codeCompilation << endl;
				cout << "verbose : file '" << mcExec << "' was generate in compilation!" << endl;
			}
			
			execute(mcExec);
			
		}else{
			char *mcExec = "";
			string remove = "";
			if(extonly){
				output = conversion.replace(
				conversion.find(".cpp"), 4, ".dll");
				
			}
			stringstream comp;
			comp << "g++.exe -c " << arg << " -o " << noExt << ".o "; 
			comp << "-I C:\\Dev-Cpp\\lib\\gcc\\mingw32\\3.4.2\\include ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2\\backward ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2\\mingw32 ";
			comp << "-I C:\\Dev-Cpp\\include\\c++\\3.4.2 ";
			comp << "-I C:\\Dev-Cpp\\include\\mc ";
			comp << "-L C:\\Dev-Cpp\\include\\mc\\lib ";
			comp << "-I C:\\Dev-Cpp\\include ";
			comp << "-DBUILDING_DLL=1";
			
			string codeCompilation = comp.str();
			char compilation[codeCompilation.length()];
			for(int i = 0; i < codeCompilation.length()+1; i++)
				 compilation[i] = codeCompilation[i];
			
			char *sys = compilation;
			
			stringstream comp1;
			comp1 << "dllwrap.exe --quiet --output-def " << noExt << ".def ";
			comp1 << "--driver-name c++ --implib " << noExt << ".a ";
			comp1 << noExt << ".o -L C:\\Dev-Cpp\\lib --no-export-all-symbols ";
			if(extonly)
				comp1 << "--add-stdcall-alias  -o " << output;
			else
				comp1 << "--add-stdcall-alias  -o " << dllfile;
			
			string dllCompilation = comp1.str();
			char compilation1[dllCompilation.length()];
			for(int i = 0; i < dllCompilation.length()+1; i++)
				 compilation1[i] = dllCompilation[i];
			
			char *sys1 = compilation1;
			
			if(verbose){
				cout << endl;
				cout << "*************************************************" << endl << endl;
				cout << "GENERATOR OF DLL FILE WITH MICROC		" << endl << endl;
				cout << "*************************************************" << endl << endl;
			}
				
			
			if(verbose)
				cout << "verbose : converting extension of '" << argv[1] << "' to '" << arg << "';" << endl;
			
			char *lang1 = "C:\\Dev-Cpp\\include\\mc0xlang.hmc";
			GenerateSintax(lang1);
			transpile(argv[1], arg);
		
			if(verbose)
				cout << "verbose : compilating file '" << arg << "'" << endl;
			
			compilate(sys, "null");
			execute(sys1);
			
			stringstream del;
			for(int j = 0; j < 5; j++){
				switch(j){
					case 0: del << "del " << noExt << ".cpp"; break;
					case 1: del << "del " << noExt << ".o";   break;					
					case 2: del << "del " << noExt << ".def"; break;					
					case 3: del << "del " << noExt << ".a";   break;
					case 4: del << "del " << lang1; 		  break; 
				}
				
				string remove = del.str();
				char delFile[remove.length()];
				for(int i = 0; i < remove.length()+1; i++)
					delFile[i] = remove[i];
				
				char *del1 = delFile;
				system(del1);
				del.str("");
			}
			
			if(verbose){
				cout << "compilation : " << codeCompilation << endl;
				cout << "compilation : " << dllCompilation << endl;
				if(extonly)
					cout << "verbose : file '" << output << "' was generate in compilation!" << endl;
				else	
					cout << "verbose : file '" << dllfile << "' was generate in compilation!" << endl;
			}
			
		}
			
			
				
				
	
	}else{
		if(cont(argv[1], "--config-access")){
			system("ExtensionMicroC1.reg");
			system("ExtensionMicroC2.reg");
		}
	}

	return 0;
}
