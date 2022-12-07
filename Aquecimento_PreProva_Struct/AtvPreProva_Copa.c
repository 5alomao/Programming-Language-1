#include <stdio.h>
#include <string.h>

typedef struct
{
	int dia,mes,ano;
}tData;

typedef struct
{ // nao alterar o struct
	int id;
	tData data;
	char nomeTime1[40];
	char nomeTime2[40];
	int golsTime1;
	int golsTime2;
	int golsPenaltiTime1;
	int golsPenaltiTime2;
	char vencedor[40];
}tCopa;

int qtd=0;
//----------------------------
void cadastra(tCopa copa[])
{
    printf("Oitavas de final\n");
    copa[qtd].id = qtd + 1;
    printf("Jogo ID: %d\n",copa[qtd].id);
    
    printf("Data do jogo DD MM AA:");
    scanf("%d%d%d", &copa[qtd].data.dia, &copa[qtd].data.mes, &copa[qtd].data.ano);

    printf("Nome do time 1:");
    fflush(stdin);
    gets(copa[qtd].nomeTime1);
    
    printf("Nome do time 2:");
    fflush(stdin);
    gets(copa[qtd].nomeTime2);
    
    printf("Gols do time 1:");
	scanf("%d", &copa[qtd].golsTime1);
	
	printf("Gols do time 2:");
	scanf("%d", &copa[qtd].golsTime2);
	
	if(copa[qtd].golsTime1 > copa[qtd].golsTime2)
	{
		strcpy(copa[qtd].vencedor, copa[qtd].nomeTime1);
	}
	else if (copa[qtd].golsTime2 > copa[qtd].golsTime1)
	{
		strcpy(copa[qtd].vencedor, copa[qtd].nomeTime2);
	} 
	else
	{
		printf("Gols de penalti do time 1:");
		scanf("%d", &copa[qtd].golsPenaltiTime1);
		
		printf("Gols de penalti do  time 2:");
		scanf("%d", &copa[qtd].golsPenaltiTime2);
		
		if(copa[qtd].golsPenaltiTime1 > copa[qtd].golsPenaltiTime2)
		{
			strcpy(copa[qtd].vencedor, copa[qtd].nomeTime1);
		}
		else
		{
			strcpy(copa[qtd].vencedor, copa[qtd].nomeTime2);
		}
	} 
    qtd++;
}

//-----------------------------

void listaJogos(tCopa copa[])
{
	int i;
	printf("\n\n*** OITAVAS DE FINAL - FIFA WORLD CUP QATAR 2022 *** \n\n");
	for(i = 0; i < qtd; i++)
	{
		printf("Jogo ID: %d\n", copa[i].id);
		printf("Data do jogo: %d/%d/%d\n", copa[i].data.dia, copa[i].data.mes, copa[i].data.ano);
		printf("Nome do time 1: %s\n", copa[i].nomeTime1);
		printf("Nome do time 2: %s\n", copa[i].nomeTime2);
		printf("Gols do time 1: %d\n", copa[i].golsTime1);
		printf("Gols do time 2: %d\n", copa[i].golsTime2);
		
		if(copa[i].golsTime1 == copa[i].golsTime2)
		{
			printf("Gols de penalti do time 1: %d\n", copa[i].golsPenaltiTime1);
			printf("Gols de penalti do time 2: %d\n", copa[i].golsPenaltiTime2);
		}
		printf("Vencedor: %s\n", copa[i].vencedor);
		printf("-------------------------------------------------------\n\n");
	}
}

//-----------------------------

void buscaNome(tCopa copa[], char nomeBusca[]){
	char nomeAux1[40], nomeAux2[40];
	int res = 0;
	
	for(int i = 0; i < qtd; i++) 
	{
		strcpy(nomeAux1, copa[i].nomeTime1);
		strcpy(nomeAux2, copa[i].nomeTime2);
		strupr(nomeAux1);
		strupr(nomeAux2);
		
		if(strcmp(nomeAux1, nomeBusca) == 0)
		{
			res = 1;
			printf("Jogo ID: %d\n", copa[i].id);
			printf("Data do jogo: %d/%d/%d\n", copa[i].data.dia, copa[i].data.mes, copa[i].data.ano);
			printf("Nome do time 1: %s\n", copa[i].nomeTime1);
			printf("Nome do time 2: %s\n", copa[i].nomeTime2);
			printf("Gols do time 1: %d\n", copa[i].golsTime1);
			printf("Gols do time 2: %d\n", copa[i].golsTime2);
			
			if(copa[i].golsTime1 == copa[i].golsTime2)
			{
				printf("Gols de penalti do time 1: %d\n", copa[i].golsPenaltiTime1);
				printf("Gols de penalti do time 2: %d\n", copa[i].golsPenaltiTime2);
			}
			printf("Vencedor: %s\n", copa[i].vencedor);
			printf("-------------------------------------------------------\n\n");
		}
		else if(strcmp(nomeAux2, nomeBusca) == 0)
		{
			res = 1;
			printf("Jogo ID: %d\n", copa[i].id);
			printf("Data do jogo: %d/%d/%d\n", copa[i].data.dia, copa[i].data.mes, copa[i].data.ano);
			printf("Nome do time 1: %s\n", copa[i].nomeTime1);
			printf("Nome do time 2: %s\n", copa[i].nomeTime2);
			printf("Gols do time 1: %d\n", copa[i].golsTime1);
			printf("Gols do time 2: %d\n", copa[i].golsTime2);
			
			if(copa[i].golsTime1 == copa[i].golsTime2)
			{
				printf("Gols de penalti do time 1: %d\n", copa[i].golsPenaltiTime1);
				printf("Gols de penalti do time 2: %d\n", copa[i].golsPenaltiTime2);
			}
			printf("Vencedor: %s\n", copa[i].vencedor);
			printf("-------------------------------------------------------\n\n");
		}
	}
	
	if(res == 0)
	{
		printf("\nTime nao encontrado! :(\n");
	}
}// fim funcao

