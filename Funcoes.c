#include "Cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filme {
  char nome[101];
  float preco;
  Info* informacoes;
};

struct info {
  char diretor[101];
  char genero[51];
  int ano;
  int faixaEtaria;
};

Filme* criar_filme() {
  Filme* f = (Filme*) malloc(sizeof(Filme));

  if(f == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }

  f->informacoes = (Info*) malloc(sizeof(Info));

  if(f->informacoes == NULL) {
    printf("Memoria insulficiente!\n");
    exit(1);
  }

  return f;

}

void free_filme(Filme* f) {
  free(f);
}

void imprimir_filme(Filme* f) {
  printf("%.2f R$ || %s\n (%s, %d) || %s %d\n", f->preco, f->nome, f->informacoes->genero, f->informacoes->faixaEtaria, f->informacoes->diretor, f->informacoes->ano);
}

void set_nome(Filme* f, char* novo) {
  strcpy(f->nome, novo);
}

void set_preco(Filme* f, float novo) {
  f->preco = novo;
}

void set_diretor(Filme* f, char* novo) {
  strcpy(f->informacoes->diretor, novo);
}

void set_genero(Filme* f, char* novo) {
  strcpy(f->informacoes->genero, novo);
}

void set_ano(Filme* f, int novo) {
  f->informacoes->ano = novo;
}

void set_faixaetaria(Filme* f, int novo) {
  f->informacoes->faixaEtaria = novo;
}

void  menu(void) {

  printf("MENU DE OPCOES\n\n");
  printf("1 - CADASTRAR UM NOVO TITULO\n");
  printf("2 - ATUALIZAR INFO DE UM TITULO\n");
  printf("3 - EXCLUIR UM TITULO\n");
  printf("4 - FINALIZAR OPERACAO\n");
  
}

void subMenu(void) {

  printf("1 - RENOMEAR TITULO\n");
  printf("2 - ATUALIZAR PRECO\n");
  printf("3 - ATUALIZAR GENERO\n");

}

void print_tabela(Filme** tabela, int tam) {
  printf("-------------TABELA DE FILMES-------------\n\n");
  for(int i = 0 ; i < tam ; i++) {
    printf("%.4d -- ", i+1);
    imprimir_filme(tabela[i]);
  }
  menu();
}
