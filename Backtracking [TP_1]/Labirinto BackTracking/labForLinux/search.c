#include "search.h"




void imprimeSolucao(int N, int M,int solucao[N][M]){
  for(int i = 0; i< N; i++){
      printf("    ");
      for(int j = 0; j < M; j ++){
        if(solucao[i][j]==1)
          printf("\033[1;97m\033[1;107m %d \033[0;0m", solucao[i][j]);
        else if (solucao[i][j]==2)
          printf("\033[1;34m\033[1;104m   \033[0;0m");
        else if(solucao[i][j]==0)
          printf("\033[1;34m\033[1;104m   \033[0;0m");
        else if(solucao[i][j]==3)
          printf("\033[1;91m\033[1;41m   \033[0;0m");
        else if(solucao[i][j]==4)
          printf("\033[1;33m\033[1;43m   \033[0;0m", solucao[i][j]);
      }
      printf("\n");
  }
}


bool procuraSolucao(int N, int M,int maze[N][M],int posInicial, int *keys, bool analise)
{
    int solucao[N][M];
    int movimentos = 0;
    int nivelRecursao = 0;
    int aux = 0;
    int colunaFim = 0;
    int tRecursivo = -1;
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < M; j ++){
            solucao[i][j] = 0;
        }
    }
    if(analise){
      if (!A_movimentaEstudante(N,M,N-1,posInicial, solucao, maze, keys, &tRecursivo, &aux, &nivelRecursao,&movimentos,&colunaFim)) {
          printf(" Já percorrir cerca de uns %d metros, não consigo encontrar a saída !\n");
          printf(" Devia ter ficado em casa, jogando Megamania !\n");
          return false;
      }
      printf(" SOLUÇÃO DO LABIRINTO \n\n");
      imprimeSolucao(N,M,solucao);
      printf("\n Chamadas Recursivas %d",tRecursivo);
      printf("\n O maior nivel de recursão atingido foi de: %d\n\n", nivelRecursao);
      printf("\n Me movimentei uns %d metros para encontrar essa saída.",movimentos);
      printf("\n Uhn, estranho ! Está escrito, coluna %d.\n",colunaFim);
    }
    else{
      if (!movimentaEstudante(N,M,N-1,posInicial, solucao, maze, keys,&movimentos,&colunaFim)) {
          printf(" Já percorrir cerca de uns %d metros, não consigo encontrar a saída !\n");
          printf(" Devia ter ficado em casa, jogando Megamania !\n");
          return false;
    }
    printf(" SOLUÇÃO DO LABIRINTO \n\n");
    imprimeSolucao(N,M,solucao);
    printf("\n Me movimentei uns %d metros para encontrar essa saída.",movimentos);
    printf("\n Uhn, estranho ! Está escrito, coluna %d.\n",colunaFim);
   }
    return true;
}



bool checar(int N, int M, int x,int y,int lab[N][M],int *keys){
    if(x >= 0 && x < N && y >= 0 && y < M && lab[x][y] == 1){
        return true;
    }
    else if(lab[x][y] == 0){
        return true;
    }
    else if(x >= 0 && x < N && y >= 0 && y < M && lab[x][y] == 3){ //TIRAR UMA CHAVE DO USUARIO AO PASSAR POR UMA PORTA
        if (*keys>0){
            *keys = *keys -1;
            return true;
        }

        else{
            return false;
        }
    }
    else if(x >= 0 && x < N && y >= 0 && y < M && lab[x][y] == 4){ //ACRESCENTAR CHAVE AO USUARIO AO PASSAR EM UMA CELULA QUE CONTEM UMA CHAVE
        *keys = *keys + 1;
        return true;
    }
    else{
        return false;
    }
}


