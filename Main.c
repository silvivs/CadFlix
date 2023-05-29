#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cabecalho.h"

int procuraSubstring(char* string);
void leitura(Filme** tabela, int index); 

int main(void) {
  int op = 0;
  int N = 0;
  int index = 0;
  
  printf("Entre com o tamanho da sua tabela: ");
  scanf("%d", &N);
  
  Filme** tabela = (Filme**)malloc(N * sizeof(Filme*));

  menu();

  while(scanf("%d", &op), op != 4){

    switch(op){
      case 1:
      if(index == N){
         N++;
         index = N - 1;
         Filme** tabela = (Filme**)realloc(tabela, N * sizeof(Filme*));
         tabela[index] = criar_filme();
         leitura(tabela, index);
         print_tabela(tabela, N);

      }else{
        tabela[index] = criar_filme();
        leitura(tabela, index);
        print_tabela(tabela, N);
        index++;
      }
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

int procuraSubstring(char* string) {
  char* resultado = strstr(string, "Terror");
  if(resultado != NULL){
    return 1;
  }else{
    return 0;
  }
}

void leitura(Filme** tabela, int index) {
  printf("Nome: ");
  char nome[101];
  scanf("%s", nome);
  set_nome(tabela[index], nome);

  printf("Preco: ");
  float preco = 0;
  scanf("%f", &preco);
  set_preco(tabela[index], preco);

  printf("Diretor: ");
  char diretor[101];
  scanf("%s", diretor);
  set_diretor(tabela[index], diretor);

  printf("Ano: ");
  int ano = 0;
  scanf("%d", &ano);
  set_ano(tabela[index], ano);

  printf("Genero: ");
  char genero[51];
  scanf("%s", genero);
  set_genero(tabela[index], genero);
 
  int faixaEtaria = 0;

  if(procuraSubstring(genero) == 1){
    printf("Faixa etaria: ");
    while(scanf("%d", &faixaEtaria), faixaEtaria < 18){
      printf("Filmes de Terror nao podem ter classificacao para menores de 18 anos!Digite outro valor: ");
    }

    set_faixaetaria(tabela[index], faixaEtaria);

  }else{
    printf("Faixa etaria: ");
    scanf("%d", &faixaEtaria);
    set_faixaetaria(tabela[index], faixaEtaria);
  }
}

