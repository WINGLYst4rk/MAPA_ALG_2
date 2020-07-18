// arquivo para resolver o problema proposto para a matéria de algoritmos e logiga de programação 2
//link para o repositorio no Github: https://github.com/WINGLYst4rk/MAPA_ALG_2
//@author: Wingly Silva Rodrigues
//RA: 20038441-5
//Uso ideal do console ao executar: 164 largura X 32 Altura.

//incialização das bibliotecas necessarias para a criação do código a ser desenvolvido.
#include <stdio.h>
#include <locale.h>
#define MAX 100
#include <stdlib.h>

//declaração do struct
typedef struct cadastro
{
	char titulo[50];
	char autor[30];
	char editora[30];
	int quantidade;
	char isbn[30];
	char issn[30];
	int ano;
	int edicao;
	int caixa;
	int RouL;// responsável por separar livro de revista
}CadastroObras;

//prototipação das funções
void cadastrarObras(CadastroObras obras[MAX]);
void ListarTodasObras(CadastroObras obras[MAX]);
void ListarObrasCaixa(int buscaCaixa, CadastroObras obras[MAX]);
void ListarTodasRevistas(int buscaCategoria, CadastroObras obras[MAX]);
void ListarTodosLivros(int buscaCategoria, CadastroObras obras[MAX]);
int registrador(CadastroObras obras[MAX]);

// função para identificação
void identificacao(){
	system("cls");
	int t;
	for(t = 0; t < 80; t++) printf("-");
	printf("\n >>>>> WINGLY SILVA RODRIGUES <<<<<");
	printf("\n >>>>> RA: 20038441-5 <<<<<");
	printf("\n >>>>> Engenharia de Software <<<<<");
	for(t = 0; t < 80; t++) printf("-");
}

//função principal
int main()
{
	CadastroObras obras[MAX];
	setlocale(LC_ALL, "");
	
	int op, buscaCategoria, buscaCaixa;
	do{
		identificacao();
		printf("\n1 - Cadastrar obras:");
		printf("\n2 - Listar todos os Livros:");
		printf("\n3 - Listar todas as Revistas:");
		printf("\n4 - Listar obras por caixa:");
		printf("\n5 - Listar Todas as Obras:");
		printf("\n0 - Sair: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				cadastrarObras(obras);
				break;
			case 2:
				printf("Digite [1] para listar todos os livros: ");
				fflush(stdin);
				scanf("%d", &buscaCategoria);
				ListarTodosLivros(buscaCategoria, obras);
				printf("\n");
				system("pause");
				break;
			case 3:
				printf("Digite [2] para listar todas as revistas: ");
				fflush(stdin);
				scanf("%d", &buscaCategoria);
				ListarTodasRevistas(buscaCategoria, obras);
				printf("\n");
				system("pause");
				break;
			case 4:
				printf("Digite a caixa para pesquisar: ");
				fflush(stdin);
				scanf("%d", &buscaCaixa);
				ListarObrasCaixa(buscaCaixa, obras);
				printf("\n");
				system("pause");
				break;
			case 5:
				ListarTodasObras(obras);
				printf("\n");
				system("pause");
				break;
			case 0:
				printf("Saindo do sistema!\n");
				printf("\n Obrigado!!!\n");
				system("pause");
				break;
			default:
				printf("Opção não identificada\n");
				system("pause");
				break;
		}
	}while(op != 0);
	return(0);
}

