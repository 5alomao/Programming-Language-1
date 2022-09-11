#include <stdlib.h>
#include <stdio.h>
#include "matLib.h"

int main(){
	
	int mat[100][100],i,j,x,par=0,imp=0;
	
	printf("Entre com a ordem da matriz: ");
	scanf("%d",&x);
	
	geraMat(mat,x,x);
	printMat(mat,x,x);	

	printf("\n\nTotal de Par: %d",parMat(mat,x,x));
	printf("\nTotal de Impar: %d",impMat(mat,x,x));
	
	return 0;
}
