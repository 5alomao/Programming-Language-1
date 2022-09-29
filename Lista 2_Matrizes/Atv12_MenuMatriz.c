#include <stdlib.h>
#include <stdio.h>
#include "matrizLib.h"

void main(){

	float mat[100][100], mat2[100][100], mat3[100][100], cons; 
	int op=1, ord,i,j;
	
	printf("Insira a ordem das matrizes: ");
	scanf("%d", &ord);
	
	printf("\nMatriz 1:");
	geraMatrixf(mat, ord, ord);
	printMatrixf(mat,ord,ord);
	printf("\n\nMatriz 2:");
	geraMatrixf(mat2, ord, ord);
	printMatrixf(mat2,ord,ord);
	
	while(op!=0){
		printf("\n\nEscolha uma opcao: \n");
		printf("1- Somar Matrizes\n2- Subtrair Matrizes\n3- Adicionar Constante\n4- Mostrar Matrizes\n0- Sair");
		printf("\n\nInsira sua Opcao: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\nMatriz somada:");
				mat3[i][j]=somaMatf(mat, mat2, ord, ord);
				printMatrixf(mat3, ord, ord);
				break;
			case 2:
				printf("\nMatriz subtraida:");
				mat3[i][j]=subtMatf(mat, mat2, ord, ord);
				printMatrixf(mat3, ord, ord);
				break;
			case 3:
				printf("Insira a constante: ");
				scanf("%f", &cons);
				for(i=0;i<ord;i++){
					for(j=0;j<ord;j++){
						mat[i][j]+=cons;
						mat2[i][j]+=cons;
					}
				}
				printf("Constante adicionada com sucesso :)\n");
				break;
			case 4:
				printf("\nMatriz 1:");
				printMatrixf(mat, ord, ord);
				printf("\n");
				printf("\nMatriz 2:");
				printMatrixf(mat2, ord, ord);
				break;
				
			case 0:
				printf("Saindo...");
				break;
			default:
				printf("Opcao invalida :(");	
		}
	}
return 0;
}
