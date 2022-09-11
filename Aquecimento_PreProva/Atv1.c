#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int startCodon(char dna[100], int n){
	
	int i,res=0;
	strupr(dna);
	for(i=0;i<n-2;i++){
		if(dna[i]=='A' && dna[i+1]=='T' && dna[i+2]=='G'){
			res=1;
			break;
		}
	}
	return res;
}


int main(){
	
	char dna[100];
	int tam, res;
	
	
	printf("Entre com a sequencia de DNA: ");
	fflush(stdin);
	gets(dna);
	
	tam = strlen(dna);
	
	res=startCodon(dna,tam);
	
	if(res==1){
	
		printf("\nExiste...\n*** Sequencia ***\n");puts(dna);
	}else{
		printf("\nInexistente...\n*** Sequencia ***\n");puts (dna);
	}
		
	return 0;
}
	

