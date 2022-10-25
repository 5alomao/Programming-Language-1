#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qtd=0;

typedef struct{
	char titulo[30];
	char console[15];
	int ranking;
}tjogo;

typedef struct{
	char nome[30];
	char data[10];
	int emprestado; 
}emp;


void cadastraJogo(tjogo j[]){
	
	
	printf("Titulo do jogo: ");
	fflush(stdin);
	gets(j[qtd].titulo);

	printf("Console: ");
	fflush(stdin);
	gets(j[qtd].console);
	
	printf("Ranking: ");
	scanf("%d",&j[qtd].ranking);

	printf("--------------------\n\nJogo cadastrado com sucesso :)");
	
	qtd++;
}

void emprestaJogo(tjogo j[], emp e[], char buscaTitulo[30]){
	int i;
	char tituloAux[30];

	for(i=0;i<qtd;i++){
	strcpy(tituloAux,j[i].titulo);
	strupr(tituloAux);
	
		if(strcmp(buscaTitulo,tituloAux)==0){
			printf("Nome: ");
			fflush(stdin);
			gets(e[qtd].nome);

			printf("Data: ");
			fflush(stdin);
			gets(e[qtd].data);

			e[i].emprestado=1;
		}
	}
}

void devolveJogo(tjogo j[], emp e[], char buscaTitulo[30]){
	int i;
	char tituloAux[30];

	for(i=0;i<qtd;i++){
		strcpy(tituloAux,j[i].titulo);
		strupr(tituloAux);
		if(strcmp(buscaTitulo,tituloAux)==0){
			e[i].emprestado=0;
		}
	}
}


int tituloBusca(tjogo j[],emp e[], char buscaTitulo[30]){

	int i;
	char tituloAux[30];

	for(i=0;i<qtd;i++){
		if(e[i].emprestado==0){
		strcpy(tituloAux,j[i].titulo);
		strupr(tituloAux);
		if(strcmp(buscaTitulo,tituloAux)==0){
			printf("** Jogo [%d] **\n",i+1);
			printf("Titulo: %s\n",j[i].titulo);
			printf("Console: %s\n",j[i].console);
			printf("Ranking: %d\n",j[i].ranking);
			printf("Emprestado: N\n");
			printf("--------------------\n\n");
			return i;
		}
	}else if(e[i].emprestado==1){
		strcpy(tituloAux,j[i].titulo);
		strupr(tituloAux);
		if(strcmp(buscaTitulo,tituloAux)==0){
			printf("** Jogo [%d] **\n",i+1);
			printf("Titulo: %s\n",j[i].titulo);
			printf("Console: %s\n",j[i].console);
			printf("Ranking: %d\n",j[i].ranking);
			printf("Emprestado: S\n");
			printf("--------------------\n\n");
			return i;
		}
	}
	}
	return -1;
}


int consoleBusca(tjogo j[], emp e[], char buscaConsole[30]){

	int i;
	char consoleAux[30];

	for(i=0;i<qtd;i++){
		if(e[i].emprestado==0){
		strcpy(consoleAux,j[i].console);
		strupr(consoleAux);
		if(strcmp(buscaConsole,consoleAux)==0){
			printf("** Jogo [%d] **\n",i+1);
			printf("Titulo: %s\n",j[i].titulo);
			printf("Console: %s\n",j[i].console);
			printf("Ranking: %d\n",j[i].ranking);
			printf("Emprestado: N\n");
			printf("--------------------\n\n");
			return i;
		}
	}else if(e[i].emprestado==1){
		if(strcmp(buscaConsole,consoleAux)==0){
			printf("** Jogo [%d] **\n",i+1);
			printf("Titulo: %s\n",j[i].titulo);
			printf("Console: %s\n",j[i].console);
			printf("Ranking: %d\n",j[i].ranking);
			printf("Emprestado: S\n");
			printf("--------------------\n\n");
			return i;
		}
	}
	}
	return -1;
}

void listaJogos(tjogo j[]){
	int i;
	
	for(i=0;i<qtd;i++){
			printf("** Jogo [%d] **\n",i+1);
			printf("Titulo: %s\n",j[i].titulo);
			printf("Console: %s\n",j[i].console);
			printf("Ranking: %d\n",j[i].ranking);
			printf("Emprestado: N\n");
			printf("--------------------\n\n");
	
		}
}


