#include <stdlib.h>
#include "matrizLib.h"

void main(){
	
	int mat[100][100], mat2[100][100], mult[100][100];
	int lin,cols,i,j,aux;
	
	printf("Linhas e Colunas da Matriz: \n");
	scanf("%d%d",&lin,&cols);
	geraMatrix(mat, lin, cols);
	printf("\nMatriz 1:");
	printMatrix(mat, lin, cols);
	printf("\n");
	
	
	geraMatrix(mat2, cols, lin);
	printf("\nMatriz 2:");
	printMatrix(mat2, cols, lin);
	printf("\n");
	
	printf("\nMatriz multiplicada:");

	for(i=0;i<lin;i++){
		for(j=0;j<cols;j++){
				mult[i][j]+=mat[i][j]*mat2[j][i];
		}
	}
	for(i=0;i<lin;i++){
		printf("\n");
		for(j=0;j<cols;j++){
			printf("%3d ",mult[i][j]);
		}
	}
return 0;
}
