#include "exibicao.h"

void imprimeMat(int n, int m, int matriz[n][m]){

  for(int i = 0; i< n; i++){
      printf("    ");
      for(int j = 0; j < m; j ++){
        if(matriz[i][j]==1)
          printf("\033[1;97m\033[1;107m %d \033[0;0m", matriz[i][j]);
        else if (matriz[i][j]==2)
          printf("\033[1;34m\033[1;104m %d \033[0;0m", matriz[i][j]);
        else if(matriz[i][j]==0)
          printf("\033[1;32m\033[1;42m   \033[0;0m", matriz[i][j]);
        else if(matriz[i][j]==3)
          printf("\033[1;91m\033[1;41m   \033[0;0m");
        else if(matriz[i][j]==4)
          printf("\033[1;33m\033[1;43m   \033[0;0m", matriz[i][j]);
      }
      printf("\n");
  }


}

void menu(){

  printf("\n\n PROGRAMA Labirinto: Opçoes do programa:\n");
  printf(" [1] Carregar novo arquivo do drone\n");
  printf(" [2] Processar e exbir possível saída\n");
  printf(" [3] Desligar drone\n");
  printf(" [0] Limpar monitor\n\n");


}

void menuArq(char *arquivo){

  printf(" PROGRAMA Labirinto: Opçoes do programa:\n");
  printf(" [1] Carregar novo arquivo do drone\n");
  printf(" [2] Processar e exbir possível saída\n");
  printf(" [3] Desligar drone\n");
  printf(" [0] Limpar monitor\n");
  printf(" Arquivo inserido: \"%s\"\n\n",arquivo);

}
