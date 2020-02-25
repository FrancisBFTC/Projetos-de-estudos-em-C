#include <windows.h>
#include <sstream>
#include <iostream>
#include "main.h"

HINSTANCE instanciaPrincipal, instancia1, instancia2, instancia3;
WNDCLASSEX classe;
int i = 0;

void LoadFile(HWND editor, LPSTR nameFile){
	HANDLE open;
	open = CreateFile(nameFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, 0);
	if(open != INVALID_HANDLE_VALUE){
		DWORD sizeFile = GetFileSize(open, NULL);
		if(sizeFile != 0xFFFFFFFF){
			LPSTR textFile = (LPSTR) GlobalAlloc(GPTR, sizeFile + 1);
			if(textFile != NULL){
				DWORD read;
				ReadFile(open, textFile, sizeFile, &read, NULL);
			}
			GlobalFree(textFile);
		}
	}
	CloseHandle(open);
}

void SaveFile(HWND editor, LPSTR nameFile){
	HANDLE save;
	save = CreateFile(nameFile, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0, 0);
	if(save != INVALID_HANDLE_VALUE){
		DWORD textSize = GetWindowTextLength(editor);
		if(textSize > 0){
			LPSTR textEditor = (LPSTR) GlobalAlloc(GPTR, textSize + 1);
			if(textEditor != NULL){
				GetWindowText(editor, textEditor, textSize + 1);
				DWORD write;
				WriteFile(open, textEditor, textSize, &write, NULL);
			}
			GlobalFree(textEditor);
		}
	}
	CloseHandle(save);
}

void OpenFile(HWND editor, bool action){
	OPENFILENAME ofn;
	char fileName[MAX_PATH];
	ZeroMemory(&ofn, sizeof(ofn));
	fileName[0] = 0;
	
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = editor;
	ofn.lpstrFile = fileName;
	ofn.lpstrFilter = "Filtro do arquivo (*.fil)\0*.fil\0\0";
	ofn.lpstrDefExt = "fil";
	ofn.nMaxFile = MAX_PATH;
	
	if(action){
		ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
		GetOpenFileName(&ofn);
		LoadFile(GetDlgItem(editor, EDITOR1), fileName);
	}else{
		ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
		GetSaveFileName(&ofn);
		SaveFile(GetDlgItem(editor, EDITOR1), fileName);
	}
}

/* Procedimento da janela principal e suas funções */
LRESULT CALLBACK Interface1(HWND window, UINT response, WPARAM acao1, LPARAM acao2){
	switch(response){
		case WM_CREATE:
		break;
		case WM_COMMAND:
			switch(acao1){
				case CONFIGPAGE:
					window = CreateWindowEx(0, "ConfigPage", "Configuracao de pagina", WS_OVERLAPPEDWINDOW,
					CW_USEDEFAULT, CW_USEDEFAULT, 400, 200, HWND_DESKTOP, NULL, instancia1, NULL);
					
					ShowWindow(window, 1);
				break;
				case IMPRIMIR:
					window = CreateWindowEx(0, "Print", "Imprimir", WS_OVERLAPPEDWINDOW, 
					CW_USEDEFAULT, CW_USEDEFAULT, 400, 200, HWND_DESKTOP, NULL, instancia2, NULL);
					
					ShowWindow(window, 1);
				break;
				case EDITOR:
				    window = CreateWindowEx(0, "Editor", "Editor de Texto", WS_OVERLAPPEDWINDOW,
					300, 100, 600, 400, HWND_DESKTOP, NULL, instancia3, NULL);
							 
				    ShowWindow(window, 1);
				break;
				case SAIR:
					PostQuitMessage(0);
				break;
			}
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
		default:
			DefWindowProc(window, response, acao1, acao2);
	}
}

