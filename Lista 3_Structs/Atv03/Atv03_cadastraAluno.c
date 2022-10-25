#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Atv03Lib.h"

int main(){

	taluno alunos[100];
	int start;
	
	printf("*** Sistema de Alunos ***\n\n");
	printf("Deseja carregar arquivos salvos?\n[1]-Sim\n[0]-Nao\n\nResposta: ");
	scanf("%d",&start);
	
	if(start==1){
		carregaArquivo(alunos);
		getch();
		system("cls");
		principal(alunos);
	}else if(start == 0){
		getch();
		system("cls");
		principal(alunos);
	}else{
		printf("\nOpcao invalida :(");
	}
	return 0;
}
