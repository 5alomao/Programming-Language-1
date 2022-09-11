#include <stdio.h>
#include <stdlib.h>
#include "vetLib.h"

int main(){
	
	int vet[100],x,i;
	int l1=0,l2=0,l3=0,l4=0,l5=0,l6=0;
	
	printf("Quantidade de arremessos: ");
	scanf("%d",&x);
	
	for(i=0;i<x;i++){
		printf("Valor do dado: ",i);
		scanf("%d",&vet[i]);
	}
	for(i=0;i<x;i++){
	
	if(vet[i]==1){
		l1++;
	}
	if(vet[i]==2){
		l2++;
	}
	if(vet[i]==3){
		l3++;
	}
	if(vet[i]==4){
		l4++;
	}
	if(vet[i]==5){
		l5++;
	}
	if(vet[i]==6){
		l6++;
	}}
	printVet(vet,x);
	printf("Lado 1: %d\n",l1);
	printf("Lado 2: %d\n",l2);
	printf("Lado 3: %d\n",l3);
	printf("Lado 4: %d\n",l4);
	printf("Lado 5: %d\n",l5);
	printf("Lado 6: %d\n",l6);		
}
