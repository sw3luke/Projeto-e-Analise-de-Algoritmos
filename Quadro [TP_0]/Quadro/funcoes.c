#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

//===================================== Gerar um asterisco simples ============================================
void fig0(char matriz[][80], int n){
    int pos = 0;
        while (pos / 80 == 0 || pos / 80 == 19 || pos % 80 == 79 || pos % 80 == 0 || matriz[pos/80][pos%80] == '*') {
            pos = rand() % 1600;
        }
        matriz[pos / 80][pos % 80] = '*';

}

//===================================== Gerar um asterisco simples ============================================


//===================================== Gerar o simbolo de soma ============================================
void fig1(char matriz[][80], int n) {
    int pos = 0;
        while (pos / 80 == 0 || pos / 80 == 19 || pos % 80 == 79 || pos % 80 == 0 || (pos / 80 - 1) == 0 || //Responsavel por checar
               (pos / 80 + 1) == 19 || (pos % 80 + 1) == 79 || (pos % 80 - 1) == 0 ||                      // se a figura pode ser desenhada
               matriz[pos / 80][pos % 80] == '*' || matriz[pos / 80 - 1][pos % 80] == '*' ||               // na posição gerada
               matriz[pos / 80 + 1][pos % 80] == '*' || matriz[pos / 80][pos % 80 - 1] == '*' ||
               matriz[pos / 80][pos % 80 + 1] == '*') {
            pos = rand() % 1600;
        }
        matriz[pos / 80][pos % 80] = '*';
        matriz[pos / 80 - 1][pos % 80] = '*';
        matriz[pos / 80 + 1][pos % 80] = '*';
        matriz[pos / 80][pos % 80 + 1] = '*';
        matriz[pos / 80][pos % 80 - 1] = '*';
}
//===================================== Gerar o simbolo de soma ============================================

//===================================== Gerar a letra X ============================================
void fig2(char matriz[][80], int n) {
        int pos = 0;
        while (pos / 80 == 0 || pos / 80 == 19 || pos % 80 == 79 || pos % 80 == 0 || (pos / 80 - 1) == 0 || //Responsavel por checar
               (pos / 80 + 1) == 19 || (pos % 80 + 1) == 79 || (pos % 80 - 1) == 0 ||
               matriz[pos / 80][pos % 80] == '*' || matriz[pos / 80 - 1][pos % 80 - 1] == '*' ||
               matriz[pos / 80 + 1][pos % 80 + 1] == '*' || matriz[pos / 80 - 1][pos % 80 + 1] == '*' ||
               matriz[pos / 80 + 1][pos % 80 - 1] == '*') {
            pos = rand() % 1600;
        }
        matriz[pos / 80][pos % 80] = '*';
        matriz[pos / 80 - 1][pos % 80 - 1] = '*';
        matriz[pos / 80 + 1][pos % 80 + 1] = '*';
        matriz[pos / 80 - 1][pos % 80 + 1] = '*';
        matriz[pos / 80 + 1][pos % 80 - 1] = '*';
}
//===================================== Gerar a letra X ============================================