//-----------------------------

void buscaData(tCopa copa[], tData d){
	
	int res = 0;
	
	for(int i = 0; i < qtd; i++)
	{
		if(copa[i].data.dia == d.dia && copa[i].data.mes == d.mes && copa[i].data.ano == d.ano)
		{
			printf("Jogo ID: %d\n", copa[i].id);
			printf("Data do jogo: %d/%d/%d\n", copa[i].data.dia, copa[i].data.mes, copa[i].data.ano);
			printf("Nome do time 1: %s\n", copa[i].nomeTime1);
			printf("Nome do time 2: %s\n", copa[i].nomeTime2);
			printf("Gols do time 1: %d\n", copa[i].golsTime1);
			printf("Gols do time 2: %d\n", copa[i].golsTime2);
			
			if(copa[i].golsTime1 == copa[i].golsTime2)
			{
				printf("Gols de penalti do time 1: %d\n", copa[i].golsPenaltiTime1);
				printf("Gols de penalti do time 2: %d\n", copa[i].golsPenaltiTime2);
			}
			printf("Vencedor: %s\n", copa[i].vencedor);
			printf("-------------------------------------------------------\n\n");
			res = 1;
		}
	}
	
	if(res == 0)
	{
		printf("Nao ha jogos nessa data!");
	}
	
}// fim funcao

//-----------------------------

void jogosQuarta(tCopa copa[])
{	
	int jg = 1;
	printf("\n\n*** OITAVAS DE FINAL - FIFA WORLD CUP QATAR 2022 *** \n\n");
	
	for(int i = 0; i < qtd; i += 2)
	{
		printf("Jogo %d: %s x %s\n", jg, copa[i].vencedor, copa[i + 1].vencedor);
		jg++;
	}
}

//-----------------------------

void salvaArquivoBinario(tCopa copa[]){
	FILE *arq;
	int i;
	arq=fopen("copa.dat","wb");
	fwrite(&copa[0],sizeof(tCopa),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//-----------------------------
void carregaBinario(tCopa copa[]){
	FILE *arq;
	arq=fopen("copa.dat","rb");
	if(arq==NULL)
	  printf("Arquivo nao encontrado!\n");
	else{
	 while(    fread(&copa[qtd],sizeof(tCopa),1,arq) >0     )
	     qtd++;  
	 printf("Dados carregados com sucesso!\n");
	}
	fclose(arq);
}
//----------------------------
int menu(){
	int op;
	printf("\t\t**** FIFA WORLD CUP QATAR 2022 ****\n\n");
	printf("1 - Informar jogo\n");
	printf("2 - Listar jogos\n");
	printf("3 - Apresentar todos jogos de uma data\n");
	printf("4 - Quartas de finais\n");
	printf("5 - Buscar por nome do time\n");
	printf("0 - Sair\n");
	printf("Digite sua opcao:"); 
	scanf("%d",&op);
	return op;
}
//-----------------------------
int main()
{
	tCopa copa[100];
	int op;
	char nomeBusca[40];
	tData d;
	carregaBinario(copa);
	do
	{
		op = menu();
		switch(op)
		{
			case 1: 
				cadastra(copa);
				break;
		   case 2: 
		   		listaJogos(copa);
		    	break;
		   case 3:
		   		printf("Insira a data do jogo para busca:");
		   		scanf("%d%d%d", &d.dia, &d.mes, &d.ano);
		   		buscaData(copa, d);
		   		printf("\n");
		     	break; 
		   case 4:
		   		jogosQuarta(copa);
		   		break;
		   case 5:
		   		printf("Entre com o nome do time: ");
		   		fflush(stdin);
		   		gets(nomeBusca);
		   		strupr(nomeBusca);
		   		buscaNome(copa, nomeBusca);
		     	break;
		   case 0: printf("Saindo ... \n");
		   			salvaArquivoBinario(copa);
		    break;
		   default:printf("Opcao invalida\n"); 	 	
		}// fim switch
		getch(); // pausa
		system("cls"); // limpa a tela
	}while(op!=0);
}// fim main

