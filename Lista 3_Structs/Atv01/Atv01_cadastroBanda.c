#include <stdio.h>
#include <string.h>
#include "Atv01Lib.h"

int main(){
	tbanda bandas[100];
	int op,rank,start,nulo=0,dadoAlt;
	char genero[40],nome[100];
	
	printf("=-=-= Iniciando Sistema de Bandas =-=-=\n\n");
	printf("Deseja carregar os dados salvos?\n[0]-Nao\n[1]-Sim\n\nResposta: ");
	scanf("%d",&start);printf("\n");
	if(start==1){
		carregaArquivo(bandas);
		printf("\nPrecione qualquer tecla para prosseguir...");
		getch();
		system("cls");
		do{
			op=menu();
			printf("\n");
			switch(op){
				case 1:
					getch();
					system("cls");
					addBanda(bandas);
					printf("\nCadastro realizado com sucesso :)\n");
					break;
				case 2:
					if(qtd==0){
						printf("Nao existem bandas cadastradas :(\nCadestre uma banda antes de listar...\n\n");
						printf("\nPrecione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("*** Lista de Bandas ***\n\n");
						listaBanda(bandas);
						printf("\nBandas listadas com sucesso :)\n");}
					break;
				case 3:
					if(qtd==0){
						printf("Nao existem bandas cadastradas :(\nCadestre uma banda antes de buscar por ranking...\n\n");
						printf("\nPrecione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("Ranking para busca: ");
						scanf("%d",&rank);
						printf("\n");
						buscaRanking(bandas,rank);
						printf("\nBusca realizada com sucesso :)\n");
					}
					break;
				case 4:
					if(qtd==0){
						printf("Nao existem bandas cadastradas :(\nCadestre uma banda antes de filtrar por genero...\n\n");
						printf("\nPrecione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
							printf("Filtro Genero: ");
						fflush(stdin);
						gets(genero);
						strupr(genero);
						printf("\n");
						filtraGenero(bandas,genero);}
						printf("\nFiltro realizado com sucesso :)\n");
					break;
				case 5:
					if(qtd==0){
						printf("Nao existem bandas cadastradas :(\nCadestre uma banda antes de filtrar por nome...\n\n");
						printf("\nPrecione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("Filtro nome: ");
						fflush(stdin);
						gets(nome);
						strupr(nome);
						printf("\n");
						if(filtraNome(bandas,nome)==-1)
							printf("Banda nao encontrada :(\n");
						else
							printf("\nFiltro realizado com sucesso :)\n");
						}
					break;
				case 6:
					if(qtd==0){
						printf("Nao existem bandas cadastradas :(\nCadestre uma banda antes de remover...\n\n");
						printf("\nPrecione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("Nome da banda: ");
						fflush(stdin);
						gets(nome);
						strupr(nome);
						printf("\n");
						removeBanda(bandas,nome);}
					break;
				case 7:
					getch();
					system("cls");
					printf("Insira o nome da banda: ");
					fflush(stdin);
					gets(nome);
					strupr(nome);
					alteraDados(bandas,nome);
					break;
				case 8:
					salvaArquivo(bandas);
					printf("\n");
					break;
				case 0:
					salvaArquivo(bandas);
					printf("Saindo...\n");
					break;
				default: 
					printf("Opcao Invalida\n");
			}
			getch(); // pausa ...
			system("cls"); // limpa tela ... clear system;
		}while(op!=0);
	}else if(start==0){
		printf("\nPrecione qualquer tecla para prosseguir...");
		getch();
		system("cls");
		do{
			op=menu();
			printf("\n");
		
			switch(op){
				case 1:
					getch();
					system("cls");
					addBanda(bandas);
					printf("\nCadastro realizado com sucesso :)");
					break;
				case 2:
					if(qtd==0){
						printf("Nao existem bandas cadastradas :(\nCadestre uma banda antes de listar...\n\n");
						printf("\nPrecione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("*** Lista de Bandas ***\n\n");
						listaBanda(bandas);
						printf("\nBandas listadas com sucesso :)");}
					break;
				case 3:
					if(qtd==0){
						printf("Nao existem bandas cadastradas :(\nCadestre uma banda antes de buscar por ranking...\n\n");
						printf("\nPrecione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("Ranking para busca: ");
						scanf("%d",&rank);
						printf("\n");
						buscaRanking(bandas,rank);
						printf("\nBusca realizada com sucesso :)");}
					break;
				case 4:
					if(qtd==0){
						printf("Nao existem bandas cadastradas :(\nCadestre uma banda antes de filtrar por genero...\n\n");
						printf("\nPrecione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("Filtro Genero: ");
						fflush(stdin);
						gets(genero);
						strupr(genero);
						printf("\n");
						filtraGenero(bandas,genero);
						printf("\nFiltro realizado com sucesso :)");
					}
					break;
				case 5:
					if(qtd==0){
						printf("Nao existem bandas cadastradas :(\nCadestre uma banda antes de filtrar por nome...\n\n");
						printf("\nPrecione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("Filtro nome: ");
						fflush(stdin);
						gets(nome);
						strupr(nome);
						printf("\n");
						if(filtraNome(bandas,nome)==-1)
							printf("Banda nao encontrada :(");
						else
							printf("\nFiltro realizado com sucesso :)\n");
					}
					break;
				case 6:
					if(qtd==0){
						printf("Nao existem bandas cadastradas :(\nCadestre uma banda antes de remover...\n\n");
						printf("\nPrecione qualquer tecla para prosseguir...");
					}else{
						getch();
						system("cls");
						printf("Nome da banda: ");
						fflush(stdin);
						gets(nome);
						strupr(nome);
						printf("\n");
						removeBanda(bandas,nome);}
					break;
				case 7:
					getch();
					system("cls");
					printf("Insira o nome da banda: ");
					fflush(stdin);
					gets(nome);
					strupr(nome);
					alteraDados(bandas,nome);
					break;
				case 8:
					salvaArquivo(bandas);
					printf("\n");
					break;
				case 0:
					salvaArquivo(bandas);
					printf("Saindo...\n");
					break;
				default: 
					printf("Opcao Invalida\n");
				
			}
			getch(); // pausa ...
			system("cls"); // limpa tela ... clear system
		
		}while(op!=0);
	}else{
		printf("Opcao invalida :(");
	}
	return 0;
}
