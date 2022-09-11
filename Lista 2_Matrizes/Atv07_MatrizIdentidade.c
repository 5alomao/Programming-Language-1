#include <stdlib.h>
#include <stdio.h>
#include "matrizLib.h"

int main(){
	
	
	int mat[100][100], i, j, ord;
	
	printf("Entre com a ordem da Matriz: ");
	scanf("%d",&ord);
	for(i=0;i<ord;i++)
		for(j=0;j<ord;j++){
		
 			if(i==j){
 				mat[i][j]=1;
	 		}else{
	 			mat[i][j]=0;
			}
		}
			 
	for(i=0;i<ord;i++){
		printf("\n");
		for(j=0;j<ord;j++){
			printf("%2d",mat[i][j]);
		}
	}
	return 0;
}
