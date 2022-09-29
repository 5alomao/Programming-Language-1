#include <stdlib.h>
#include "matrizLib.h"

void main(){
	
	int mat[100][100], ordem, res;
	
	printf("Insira a ordem da matriz: ");
	scanf("%d", &ordem);
	
	leiaMatrix(mat, ordem, ordem);
	res = matBits(mat, ordem);
	printMatrix(mat, ordem, ordem);
	
	if(res == 1){
		printf("\nMatriz Bits!");
	}else{
		printf("\nMatriz nao Bits!");
	}
	
}
