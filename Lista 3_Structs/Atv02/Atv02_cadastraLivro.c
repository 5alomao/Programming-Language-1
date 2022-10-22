#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Atv02Lib.h"
int main(){
	
	tlivro livros[100];
	
	printf("=-=-= Iniciando Sistema de Livros =-=-=\n\n");
	printf("Deseja carregar os dados salvos?\n[0]-Nao\n[1]-Sim\n\nResposta: ");
	scanf("%d",&start);printf("\n");
	
	if(start==1){
		carregaArquivo(livros);
		printf("\nPrecione qualquer tecla para prosseguir...");
		getch();
		system("cls");
		principal(livros);
	}else if(start==0){
		printf("Precione qualquer tecla para prosseguir...");
		getch();
		system("cls");
		principal(livros);
	}else{
		printf("Opcao invalida :(");
	}
}
