#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char titulo[40];
	char autor[15];
	int prateleira;
	int ano;
}tlivro;

int qtd=0;

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
			printf("\nBusca realizada com sucesso :)");
		}else{
			printf("Nao foram encontrados livros :(");
		}
	}
}

void salvaArquivo(tlivro l[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosLivros.txt","wb");
	fwrite(&l[i],sizeof(tlivro),qtd,arq);
	printf("\nDados salvos com sucesso\n");
	fclose(arq);
}
//SALVAR ARQUIVOS

void carregaArquivo(tlivro l[]){
	FILE *arq;
	arq=fopen("dadosLivros.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n");
	  return;
	}// fim if
	while(fread(&l[qtd],sizeof(tlivro),1,arq) >0 )
		qtd++;  
	printf("Dados carregados com sucesso...\n");
	fclose(arq);
}
//CARREGAR ARQUIVOS

void removeAluno(tlivro l[],char tituloBusca[100]){
	int posicao=0;
	int res=0;
	
	posicao = buscaTitulo(l,tituloBusca);
	
	if(posicao==-1)
		printf("Livro nao encontrada...\n");
	
	printf("Deseja remover o livro?\n[1]-Sim\n[2]-Nao\n\nResposta: ");
	scanf("%d",&res);
	
	if(res==1){
		l[posicao] = l[qtd-1]; //sobrepondo com a ultima banda;
		printf("\nLivro removido com sucesso :)\n");
		qtd--;
	}else{
		printf("\nOperacao cancelada... \n");
	}
}
//REMOVER BANDA

void principal(tlivro livros[]){
	int op,anoBusca,start;
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
						getch();
						system("cls");
						printf("Titulo para busca: ");
						fflush(stdin);
						gets(tituloBusca);
						strupr(tituloBusca);
						printf("\n");
						if(buscaTitulo(livros,tituloBusca)==-1)
							printf("Livro nao encontrado :(");
						else
							printf("\nBusca realizada com sucesso :)\n");
						}
					break;
				case 3:;
					if(qtd==0){
						printf("\nNao existem livros cadastrados :(\nCadastre um livro antes de listar...\n\n");
						printf("\nPressione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("*** Lista de Livros ***\n\n");
						listaLivro(livros);
						printf("\nLivros listados com sucesso :)");}
					break;
				case 4:	
					if(qtd==0){
						printf("\nNao existem livros cadastrados :(\nCadastre um livro antes de filtrar por ano...\n\n");
						printf("\nPressione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("Ano minimo: ");
						scanf("%d",&anoBusca);
						printf("\n");
						anoRecente(livros,anoBusca);
					}
					break;
				case 5: 
					if(qtd==0){
							printf("\nNao existem livros cadastrados :(\nCadastre um livro antes de filtrar por ano...\n\n");
							printf("\nPressione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("Titulo para remover: ");
						fflush(stdin);
						gets(tituloBusca);
						strupr(tituloBusca);
						removeAluno(livros,tituloBusca);
					}
					break;
				case 6:
					printf("\n");
					salvaArquivo(livros);
					break;
				case 0:
					salvaArquivo(livros);
					printf("\n\nSaindo...");
					break;
				default:
					printf("Opcao invalida :(");
			}
			getch();
			system("cls");
		}while(op!=0);
}
//Codigo Principal

int menuOp(){
	int op;
	
	printf("*** Sistema de Livros ***\n");
	printf("[1]- Cadastrar novo livro\n");
	printf("[2]- Buscar por titulo\n");
	printf("[3]- Listar livros\n");
	printf("[4]- Buscar por ano\n");
	printf("[5]- Remover livro\n");
	printf("[6]- Salvar dados\n");
	printf("[0]- Sair\n");
	
	printf("\nEntre com sua escolha: ");
	scanf("%d",&op);
	
	return op;
}


