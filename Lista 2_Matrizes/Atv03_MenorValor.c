#include <stdlib.h>
#include <stdio.h>
#include "matrizLib.h"

int main(){
	
	int i,j,lin,cols,mat[100][100], res;
	
	
	printf("Qntd de lin e cols: ");
	scanf("%d%d",&lin,&cols);
	
	geraMatrix(mat,lin,cols);
	printf("\n*** Matrix ***");
	printMatrix(mat,lin,cols);
	
	res = menorMatrix(mat,lin,cols);
	
	printf("\n\nMenor valor da matriz: %d\n",res);
	
	return 0;
}