/* Procedimento da janela de configuração de página e suas funções */
LRESULT CALLBACK Interface2(HWND window, UINT response, WPARAM acao1, LPARAM acao2){
	HWND textBox1, textBox2, textBox3, textBox4;
	HWND labelx, labely, labelw, labelh;
	switch(response){
		case WM_CREATE:
			CreateWindow(TEXT("BUTTON"), TEXT("Layout"), WS_VISIBLE | WS_CHILD | WS_BORDER,
			             10, 10, 100, 20, window, (HMENU) BUTTON1, NULL, NULL);
						 
			CreateWindow(TEXT("BUTTON"), TEXT("Size"), WS_VISIBLE | WS_CHILD | WS_BORDER,
			             10, 35, 100, 20, window, (HMENU) BUTTON2, NULL, NULL);
						 
			CreateWindow(TEXT("BUTTON"), TEXT("Lines"), WS_VISIBLE | WS_CHILD | WS_BORDER,
			             10, 60, 100, 20, window, (HMENU) BUTTON3, NULL, NULL);
						 
			CreateWindow(TEXT("BUTTON"), TEXT("Dimension"), WS_VISIBLE | WS_CHILD | WS_BORDER,
						 10, 85, 100, 20, window, (HMENU) BUTTON4, NULL, NULL);
						 
			labelx = CreateWindow(TEXT("static"), TEXT("X : "), WS_VISIBLE | WS_CHILD | WS_TABSTOP,
						 150, 10, 50, 20, window, (HMENU) LABEL1, NULL, NULL);
						 
			labely = CreateWindow(TEXT("static"), TEXT("Y : "), WS_VISIBLE | WS_CHILD | WS_TABSTOP,
						 150, 35, 50, 20, window, (HMENU) LABEL2, NULL, NULL);
						 
			textBox1 = CreateWindow(TEXT("edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER,
						 190, 10, 50, 20, window, (HMENU) TEXT1, NULL, NULL);
				
			textBox2 = CreateWindow(TEXT("edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER,
						 190, 35, 50, 20, window, (HMENU) TEXT2, NULL, NULL);
			
			labelw = CreateWindow(TEXT("static"), TEXT("W : "), WS_VISIBLE | WS_CHILD | WS_TABSTOP,
								  260, 10, 50, 20, window, (HMENU) LABEL3, NULL, NULL);
								  
			labely = CreateWindow(TEXT("static"), TEXT("H : "), WS_VISIBLE | WS_CHILD | WS_TABSTOP,
								  260, 35, 50, 20, window, (HMENU) LABEL4, NULL, NULL);
								  
			textBox3 = CreateWindow(TEXT("edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER,
								  300, 10, 50, 20, window, (HMENU) TEXT3, NULL, NULL);
								  
			textBox4 = CreateWindow(TEXT("edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER,
								  300, 35, 50, 20, window, (HMENU) TEXT4, NULL, NULL);
								  
	
			UpdateWindow(window);
		break;
		case WM_COMMAND:
		break;
		case WM_DESTROY:
			
		break;
		default:
			DefWindowProc(window, response, acao1, acao2);
	}
}

/* Procedimento da janela de impressão e suas funções  */
LRESULT CALLBACK Interface3(HWND window, UINT response, WPARAM acao1, LPARAM acao2){
	switch(response){
		case WM_CREATE:
		break;
		case WM_COMMAND:
		break;
		case WM_DESTROY:
		break;
		default:
			DefWindowProc(window, response, acao1, acao2);
	}
}

/* Procedimento da janela do editor de texto e suas funções  */
LRESULT CALLBACK Interface4(HWND window, UINT response, WPARAM acao1, LPARAM acao2){
	switch(response){
		case WM_CREATE:
			CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL 
			            | ES_MULTILINE | ES_READONLY, CW_USEDEFAULT, CW_USEDEFAULT,
						CW_USEDEFAULT, CW_USEDEFAULT, window, (HMENU) EDITOR1, instancia3, NULL);
		break;
		case WM_SIZE:
            if(acao1 != SIZE_MINIMIZED){
                 MoveWindow(GetDlgItem(window, EDITOR1), 0, 0, LOWORD(acao2), HIWORD(acao2), true);
            } 
        break;
		case WM_COMMAND:
			switch(acao1){
				case NOVO:
					SetDlgItemTextA(window, EDITOR1, "Novo arquivo");
				break;
			}
		break;
		case WM_DESTROY:
		break;
		default:
			DefWindowProc(window, response, acao1, acao2);
	}
}

/* 
*   Carregador de classes de janelas onde toda classe de janela
*   Será carregada por esta função
*	@return Retorno booleano, caso a classe não é registrada, o retorno e falso!
*/
bool LoadClass(char *ClassName, char *MenuName, HINSTANCE instance, int win){
	classe.lpszClassName = ClassName;
	classe.lpszMenuName = MenuName;
	classe.hInstance = instance;
	switch(win){
		case 1: classe.lpfnWndProc = Interface1; break;
		case 2: classe.lpfnWndProc = Interface2; break;
		case 3: classe.lpfnWndProc = Interface3; break;
		case 4: classe.lpfnWndProc = Interface4; break;
	}
	classe.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	classe.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	classe.hCursor = LoadCursor(NULL, IDC_ARROW);
	classe.style = CS_DBLCLKS;
	classe.cbSize = sizeof(WNDCLASSEX);
	classe.cbClsExtra = 0;
	classe.cbWndExtra = 0;
	classe.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
	
	if(!RegisterClassEx(&classe))
		return false;
	
	return true;
}

/* 
*  Metódo main que carrega a classe principal da primeira janela
*  e se carregada, carrega as classes de todas as outras janelas
*  e constrói a janela principal, método de tipo WINAPI;
*  @return o retorno é 0 em response.wParam caso o usuário opte por sair do programa
 */
int WINAPI WinMain(HINSTANCE eInstancia, HINSTANCE instancia2, LPSTR argumento, int cmd){
	HWND window;
	MSG response;
	instanciaPrincipal = eInstancia;
	bool MyClass = LoadClass("WinApp1", "MeuMenu", instanciaPrincipal, 1);
	
	if(MyClass){
		LoadClass("ConfigPage", NULL, instancia1, 2);
		LoadClass("Print", NULL, instancia2, 3);
		LoadClass("Editor", "EditorMenu", instancia3, 4);
		window = CreateWindowEx(0, "WinApp1", "Minha Primeira Janela", WS_OVERLAPPEDWINDOW, 100, 100, 500, 400, 
								HWND_DESKTOP, NULL, instanciaPrincipal, NULL);
								
		ShowWindow(window, cmd);
		while(GetMessage(&response, NULL, 0, 0)){
			TranslateMessage(&response);
			DispatchMessage(&response);
		}
		return response.wParam;
	}
}
