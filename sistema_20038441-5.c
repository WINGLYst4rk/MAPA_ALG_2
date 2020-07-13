/* arquivo para resolver o problema proposto para a matéria de algoritmos e logiga de programação 2
incialização das bibliotecas necessarias para a criação do código a ser desenvolvido.
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
		printf("3 - Pesquisar livros por código\n");
		printf("4 - Ordenar os livros por ano\n");
		printf("5 - Sair\n");
		printf("Digite a opção desejada: ");
		scanf("%d", &op);
		fflush (stdin);
		if (op == 1){
			system("cls");
			for (i=0; i<TAM; i++){
				printf("Digite o código do livro da posição %d:", i+1);
				scanf("%d", &ficha[i].codigo);
				fflush(stdin);
				printf("Digite o título do livro: ");
				scanf("%50[^\n]s", &ficha[i].codigo);
				fflush(stdin);
				printf("Digite o nome do autor: ");
				scanf("%30[^\n]s", &ficha[i].autor);
				fflush(stdin);
				printf("Digite a área do livro: ");
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