//===================================== Gerar a imagem criada ============================================
void fig42(char matriz[][80]){
    int pos = 0;
    int j = 0;
    int var = 0;
    //==========================================Escrita da palavra "NOKIA" ==================================================
    //primeira linha
    for(j = 19; j < 58; j++){
        if(j == 21 || j == 22 || j == 23 || j == 26 || j == 27 || j == 28 || j == 34 || j == 35 || j == 36 || j == 39 || j == 40 ||
           j == 43 || j == 44 || j == 47 || j == 48 || j == 49 || j == 55 || j == 56 || j == 57){
            matriz[14][j] = ' ';
        }
        else {
            matriz[14][j] = '*';
        }
    }
    //Segunda linha
    for(j = 19; j < 58; j ++){
        if(j == 22 || j == 23 || j == 26 || j == 27 || j == 30 || j == 31 || j == 32 || j == 35 || j == 36 || j == 39 ||
           j == 42 || j == 43 || j == 44 || j == 47 || j == 48 || j == 51 || j == 52 || j == 53 || j == 56 || j == 57){
            matriz[15][j] = ' ';
        }
        else{
            matriz[15][j] = '*';
        }
    }
    //Terceira linha
    for(j = 19; j< 58; j++){
        if(j == 21 || j == 23 || j == 26 || j == 27 || j == 30 || j == 31 || j == 32 || j == 35 || j == 36 || j == 41 || j == 42 ||
           j == 43 || j == 44 || j == 47 || j == 48 || j == 56 || j == 57){
            matriz[16][j] = ' ';
        }
        else{
            matriz[16][j] = '*';
        }
    }
    //Quarta linha
    for(j = 19; j < 58; j++){
        if(j == 21 || j == 26 || j == 27 || j == 30 || j == 31 || j == 32 || j == 35 || j == 36 || j == 39 || j == 42 || j == 43 ||
           j == 44 || j == 47 || j == 48 || j == 51 || j == 52 || j == 53  || j == 56 || j == 57){
            matriz[17][j] = ' ';
        }
        else{
            matriz[17][j] = '*';
        }
    }
    //Quinta linha
    for(j = 19; j < 58; j ++){
        if(j == 21 || j == 22 || j == 26  || j == 27  || j == 28 || j == 34  || j == 35  || j == 36 || j == 39  || j == 40 || j == 43 ||
           j == 44 || j == 47  || j == 48 || j == 51  || j == 52  || j == 53 || j == 56  || j == 57 ){
            matriz[18][j] = ' ';
        }
        else{
            matriz[18][j] = '*';
        }
    }
    //==========================================Escrita da palavra "NOKIA" ==================================================



    while(pos/80 == 0 || pos/80 == 19|| pos%80 == 79 || pos%80 == 0 || (pos/80 - 3) <= 0 || (pos/80 + 3) >= 19 ||
    (pos%80 + 5) >= 79 || (pos%80 - 5) <= 0 || matriz[pos/80][pos%80] == '*' || matriz[pos/80 - 1][pos%80] == '*' ||
    matriz[pos/80 - 2][pos%80] == '*' || matriz[pos/80 + 1][pos%80] == '*' || matriz[pos/80 + 2][pos%80] == '*' ||
    matriz[pos/80][pos%80 - 1] == '*' || matriz[pos/80 - 1][pos%80 - 1] == '*' || matriz[pos/80 - 2][pos%80 - 1] == '*' ||
    matriz[pos/80 + 1][pos%80 - 1] == '*' || matriz[pos/80 + 2][pos%80 - 1] == '*' ||
    matriz[pos/80][pos%80 + 1] == '*' || matriz[pos/80 - 1][pos%80 + 1] == '*' ||
    matriz[pos/80 - 2][pos%80 + 1] == '*' || matriz[pos/80 + 1][pos%80 + 1] == '*' ||
    matriz[pos/80 + 2][pos%80 + 1] == '*' || matriz[pos/80][pos%80 + 2] == '*' ||
    matriz[pos/80 - 2][pos%80 + 2] == '*' || matriz[pos/80 + 2][pos%80 + 2] == '*' ||
    matriz[pos/80 - 1][pos%80 + 3] == '*' || matriz[pos/80 + 1][pos%80 + 3] == '*' ||
    matriz[pos/80][pos%80 + 4] == '*' || matriz[pos/80][pos%80 + 5] == '*' ||
    matriz[pos/80][pos%80 - 2] == '*'||
    matriz[pos/80 - 1][pos%80 - 3] == '*' ||
    matriz[pos/80 + 1][pos%80 - 3] == '*' ||
    matriz[pos/80][pos%80 - 4] == '*' ||
    matriz[pos/80 - 2][pos%80 - 3] == '*' ||
    matriz[pos/80 + 2][pos%80 - 3] == '*' ||
    matriz[pos/80 - 2][pos%80 - 4] == '*' ||
    matriz[pos/80 + 2][pos%80 - 4] == '*' ||
    matriz[pos/80 - 3][pos%80 - 4] == '*' ||
    matriz[pos/80 + 3][pos%80 - 4] == '*' ||
    matriz[pos/80 - 3][pos%80 - 5] == '*' ||
    matriz[pos/80 + 3][pos%80 - 5] == '*' ||
    //a partir daqui é para separar uma nave da outra
    matriz[pos/80][pos%80 + 6] == '*'
    || matriz[pos/80 - 1][pos%80 - 6] == '*'
    || matriz[pos/80 - 2][pos%80 - 6] == '*'
    || matriz[pos/80 - 3][pos%80 - 6] == '*'
    || matriz[pos/80 - 4][pos%80 - 6] == '*' ||
    matriz[pos/80][pos%80 - 6] == '*' || matriz[pos/80 + 1][pos%80 - 6] == '*'
    || matriz[pos/80 + 2][pos%80 - 6] == '*' || matriz[pos/80 + 3][pos%80 - 6] == '*' || matriz[pos/80 + 4][pos%80 - 6] == '*'
    || matriz[pos/80 - 1][pos%80 - 6] == '*' || matriz[pos/80 - 2][pos%80 - 6] == '*' || matriz[pos/80 - 3][pos%80 - 6] == '*'
    || matriz[pos/80 - 4][pos%80 - 6] == '*' || matriz[pos/80 - 4][pos%80 - 5] == '*' || matriz[pos/80 - 4][pos%80 - 4] == '*'
    || matriz[pos/80 + 4][pos%80 - 5] == '*' || matriz[pos/80 + 4][pos%80 - 4] == '*'){
        //caso a figura nao possa ser desenhada na atual posição, uma nova posição será gerada pela seguinte linha de codigo:
        pos = rand() % 1600;
        //A variavel Pos representa a posição central da figura.
    }
    matriz[pos/80][pos%80] = '*';
    matriz[pos/80 - 1][pos%80] = '*';
    matriz[pos/80 - 2][pos%80] = '*';
    matriz[pos/80 + 1][pos%80] = '*';
    matriz[pos/80 + 2][pos%80] = '*';

    matriz[pos/80][pos%80 - 1] = '*';
    matriz[pos/80 - 1][pos%80 - 1] = '*';
    matriz[pos/80 - 2][pos%80 - 1] = '*';
    matriz[pos/80 + 1][pos%80 - 1] = '*';
    matriz[pos/80 + 2][pos%80 - 1] = '*';

    matriz[pos/80][pos%80 + 1] = '*';
    matriz[pos/80 - 1][pos%80 + 1] = '*';
    matriz[pos/80 - 2][pos%80 + 1] = '*';
    matriz[pos/80 + 1][pos%80 + 1] = '*';
    matriz[pos/80 + 2][pos%80 + 1] = '*';

    matriz[pos/80][pos%80 + 2] = '*';
    matriz[pos/80 - 2][pos%80 + 2] = '*';
    matriz[pos/80 + 2][pos%80 + 2] = '*';

    matriz[pos/80 - 1][pos%80 + 3] = '*';
    matriz[pos/80 + 1][pos%80 + 3] = '*';

    matriz[pos/80][pos%80 + 4] = '*';

    matriz[pos/80][pos%80 + 5] = '*';
    //============== CAUDA da NAVE ===============
    matriz[pos/80][pos%80 - 2] = '*';

    matriz[pos/80 - 1][pos%80 - 3] = '*';
    matriz[pos/80 + 1][pos%80 - 3] = '*';

    matriz[pos/80][pos%80 - 4] = '*';
    matriz[pos/80 - 2][pos%80 - 3] = '*';
    matriz[pos/80 + 2][pos%80 - 3] = '*';
    matriz[pos/80 - 2][pos%80 - 4] = '*';
    matriz[pos/80 + 2][pos%80 - 4] = '*';
    matriz[pos/80 - 3][pos%80 - 4] = '*';
    matriz[pos/80 + 3][pos%80 - 4] = '*';
    matriz[pos/80 - 3][pos%80 - 5] = '*';
    matriz[pos/80 + 3][pos%80 - 5] = '*';

    //============== CAUDA da NAVE ===============
}


