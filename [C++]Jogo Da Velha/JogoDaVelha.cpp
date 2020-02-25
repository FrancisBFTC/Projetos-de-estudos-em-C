#include <cstdlib>
#include <cstdio>
#include <stdbool.h>
#include <conio.h>
  
  
/* ========================================================
*    Nome   : JOGO DA VELHA
*    Autor  : Wenderson Francisco
*    Data   : 30/01/2019  
* =========================================================
*/
  
//Area de variáveis
/* ----------------------------------*/
    char jogo[3][3];
   // char jogadorX = false;
    char carac1[1], carac2[1];
    char jog1[20], jog2[20];
    bool velha1 = false;
/* ----------------------------------*/
 
//Método Principal
/* --------------------------------------------*/   
    int main(void){
        void comecar(void);
        void numeracao(void);
        void mostrar(void);
        void jogoAtual(void);
        void passarVez(void);
        
        system("title Jogo Da Velha");
        
        bool finalizar = false;
        char resp[1];
        
        comecar();
        do{
		   numeracao();
		   jogoAtual();
		   passarVez();
		   printf("\nDeseja finalizar ? (y/n) ");
		   scanf("%s", &resp);
		   if(resp[0] == 'y')
		        finalizar = true;
           else
                finalizar = false;
                
           system("CLS");
        }while(!finalizar);
		
		return 0;
	}
/* --------------------------------------------*/ 
	
//Função para preencher o jogo da velha
/* --------------------------------------------*/ 
	void numeracao(){
		char n = '1';
		for ( int i = 0; i < 3; i++ ) {
			for ( int j = 0; j < 3; j++ ) {
				jogo[i][j] = n;
				n++; 
			}
		}
	}
/* --------------------------------------------*/ 

//Função pra mostrar o jogo
/*--------------------------------------------*/
	 void mostrar(){
		for ( int i = 0; i < 3; i++ ) {
			printf("\n");
			for ( int j = 0; j < 3; j++ ) {
				printf("\t[%c]", jogo[i][j]);
			}
		}
	}
/*--------------------------------------------*/

//Função pra definir o jogador e a letra
/*--------------------------------------------------------------*/
	 void comecar(){
		bool comecar = false;
		do{
			printf("\n===================================\n");
			printf("\tJogo Da Velha\t\n");
			printf("===================================\n");
			printf("Primeiro jogador : ");
			scanf("%s", &jog1);
			printf("\nEscolha a letra [ X / O ]: ");
			scanf("%s", &carac1);
			printf("\nSegundo jogador : ");
			scanf("%s", &jog2);
			if(carac1[0] == 'X' || carac1[0] == 'x'){
                      carac1[0] = 'X';
			          carac2[0] = 'O';
            }else{
                      carac1[0] = 'O';
                      carac2[0] = 'X';         
            }
			if((carac1[0] == 'X') || (carac1[0] == 'x') || (carac1[0] == 'O') || (carac1[0] == 'o')
                 && (carac2[0] == 'X') || (carac2[0] == 'x') || (carac2[0] == 'O') || (carac2[0] == 'o')){
			//	jogadorX = true;
				comecar = true;
			}else{
			
				//	jogadorX = false;
					comecar = false;
			        printf("\nAlguem colocou a letra invalida!Tente novamente!\n");
				    system("PAUSE");
				
			}
		
          
		}while(!comecar);
		system("CLS");
	}
/*--------------------------------------------------------------*/

//Função pra mostrar o jogo atual e limpar tela
/*--------------------------------------------------------------*/
	 void jogoAtual(){
            system("CLS");
			printf("\n===================================\n");
			printf("\tJogo Da Velha\t\n");
			printf("===================================\n");
			mostrar();
	}
/*--------------------------------------------------------------*/

//Função pra verificar as marcações
/*----------------------------------------------------------------------------------*/
     bool verificar(char C){
          bool marcado = false;
          for(int l = 0; l < 3; l++){
               marcado = (jogo[l][0] == C) && (jogo[l][1] == C) && (jogo[l][2] == C);
               if(marcado)
                     return marcado;
          } 
          
          for(int c = 0; c < 3; c++){
               marcado = (jogo[0][c] == C) && (jogo[1][c] == C) && (jogo[2][c] == C);
               if(marcado)
                     return marcado;    
          }  
          
          marcado = (jogo[0][0] == C) && (jogo[1][1] == C) && (jogo[2][2] == C)
                 || (jogo[0][2] == C) && (jogo[1][1] == C) && (jogo[2][0] == C);
          
          return marcado;       
     }
/*----------------------------------------------------------------------------------*/
     
//Função dos jogadores
/*----------------------------------------------------------------------------------*/
     bool jogador(int j){
			bool terminar = false;
			char let;
           // let = (jogadorX) ? 'X' : 'O';
         
           
           let = (j == 1) ? carac1[0] : carac2[0];
           
			do{
                if(j == 1)
                    printf("\nJogador 1 - [%s] : ", jog1);
                else
                    printf("\nJogador 2 - [%s] : ", jog2);
				
				int numero;
				scanf("%d", &numero);
				if(numero > 0 && numero < 10){
					terminar = true;
					switch(numero){
						case 1: jogo[0][0] = let;
								jogoAtual();
								break;
						case 2:	jogo[0][1] = let;
								jogoAtual();
								break;
						case 3:	jogo[0][2] = let;
								jogoAtual();
								break;
						case 4:	jogo[1][0] = let;
								jogoAtual();
								break;
						case 5:	jogo[1][1] = let;
								jogoAtual();
								break;
						case 6:	jogo[1][2] = let;
								jogoAtual();
								break;
						case 7:	jogo[2][0] = let;
								jogoAtual();
								break;
						case 8:	jogo[2][1] = let;
								jogoAtual();
								break;
						case 9:	jogo[2][2] = let;
								jogoAtual();
								break;
					}
				}else{
					printf("\nOpcao invalida!Tente Novamente!\n");
					terminar = false;
				}
			}while(!terminar);
			
          return verificar(let);
			
	}
/*----------------------------------------------------------------------------------*/

//Função pra determinar a vez de cada jogador
//E verificar se deu velha
/*-------------------------------------------------------*/
	 void passarVez(){
		int n = 0;
		bool velha = true;
		for(int j = 0; j < 9; j++){
			if(n == 0){
                if(jogador(1)){
                    printf("\n%s ganhou!\n", jog1);
                    velha = false;
    				break;
                }
				
                    n = 1;
			}else{
				if(jogador(2))
                    printf("\n%s ganhou!\n", jog2);
                    velha = false;
                    break;
                }
                    
				    n = 0;
			}
			velha1 = velha;
			
			if(velha1)
		         printf("\nIIII... DEU VELHA!\n");
		}
	
/*-------------------------------------------------------*/