void salvaArquivo(tjogo j[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosJogos.txt","wb");
	fwrite(&j[i],sizeof(tjogo),qtd,arq);
	printf("\nDados salvos com sucesso...\n");
	fclose(arq);
}
//SALVAR ARQUIVOS

void carregaArquivo(tjogo j[]){
	FILE *arq;
	arq=fopen("dadosJogos.txt","rb");
	if(arq==NULL){
	  printf("\nArquivo nao encontrado :(\n\nCadastre um aluno e salve para gerar o arquivo :)");
	  return;
	  }// fim if
	 while(fread(&j[qtd],sizeof(tjogo),1,arq) >0 )
	      qtd++;  
	 printf("\nDados carregados com sucesso...\n");
	fclose(arq);
}

void principal(tjogo jogos[]){
	int op;
	char buscaTitulo[30];
	char buscaConsole[15];
	emp emprestados[100];
	
	do{
		op=menuOp();

		switch(op){
			case 1:
				printf("\n");
				cadastraJogo(jogos);
				break;
				
			case 2:
				if(qtd==0){
					printf("\nNao existem jogos cadastrados :(\nCadastre um jogo antes de listar...\n\n");
					printf("\nPressione qualquer tecla para prosseguir...");
				}else{
					getch();
					system("cls");
					printf("*** Lista de Jogos  ***\n\n");
					listaJogos(jogos);}
				break;
				
			case 3:
				if(qtd==0){
					printf("\nNao existem jogos cadastrados :(\nCadastre um jogo antes de buscar por titulo...\n\n");
					printf("\nPressione qualquer tecla para prosseguir...");
				}else{
					printf("\nInsira o titulo: ");
					fflush(stdin);
					gets(buscaTitulo);
					strupr(buscaTitulo);
					printf("\n");
					tituloBusca(jogos,emprestados,buscaTitulo);}
				break;
				
			case 4:
				if(qtd==0){
					printf("\nNao existem jogos cadastrados :(\nCadastre um jogo antes de buscar por console...\n\n");
					printf("\nPressione qualquer tecla para prosseguir...");
				}else{
					printf("\nInsira o console: ");
					fflush(stdin);
					gets(buscaConsole);
					strupr(buscaConsole);
					printf("\n");
					consoleBusca(jogos,emprestados,buscaConsole);}
				break;
				
			case 5:
				if(qtd==0){
					printf("\nNao existem jogos cadastrados :(\nCadastre um jogo antes de emprestar...\n\n");
					printf("\nPressione qualquer tecla para prosseguir...");
				}else{
				printf("\nInsira o titulo: ");
				fflush(stdin);
				gets(buscaTitulo);
				strupr(buscaTitulo);
				printf("\n");
				emprestaJogo(jogos,emprestados,buscaTitulo);}
				break;
		
			case 6:
				if(qtd==0){
					printf("\nNao existem jogos cadastrados :(\nCadastre um jogo antes e o empreste antes de devolver...\n\n");
					printf("\nPressione qualquer tecla para prosseguir...");
				}else{
				printf("\nInsira o titulo: ");
				fflush(stdin);
				gets(buscaTitulo);
				strupr(buscaTitulo);
				printf("\n");
				devolveJogo(jogos,emprestados,buscaTitulo);}
				break;
			case 7:
				salvaArquivo(jogos);
				break;
			case 0:
				salvaArquivo(jogos);
				printf("\nSaindo...");
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

	printf("*** Sistema de Jogos ***\n");
	printf("[1]- Cadastrar novo jogo\n");
	printf("[2]- Listar jogos\n");
	printf("[3]- Buscar jogo por titulo\n");
	printf("[4]- Buscar jogos por console\n");
	printf("[5]- Emprestar jogo\n");
	printf("[6]- Devolver jogo\n");
	printf("[7]- Salvar dados\n");
	printf("[0]- Sair\n");
	
	printf("\n\nEntre com sua escolha: ");
	scanf("%d",&op);

	return op;
}
