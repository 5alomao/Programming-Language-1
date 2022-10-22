#include <stdio.h>
#include <string.h>
#include "Atv01Lib.h"

int main(){
	tbanda bandas[100];
	int start;
	printf("=-=-= Iniciando Sistema de Bandas =-=-=\n\n");
	printf("Deseja carregar os dados salvos?\n[0]-Nao\n[1]-Sim\n\nResposta: ");
	scanf("%d",&start);printf("\n");
	if(start==1){
		carregaArquivo(bandas);
		printf("\nPrecione qualquer tecla para prosseguir...");
		getch();
		system("cls");
		principal(bandas);
	}else if(start==0){
		printf("Precione qualquer tecla para prosseguir...");
		getch();
		system("cls");
		principal(bandas);
	}else{
		printf("Opcao invalida :(");
	}
}
