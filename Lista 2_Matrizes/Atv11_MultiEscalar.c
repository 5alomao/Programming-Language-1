#include <stdio.h>
#include "matrizLib.h"

int main(){
	
	int mat[100][100],ord,mult;
	
	printf("Entre com a ordem da matriz: ");
	scanf("%d",&ord);
	
	geraMatrix(mat,ord,ord);
	printMatrix(mat,ord,ord);
	
	
	printf("\n\nMultiplicador escalar: ");
	scanf("%d",&mult);
	
	multEscalar(mat,ord,mult);
	
	printf("\nMatriz Multiplicada:\n");
	printMatrix(mat,ord,ord);
	
	return 0;
}