bool A_movimentaEstudante(int N, int M, int x,int y,int solucao[N][M],int lab[N][M], int *keys, int *tRecursivo, int *aux, int *nivelRecursao, int *movimentos, int *colunaFim){
    *tRecursivo += 1;//conta o numero de chamadas recursivas
    if(x == 0 && checar(N,M,x,y,lab,keys)){
        *colunaFim = y;
        solucao[x][y] = 1;
        return true;
    }
    if(checar(N,M,x,y,lab,keys)){
        solucao[x][y] = 1;
        *movimentos+=1;
        if(solucao[x-1][y] != 1) {
            *aux = *aux + 1;//nivel recursao
            if(A_movimentaEstudante(N,M,x-1,y,solucao,lab,keys, tRecursivo, aux, nivelRecursao,movimentos,colunaFim)){
                return true;
            }
        }
        if(solucao[x][y+1] != 1) {
            *aux = *aux + 1;//nivel recursao
            if (A_movimentaEstudante(N,M,x, y + 1, solucao, lab,keys, tRecursivo, aux, nivelRecursao,movimentos,colunaFim)) {
                return true;
            }
        }
        if(solucao[x][y-1] != 1) {
            *aux = *aux + 1;//nivel recursao
            if (A_movimentaEstudante(N,M,x, y - 1, solucao, lab,keys, tRecursivo, aux, nivelRecursao,movimentos,colunaFim)) {
                return true;
            }
        }
        if(solucao[x+1][y] != 1){
            *aux = *aux + 1;//nivel recursao
            if(A_movimentaEstudante(N,M,x+1, y, solucao, lab, keys, tRecursivo, aux, nivelRecursao,movimentos,colunaFim)){
                return true;
            }
        }
        if(lab[x][y]==3){ //ADICIONAR CHAVE AO USUARIO AO VOLTARMOS POR UMA PORTA QUE HAVIAMOS ABERTO
            *keys = *keys+1;
        }

        if(lab[x][y]==4){ //DEVOLVER CHAVE AO RETORNAR PELA CELULA QUE HAVIAMOS PEGADO A CHAVE
            *keys = *keys-1;
        }
        solucao[x][y] = 0;
        if(*aux > *nivelRecursao) {
            *nivelRecursao = *aux;
            *aux = 0;
        }
        *aux = 0;
        *movimentos+=1;
        return false;
    }
    return false;
}


bool movimentaEstudante(int N, int M, int x,int y,int solucao[N][M],int lab[N][M], int *keys, int *movimentos, int *colunaFim){

    if(x == 0 && checar(N,M,x,y,lab,keys)){
        *colunaFim = y;
        solucao[x][y] = 1;
        return true;
    }
    if(checar(N,M,x,y,lab,keys)){
        solucao[x][y] = 1;
        *movimentos+=1;
        if(solucao[x-1][y] != 1) {
            if(movimentaEstudante(N,M,x-1,y,solucao,lab,keys,movimentos,colunaFim)){
                return true;
            }
        }
        if(solucao[x][y+1] != 1) {
            if (movimentaEstudante(N,M,x, y + 1, solucao, lab,keys,movimentos,colunaFim)) {
                return true;
            }
        }
        if(solucao[x][y-1] != 1) {
            if (movimentaEstudante(N,M,x, y - 1, solucao, lab,keys,movimentos,colunaFim)) {
                return true;
            }
        }
        if(solucao[x+1][y] != 1){
            if(movimentaEstudante(N,M,x+1, y, solucao, lab, keys,movimentos,colunaFim)){
                return true;
            }
        }
        if(lab[x][y]==3){ //ADICIONAR CHAVE AO USUARIO AO VOLTARMOS POR UMA PORTA QUE HAVIAMOS ABERTO
            *keys = *keys+1;
        }
        if(lab[x][y]==4){ //DEVOLVER CHAVE AO RETORNAR PELA CELULA QUE HAVIAMOS PEGADO A CHAVE
            *keys = *keys-1;
        }
        solucao[x][y] = 0;
        *movimentos+=1;
        return false;
    }
    return false;
}
