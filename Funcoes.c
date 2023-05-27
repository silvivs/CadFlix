#include "Cabecalho.h"
#include <stdio.h>
#include <stdlib.h>

struct filme {
  char nome[81];
  float preco = 0.0;
  char diretor[81];
  int ano = 0;
  char genero[81];
  int idade = 0;
};

Filme* criar_filme() {
  Filme* f = (Filme*) malloc(sizeof(FIlme));

  if(f == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }

}

void free_filme(Filme* f) {
  free(f);
}

void imprimir_filme(Filme* f) {
  printf("Nome: %s\n", f.nome);
  printf("Preço: %.2f\n", f.preco):
  printf("Diretor: %s\n", f.diretor);
  printf("Ano: %d\n", f.ano);
  printf("Gênero: %s\n", f.genero);
  printf("Faixa etária: %d\n", f.idade);
}
