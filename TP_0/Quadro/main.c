#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <time.h>

int main() {
    int loop = 0; // checa se o usuario quer fazer outro quadro
    while (loop != 2) {
    srand(time(NULL));
    char matriz[20][80];
    int i = 0;
    int j = 0;
    int n = 0;
    int count = 0;
    int pos = 0;
    int fig = 0;
    int var = 0;

    //================P. Espaço====================
        for (i = 0; i < 20; i++) {
            for (j = 0; j < 80; j++) {
                matriz[i][j] = ' ';         // este loop preenche todas as casa da matriz com espaços
            }
        }
    //================P. Espaço====================

    //===================F. Quadro======================
    for (i = 0; i < 20; i++) {
            for (j = 0; j < 80; j++) {
                if (i == 0 || i == 19) {
                    matriz[i][j] = '-';
                }
                if (j == 0 || j == 79) {     //Loop responsavel por adaptar as posições da matriz
                    matriz[i][j] = '|';      // ao formato do quadro
                }
            }
            matriz[i][j] = '\n';
        }
    //===================F. Quadro======================

    //=============P. Quadro em branco==============
        for (i = 0; i < 20; i++) {
            for (j = 0; j < 80; j++) {
                printf("%c", matriz[i][j]);      //Parte do codigo responsavel
            }                                    //por printar o quadro em branco
            printf("\n");
        }
    //=============P. Quadro em branco==============
        printf("\nQue tal criarmos uma obra de arte?\n");
        printf("=========================================\n");
        printf("Escolha sua figura desejada: \n");
        printf("0 - Asterisco simples\n");
        printf("1 - Simbolo de soma com asteriscos\n");
        printf("2 - Letra X com asteriscos\n");
        printf("3 - Figuras aleatorias\n");
        printf("42 - EasterEgg\n");
        scanf("%d", &fig);
        printf("\n");
        printf("Escolha um numero de figuras em sua obra: ");
        scanf("%d", &n);
        printf("\n");

        if (n > 100) { // checar se o numero escolhido é maior que 100 para as figuras padrões
            printf("limitamos sua escolha a apenas 100 figuras");
            n = 100;
        } else if (n < 0) {  // checar se o numero escolhido é menor que 0
            printf("O número escolhido é muito pequeno, geraremos um para você");
            n = rand() % 100;
        }
        if (fig == 0) { //escolha da primeira figura
            while (count != n) {
                fig0(matriz, n); //chamada para a função responsavel por desenhar o quadro com base na figura escolhida
                count++;
            }
        } else if (fig == 1) {
            while (count != n) {
                fig1(matriz, n); //chamada para a função responsavel por desenhar o quadro com base na figura escolhida
                count++;
            }
        } else if (fig == 2) {
            while (count != n) {
                fig2(matriz, n); //chamada para a função responsavel por desenhar o quadro com base na figura escolhida
                count++;
            }
        } else if (fig == 3) {
            printf("você escolheu pelo conjunto das 3 imagens aleatorias!");
            fig = rand() % 3; // gera o numero de seleção para a figura que sera inserida.
            while (count != n) {
                if (fig == 0) {
                    fig0(matriz, n); //chamada para a função responsavel por desenhar o quadro com base na figura escolhida
                }
                if (fig == 1) {
                    fig1(matriz, n); //chamada para a função responsavel por desenhar o quadro com base na figura escolhida
                }
                if (fig == 2) {
                    fig2(matriz, n); //chamada para a função responsavel por desenhar o quadro com base na figura escolhida
                }
                fig = rand() % 3;
                count++;
            }

        } else if (fig == 42) {
            printf("Resposta certa =)");
            printf("\n1 - Variar o número de naves.");
            printf("\n2 - Variar o número de asteróides.\n");
            scanf(" %d", &var);
            if (var == 1) { // caso tenha escolhido variar o numero de naves.
                if(n > 5){
                    printf("O valor escolhido é muito alto, diminuimos o valor para 5.");
                    n = 5;
                }
                while (count != n) {
                    fig42(matriz); //chamada para a função responsavel por desenhar o quadro com base na figura escolhida
                    count++;
                }
            } else if (var == 2) { // caso tenha escolhido variar o numero de asteróides.
                if(n >= 9){
                    printf("O valor escolhido é muito alto, diminuimos o valor para 8.");
                    n = 8;
                }
                while (count != n) {
                    fig42asteroides(matriz); //chamada para a função responsavel por desenhar o quadro com base na figura escolhida
                    count++;
                }
            } else {
                printf("Escolha Invalida");
            }
        }


        printf("Sua obra de arte é: \n");

        for (i = 0; i < 20; i++) {
            for (j = 0; j < 80; j++) {
                printf("%c", matriz[i][j]);
            }
            printf("\n");
        }
        printf("Deseja criar outra arte?");
        printf("\n1 - Sim");
        printf("\n2 - Não\n");
        scanf("%d", &loop);
    }
    return 0;
}