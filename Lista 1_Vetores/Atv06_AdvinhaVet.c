#include <stdio.h>
#include <stdlib.h>
#include "vetLib.h"


int main(){
	int x, adv, vet[100];
	
	printf("Quantidade de num para sorteio: ");
	scanf("%d", &x);
	
	geraVet(vet, x);
	
	printf("Advinhe o num sorteado: ");
	scanf("%d", &adv);
	
	
	
	if(advinhaVet(vet, x, adv) == 1){
		printVet(vet,x);
	}else{
		printf("O numero %d nao foi sorteado!\n\n", adv);
		printVet(vet,x);
	}
	return 0;
}
