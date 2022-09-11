#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(){
	
	char msg[100];
	int tam,i;
	
	printf("Insira a mensagem para decodificar: ");
	gets(msg);
	
	tam = strlen(msg);
	
	printf("Mensagem decodificada: \n");
	
	for(i=0;i<tam;i++){
		if(msg[i] != 'p'){
			printf("%c", msg[i]);
		}else if(msg[i - 1] == 'p' && msg[i + 1] == 'p'){
			printf("%c", msg[i]);
		}
	}
}
