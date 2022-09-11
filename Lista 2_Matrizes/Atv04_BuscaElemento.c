#include <stdlib.h>
#include <stdio.h>
#include "matrizLib.h"

int main(){
	
	int lin, cols, mat[100][100], busca;
	
	
	printf("Qntd de lin e cols: ");
	scanf("%d%d",&lin, &cols);
	
	geraMatrix(mat,lin,cols);
	
	printf("\n*** Matrix ***");
	printMatrix(mat,lin,cols);
	
	buscaMatrix(mat,lin,cols);
	
	return 0;
}
