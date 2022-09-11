#include <string.h>

int main(){
	
	char vet[100];
	int tamanho, i;
	
	printf("Digite a Palavra: ");
	gets(vet);
	
	tamanho = strlen(vet);
	
	printf("\nPalavra ao contrario: ");
	
	for(i=0;i<tamanho;i++){
		printf("%c", vet[tamanho-1-i]);
	}
	
}
