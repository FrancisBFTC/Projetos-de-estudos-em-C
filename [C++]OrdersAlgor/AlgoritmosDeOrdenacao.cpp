#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

/* ==========================================
*           ALGORITMO DE ORDENA�AO
*             criado por Francis
*  ===========================================
*/ 
//Vari�veis de manipula�ao
int   q = 0;
char  v = 's';
char* Method = "";
bool  out = false, noExist = false;

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* ***** FUN�OES DE ORDENA��O ***** */
//Ordena��o por sele��o
void SelectOrder (int vet[], int tam){
    int i, j, min, x;
    for (i = 0; i < tam-1; i++){
        min = i;
        for (j = i+1; j < tam; j++){
            if (vet[j] < vet[min])
               min = j;
        }
        x = vet[min];
        vet[min] = vet[i];
        vet[i] = x;
    }
}

//Ordena��o por inser��o
void InsertOrder (int vet[], int tam){
    int i, j, x;
    for (i=1; i<=tam; i++){
        x = vet[i];
        j = i-1;
        vet[-1] = x; 
        while (x < vet[j]){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = x;
    }
}
/* ***** FIM DAS FUN�OES DE ORDENA��O ***** */
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

//Mostrar Dados do vetor
void showData(int vetor[], int tam){
     int i;
     for(i = 0; i < tam; i++){
          printf("(%d) ", vetor[i]);
     }
}

//Colocar Dados no vetor
void putData(int vetor[], int tam){
     int i;
      for(i = 0; i < tam; i++){
          printf("Digite o valor %d: ", i);
          scanf("%d", &vetor[i]);
      }     
}

//Escolha do algoritmo de ordena��o
void AlgorithmOrder(char* Alg, int vet[], int tam){
          if(Alg == "SELECAO")
                 SelectOrder(vet, tam);
          else
              if(Alg == "INSERCAO")
                     InsertOrder(vet, tam);
              else
                  printf("Este Metodo ainda nao existe no sistema!");
} 

//Informa��es de op��es na tela
void Options(){
    int quant;
    int Op;
    
    printf("Insira a quantidade de dados : ");
    scanf("%d", &quant);
    q = quant; 
    
    printf("Escolha o M�todo de Ordenacao: \n");
    printf("[1] - Selecao\n");
    printf("[2] - Insercao\n");
    printf("[3] - QuickSort\n");
    printf("[4] - MergeSort\n");
    printf("[5] - ShellSort\n");
    printf("[0] - Cancelar\n");
    scanf("%d", &Op);
    
    switch(Op){
         case 1: Method = "SELECAO";
                 break;
         case 2: Method = "INSERCAO";
                 break;
         case 3: Method = "QUICKSORT";
                 noExist = true;
                 break;
         case 4: Method = "MERGESORT";
                 noExist = true;
                 break;
         case 5: Method = "SHELLSORT";
                 noExist = true;
                 break;
         default: printf("\nVoce cancelou!\n");
                  out = true;
                  break;   
    }
    printf("\n------------------------------\n");
    printf("Metodo de %s", Method);
    printf("\n------------------------------\n");
    
}                   

//Metodo Principal que executa as fun��es
int main(void){
    system("title Algoritmos de Ordenacao");
    if(!out){
        while(v == 's'){
                Options();
                if(out) break;
                if(noExist){ 
                    printf("Este metodo ainda nao existe no Sistema!\n");         
                    break;
                }
                noExist = false;
                
                int vetor[q];
                putData(vetor, q);
                
                printf("\n NUMEROS DESORDENADOS: \n");
                showData(vetor, q);
                
                AlgorithmOrder(Method, vetor, q);
                printf("\n \n NUMEROS ORDENADOS: \n");
                showData(vetor, q);
                
                printf("\nDeseja continuar? (s/n)\n");
                v = getch();
                system("cls");
        }
    }
    printf("Saindo do Sistema...");
    while(!kbhit()){}
    return 0;
}
