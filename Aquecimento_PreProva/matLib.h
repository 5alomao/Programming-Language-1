#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Gerador de Matrizes
void geraMat(int mat[][100], int lin, int cols){
	int i,j;
	srand(time(NULL)); // inicializa gerador
	for(i=0;i<lin;i++){
		for(j=0;j<cols;j++){
			mat[i][j]=rand()%10; }
		}
	}

//Contador de par Matriz
int parMat (int mat[][100], int lin, int cols){
	
	int i, j, par=0;
	for(i=0;i<lin;i++){
		for(j=0;j<cols;j++){
			if(mat[i][j]%2==0)
				par++;
		}	
	}
	return par;
}

//Contador de impar Matriz
int impMat (int mat[][100], int lin, int cols){
	
	int i, j, imp=0;
	for(i=0;i<lin;i++){
		for(j=0;j<cols;j++){
			if(mat[i][j]%2!=0)
				imp++;
		}	
	}
	return imp;
}

//Mostra Matriz
void printMat (int mat[][100], int lin, int cols){
	int i,j;
	for(i=0;i<lin;i++){
		printf("\n");
		for(j=0;j<cols;j++){
			printf(" %d |",mat[i][j]);
		}	
	}
}

int existeDna(int dna[], int n){
	
	int certo=0, i;
	for(i=0;i<n;i++){
		if(dna[i-n]=='A' && dna[i+1-n]=='T' && dna[i+2-n]=='G'){
			certo = 1;
		}
	printf("\n");		
	return certo;
}}
