#include <stdlib.h>
#include <stdio.h>
#include "vetLib.h"

int main(){
	
	int vet[100], i, x;
	
	printf("Quantidade de Vetores: ");
	scanf("%d",&x);
	printf("\n");
	geraVet(vet,x);
	printVet(vet,x);
	
	printf("\nSoma dos Vetores: %d\n",somaVet(vet,x));
	
	return 0;
}
