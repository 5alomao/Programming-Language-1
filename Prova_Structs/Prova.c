#include <stdio.h>
#include <string.h>
typedef struct{
	int dia,mes,ano;
}tData;
typedef struct{
	char nome[40];
	tData data;
	int tamanho;
	int lancamento;
	int qtdEstoque;
	float preco;
}tBeleza;
int qtd=0;
//----------------------------
void cadastra(tBeleza b[100]){
    printf("\n*** Cadastro de produtos ***\n");
    
    printf("Nome:");
    fflush(stdin); 
	gets(b[qtd].nome);
	
    printf("Data (DD MM AA): ");
    scanf("%d%d%d",&b[qtd].data.dia, &b[qtd].data.mes, &b[qtd].data.ano);
    
    printf("[1] - ml\n[2] - gramas\nTamanho: ");
    scanf("%d", &b[qtd].tamanho);
	
	printf("[1] - Sim\n[0] - Nao\nLancamento: ");
	scanf("%d", &b[qtd].lancamento);
	
	printf("Quantidade Estoque: ");
	scanf("%d", &b[qtd].qtdEstoque);
	
	printf("Preco: ");
	scanf("%f", &b[qtd].preco);
	
	printf("\nDados cadastrados com sucesso :)");
	
    qtd++;
}
//-----------------------------
void listaProd(tBeleza b[]){
	int i;
	
	for(i=0;i<qtd;i++){
		printf("Produto: %d\n",i+1);
		printf("Nome: %s\n", b[i].nome);	
    	printf("Data: %d %d %d\n",b[i].data.dia, b[i].data.mes, b[i].data.ano);
    	printf("Tamanho: %d\n", b[i].tamanho);
		printf("Lancamento: %d\n", b[i].lancamento);
		printf("Quantidade Estoque: %d\n", b[i].qtdEstoque);
		printf("Preco: %.2f\n", b[i].preco);
		printf("-------------------\n");
	}
	
}
//-----------------------------
void listaLancamento(tBeleza b[]){
	int i;
	
	for(i=0;i<qtd;i++){
		if(b[i].lancamento == 1){
		printf("Produto: %d\n",i+1);
		printf("Nome: %s\n", b[i].nome);	
   		printf("Data: %d %d %d\n",b[i].data.dia, b[i].data.mes, b[i].data.ano);
   		printf("Tamanho: %d\n", b[i].tamanho);
		printf("Lancamento: %d\n", b[i].lancamento);
		printf("Quantidade Estoque: %d\n", b[i].qtdEstoque);
		printf("Preco: %.2f\n", b[i].preco);
		printf("-------------------\n");
		}
	}
	
}
//-----------------------------
void valorEstoque(tBeleza b[]){
	
	float total=0.0;
	int i;
	
	for(i=0;i<qtd;i++){
		total+=( b[i].preco * b[i].qtdEstoque);
	}
	
	printf("Valor Total em Estoque: %.2f\n", total);
	
}
//-----------------------------
void comparaPreco(tBeleza b[]){
	
	int i;
	int maior=0, menor=0;
	
	for(i=0;i<qtd;i++){
		if(b[i].preco > b[maior].preco){
			maior = i;
		}else{
			menor = i;
		}
	}
	
	printf("*** Produto Mais Caro ***\n");
	printf("Produto: %d\n",maior);
	printf("Nome: %s\n", b[maior].nome);
	printf("Data: %d %d %d\n",b[maior].data.dia, b[i].data.mes, b[i].data.ano);
    printf("Tamanho: %d\n", b[maior].tamanho);
	printf("Lancamento: %d\n", b[maior].lancamento);
	printf("Quantidade Estoque: %d\n", b[maior].qtdEstoque);
	printf("Preco: %.2f\n", b[maior].preco);
	printf("-------------------\n");
	
	printf("*** Produto Mais Barato ***\n");
	printf("Produto: %d\n",menor);
	printf("Nome: %s\n", b[menor].nome);	
    printf("Data: %d %d %d\n",b[menor].data.dia, b[i].data.mes, b[i].data.ano);
    printf("Tamanho: %d\n", b[menor].tamanho);
	printf("Lancamento: %d\n", b[menor].lancamento);
	printf("Quantidade Estoque: %d\n", b[menor].qtdEstoque);
	printf("Preco: %.2f\n", b[menor].preco);
	printf("-------------------\n");
	
}
//-----------------------------
void buscaMes(tBeleza b[], tData d){
	
	int i;
	
	for(i=0; i<qtd; i++){
		
		if(b[i].data.mes == d.mes && b[i].data.ano == d.ano){
			printf("Produto: %d\n",i+1);
			printf("Nome: %s\n", b[i].nome);	
    		printf("Data: %d %d %d\n",b[i].data.dia, b[i].data.mes, b[i].data.ano);
    		printf("Tamanho: %d\n", b[i].tamanho);
			printf("Lancamento: %d\n", b[i].lancamento);
			printf("Quantidade Estoque: %d\n", b[i].qtdEstoque);
			printf("Preco: %.2f\n", b[i].preco);
			printf("-------------------\n");
		}
	}
	
}// fim funcao
//-----------------------------
void alteraEstoque(tBeleza b[], char nomeBusca[40]){
	
	char nomeAux[40];
	int i,addEstoque;
	
	for(i=0;i<qtd;i++){
		strcpy(nomeAux,b[i].nome);
		strupr(nomeAux);
		if(strcmp(nomeAux,nomeBusca)==0){
			printf("Adicionar ao Estoque: ");
			scanf("%d", &addEstoque);
			b[i].qtdEstoque += addEstoque;
			printf("Adicionado com sucesso :)");
		}
	}
}
//-----------------------------
void salvaArquivoBinario(tBeleza b[]){
	FILE *arq;
	int i;
	arq=fopen("beleza.dat","wb");
	fwrite(&b[0],sizeof(tBeleza),qtd,arq);
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//-----------------------------
void carregaBinario(tBeleza b[]){
	FILE *arq;
	arq=fopen("beleza.dat","rb");
	if(arq==NULL)
	  printf("Arquivo nao encontrado!\n");
	else{
	 while(    fread(&b[qtd],sizeof(tBeleza),1,arq) >0     )
	     qtd++;  
	 printf("Dados carregados com sucesso!\n");
	}
	fclose(arq);
}
//----------------------------
int menu(){
	int op;
	printf("\t\t**** Beleza na Web ****\n");
	printf("1 - Cadastrar novo produto\n");
	printf("2 - Listar todos produtos\n");
	printf("3 - Salvar em arquivo\n");
	printf("4 - Carregar\n");
    printf("5 - Listar produtos em lancamento\n");
    printf("6 - Valor Total Estoque\n");
    printf("7 - Produto (Caro/Barato)\n");
    printf("8 - Buscar Produto por Mes\n");
    printf("9 - Alterar QtdEstoque\n");
	printf("0 - Sair\n");
	printf("\nDigite sua opcao: "); 
	scanf("%d",&op);
	printf("\n");
	return op;
}
//-----------------------------
int main(){
	tBeleza produtos[100];
	int op;
	tData dataBusca;
	char nomeBusca[40];
	do{
		op = menu();
		switch(op){
			case 1: 
				cadastra(produtos);
				break;
			case 2: 
				listaProd(produtos);
				printf("\n");
				printf("Dados listados com sucesso :)");
				break;
			case 3: 
				salvaArquivoBinario(produtos);
				break; 
			case 4: 
				carregaBinario(produtos);
				break; 
			case 5:
				printf("*** Produtos em Lancamento ***\n");
				listaLancamento(produtos);
				break;
			case 6:
				valorEstoque(produtos);
				break;
			case 7:
				comparaPreco(produtos);
				break;
			case 8:
				printf("Data para busca (MM AA): ");
				scanf("%d%d", &dataBusca.mes, &dataBusca.ano);
				buscaMes(produtos,dataBusca);
				break;
			case 9:
				printf("Nome do Produto: ");
				fflush(stdin);
				gets(nomeBusca);
				strupr(nomeBusca);
				alteraEstoque(produtos,nomeBusca);
				break;
			case 0: printf("Saindo ... \n");
				salvaArquivoBinario(produtos);
				break;
			default:printf("Opcao invalida\n"); 	 	
		}// fim switch
		getch(); // pausa
		system("cls"); // limpa a tela
	}while(op!=0);
}// fim main
