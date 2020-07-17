// arquivo para resolver o problema proposto para a mat�ria de algoritmos e logiga de programa��o 2
//incializa��o das bibliotecas necessarias para a cria��o do c�digo a ser desenvolvido.
//@author: Wingly Silva Rodrigues
//RA: 20038441-5


#include <stdio.h>
#include <locale.h>
#define MAXI 100
#include <stdlib.h>


//declara��o do struct
typedef struct cadastro
{
	char titulo[50];
	char autor[30];
	char editora[30];
	int quantidade;
	int ano;
	int edicao;
	char isbn[40];
	int caixa;
}CadastroObras;

//fun��o com a indentifica��o
void identificacao(){
	system("cls");
	int t;
	for(t = 0; t < 80; t++) printf("-");
	printf("\n >>>>> WINGLY SILVA RODRIGUES <<<<<");
	printf("\n >>>>> RA: 20038441-5 <<<<<");
	printf("\n >>>>> Engenharia de Software <<<<< \n");
	for(t = 0; t < 80; t++) printf("-");
}

//fun��o para cadastrar livros

void CadastrarObras(CadastroObras obras[MAXI]){
	system("cls");
	identificacao();
	int i;
	FILE *arq;
	
	arq = fopen("arquivo.txt", "a+");
	
	if(arq != NULL)
	{
		for(i = 0; i < 2; i++){
			printf("\n Informe o T�tulo do livro: ");
			fflush(stdin);
			gets(obras[i].titulo);
			printf("\n Informe o autor do livro: ");
			fflush(stdin);
			gets(obras[i].autor);
			printf("\n Informe a edi��o:");
			fflush(stdin);
			scanf("%d", &obras[i].edicao);
			printf("\n Digite o ISBN do livro: ");
			fflush(stdin);
			gets(obras[i].isbn);
			printf("\n Informe a editora: ");
			fflush(stdin);
			gets(obras[i].editora);
			printf("\n Informe o ano do livro: ");
			fflush(stdin);
			scanf("%d", &obras[i].ano);
			printf("\n Informe a quantidade de livros: ");
			fflush(stdin);
			scanf("%d", &obras[i].quantidade);
			printf("\n Informe a caixa para amarzenar o livro: ");
			fflush(stdin);
			scanf("%d", &obras[i].caixa);
			fwrite(&obras[i], sizeof(CadastroObras), 1, arq);
			
		}fclose(arq);
	}else{
		printf("\n O arquino n�o pode ser aberto.");
		exit(1);
	}
}

//fun��o responsavel pelo registo 
int Registro(CadastroObras obras[MAXI])
{
	FILE * arq = fopen("arquivo.txt", "r");
	if(arq != NULL)
	{
		int contador = 0;
		while(1)//ir� percorrer todo o arquivo e quando n�o encontrar mais registros, o la�o termina
		{
			CadastroObras ob;//criando um registro tempor�rio
		
			//leitura de registro por registro, ou seja, pega um registro
			int registro = fread(&ob, sizeof(CadastroObras), 1, arq);
			
			//se a leitura do registro retornar 0, siginifica que a pr�xima posi��o do arquivo � zero ai saimos do la�o
			if(registro < 1)
				break;
			else
				obras[contador] = ob;//pega registro lido e colocar vetor de registro
			contador++;
		}
		fclose(arq); // fecha o arquivo
		return contador;//retorna a quantidade de registros que h� no arquivo
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}
//fun��o para listar todas as obras
void ListarTodasObras(CadastroObras obras[MAXI]){	
	identificacao();
	
	int quantidadeobras = Registro(obras);
	int i;
	
	printf("\n>>>> Lista de produtos <<<< %d\n", quantidadeobras);
	
	printf("ITEM \t| DESCRI��O \t\t| QUANTIDADE \t| CATEGORIA \t | LOTE");
	for(i = 0; i < quantidadeobras; i++)
	{
		printf("\n %d", i);
		printf("\n%s \t| %d  \t \t| %d \t\t | %d \t\t | %d", i+1, obras[i].titulo, obras[i].quantidade, obras[i].ano, obras[i].caixa);	
	}
}

//fun��o listar por caixa


//fun��o principal
int main(){
	CadastroObras obras[MAXI];
	setlocale(LC_ALL,"");
	identificacao();
	
	int op;
	
	do{
		
		printf("\n 1 - Cadastrar obras: ");
		printf("\n 2 - Listar todas as obras por caixa: ");
		printf("\n 3 - Listar todas as revistas: ");
		printf("\n 4 - Listar todas os livros: ");
		printf("\n 0 - Sair: ");
		printf("\n Digite sua op��o: ");
		scanf("%d", &op);
	
	switch(op)
	{
		case 1:
			CadastrarObras(obras);
			break;
		case 2:
			ListarTodasObras(obras);
			printf("\n");
			system("pause");
			break;
		case 3:
			printf("teste");
			break;
		default:
			printf("Op��o n�o existente!");
			break;
	}
	}while(op != 0);
	return(0);
	
}
