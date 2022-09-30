#include <stdio.h>
#include <time.h>

void geraMat(int m[][100],int lin, int cols){
	int i,j;
	srand(time(NULL));
	for(i=1;i<lin;i++)
	  for(j=1;j<cols;j++)
	     m[i][j]=rand()%2;
}

void printMat(int mat[100][100], int lin, int cols){
	int i,j;
	for(i=1;i<lin;i++){
		printf("\n");
		for(j=1;j<cols;j++){
			printf(" %2d ",mat[i][j]);
		}
	}
}

int somaChuva(int mat[100][100],int lin, int cols, int mes){
	int i,j,soma=0;
	
	for(i=1;i<lin;i++)
	  for(j=1;j<cols;j++){
	  	if(mes==i){
	  		soma+=mat[i][j];
		  }
	  }
	  return soma;
}

int main(){
	
	int mat[100][100],x;
	
	geraMat(mat,13,32);
	printMat(mat,13,32);
	
	printf("\n\nMes para soma da chuva:");
	scanf("%d",&x);
	
	printf("Soma da chuva no mes %d: %d ",x,somaChuva(mat,13,32,x));
		
	return 0;
}
