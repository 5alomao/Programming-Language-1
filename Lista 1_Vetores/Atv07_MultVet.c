#include <stdlib.h>
#include <stdio.h>
#include "vetLib.h"

void main(){
	
	int vet[100],vet2[100],vetRes[100],x,i;
	
	printf("Quantidade de Vetores: ");
	scanf("%d",&x);
	
	geraVet(vet,x);
	geraVet(vet2,x);
	
	for(i=0;i<x;i++){
		vetRes[i]=vet[i]*vet2[i];
	}
	printf("Elementos do Vetor[1]: ");
	printVet(vet,x);
	printf("Elementos do Vetor[2]: ");
	printVet(vet2,x);
	printf("Elementos Multiplicados: ");
	printVet(vetRes,x);

}
