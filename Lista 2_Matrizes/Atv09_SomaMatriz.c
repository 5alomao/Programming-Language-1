#include <stdlib.h>
#include <stdio.h>
#include "matrizLib.h"

int main(){
	
	int ord, mat[100][100],mat2[100][100], lin,cols,i,j,lin2,cols2;
	
	printf("Linhas e Colunas Matriz 1: ");
	scanf("%d%d",&lin,&cols);
	geraMatrix(mat,lin,cols);
	
	printf("Linhas e Colunas Matriz 2: ");
	scanf("%d%d",&lin2,&cols2);
	geraMatrix(mat2,lin2,cols2);
	
	printf("\nMatriz 1");
	printMatrix(mat,lin,cols);
	
	printf("\n\nMatriz 2");
	printMatrix(mat2,lin2,cols2);
	
	if(lin==lin2 && cols==cols2){
		printf("\n\nSoma Matriz");
		somaMat(mat,mat2,lin,cols);}
	else
		printf("\n\nPossuem ordem diferente...");
			
	return 0;
}
