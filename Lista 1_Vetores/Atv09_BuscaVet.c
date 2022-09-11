#include <stdio.h>
#include "vetLib.h"


int main(){
	
	int i,bus,v[50],n,res;
	
	printf("Digite a quantidade de elementos: ");
	scanf("%d",&n);

		
	geraVet(v,n);
	printf("\nVetor gerado: \n");
	printVet(v,n);
	
	printf("\nValor para busca: ");
	scanf("%d",&bus);
	
	res = existeVet(bus,v,n);
	
	printf("\n%d encontrado %d vez(es)\n",bus,res);
	
	return 0;
}
