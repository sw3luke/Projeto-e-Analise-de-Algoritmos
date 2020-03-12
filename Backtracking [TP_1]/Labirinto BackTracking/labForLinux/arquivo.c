#include "arquivo.h"


void programa(char *local, char *analise){
  int linhas, colunas;
  int posInicial = 0;
  int keys = 0;
  bool analisa = false;
  int **matriz = entradaArquivo(local,&linhas,&colunas,&keys,&posInicial);
  int matrizA[linhas][colunas];
  convertMatriz(matriz,linhas,colunas,matrizA);
  imprimeMat(linhas,colunas,matrizA);
  printf("\n\n");
  if(analise){
    if(strcmp(analise,"-a")==0){
      procuraSolucao(linhas,colunas,matrizA,posInicial,&keys,true);
      return;
    }
  }
  procuraSolucao(linhas,colunas,matrizA,posInicial,&keys,false);
}

void Error(){
  system("clear");
  printf(" Sem arquivo para processar, drone inoperante !\n");
  printf(" Pressione qualquer tecla para continuar...\n");
  fflush(stdin);
  getchar();
}
int** entradaArquivo(char *local,int *linhas, int *colunas, int *keys, int *posInicial){

  FILE *arquivo;
  arquivo = fopen(local, "r");

  if (arquivo == NULL)
  {
    printf("\n Não foi possível abrir o arquivo %s",local);
  }

  else
  {
    if(fscanf(arquivo,"%d %d %d\n",linhas,colunas,keys) != EOF){
      int **matriz = (int**) malloc(*linhas*sizeof(int*));
      char *vetor = (char*)malloc(*colunas*sizeof(char));
      int coluna = 0;
      while(fscanf(arquivo,"%s\n",vetor) != EOF){
        matriz[coluna] = (int*) malloc(*colunas*sizeof(int));
        for (int i=0;i<*colunas;i++){
          if (vetor[i]-'0'==0){
            *posInicial = i;
          }
          matriz[coluna][i] = vetor[i]-'0';
        }
        coluna++;
      }

      return matriz;
    }

  }
}


void convertMatriz(int **matrizPointer, int linhas, int colunas, int matriz[linhas][colunas]){

  for(int i = 0; i< linhas; i++){
      for(int j = 0; j < colunas; j ++){
          matriz[i][j] = matrizPointer[i][j];
      }
  }
}
