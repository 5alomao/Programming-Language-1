#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	
	char nome[40];
	char genero[40];
	int integrantes;
	int ranking;
	
}tbanda;
//CRIANDO VARIAVEIS DA STRUCT

int qtd=0; // controlar a posicao de cadastro no vetor

void addBanda(tbanda b[]){
	printf("Nome da banda: ");
	fflush(stdin); // limpa o buffer do teclado 
	gets(b[qtd].nome);
	printf("Genero da banda: ");
	fflush(stdin); // limpa o buffer do teclado 
	gets(b[qtd].genero);
	printf("Quantidade de Integrantes: ");
	scanf("%d",&b[qtd].integrantes);
	printf("Ranking da Banda: ");
	scanf("%d",&b[qtd].ranking);
	qtd++;
} 
//ADICIONAR BANDA

void listaBanda(tbanda b[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("*** Banda %d ***\n",i+1);
		printf("Nome da banda: %s\n",b[i].nome);
		printf("Genero da banda: %s\n",b[i].genero);
		printf("Quantidade de Integrantes: %d\n",b[i].integrantes);
		printf("Ranking da banda: %d\n",b[i].ranking);
		printf("-------------------------\n");
	}
}
//LISTAR BANDA

int filtraNome(tbanda b[], char nomeBusca[100]){
	int i;
	char nomeAux[100];

	for(i=0;i<qtd;i++){
		strcpy(nomeAux,b[i].nome);
		strupr(nomeAux);
		if(strcmp(nomeBusca,nomeAux)==0){
			printf("*** Banda %d ***\n",i+1);
			printf("Nome da banda: %s\n",b[i].nome);
			printf("Genero da banda: %s\n",b[i].genero);
			printf("Quantidade de Integrantes: %d\n",b[i].integrantes);
			printf("Ranking da banda: %d\n",b[i].ranking);
			printf("-------------------------\n");
			return i;	
		}
	}
	return -1;
}
//LISTAR BANDA

void removeBanda(tbanda b[],char nomeBusca[100]){
	int posicao=0;
	int res=0;
	
	posicao = filtraNome(b,nomeBusca);
	
	if(posicao==-1)
		printf("Banda nao encontrada...\n");
	
	printf("Deseja remover a banda ?\n[1]-Sim\n[2]-Nao\n\nResposta: ");
	scanf("%d",&res);
	
	if(res==1){
		b[posicao] = b[qtd-1]; //sobrepondo com a ultima banda;
		printf("\nBanda removida com sucesso :)\n");
		qtd--;
	}else{
		printf("\nOperacao cancelada... \n");
	}
}
//REMOVER BANDA

void filtraGenero(tbanda b[], char generoBusca[40]){
	int i;
	char generoAux[40];
	for(i=0;i<qtd;i++){
		strcpy(generoAux,b[i].genero);
		strupr(generoAux);
		if(strcmp(generoBusca,generoAux)==0){
			printf("*** Banda %d ***\n",i+1);
			printf("Nome da banda: %s\n",b[i].nome);
			printf("Genero da banda: %s\n",b[i].genero);
			printf("Quantidade de Integrantes: %d\n",b[i].integrantes);
			printf("Ranking da banda: %d\n",b[i].ranking);
			printf("-------------------------\n");
			printf("\nFiltro realizado com sucesso :)\n");
		}else{
			printf("Genero nao encontado :(");
		}
	}
}
//FILTRAR PRO GENERO

void buscaRanking(tbanda b[], int busca){
	int i;

	for(i=0;i<qtd;i++)
		if(busca==b[i].ranking){
			printf("*** Banda %d ***\n",i+1);
			printf("Nome da banda: %s\n",b[i].nome);
			printf("Genero da banda: %s\n",b[i].genero);
			printf("Quantidade de Integrantes: %d\n",b[i].integrantes);
			printf("Ranking da banda: %d\n",b[i].ranking);
			printf("-------------------------\n");
			printf("\nBusca realizada com sucesso :)\n");
		}else{
			printf("Ranking nao encontrado :(");
		}
}
//BUSCAR POR RANKING

void salvaArquivo(tbanda bandas[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosBandas.txt","wb");
	fwrite(&bandas[i],sizeof(tbanda),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//SALVAR ARQUIVOS

void carregaArquivo(tbanda bandas[]){
	FILE *arq;
	arq=fopen("dadosBandas.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n\nCadastre bandas e salve para gerar o arquivo :)\n");
	  return;
	}// fim if
	while(fread(&bandas[qtd],sizeof(tbanda),1,arq) >0 )
		qtd++;  
	printf("Dados carregados com sucesso...\n");
	fclose(arq);
}
//CARREGAR ARQUIVOS

void alteraDados(tbanda b[], char nomeBusca[100]){
	int i=0, alter;
	
	if(filtraNome(b,nomeBusca)==-1)
		printf("\nBanda nao encontrada :(\n");
	else{
		system("cls");
		i = filtraNome(b,nomeBusca);
		alter=menuAlter();
	
		if(alter==1){
			printf("\nEntre com o novo nome: ");
			fflush(stdin);
			gets(b[i].nome);
			printf("\nDado alterado com sucesso :)\n");
		}else if(alter==2){
			printf("\nEntre com o novo genero: ");
			fflush(stdin);
			gets(b[i].genero);
			printf("\nDado alterado com sucesso :)\n");
		}else if(alter==3){
			printf("\nEntre com a nova quantidade de integrantes: ");
			fflush(stdin);
			scanf("%d",&b[i].integrantes);
			printf("\nDado alterado com sucesso :)\n");
		}else if(alter==4){
			printf("\nEntre com o novo ranking da banda: ");
			scanf("%d",&b[i].ranking);
			printf("\nDado alterado com sucesso :)\n");
		}else{
			printf("\nOpcao invalida :(\n");
		}
	
	}
}

int menuAlter(){
	int op;
	printf("\nQual dado deseja alterar: \n");
	printf("[1]- Nome\n");
	printf("[2]- Genero\n");
	printf("[3]- Quantidade de integrantes\n");
	printf("[4]- Ranking\n");
	printf("\nEntre com sua escolha: ");
	scanf("%d",&op);
	return op;
}

void principal(tbanda bandas[]){
	int  op, rank;
	char genero[40],nome[100];
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
							printf("\nBusca realizada com sucesso :)\n");
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
}
//Codigo Principal
int menu(){
	int op;
	printf("*** Sistema de Bandas ***\n");
	printf("[1]- Inserir nova banda\n");
	printf("[2]- Listar bandas cadastradas\n");
	printf("[3]- Buscar bandas pelo ranking\n");
	printf("[4]- Filtrar bandas por generos \n");
	printf("[5]- Buscar bandas pelo nome\n");
	printf("[6]- Remover banda do sistema\n");
	printf("[7]- Alterar dados de um registro\n");
	printf("[8]- Salvar dados atuais\n");
	printf("[0]- Sair\n\n");
	
	printf("Entre com sua escolha: ");
	scanf("%d",&op);
	return op;
}
//MENU DE ESCOLHAS
