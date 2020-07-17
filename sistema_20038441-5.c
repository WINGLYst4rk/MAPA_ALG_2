// arquivo para resolver o problema proposto para a matï¿½ria de algoritmos e logiga de programaï¿½ï¿½o 2
//incializaï¿½ï¿½o das bibliotecas necessarias para a criaï¿½ï¿½o do cï¿½digo a ser desenvolvido.
//@author: Wingly Silva Rodrigues
//RA: 20038441-5


#include <stdio.h>
#include <locale.h>
#define MAXI 100
#include <stdlib.h>


//declaraï¿½ï¿½o do struct
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

//função com a indentificação
void identificacao(){
	system("cls");
	int t;
	for(t = 0; t < 80; t++) printf("-");
	printf("\n >>>>> WINGLY SILVA RODRIGUES <<<<<");
	printf("\n >>>>> RA: 20038441-5 <<<<<");
	printf("\n >>>>> Engenharia de Software <<<<< \n");
	for(t = 0; t < 80; t++) printf("-");
}

//função para cadastrar livros

void CadastrarObras(CadastroObras obras[MAXI]){
	system("cls");
	identificacao();
	int i;
	FILE *arq;
	
	arq = fopen("arquivo.txt", "a+");
	
	if(arq != NULL)
	{
		for(i = 0; i < 2; i++){
			printf("\n Informe o Título do livro: ");
			fflush(stdin);
			gets(obras[i].titulo);
			printf("\n Informe o autor do livro: ");
			fflush(stdin);
			gets(obras[i].autor);
			printf("\n Informe a ediï¿½ï¿½o:");
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
		printf("\n O arquino não pode ser aberto.");
		exit(1);
	}
}

//função responsavel pelo registo 
int Registro(CadastroObras obras[MAXI])
{
	FILE * arq = fopen("arquivo.txt", "r");
	if(arq != NULL)
	{
		int contador = 0;
		while(1)//irá percorrer todo o arquivo e quando não encontrar mais registros, o laço termina
		{
			CadastroObras ob;//criando um registro temporário
		
			//leitura de registro por registro, ou seja, pega um registro
			int registro = fread(&ob, sizeof(CadastroObras), 1, arq);
			
			//se a leitura do registro retornar 0, siginifica que a próxima posição do arquivo é zero ai saimos do laço
			if(registro < 1)
				break;
			else
				obras[contador] = ob;//pega registro lido e colocar vetor de registro
			contador++;
		}
		fclose(arq); // fecha o arquivo
		return contador;//retorna a quantidade de registros que há no arquivo
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}
//função para listar todas as obras
void ListarTodasObras(CadastroObras obras[MAXI]){	
	identificacao();
	
	int quantidadeobras = Registro(obras);
	int i;
	
	printf("\n>>>> Lista de produtos <<<< %d\n", quantidadeobras);
	
	printf("ITEM \t| DESCRIÇÃO \t\t| QUANTIDADE \t| CATEGORIA \t | LOTE");
	for(i = 0; i < quantidadeobras; i++)
	{
		printf("\n %d", i);
		printf("\n%s \t| %d  \t \t| %d \t\t | %d \t\t | %d", i+1, obras[i].titulo, obras[i].quantidade, obras[i].ano, obras[i].caixa);	
	}
}

//função listar por caixa


//função principal
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
		printf("\n Digite sua opção: ");
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
			printf("Opção não existente!");
			break;
	}
	}while(op != 0);
	return(0);
	
}
