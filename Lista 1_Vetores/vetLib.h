#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Gera
void geraVet(int v[], int n){
	int i;
	srand(time(NULL)); // inicializa gerador
	for(i=0;i<n;i++)
		v[i]=rand()%20; }


//Leia
void leiaVet(int v[],int n){
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
}

//Print
void printVet(int v[], int n){
	int i;
	for(i=0;i<n;i++)
		printf(" %d |",v[i]);
	printf("\n");	
}

//Soma
int somaVet(int v[], int n){
	int i,soma=0;
	for(i=0;i<n;i++)
		soma+=v[i];
	return soma;	
}

//Maior
int maiorVet(int v[], int n){
	int i, maior = v[0];
	for(i=0;i<n;i++){
		if(v[i]> maior)
			maior = v[i];
	}// fim for		
	return maior;		
}

//Menor
int menorVet(int v[], int n){
	int i, menor = v[0];
	for(i=0;i<n;i++){
		if(v[i] < menor)
			menor = v[i];
	}// fim for		
	return menor;		
}

//Existe
int existeVet(int x, int v[], int n){
	
	
	int cont=0,i;
	for(i=0;i<n;i++)
		if(v[i]==x)
			cont++;
			
	return cont;	
}

//Impar
int impVet(int v[], int n){
	
	int i, impar=0;
	
	for(i=0;i<n;i++)
		if(v[i]%2!=0)
			impar++;
	
	return impar;
}

//Advinhar
int advinhaVet(int v[], int n, int adv){
	
	int certo=0, i;
	for(i=0;i<n;i++)
		if(adv == v[i]){
			certo = 1;
			printf("\nValor %d Sorteado no Vetor[%d]\n",adv,i);}
			
	printf("\n");		
	return certo;
}

//Ler Vetor Samba
void leiaVetorfloat(float v[], int n){
	float x;
	int i;
	for(i=0;i<n;i++){
		printf("Valor[%d]: ", i);
		scanf("%f", &x);
		v[i] = x;
	}
}

//Somar Vetor Samba
float somaVetorfloat(float v[], int n){
	float soma = 0;
	int i;
	
	for(i=0;i<n;i++){
		soma += v[i];
	}
	
	return soma;
}

//Menor Vetor Samba
float menorValorfloat(float v[], int n){
	float menor = v[0];
	int i;
	
	for(i=1;i<n;i++){
		if(v[i] < menor){
			menor = v[i];
		}
	}
	
	return menor;
}

//Maior Vetor Samba
float maiorValorfloat(float v[], int n){
	float maior = v[0];
	int i;
	
	for(i=1;i<n;i++){
		if(v[i] > maior){
			maior = v[i];
		}
	}
	
	return maior;
}
