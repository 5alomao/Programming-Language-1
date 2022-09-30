#include <stdio.h>
#include <time.h>

int treinaDrag(int drag[]){
	int i,dias=0;
	
	do{
			drag[2]+=2;
			drag[0]+=10;
			dias++;
		
	}while(drag[0]<300 || drag[2]<10);
	
	return dias;
}

int main(){
	
	int drag[5],i,dias;
	
	printf("Entre com as caracteristicas do dragao na seguinte ordem:\n\n");
	printf("Tamanho | Forca | Fogo | Velocidade | Inteligencia\n\n");
	
	for(i=0;i<5;i++)
		scanf("%d",&drag[i]);
		
	dias = treinaDrag(drag);
	
	printf("\nDias para treinar o dragao: %d", dias);
	
	return 0;
}
