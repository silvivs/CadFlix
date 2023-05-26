# CadFlix
Sistema de Cadastro de Filmes - Algoritmo e Estrutura de Dados I - ES - IComp - UFA


INSTRUÇÕES DO TRABALHO 2 - AED1
JOHNATAS PHILIPE RODRIGUES DA SILVA
THALLYSON GONZAGA BLANCO PARDO

CADASTRO DE FILMES
Algoritmos e estruturas de dados 1 - 13/10/2021

Neste trabalho prático seu objetivo é realizar operações de cadastro e
exclusão de títulos na sua loja online de filmes para consolidar os
conceitos de Ponteiros, Estruturas, Operações com vetores, vetores de
caracteres e Alocação dinâmica de memória.

--- Regras Gerais
O trabalho deve ser implementado usando o conceito de TAD. Deverão ser
entregue 3 arquivos para avaliação:
● Cabecalho.h (Protótipos de funções, tipos de ponteiros e dados
globalmente acessíveis)
● Funcoes.c (Declaração dos seus tipos de dados, implementação das
funções do seu programa encapsuladas linkadas com seu
Cabecalho.h)
● Main.c
● A submissão deve ser realizada pelo Colabweb, enviando um único
arquivo .zip identificado com o nome completo do aluno(a).
● Deve ser utilizado obrigatoriamente um vetor de ponteiros para
structs, de forma a criar a tabela de cadastros dos filmes sem
ocupar memória desnecessariamente no arquivo Main.c.
● Data de entrega 20/10/2021
Entradas
● A Primeira entrada consiste em um inteiro N indicando o tamanho
da sua tabela de filmes.
● As estradas sucessivas serão os filmes cadastrados como mostra a
figura (Título, preço, gênero, faixa etária, ano e diretor). Atenção: a
quantidade de filmes cadastrados não pode ser maior que N.

--- Operações
● Deve ser exibido um menu textual com o seguinte conjunto de
operações: CADASTRAR UM NOVO TÍTULO, ATUALIZAR INFO DE UM
TÍTULO, EXCLUIR UM TÍTULO e FINALIZAR OPERAÇÃO, como
mostra a figura.
● O administrador da loja pode escolher qualquer uma dessas
entradas para realizar uma alteração.

--- Restrições de cadastro
● Filmes do gênero Terror não podem ter faixa etária abaixo de 18. Ao
invés de finalizar a operação, ao entrar com um valor inválido,
mostre uma mensagem de erro e ofereça a opção de entrar com um
valor diferente. Esta restrição é válida para a opção de CADASTRAR
UM NOVO TITULO.
Obs.: Note que um filme pode ter mais de um gênero (Ex.:
Suspense/Drama/Terror; Comédia/Ficção). Seu programa deve ser capaz
de identificar qual filme possui a classificação “Terror” independente da
quantidade de gêneros atribuídos.

--- Atualizações dos cadastros
● Ao ATUALIZAR INFO DE UM TÍTULO deverá ser mostrado um
submenu com as opções de RENOMEAR TÍTULO, ATUALIZAR PREÇO
e ATUALIZAR GÊNERO.
● Ao RENOMEAR TÍTULO obrigatoriamente se deverá RENOMEAR
DIRETOR.

Obs.: Note que ao oferecer a opção de CADASTRAR UM NOVO TÍTULO o
tamanho da sua tabela irá aumentar dinamicamente. A operação será
realizada quantas vezes se desejar.

Obs.: Ao excluir um título sua tabela deve ser reorganizada para evitar
“buracos”.

--- Saídas
Ao fim de cada operação a tabela atualizada dos filmes deverá ser
impressa, seguida do menu de opções.
● O programa termina quando a operação de FINALIZAR for escolhida.

--- Estrutura
● Seu código deve estar documentado ( //comentários que descrevem
as funcionalidade de cada função ).
● Use as estruturas abaixo fornecidas:

typedef struct info {
  char diretor[101]; //101 caracteres + 1 para fim de string
  char genero[51]; //50 caracteres + 1 para fim de string
  int ano;
	int faixaEtaria; // Use 0 para classificação livre
} Info;

typedef struct filme{
   char nome[101]; //100 caracteres + 1 para fim de string
   float preco; // Até duas casas decimais
   Info* informações; // Ponteiro para struct Info
} Filme;

● Segue a função de impressão usada nas imagens demonstrativas.
Reutilize-a.

// Função que imprime a tabela atualizada dos filmes cadastrados
// código -- preço R$ ## nome (gênero, faixa etária) ## diretor ano
// 0001 -- 25.50 R$ ## The Godfather Part II (Crime/Drama, 16) ## Francis Ford
Coppola 1974

void print_tabela(Filme** tabela, int tam){
  printf("-------------TABELA DE FILMES-------------\n\n");
  for(int i = 0; i < tam; i++){
    printf("%.4d -- ",i+1); //código de 4 caracteres
    imprimir_filme(tabela[i]);
    }
  menu();
}

● Protótipos das funções para o arquivo de cabeçalho
//Arquivo de cabeçalho.h para o módulo de funções Videoteca
//Todas as funções devem ser implementadas independente se vão ser utilizadas
ou não

//estrutura para um Filme
typedef struct filme Filme;

//Função que cria e retorna um ponteiro simples para o tipo Filme
Filme* criar_filme;

//Função que exclui um filme e libera memória
void free_filme(Filme* f);

//função que imprime informações de um filme
void imprimir_filme(Filme* f);

//FUNÇÕES DE MANIPULAÇÃO
//função que acessa e modifica o nome de um filme
void set_nome(Filme* f, char* novo);

//função que acessa e modifica o preço de um filme
void set_preco(Filme* f, float novo);

//função que acessa e renomeia um diretor de um filme
void set_diretor(Filme* f, char* novo);

//função que acessa e renomeia os gêneros de um filme
void set_genero(Filme* f, char* novo);

//função que acessa e modifica o ano de um filme
void set_ano(Filme* f, int novo);

//função que acessa e modifica a faixa etária de um filme
void set_faixaetaria(Filme* f, int novo);
