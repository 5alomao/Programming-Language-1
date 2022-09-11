#include <stdio.h>
#include "matrizLib.h"

int main(){
	
	int mat[100][100], lin,cols,busca,cont=0;
	int i,j;
	
	printf("Qtde de lin e cols: ");
	scanf("%d%d",&lin,&cols);
	
	geraMatrix(mat,lin,cols);
	
	printf("\n*** Matriz ***");
	
	printMatrix(mat,lin,cols);
	
	printf("\n\nValor para verificacao: ");
	scanf("%d",&busca);
	
	for(i=0;i<lin;i++)
		for(j=0;j<cols;j++)
			if(mat[i][j]>busca)
				cont++;
	printf("\n%d valores maiores que %d\n",cont,busca);
				
	return 0;
}
