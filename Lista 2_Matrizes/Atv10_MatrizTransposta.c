#include <stdlib.h>
#include <stdio.h>
#include "matrizLib.h"

int main(){
	
	int mat[100][100],lin,cols,i,j;
	
	printf("Qntd de lin e cols: ");
	scanf("%d%d",&lin,&cols);
	
	geraMatrix(mat,lin,cols);
	printf("\n** Matriz **");
	printMatrix(mat,lin,cols);
	
	printf("\n\n** Matriz Transposta **");
	matTransp(mat,lin,cols);
	
	return 0;
}