void fig42asteroides(char matriz[][80]){
    int nave = 732;
    int pos = 0;
//============================================== NAVE ==================================================
    matriz[nave/80][nave%80] = '*';
    matriz[nave/80 - 1][nave%80] = '*';
    matriz[nave/80 - 2][nave%80] = '*';
    matriz[nave/80 + 1][nave%80] = '*';
    matriz[nave/80 + 2][nave%80] = '*';
    matriz[nave/80][nave%80 - 1] = '*';
    matriz[nave/80 - 1][nave%80 - 1] = '*';
    matriz[nave/80 - 2][nave%80 - 1] = '*';
    matriz[nave/80 + 1][nave%80 - 1] = '*';
    matriz[nave/80 + 2][nave%80 - 1] = '*';
    matriz[nave/80][nave%80 + 1] = '*';
    matriz[nave/80 - 1][nave%80 + 1] = '*';
    matriz[nave/80 - 2][nave%80 + 1] = '*';
    matriz[nave/80 + 1][nave%80 + 1] = '*';
    matriz[nave/80 + 2][nave%80 + 1] = '*';
    matriz[nave/80][nave%80 + 2] = '*';
    matriz[nave/80 - 2][nave%80 + 2] = '*';
    matriz[nave/80 + 2][nave%80 + 2] = '*';
    matriz[nave/80 - 1][nave%80 + 3] = '*';
    matriz[nave/80 + 1][nave%80 + 3] = '*';
    matriz[nave/80][nave%80 + 4] = '*';
    matriz[nave/80][nave%80 + 5] = '*';
    //CAUDA
    matriz[nave/80][nave%80 - 2] = '*';
    matriz[nave/80 - 1][nave%80 - 3] = '*';
    matriz[nave/80 + 1][nave%80 - 3] = '*';
    matriz[nave/80][nave%80 - 4] = '*';
    matriz[nave/80 - 2][nave%80 - 3] = '*';
    matriz[nave/80 + 2][nave%80 - 3] = '*';
    matriz[nave/80 - 2][nave%80 - 4] = '*';
    matriz[nave/80 + 2][nave%80 - 4] = '*';
    matriz[nave/80 - 3][nave%80 - 4] = '*';
    matriz[nave/80 + 3][nave%80 - 4] = '*';
    matriz[nave/80 - 3][nave%80 - 5] = '*';
    matriz[nave/80 + 3][nave%80 - 5] = '*';
//============================================== NAVE ==================================================

//==========================================Escrita da palavra "NOKIA" ==================================================
    int j = 0;
    //primeira linha
    for(j = 19; j < 58; j++){
        if(j == 21 || j == 22 || j == 23 || j == 26 || j == 27 || j == 28 || j == 34 || j == 35 || j == 36 || j == 39 || j == 40 ||
           j == 43 || j == 44 || j == 47 || j == 48 || j == 49 || j == 55 || j == 56 || j == 57){
            matriz[14][j] = ' ';
        }
        else {
            matriz[14][j] = '*';
        }
    }
    //Segunda linha
    for(j = 19; j < 58; j ++){
        if(j == 22 || j == 23 || j == 26 || j == 27 || j == 30 || j == 31 || j == 32 || j == 35 || j == 36 || j == 39 ||
           j == 42 || j == 43 || j == 44 || j == 47 || j == 48 || j == 51 || j == 52 || j == 53 || j == 56 || j == 57){
            matriz[15][j] = ' ';
        }
        else{
            matriz[15][j] = '*';
        }
    }
    //Terceira linha
    for(j = 19; j< 58; j++){
        if(j == 21 || j == 23 || j == 26 || j == 27 || j == 30 || j == 31 || j == 32 || j == 35 || j == 36 || j == 41 || j == 42 ||
           j == 43 || j == 44 || j == 47 || j == 48 || j == 56 || j == 57){
            matriz[16][j] = ' ';
        }
        else{
            matriz[16][j] = '*';
        }
    }
    //Quarta linha
    for(j = 19; j < 58; j++){
        if(j == 21 || j == 26 || j == 27 || j == 30 || j == 31 || j == 32 || j == 35 || j == 36 || j == 39 || j == 42 || j == 43 ||
           j == 44 || j == 47 || j == 48 || j == 51 || j == 52 || j == 53  || j == 56 || j == 57){
            matriz[17][j] = ' ';
        }
        else{
            matriz[17][j] = '*';
        }
    }
    //Quinta linha
    for(j = 19; j < 58; j ++){
        if(j == 21 || j == 22 || j == 26  || j == 27  || j == 28 || j == 34  || j == 35  || j == 36 || j == 39  || j == 40 || j == 43 ||
           j == 44 || j == 47  || j == 48 || j == 51  || j == 52  || j == 53 || j == 56  || j == 57 ){
            matriz[18][j] = ' ';
        }
        else{
            matriz[18][j] = '*';
        }
    }
//==========================================Escrita da palavra "NOKIA" ==================================================


//=================== O while é responsavel por checar se a figura pode ser desenhada na posição gerada =======================
    while(pos/80 == 0 || pos/80 == 19|| pos%80 == 79 || pos%80 == 0 || (pos - 4)/80 <= 0 || (pos + 4)/80 <= 0 ||
    pos%80 <= 4 || pos%80 >= 77 || pos/80 <= 3 || pos/80 >= 16 || matriz[pos/80][pos%80] != ' ' || matriz[pos/80][pos%80 -1] != ' '
    || matriz[pos/80][pos%80 - 2] != ' ' || matriz[pos/80][pos%80 - 3] != ' ' || matriz[pos/80][pos%80 - 4] != ' '
    || matriz[pos/80][pos%80 - 5] != ' ' || matriz[pos/80][pos%80 + 1] != ' ' || matriz[pos/80][pos%80 + 2] != ' '
    || matriz[pos/80][pos%80 + 3] != ' ' || matriz[pos/80][pos%80+ 4] != ' ' || matriz[pos/80][pos%80 + 5] != ' '

    || matriz[pos/80 - 1][pos%80] != ' ' || matriz[pos/80 - 1][pos%80 - 1] != ' ' || matriz[pos/80 - 1][pos%80 - 2] != ' '
    || matriz[pos/80 - 1][pos%80 - 3] != ' ' || matriz[pos/80 - 1][pos%80 - 4] != ' ' || matriz[pos/80 - 1][pos%80 - 5] != ' '
    || matriz[pos/80 - 1][pos%80 + 1] != ' ' || matriz[pos/80 - 1][pos%80 + 2] != ' ' || matriz[pos/80 - 1][pos%80 + 3] != ' '
    || matriz[pos/80 - 1][pos%80 + 4] != ' ' || matriz[pos/80 - 1][pos%80 + 5] != ' '

    || matriz[pos/80 - 2][pos%80] != ' ' || matriz[pos/80 - 2][pos%80 - 1] != ' ' || matriz[pos/80 - 2][pos%80 - 2] != ' '
    || matriz[pos/80 - 2][pos%80 - 3] != ' ' || matriz[pos/80 - 2][pos%80 - 4] != ' ' || matriz[pos/80 - 2][pos%80 - 5] != ' '
    || matriz[pos/80 - 2][pos%80 + 1] != ' ' || matriz[pos/80 - 2][pos%80 + 2] != ' ' || matriz[pos/80 - 2][pos%80 + 3] != ' '
    || matriz[pos/80 - 2][pos%80 + 4] != ' ' || matriz[pos/80 - 2][pos%80 + 5] != ' '

    || matriz[pos/80 + 1][pos%80] != ' ' || matriz[pos/80 + 1][pos%80 - 1] != ' ' || matriz[pos/80 + 1][pos%80 - 2] != ' '
    || matriz[pos/80 + 1][pos%80 - 3] != ' ' || matriz[pos/80 + 1][pos%80 - 4] != ' ' || matriz[pos/80 + 1][pos%80 - 5] != ' '
    || matriz[pos/80 + 1][pos%80 + 1] != ' ' || matriz[pos/80 + 1][pos%80 + 2] != ' ' || matriz[pos/80 + 1][pos%80 + 3] != ' '
    || matriz[pos/80 + 1][pos%80 + 4] != ' ' || matriz[pos/80 + 1][pos%80 + 5] != ' '

    || matriz[pos/80 + 2][pos%80] != ' ' || matriz[pos/80 + 2][pos%80 - 1] != ' ' || matriz[pos/80 + 2][pos%80 - 2] != ' '
    || matriz[pos/80 + 2][pos%80 - 3] != ' ' || matriz[pos/80 + 2][pos%80 - 4] != ' ' || matriz[pos/80 + 2][pos%80 - 5] != ' '
    || matriz[pos/80 + 2][pos%80 + 1] != ' ' || matriz[pos/80 + 2][pos%80 + 2] != ' ' || matriz[pos/80 + 2][pos%80 + 3] != ' '
    || matriz[pos/80 + 2][pos%80 + 4] != ' ' || matriz[pos/80 + 2][pos%80 + 5] != ' '){
        //caso a figura nao possa ser desenhada na atual posição, uma nova posição será gerada pela seguinte linha de codigo:
        pos = rand() % 1600;
        //A variavel Pos representa a posição central da figura.
    }
//=================== O while é responsavel por checar se a figura pode ser desenhada na posição gerada =======================


//============================== trecho responsavel pelo desenho do asteroide ================================
    matriz[pos/80][pos%80] = ' ';
    matriz[pos/80][pos%80 - 1] = '\"';
    matriz[pos/80][pos%80 - 2] = ' ';
    matriz[pos/80][pos%80 - 3] = ' ';
    matriz[pos/80][pos%80 - 4] = '|';
    matriz[pos/80][pos%80 + 1] = ' ';
    matriz[pos/80][pos%80 + 2] = ' ';
    matriz[pos/80][pos%80 + 3] = ' ';
    matriz[pos/80][pos%80 + 4] = '|';

    matriz[pos/80 - 1][pos%80] = ' ';
    matriz[pos/80 - 1][pos%80 - 1] = ' ';
    matriz[pos/80 - 1][pos%80 - 2] = ' ';
    matriz[pos/80 - 1][pos%80 - 3] = '/';
    matriz[pos/80 - 1][pos%80 + 1] = ' ';
    matriz[pos/80 - 1][pos%80 + 2] = ' ';
    matriz[pos/80 - 1][pos%80 + 3] = '\\';

    matriz[pos/80 - 2][pos%80] = '_';
    matriz[pos/80 - 2][pos%80 - 1] = '_';
    matriz[pos/80 - 2][pos%80 - 2] = '_';
    matriz[pos/80 - 2][pos%80 + 1] = '_';
    matriz[pos/80 - 2][pos%80 + 2] = '_';

    matriz[pos/80 + 1][pos%80] = '_';
    matriz[pos/80 + 1][pos%80 - 1] = '_';
    matriz[pos/80 + 1][pos%80 - 2] = '_';
    matriz[pos/80 + 1][pos%80 - 3] = '\\';
    matriz[pos/80 + 1][pos%80 + 1] = '_';
    matriz[pos/80 + 1][pos%80 + 2] = '_';
    matriz[pos/80 + 1][pos%80 + 3] = '/';
//============================== trecho responsavel pelo desenho do asteroide ================================
}