#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Atv05Lib.h"

int main(){

	tjogo jogos[100];
	int start;
	
	printf("*** Iniciando Sistema de Jogos ***\n\n");
	printf("Deseja carregar dados salvos ?\n[1]-Sim\n[0]-Nao\n\nResposta: ");
	scanf("%d",&start);
	
	if(start==1){
		carregaArquivo(jogos);
		getch();
		system("cls");
		principal(jogos);
	}else if(start==0){
		getch();
		system("cls");
		principal(jogos);
	}else{
		printf("Opcao invalida :(");
	}
		
}
