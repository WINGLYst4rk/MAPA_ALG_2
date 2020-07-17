// arquivo para resolver o problema proposto para a matéria de algoritmos e logiga de programação 2
//link para o repositorio no Github: https://github.com/WINGLYst4rk/MAPA_ALG_2
//@author: Wingly Silva Rodrigues
//RA: 20038441-5

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
	int area;
	int ano;
	int edicao;
	int caixa;
}CadastroObras;

//prototipação das funções
void cadastrarObras(CadastroObras obras[MAX]);
void ListarTodasObras(CadastroObras obras[MAX]);
void ListarObrasCaixa(CadastoObras obras[MAX]);
void ListarTodasRevistas(CadastroObras obras[MAX]);
void ListarTodosLivros(CadastroObras obras[MAX]);
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
int main
{
	CadastroObras obras[MAX];
	setlocale(LC_ALL, "");
	
	int op, buscaLivro, buscaCaixa;
	do{
		identificacao();
		printf("\n1 - Cadastrar obras:");
		printf("\n2 - Listar todos os Livros:");
		printf("\n3 - Listar todos os livros:");
		printf("\n4 - Listar obras por caixa:");
		printf("\n0 - Sair: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				cadastrarObras(obras);
				break;
			case 2:
				ListarTodosLivros(obras);
				printf("\n");
				system("pause");
				break;
			case 3:
				ListarTodasRevistas(obras);
				printf("\n");
				system("pause");
				break;
			case 4:
				ListarObrasCaixa(obras);
				printf("\n");
				system("pause");
				break;
			case 0:
				printf("Saindo do sistema!");
				printf("\n Obrigado!!!");
				system("pause");
				break;
			default:
				printf("Opção não identificada");
				system("pause");
				break;
		}
	}while(op != 0);
	return(0);
}

//função para cadstro de obras
void cadastrarObras(CadstroObras obras[MAX])
{
	identificacao();
	int i, es;
	FILE * arq;
	
	arq = fopen("arquivo.txt", "a+");// função responsavel por abrir ou criar o arquivo para armazenar os dados
	
	if(arq != NULL)
	{
		printf("Digite [1] Livro [2] Revista: ");
		scanf("%d", &es);
		switch(es){// Usando switch case para fazer a decisão entre cadastrar livro ou revista
			case 1:
				for(i = 0; i < 2; i++){
					printf("Informe os dados do livro:");
					printf("\n Digite o Título do livro: ");
					fflush(stdiin);
					gets(obras[i].titulo);
					printf("\n Digite o Autor do Livro: ");
					fflush(stdin);
					gets(obras[i].autor);
					printf("\n Digite a Área do Livro: ");
					fflush(stdin);
					gets(obras[i].area);
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
					fwrite(&obras[i], sizeof(CadastroObras), 1, arq);	
					
				}
				fclose(arq);
			case 2:
				for(i = 0; i < 2; i++){
					printf("Informe os dados da revista:");
					printf("\n Digite o Título da Revista: ");
					fflush(stdiin);
					gets(obras[i].titulo);
					printf("\n Digite o Autor da Revista: ");
					fflush(stdin);
					gets(obras[i].autor);
					printf("\n Digite a Área da Revista: ");
					fflush(stdin);
					gets(obras[i].area);
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
