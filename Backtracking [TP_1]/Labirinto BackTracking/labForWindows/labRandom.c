#include "labRandom.h"

bool labRandom(int n, int m, int Lab[n][m], int *posInicial){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j ++){
            Lab[i][j] = 1;
        }
    }
    srand(time(NULL));
    int obstaculos = (rand() % ((n*m)/2));
    while (obstaculos<((n*m)/2)-1){
        obstaculos = (rand() % ((n*m)/2));
    }
    printf("\nOBS: %d\n",obstaculos);
    for(int k = 0; k < obstaculos; k++){
        int linha = rand()%n;
        int coluna = rand()%m;
        if(Lab[linha][coluna] == 2){
            obstaculos = obstaculos+1;
        }
        Lab[linha][coluna] = 2;
    }
    bool existe = false;
    *posInicial = rand() % m;
    for(int h =0;h<m;h++){
        if(Lab[n-1][h]==1){
            existe = true;
        }
    }
    while(Lab[n-1][*posInicial]==0 && existe){
        *posInicial = (rand() % m);
    }
    Lab[n-1][*posInicial]=0;
    if(existe == true){
        return true;
    }
    else{
        return false;
    }
}
