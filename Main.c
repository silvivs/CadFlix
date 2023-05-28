#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cabecalho.h"

int main(void) {
  int op = 0;

  menu();

  while(scanf("%d", &op), op != 4){

    switch(op){
      case 1:
      break;

      case 2:
      break;

      case 3:
      break;

      default:
      printf("Opcao invalida!\n\n");
      break;
    }

    menu();
  }
  
  
  return 0;
}
