#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char titulo[40];
	char autor[15];
	int prateleira;
	int ano;
}tlivro;
qtd=0;

void addLivro(tlivro l[]){
	printf("\nTitulo: ");
	fflush(stdin);
	gets(l[qtd].titulo);
	printf("Autor: ");
	fflush(stdin);
	gets(l[qtd].autor);
	printf("Prateleira: ");
	scanf("%d",&l[qtd].prateleira);
	printf("Ano: ");
	scanf("%d",&l[qtd].ano);
	qtd++;
}

int buscaTitulo(tlivro l[], char tituloBusca[40]){
	
	int i;
	char tituloAux[40];
	
	for(i=0;i<qtd;i++){
		strcpy(tituloAux,l[i].titulo);
		strupr(tituloAux);
		if(strcmp(tituloBusca,tituloAux)==0){
			printf("*** Livro %d ***\n",i+1);
			printf("Titulo: %s\n",l[i].titulo);
			printf("Prateleira: %d\n",l[i].prateleira);
			printf("---------------------\n");
			return i;			
		}
	}
	return -1;
}

void listaLivro(tlivro l[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("*** Livro %d ***\n",i+1);
		printf("Titulo: %s\n",l[i].titulo);
		printf("Autor: %s\n",l[i].autor);
		printf("Prateleira: %d\n",l[i].prateleira);
		printf("Ano: %d\n",l[i].ano);
		printf("-------------------------\n");
	}
}

void anoRecente(tlivro l[], int anoBusca){
	
	int i;
	
	for(i=0;i<qtd;i++){
		if(anoBusca<l[i].ano){
			printf("*** Livro %d ***\n",i+1);
			printf("Titulo: %s\n",l[i].titulo);
			printf("Autor: %s\n",l[i].autor);
			printf("Prateleira: %d\n",l[i].prateleira);
			printf("Ano: %d\n",l[i].ano);
			printf("-------------------------\n");	
		}
	}
}
int menuOp(){
	int op;
	
	printf("*** Sistema de Livros ***\n");
	printf("[1]-Cadastrar novo livro\n");
	printf("[2]-Buscar por titulo\n");
	printf("[3]-Listar livros\n");
	printf("[4]-Buscar por ano\n");
	printf("[0]-Sair\n");
	
	printf("\nEntre com sua escolha: ");
	scanf("%d",&op);
	
	return op;
}


