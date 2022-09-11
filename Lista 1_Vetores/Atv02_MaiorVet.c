#include <stdlib.h>
#include <stdio.h>
#include "vetLib.h"

int main(){
	
	int vet[100],x;
	
	printf("Quantidade de Vetores: ");
	scanf("%d",&x);
	printf("\n");
	geraVet(vet,x);
	printVet(vet,x);
	
	printf("\nMaior Vetor: %d\n",maiorVet(vet,x));
	
	return 0;
}
