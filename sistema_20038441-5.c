// arquivo para resolver o problema proposto para a matéria de algoritmos e logiga de programação 2
//incialização das bibliotecas necessarias para a criação do código a ser desenvolvido.
//@author: Wingly Silva Rodrigues
//RA: 20038441-5


#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define MAX 100

//declaração do struct
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
void indentificacao(){
	system("cls");
	int t;
	for(t = 0; t < 80; t++) printf("-");
	printf("\n >>>>> WINGLY SILVA RODRIGUES <<<<<");
	printf("\n >>>>> RA: 20038441-5 <<<<<");
	printf("\n >>>>> Engenharia de Software <<<<< \n");
	for(t = 0; t < 80; t++) printf("-");
}

//função para cadastrar livros

void CadastrarObras(CadastroObras obras[MAX]){
	indentificacao();
	int i;
	FILE *arq;
	
	arq = fopen("arquivo.txt", "a");
	
	if(arq != NULL)
	{
		for(i = 0; i < 2; i++){
			printf("\n Informe o Título do livro: ");
			fflush(stdin);
			gets(obras[i].titulo);
			printf("\n Informe o autor do livro: ");
			fflush(stdin);
			gets(obras[i].autor);
			printf("\n Informe a edição:");
			fflush(stdin);
			scanf("%d", &obras[i].edicao);
			printf("\n Digite o ISBN do livro: ");
			fflush(stdin);
			gets(obras[i].isbn);
			
			
		}
	}
}

//função principal
int main(){
	setlocale(LC_ALL,"");
	indentificacao();
	CadastrarObras("teste");
}



