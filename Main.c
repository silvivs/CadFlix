#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cabecalho.h"

int main(void) {
  int op = 0;
  int N = 0;

  scanf("%d", &N);
  
  Filme* tabela[N];

  menu();

  while(scanf("%d", &op), op != 4){

    switch(op){
      case 1:
      //parei aqui
      //todas vez que a opção 1 for selecionada a tabela aumenta dinamicamente, mas o comando do trabalho diz que não deve ser colocado mais que N na tabela. Informação conflitante?
      break;


      case 2:

      subMenu();

      int sub_op2 = 0;
      scanf("%d", &sub_op2);

      switch(sub_op2){
        case 1:
        break;

        case 2:
        break;

        case 3:
        break;

        default:
        printf("Opcao invalida\n");
        break;
      }

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
