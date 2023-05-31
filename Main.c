#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cabecalho.h"

int main(void) {
  int op = 0;
  int N = 0;
  int index = 0;

  printf("Entre com o tamanho da sua tabela: ");
  scanf("%d", &N);

  Filme** tabela = (Filme**)malloc(N * sizeof(Filme*));

  menu();

  while (scanf("%d", &op), op != 4) {
    getchar();

    switch (op) {
      case 1:
        if (N == index) {
          printf("Limite maximo alcancado\n");
          menu();
          continue;
        }
        
        tabela[index] = criar_filme();

        printf("Nome: ");
        char nome[101];
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
        set_nome(tabela[index], nome);

        printf("Preco: ");
        float preco = 0;
        scanf("%f", &preco);
        getchar();
        set_preco(tabela[index], preco);

        printf("Diretor: ");
        char diretor[101];
        fgets(diretor, sizeof(diretor), stdin);
        diretor[strcspn(diretor, "\n")] = '\0';
        set_diretor(tabela[index], diretor);

        printf("Ano: ");
        int ano = 0;
        scanf("%d", &ano);
        getchar();
        set_ano(tabela[index], ano);

        printf("Genero: ");
        char genero[51];
        fgets(genero, sizeof(genero), stdin);
        genero[strcspn(genero, "\n")] = '\0';
        set_genero(tabela[index], genero);

        int faixaEtaria = 0;

        if (procuraSubstring(genero) == 1) {
          printf("Faixa etaria: ");
          while (scanf("%d", &faixaEtaria), faixaEtaria < 18) {
            printf("Filmes de Terror nao podem ter classificacao para menores de 18 anos!Digite outro valor: ");
          }

          set_faixaetaria(tabela[index], faixaEtaria);
        }
        else {
          printf("Faixa etaria: ");
          scanf("%d", &faixaEtaria);
          set_faixaetaria(tabela[index], faixaEtaria);
        }

        print_tabela(tabela, index + 1);
        index++;
        break;

      case 2:

        subMenu();
        int id = 0;
        int sub_op2 = 0;
        scanf("%d", &sub_op2);
        getchar();

        switch (sub_op2) {
          case 1:
            printf("Informe o codigo do filme que sera renomeado: ");
            scanf("%d", &id);
            getchar();

            printf("Nome: ");
            char nome[101];
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';
            set_nome(tabela[id - 1], nome);

            printf("Diretor: ");
            char diretor[101];
            fgets(diretor, sizeof(diretor), stdin);
            diretor[strcspn(diretor, "\n")] = '\0';
            set_diretor(tabela[id - 1], diretor);

            print_tabela(tabela, index);

            break;

          case 2:
            printf("Informe o codigo do filme que tera o preco atualizado: ");
            scanf("%d", &id);
            getchar();

            printf("Preco: ");
            float preco = 0;
            scanf("%f", &preco);
            getchar();
            set_preco(tabela[id - 1], preco);

            print_tabela(tabela, index);

            break;

          case 3:
            printf("Informe o codigo do filme que tera o genero atualizado: ");
            scanf("%d", &id);
            getchar();

            printf("Genero: ");
            char genero[51];
            fgets(genero, sizeof(genero), stdin);
            genero[strcspn(genero, "\n")] = '\0';
            set_genero(tabela[id - 1], genero);

            if (procuraSubstring(genero) == 1) {
               printf("Faixa etaria: ");
               while (scanf("%d", &faixaEtaria), faixaEtaria < 18) {
                  printf("Filmes de Terror nao podem ter classificacao para menores de 18 anos!Digite outro valor: ");
             }

            set_faixaetaria(tabela[id - 1], faixaEtaria);
            }


            print_tabela(tabela, index);        

            break;

          default:
            printf("Opcao invalida\n");
            break;
        }

        break;

      case 3:
        printf("Informe o codigo do filme que será apagado: ");
        scanf("%d", &id);
        getchar();

        free_filme(tabela[id-1]);
        tabela[id-1] = NULL;

        for(int i = 0 ; i < index -1 ; i++){
          if(tabela[i] == NULL){
            tabela[i] = tabela[i+1];
            tabela[i+1] = NULL;
          }
        }

        N--;

        tabela = (Filme**) realloc(tabela, N * sizeof(Filme*));

        index--;

        print_tabela(tabela, index);

        break;

      default:
        printf("Opcao invalida!\n\n");
        break;
    }
    menu();
  }

  return 0;
}
