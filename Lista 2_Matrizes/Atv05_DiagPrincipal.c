#include <stdlib.h>
#include <stdio.h>
#include "matrizLib.h"

int main(){
	
	int i, ord, mat[100][100], soma=0;
	
	
	printf("Entre com a ordem da Matriz: ");
	scanf("%d",&ord);
	
	geraMatrix(mat,ord,ord);
	
	printf("\n*** Matrix ***");
	printMatrix(mat,ord,ord);
	
	printf("\n\n*** Diagonal Principal ***\n");
	for(i=0;i<ord;i++){
		printf(" %d |",mat[i][i]);
		soma+=mat[i][i];
	}
	
	printf("\n");
	printf("Soma Diagonal Principal: %d\n",soma);
	
	return 0;
}
