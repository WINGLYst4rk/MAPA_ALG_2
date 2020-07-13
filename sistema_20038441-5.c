/* arquivo para resolver o problema proposto para a mat�ria de algoritmos e logiga de programa��o 2
incializa��o das bibliotecas necessarias para a cria��o do c�digo a ser desenvolvido.
@author: Wingly Silva Rodrigues
RA: 20038441-5
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM 20

struct livro{
	int codigo;
	char titulo[50];
	char autor[30];
	char area[30];
	int ano;
	char editora[30];
};

int main() {
	setlocale(LC_ALL,"");
	struct livro ficha[TAM];
	struct livro troca;
	int busca, i, j, acha, op;
	
	op = 0;
	while (op != 5) {
		printf("1 - Cadastrar os livros\n");
		printf("2 - Imprimir os livros cadastrados\n");
		printf("3 - Pesquisar livros por c�digo\n");
		printf("4 - Ordenar os livros por ano\n");
		printf("5 - Sair\n");
		printf("Digite a op��o desejada: ");
		scanf("%d", &op);
		fflush (stdin);
		if (op == 1){
			system("cls");
			for (i=0; i<TAM; i++){
				printf("Digite o c�digo do livro da posi��o %d:", i+1);
				scanf("%d", &ficha[i].codigo);
				fflush(stdin);
				printf("Digite o t�tulo do livro: ");
				scanf("%50[^\n]s", &ficha[i].codigo);
				fflush(stdin);
				printf("Digite o nome do autor: ");
				scanf("%30[^\n]s", &ficha[i].autor);
				fflush(stdin);
				printf("Digite a �rea do livro: ");
				scanf("%30[^\n]s", &ficha[i].area);
				fflush(stdin);
				printf("Digite o ano: ");
				scanf("%d", &ficha[i].ano);
				fflush(stdin);
				printf("Digite o nome da editora: ");
				scanf("%30[^\n]s", &ficha[i].editora);
				fflush(stdin);
			}
		}
		else{
			if (op == 2){
				system("cls");
				for (i=0; i<TAM; i++){
					
				}
			}			
		}
	}
	
}