//função para cadstro de obras
void cadastrarObras(CadastroObras obras[MAX])
{
	identificacao();
	int i, es;
	FILE * arq;
	
	arq = fopen("arquivo.txt", "a+");// função responsavel por abrir ou criar o arquivo para armazenar os dados
	
	if(arq != NULL)
	{
		printf("\n Digite [1] Livro [2] Revista: ");
		scanf("%d", &es);
		switch(es){// Usando switch case para fazer a decisão entre cadastrar livro ou revista
			case 1:
				for(i = 0; i < 2; i++){
					printf("Informe os dados do livro:");
					printf("\n Digite o Título do livro: ");
					fflush(stdin);
					gets(obras[i].titulo);
					printf("\n Digite o Autor do Livro: ");
					fflush(stdin);
					gets(obras[i].autor);
					printf("\n Digite a Área do Livro: ");
					fflush(stdin);
					gets(obras[i].isbn);
					printf("\n Digite a Quantidade de Livros: ");
					fflush(stdin);
					scanf("%d", &obras[i].quantidade);
					printf("\n Digite o Ano do livro: ");
					fflush(stdin);
					scanf("%d", &obras[i].ano);
					printf("\n Digite a edição do Livro: ");
					fflush(stdin);
					scanf("%d", &obras[i].edicao);
					printf("\n Digite a Editora: ");
					fflush(stdin);
					gets(obras[i].editora);
					printf("\n Informe a Caixa onde o livro está armazenado: ");
					scanf("%d", &obras[i].caixa);
					printf("\n Digite [1] para confirmar: ");
					scanf("%d", &obras[i].RouL);
					fwrite(&obras[i], sizeof(CadastroObras), 1, arq);	
					
				}
				fclose(arq);
			case 2:
				for(i = 0; i < 2; i++){
					printf("Informe os dados da revista:");
					printf("\n Digite o Título da Revista: ");
					fflush(stdin);
					gets(obras[i].titulo);
					printf("\n Digite o Autor da Revista: ");
					fflush(stdin);
					gets(obras[i].autor);
					printf("\n Digite a Área da Revista: ");
					fflush(stdin);
					gets(obras[i].issn);
					printf("\n Digite a Quantidade de Revistas: ");
					fflush(stdin);
					scanf("%d", &obras[i].quantidade);
					printf("\n Digite o Ano da Revista: ");
					fflush(stdin);
					scanf("%d", &obras[i].ano);
					printf("\n Digite a edição da Revista: ");
					fflush(stdin);
					scanf("%d", &obras[i].edicao);
					printf("\n Digite a Editora: ");
					fflush(stdin);
					gets(obras[i].editora);
					printf("\n Informe a Caixa onde a Revista está armazenada: ");
					scanf("%d", &obras[i].caixa);
					printf("\n Digite [2] para confirmar: ");
					fflush(stdin);
					scanf("%d", &obras[i].RouL);
					fwrite(&obras[i], sizeof(CadastroObras), 1, arq);	
				}
				fclose(arq);
			default:// usando o default para evitar repetição.
				for(i = 0; i < 2; i++){
					printf("Informe os dados do livro:");
					printf("\n Digite o Título do livro: ");
					fflush(stdin);
					gets(obras[i].titulo);
					printf("\n Digite o Autor do Livro: ");
					fflush(stdin);
					gets(obras[i].autor);
					printf("\n Digite a Área do Livro: ");
					fflush(stdin);
					gets(obras[i].isbn);
					printf("\n Digite a Quantidade de Livros: ");
					fflush(stdin);
					scanf("%d", &obras[i].quantidade);
					printf("\n Digite o Ano do livro: ");
					fflush(stdin);
					scanf("%d", &obras[i].ano);
					printf("\n Digite a edição do Livro: ");
					fflush(stdin);
					scanf("%d", &obras[i].edicao);
					printf("\n Digite a Editora: ");
					fflush(stdin);
					gets(obras[i].editora);
					printf("\n Informe a Caixa onde o livro está armazenado: ");
					scanf("%d", &obras[i].caixa);
					printf("\n Digite [1] para confirmar: ");
					scanf("%d", &obras[i].RouL);
					fwrite(&obras[i], sizeof(CadastroObras), 1, arq);
				}
				fclose(arq);
		}
	}
	else
	{
		printf("\nNão foi possível abrir o arquivo!");
		exit(1);
	}
}

//função para registrar os dados cadastrados
int registrador(CadastroObras obras[MAX])
{
	FILE * arq = fopen("arquivo.txt", "r");// abrindo o arquivo em forma de leitura
	if(arq != NULL)
	{
		int contador = 0;
		while(1)// usando while para percorrer o arquivo e caso não tiver mais registro termina o laço
		{
			CadastroObras ob;// registro temporario de dados
			
			//usando fread para ler e armazenar os dados na variável "registro"
			int registro = fread(&ob, sizeof(CadastroObras), 1, arq);
			
			//caso seja retornado 0 o laço termina e paramos de ler o arquivo
			if(registro < 1)
				break;
			else
				obras[contador] = ob;// armazenando o registro lido no vetor de obras
			contador++;
		}
		fclose(arq);
		return contador;
	}
	else
	{
		printf("\nNão foi possível abrir o arquivo!");
		exit(1);
	}
}

