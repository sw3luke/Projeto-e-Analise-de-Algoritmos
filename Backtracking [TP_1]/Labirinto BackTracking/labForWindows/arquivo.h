#include "search.c"

int** entradaArquivo(char *local,int *linhas, int *colunas, int *keys, int *posInicial);
void convertMatriz(int **matrizPointer, int linhas, int colunas, int matriz[linhas][colunas]);
void programa(char *local, char *analise);
void Error();
