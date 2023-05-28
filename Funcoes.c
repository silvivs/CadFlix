#include "Cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filme {
  char nome[81];
  float preco;
  char diretor[81];
  int ano;
  char genero[81];
  int idade;
};

Filme* criar_filme() {
  Filme* f = (Filme*) malloc(sizeof(Filme));

  if(f == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }

}

void free_filme(Filme* f) {
  free(f);
}

void imprimir_filme(Filme* f) {

  printf("Nome: %s\n", f->nome);
  printf("Preço: %.2f\n", f->preco);
  printf("Diretor: %s\n", f->diretor);
  printf("Ano: %d\n", f->ano);
  printf("Gênero: %s\n", f->genero);
  printf("Faixa etária: %d\n", f->idade);

}

void set_nome(Filme* f, char* novo){
  strcpy(f->nome, novo);
}

void set_preco(Filme* f, float novo){
  f->preco = novo;
}

void set_diretor(Filme* f, char* novo){
  strcpy(f->diretor, novo);
}

void set_genero(Filme* f, char* novo){
  strcpy(f->genero, novo);
}

void set_ano(Filme* f, int novo){
  f->ano = novo;
}

void set_faixaetaria(Filme* f, int novo){
  f->idade = novo;
}