//função para buscar todas obras
void ListarTodasObras(CadastroObras obras[MAX])
{
	identificacao();
	
	int quantidadeObras = registrador(obras);
	int i;
	
	printf("\n>>>> Lista de obras <<<< %d\n", quantidadeObras);
	
	printf("ITEM \t| TÍTULO \t\t| AUTOR \t\t| ISBN\t\t| ISSN\t\t| QUANTIDADE \t| ANO \t| EDIÇÃO \t| EDITORA \t\t| CAIXA");
	for(i = 0; i < quantidadeObras; i++)
	{
		printf("\n %d", i);
		printf("\%d \t| %s \t\t| %s \t\t| %s \t\t| %s\t\t| %d \t| %d \t| %d \t| %s \t\t| %d", i + 1, obras[i].titulo, obras[i].autor, obras[i].isbn,obras[i].issn, obras[i].quantidade, obras[i].ano, obras[i].edicao, obras[i].editora, obras[i].caixa);
	}
}

//função de buscar livro
void ListarTodosLivros(int buscaCategoria, CadastroObras obras[MAX])
{
	identificacao();
	
	int quantidadeObras = registrador(obras);
	int i;
	
	printf("\n>>>> Lista de Livros <<<<\n");
	if(buscaCategoria == 1){
		printf("Mostrando todos os livros\n");
	}else if(buscaCategoria == 2){
		printf("Mostrando todas as revistas\n");
	}else{
		printf("Não existe essa categoria\n");
	}
	
	printf("ITEM \t| TÍTULO \t\t| AUTOR \t\t| ISBN \t\t| QUANTIDADE \t| ANO \t| EDIÇÃO \t| EDITORA \t\t| CAIXA");
	for(i = 0; i < quantidadeObras; i++)
	{
		if(obras[i].RouL == buscaCategoria){
			printf("\%d \t| %s \t\t| %s \t\t| %s \t\t| %d \t| %d \t| %d \t| %s \t\t| %d", i + 1, obras[i].titulo, obras[i].autor, obras[i].isbn, obras[i].quantidade, obras[i].ano, obras[i].edicao, obras[i].editora, obras[i].caixa);
		}
	}
}

//função de buscar revista
void ListarTodasRevistas(int buscaCategoria, CadastroObras obras[MAX])
{
		identificacao();
	
	int quantidadeObras = registrador(obras);
	int i;
	
	printf("\n>>>> Lista de Livros <<<<\n");
	if(buscaCategoria == 1){
		printf("Mostrando todos os livros\n");
	}else if(buscaCategoria == 2){
		printf("Mostrando todas as revistas\n");
	}else{
		printf("Não existe essa categoria\n");
	}
	
	printf("ITEM \t| TÍTULO \t\t| AUTOR \t\t| ISSN \t\t| QUANTIDADE \t| ANO \t| EDIÇÃO \t| EDITORA \t\t| CAIXA");
	for(i = 0; i < quantidadeObras; i++)
	{
		if(obras[i].RouL == buscaCategoria){
			printf("\%d \t| %s \t\t| %s \t\t| %s \t\t| %d \t| %d \t| %d \t| %s \t\t| %d", i + 1, obras[i].titulo, obras[i].autor, obras[i].issn, obras[i].quantidade, obras[i].ano, obras[i].edicao, obras[i].editora, obras[i].caixa);
		}
	}
}

//função para listar todas as obras por caixa
void ListarObrasCaixa(int buscaCaixa, CadastroObras obras[MAX])
{
	int quantidadeObras = registrador(obras);
	int i;
	
	printf("\n>>>> Lista de livro por caixa <<<< \n");
	printf("Caixa pesquisada: %d \n", buscaCaixa);
	
		printf("ITEM \t| TÍTULO \t\t| AUTOR \t\t| ISBN \t\t| QUANTIDADE \t| ANO \t| EDIÇÃO \t| EDITORA \t\t| CAIXA");
	for(i = 0; i < quantidadeObras; i++)
	{
		if(obras[i].caixa == buscaCaixa){
			printf("\%d \t| %s \t\t| %s \t\t| %s \t\t| %d \t| %d \t| %d \t| %s \t\t| %d", i + 1, obras[i].titulo, obras[i].autor, obras[i].isbn, obras[i].quantidade, obras[i].ano, obras[i].edicao, obras[i].editora, obras[i].caixa);
		}
	}
}
