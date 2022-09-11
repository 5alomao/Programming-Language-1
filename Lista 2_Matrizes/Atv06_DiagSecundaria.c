#include <stdlib.h>
#include <stdio.h>
#include "matrizLib.h"

int main(){
	
	int i, j, ord, mat[100][100], soma=0;
	
	printf("Entre com a ordem da Matriz: ");
	scanf("%d",&ord);
	
	geraMatrix(mat,ord,ord);
	printf("\n*** Matrix ***");
	printMatrix(mat,ord,ord);
	
	printf("\n\n*** Diagonal Secundaria ***\n");
	
	j=ord-1;
	for(i=0;i<ord;i++){
		printf(" %d |",mat[i][j]);
		soma+=mat[i][j];
		j--;
	}
	
	printf("\n");
	printf("Soma Diagonal Secundaria: %d",soma);
	
	return 0;
}
