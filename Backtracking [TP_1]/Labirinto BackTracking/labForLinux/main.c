#include "arquivo.c"
#include <conio.h>


#define analise(var) var

int main(int argc, char **argv){


    char local[32] = " ";
    char entrada[16];

    system("clear");
    menu();
    printf(" ->");scanf("%s",entrada);
    char entrad1 = entrada[0];
    getchar();

    while(entrad1 != '3'){
      system("clear");
      menu();
      switch (entrad1) {
        case '1':
          printf("\n Nome do Arquivo: \n -> ");scanf("%s",local);
          system("clear");
          menuArq(local);
        break;
        case '2':
          if(strcmp(local," ")!=0){
            programa(local, argv[1]);
          }
          else{
            Error();
            system("clear");
            menu();
          }
        break;
        case '0':
          system("clear");
          if(strcmp(local," ")!=0)
            menuArq(local);
          else
            menu();
        break;
        }
      printf(" ->");scanf("%s",entrada);
      entrad1 = entrada[0];
      getchar();
      }

    return 0;
}
