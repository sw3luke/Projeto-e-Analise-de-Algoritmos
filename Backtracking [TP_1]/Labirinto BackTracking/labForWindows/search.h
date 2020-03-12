#include "exibicao.c"



bool checar(int N, int M,int x,int y,int lab[N][M], int *keys);
void imprimeSolucao(int N, int M, int sol[N][M]);
bool procuraSolucao(int N, int M,int maze[N][M],int posInicial, int *keys, bool analise);
bool A_movimentaEstudante(int N, int M, int x,int y,int solv[N][M],int lab[N][M], int *keys, int *tRecursivo, int *aux, int *nivelRecursao, int *movimentos, int *colunaFim);
bool movimentaEstudante(int N, int M, int x,int y,int solv[N][M],int lab[N][M], int *keys, int *movimentos, int *colunaFim);
