// arquivo para resolver o problema proposto para a mat�ria de algoritmos e logiga de programa��o 2
//incializa��o das bibliotecas necessarias para a cria��o do c�digo a ser desenvolvido.
//@author: Wingly Silva Rodrigues
//RA: 20038441-5


#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define MAX 100

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
void indentificacao(){
	system("cls");
	int t;
	for(t = 0; t < 80; t++) printf("-");
	printf("\n >>>>> WINGLY SILVA RODRIGUES <<<<<");
	printf("\n >>>>> RA: 20038441-5 <<<<<");
	printf("\n >>>>> Engenharia de Software <<<<< \n");
	for(t = 0; t < 80; t++) printf("-");
}

//fun��o para cadastrar livros

void CadastrarObras(CadastroObras obras[MAX]){
	indentificacao();
	int i;
	FILE *arq;
	
	arq = fopen("arquivo.txt", "a");
	
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
			
			
		}
	}
}

//fun��o principal
int main(){
	setlocale(LC_ALL,"");
	indentificacao();
	CadastrarObras("teste");
}



