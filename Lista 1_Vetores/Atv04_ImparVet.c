#include <stdio.h>
#include <stdlib.h>
#include "vetLib.h"

int main(){
	
	int vet[100],x;
	
	printf("Quantidade de Vetores: ");
	scanf("%d",&x);
	printf("\n");
	geraVet(vet,x);
	printVet(vet,x);
	
	printf("\nVetores Impares: %d\n",impVet(vet,x));
	
	return 0;
}
