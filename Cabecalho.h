//Protótipos de funções, tipos de ponteiros e dados globalmente acessíveis)

//Arquivo de cabeçalho.h para o módulo de funções Videoteca
//Todas as funções devem ser implementadas independente se vão ser utilizadas ou não

//estrutura para um Filme
typedef struct filme Filme;

//estrutura para informações a respeito do filme
typedef struct info Info;

//Função que cria e retorna um ponteiro simples para o tipo Filme
Filme* criar_filme();

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

//menu principal
void menu(void);

//menu secundário da opção 2
void subMenu(void);

void printf_tabela(Filme** tabela, int tam);
