#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Atv02Lib.h"
int main(){
	
	tlivro livros[100];
	int op,anoBusca;
	char tituloBusca[40];
	

	
	do{
		op=menuOp();
		switch(op){
			case 1:
				addLivro(livros);
				printf("\nCadastro realizado com sucesso :)");
				break;
			case 2:
				if(qtd==0){
					printf("\nNao existem livros cadastrados :(\nCadastre um livro antes de buscar por titulo...\n\n");
					printf("\nPressione qualquer tecla para prosseguir...");
				}else{
				printf("\nTitulo para busca: ");
				fflush(stdin);
				gets(tituloBusca);
				strupr(tituloBusca);
				printf("\n");
				buscaTitulo(livros,tituloBusca);
				printf("\nBusca realizada com sucesso :)");}
				break;
			case 3:;
				if(qtd==0){
					printf("\nNao existem livros cadastrados :(\nCadastre um livro antes de listar...\n\n");
					printf("\nPressione qualquer tecla para prosseguir...");
				}else{
				printf("\n");
				listaLivro(livros);
				printf("\nLivros listados com sucesso :)");}
				break;
			case 4:
				if(qtd==0){
					printf("\nNao existem livros cadastrados :(\nCadastre um livro antes de filtrar por ano...\n\n");
					printf("\nPressione qualquer tecla para prosseguir...");
				}else{
				printf("\nAno minimo: ");
				scanf("%d",&anoBusca);
				printf("\n");
				anoRecente(livros,anoBusca);
				printf("\nBusca realizada com sucesso :)");}
				break;
			case 0:
				printf("\n\nSaindo...");
				break;
			default:
				printf("Opcao invalida :(");
		}
		getch();
		system("cls");
	}while(op!=0);
	return 0;
}
