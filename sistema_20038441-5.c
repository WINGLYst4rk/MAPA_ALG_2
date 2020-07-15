/* arquivo para resolver o problema proposto para a matéria de algoritmos e logiga de programação 2
incialização das bibliotecas necessarias para a criação do código a ser desenvolvido.
@author: Wingly Silva Rodrigues
RA: 20038441-5
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define max 100

//declaração do struct
typedef struct cadastro
{
	char descricao[50];
	int quantidade;
	int categoria;
	int lote;	
}CadastroLivro;

void indentificacao(){
	system("cls");
	int t;
	for(t=0; t<80; t++) printf("-");
	printf("\n >>>>> WINGLY SILVA RODRIGUES <<<<<");
	printf("\n >>>>> RA: 20038441-5 <<<<<");
	printf("\n >>>>> Engenharia de Software <<<<< \n");
	for(t=0; t<80; t++) printf("-");
}
//prototipação de funções


//função principal

int main()
{
	//Cadastrolivro livro[MAX];
	setlocale(LC_ALL, "");
	
	int op, buscaLote, buscaCategoria;
//	do{
		indentificacao();
		printf("\n1 - Cadastrar Livro");
		printf("\n2 - Cadastrar Revista");
		printf("\n3 - Listar todos os produtos");
		
	//}
}
