// arquivo para resolver o problema proposto para a mat�ria de algoritmos e logiga de programa��o 2
//link para o repositorio no Github: https://github.com/WINGLYst4rk/MAPA_ALG_2
//@author: Wingly Silva Rodrigues
//RA: 20038441-5

//incializa��o das bibliotecas necessarias para a cria��o do c�digo a ser desenvolvido.
#include <stdio.h>
#include <locale.h>
#define MAX 100
#include <stdlib.h>

//declara��o do struct
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

//prototipa��o das fun��es
void cadastrarObras(CadastroObras obras[MAX]);
void ListarTodasObras(CadastroObras obras[MAX]);
void ListarObrasCaixa(CadastoObras obras[MAX]);
void ListarTodasRevistas(CadastroObras obras[MAX]);
void ListarTodosLivros(CadastroObras obras[MAX]);
int registrador(CadastroObras obras[MAX]);

// fun��o para identifica��o
void identificacao(){
	system("cls");
	int t;
	for(t = 0; t < 80; t++) printf("-");
	printf("\n >>>>> WINGLY SILVA RODRIGUES <<<<<");
	printf("\n >>>>> RA: 20038441-5 <<<<<");
	printf("\n >>>>> Engenharia de Software <<<<<");
	for(t = 0; t < 80; t++) printf("-");
}

//fun��o principal
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
				printf("Op��o n�o identificada");
				system("pause");
				break;
		}
	}while(op != 0);
	return(0);
}

//fun��o para cadstro de obras
void cadastrarObras(CadstroObras obras[MAX])
{
	identificacao();
	int i, es;
	FILE * arq;
	
	arq = fopen("arquivo.txt", "a+");// fun��o responsavel por abrir ou criar o arquivo para armazenar os dados
	
	if(arq != NULL)
	{
		printf("Digite [1] Livro [2] Revista: ");
		scanf("%d", &es);
		switch(es){// Usando switch case para fazer a decis�o entre cadastrar livro ou revista
			case 1:
				for(i = 0; i < 2; i++){
					printf("Informe os dados do livro:");
					printf("\n Digite o T�tulo do livro: ");
					fflush(stdiin);
					gets(obras[i].titulo);
					printf("\n Digite o Autor do Livro: ");
					fflush(stdin);
					gets(obras[i].autor);
					printf("\n Digite a �rea do Livro: ");
					fflush(stdin);
					gets(obras[i].area);
					printf("\n Digite a Quantidade de Livros: ");
					fflush(stdin);
					scanf("%d", &obras[i].quantidade);
					printf("\n Digite o Ano do livro: ");
					fflush(stdin);
					scanf("%d", &obras[i].ano);
					printf("\n Digite a edi��o do Livro: ");
					fflush(stdin);
					scanf("%d", &obras[i].edicao);
					printf("\n Digite a Editora: ");
					fflush(stdin);
					gets(obras[i].editora);
					printf("\n Informe a Caixa onde o livro est� armazenado: ");
					scanf("%d", &obras[i].caixa);
					fwrite(&obras[i], sizeof(CadastroObras), 1, arq);	
					
				}
				fclose(arq);
			case 2:
				for(i = 0; i < 2; i++){
					printf("Informe os dados da revista:");
					printf("\n Digite o T�tulo da Revista: ");
					fflush(stdiin);
					gets(obras[i].titulo);
					printf("\n Digite o Autor da Revista: ");
					fflush(stdin);
					gets(obras[i].autor);
					printf("\n Digite a �rea da Revista: ");
					fflush(stdin);
					gets(obras[i].area);
					printf("\n Digite a Quantidade de Revistas: ");
					fflush(stdin);
					scanf("%d", &obras[i].quantidade);
					printf("\n Digite o Ano da Revista: ");
					fflush(stdin);
					scanf("%d", &obras[i].ano);
					printf("\n Digite a edi��o da Revista: ");
					fflush(stdin);
					scanf("%d", &obras[i].edicao);
					printf("\n Digite a Editora: ");
					fflush(stdin);
					gets(obras[i].editora);
					printf("\n Informe a Caixa onde a Revista est� armazenada: ");
					scanf("%d", &obras[i].caixa);
					fwrite(&obras[i], sizeof(CadastroObras), 1, arq);	
				}
				fclose(arq);
		}
	}
	else
	{
		printf("\nN�o foi poss�vel abrir o arquivo!");
		exit(1);
	}
}

//fun��o para registrar os dados cadastrados
int registrador(CadastroObras obras[MAX])
{
	FILE * arq = fopen("arquivo.txt", "r");// abrindo o arquivo em forma de leitura
	if(arq != NULL)
	{
		int contador = 0;
		while(1)// usando while para percorrer o arquivo e caso n�o tiver mais registro termina o la�o
		{
			CadastroObras ob;// registro temporario de dados
			
			//usando fread para ler e armazenar os dados na vari�vel "registro"
			int registro = fread(&ob, sizeof(CadastroObras), 1, arq);
			
			//caso seja retornado 0 o la�o termina e paramos de ler o arquivo
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
		printf("\nN�o foi poss�vel abrir o arquivo!");
		exit(1);
	}
}
