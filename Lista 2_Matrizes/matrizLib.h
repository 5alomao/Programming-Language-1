#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int m[][100],int lin,int cols){
	int i,j;
	
	for(i=0;i<lin;i++){
		printf("\n");
		for(j=0;j<cols;j++)
		   printf("%2d ",m[i][j]);
	  
	}// fim for i
}// fim funcao
//Printa matriz

void geraMatrix(int m[][100],int lin, int cols){
	int i,j;
	srand(time(NULL));
	for(i=0;i<lin;i++)
	  for(j=0;j<cols;j++)
	     m[i][j]=rand()%10;
}
//Gera matriz

void geraMatrixf(float m[100][100],int lin, int cols){
	int i,j;
	srand(time(NULL));
	for(i=0;i<lin;i++)
	  for(j=0;j<cols;j++)
	     m[i][j]=rand()%20;
}

void leiaMatrix(int m[][100],int lin, int cols){
	int i,j;
	for(i=0;i<lin;i++)
	  for(j=0;j<cols;j++)
	     scanf("%d",&m[i][j]);
}
//leia matriz

void carregaMatrix(int m[][100],int lin, int cols){
	FILE *arq;
	int i,j;
	arq= fopen("numeros.txt","r");
	if(arq==NULL)
	   printf("Arquivo nao encontrado\n");
	for(i=0;i<lin;i++){
	   for(j=0;j<cols;j++){
              fscanf(arq,"%d",&m[i][j]); 
		}// fim for j
	}// fim for i     
}

int menorMatrix(int m[][100], int lin, int cols){
	
	int i,j, menor=m[0][0];
	for(i=0;i<lin;i++){
		
		for(j=0;j<cols;j++){
				if(m[i][j]<menor)
					menor=m[i][j];
		}//colunas
	}//linhas
	return menor;
}
//função menor matriz

int maiorMatrix(int m[][100], int lin, int cols){
	
	int i,j, maior=m[0][0];
	for(i=0;i<lin;i++){
		
		for(j=0;j<cols;j++){
				if(m[i][j]>maior)
					maior=m[i][j];
		}//colunas
	}//linhas
	return maior;
}
//função maior matriz

int buscaMatrix(int m[][100], int lin, int cols){

	int busca, i, j, cont=0;
	printf("\n\nDigite um valor para busca: ");
	scanf("%d",&busca);
	
	for(i=0;i<lin;i++){
	for(j=0;j<cols;j++){
		if(busca==m[i][j])
			cont++;
		}
	}
	printf("\n");
	printf("O valor %d aparece: %d\n",busca,cont);
}
//função buscar elemento na matriz

int somaMat(int mat[100][100], int mat2[100][100], int lin, int cols){
	
	int mat3[100][100], i,j;
	
	for(i=0;i<lin;i++){
	for(j=0;j<cols;j++){
		mat3[i][j]=mat[i][j]+mat2[i][j];
	}}
	for(i=0;i<lin;i++){
		printf("\n");
	for(j=0;j<cols;j++){
		printf("%2d ",mat3[i][j]);
	}}
	return mat3[i][j];
}
//Soma de duas Matrizes

int somaMatf(float mat[100][100], float mat2[100][100], int lin, int cols){
	
	float mat3[100][100];
	int i,j;
	
	for(i=0;i<lin;i++){
	for(j=0;j<cols;j++){
		mat3[i][j]=mat[i][j]+mat2[i][j];
	}}
	for(i=0;i<lin;i++){
		printf("\n");
	for(j=0;j<cols;j++){
		printf("%.2f ",mat3[i][j]);
	}}
	return mat3[i][j];
}

int matTransp(int mat[100][100],int lin,int cols){
	
	int i,j;
	
	mat[i][j]=mat[j][i];
	for(j=0;j<cols;j++){
		printf("\n");
		for(i=0;i<lin;i++){
			printf(" %d ",mat[i][j]);
		}
	}
	return mat[i][j];
}
