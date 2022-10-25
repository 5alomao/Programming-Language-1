#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char matricula[20];
	char nome[150];
	float nota[3];
	float med;
}taluno;

int qtd=0;

void cadastraAluno(taluno a[]){
	int y;
	float soma;
	printf("Nome: ");
	fflush(stdin);
	gets(a[qtd].nome);
	printf("Matricula: ");
	fflush(stdin);
	gets(a[qtd].matricula);
	for(y=0;y<3;y++){
	printf("Nota [%d]: ",y+1);
	scanf("%f",&a[qtd].nota[y]);
	soma+=a[qtd].nota[y];
	}
	a[qtd].med=soma/3;
	printf("------------------\n\n");
	printf("Cadastrado com sucesso :)");
	qtd++;
}

void listaAluno(taluno a[]){
	int i;
	for(i=0;i<qtd;i++){
		printf("*** Aluno %d ***\n",i+1);
		printf("Nome: %s\n",a[i].nome);
		printf("Matricula: %s\n",a[i].matricula);
		printf("Nota [1]: %.1f\n",a[i].nota[0]);
		printf("Nota [2]: %.1f\n",a[i].nota[1]);
		printf("Nota [3]: %.1f\n",a[i].nota[2]);
		printf("Media: %.2f\n",a[i].med);
		printf("--------------------\n\n");
	}
}

int buscaMatri(taluno a[], char matriculaBusca[20]){
	
	int i;
	char matriculaAux[20];
	
	for(i=0;i<qtd;i++){
		strcpy(matriculaAux,a[i].matricula);
		strupr(matriculaAux);
		if(strcmp(matriculaBusca,matriculaAux)==0){
			printf("*** Aluno %d ***\n",i+1);
			printf("Nome: %s\n",a[i].nome);
			printf("Matricula: %s\n",a[i].matricula);
			printf("Nota [1]: %.1f\n",a[i].nota[0]);
			printf("Nota [2]: %.1f\n",a[i].nota[1]);
			printf("Nota [3]: %.1f\n",a[i].nota[2]);
			printf("Media: %.2f\n",a[i].med);
			printf("--------------------\n\n");	
			return i;
		}	
	}
	return -1;
}

int buscaNome(taluno a[], char nomeBusca[150]){
	
	int i;
	char nomeAux[150];
	
	for(i=0;i<qtd;i++){
		strcpy(nomeAux,a[i].nome);
		strupr(nomeAux);
		if(strcmp(nomeBusca,nomeAux)==0){
			printf("*** Aluno %d ***\n",i+1);
			printf("Nome: %s\n",a[i].nome);
			printf("Matricula: %s\n",a[i].matricula);
			printf("Nota [1]: %.1f\n",a[i].nota[0]);
			printf("Nota [2]: %.1f\n",a[i].nota[1]);
			printf("Nota [3]: %.1f\n",a[i].nota[2]);
			printf("Media: %.2f\n",a[i].med);
			printf("--------------------\n\n");
			return i;
		}
	}
	return -1;
}

void salvaArquivo(taluno a[]){
	FILE *arq;
	int i=0;
	arq=fopen("dadosAlunos.txt","wb");
	fwrite(&a[i],sizeof(taluno),qtd,arq);
	printf("Dados salvos com sucesso...\n");
	fclose(arq);
}
//SALVAR ARQUIVOS

void carregaArquivo(taluno a[]){
	FILE *arq;
	arq=fopen("dadosAlunos.txt","rb");
	if(arq==NULL){
	  printf("Arquivo nao encontrado :(\n\nCadastre um aluno e salve para gerar o arquivo :)");
	  return;
	  }// fim if
	 while(fread(&a[qtd],sizeof(taluno),1,arq) >0 )
	      qtd++;  
	 printf("\nDados carregados com sucesso...\n");
	fclose(arq);
}

void resultado(taluno a[]){
	
	int i;
	for(i=0;i<qtd;i++){
		if(a[i].med>=6){
			printf("*** Aluno %d ***\n",i+1);
			printf("Nome: %s\n",a[i].nome);
			printf("Matricula: %s\n",a[i].matricula);
			printf("Nota [1]: %.1f\n",a[i].nota[0]);
			printf("Nota [2]: %.1f\n",a[i].nota[1]);
			printf("Nota [3]: %.1f\n",a[i].nota[2]);
			printf("Media: %.2f\n",a[i].med);
			printf("Situacao: Aprovado\n");
			printf("--------------------\n\n");
		}else{
			printf("*** Aluno %d ***\n",i+1);
			printf("Nome: %s\n",a[i].nome);
			printf("Matricula: %s\n",a[i].matricula);
			printf("Nota [1]: %.1f\n",a[i].nota[0]);
			printf("Nota [2]: %.1f\n",a[i].nota[1]);
			printf("Nota [3]: %.1f\n",a[i].nota[2]);
			printf("Media: %.2f\n",a[i].med);
			printf("Situacao: Reprovado\n");
			printf("--------------------\n\n");
		}
			
}
}

void principal (taluno alunos[]){
	int op,res=0;
	char matriculaBusca[20], nomeBusca[150];
	do{
		op=menuOp();
		switch(op){
			case 1:
				getch();
				system("cls");
				printf("Preencha os campos a seguir:\n\n");
				cadastraAluno(alunos);
				break;				
				case 2:
				getch();
				system("cls");
				printf("*** Lista de Alunos ***\n\n");
				listaAluno(alunos);
				break;
			case 3:
				getch();
				system("cls");
				printf("Insira a matricula: ");
				fflush(stdin);
				gets(matriculaBusca);
				strupr(matriculaBusca);
				printf("\n");
				res=buscaMatri(alunos,matriculaBusca);
				if(res==-1){
					printf("Matricula nao encontrada :(");
				}
				break;
			case 4:
				getch();
				system("cls");
				printf("Insira o nome: ");
				fflush(stdin);
				gets(nomeBusca);
				strupr(nomeBusca);
				printf("\n");
				res=buscaNome(alunos,nomeBusca);
				if(res==-1){
					printf("Nome nao encontrada :(");
				}
				break;	
			case 5:
				getch();
				system("cls");
				printf("*** Aluno com maior media ***\n\n");
				maiorMed(alunos);
				break;
			case 6:
				getch();
				system("cls");
				printf("*** Situacao dos Alunos ***\n\n");
				resultado(alunos);
				break;	
			case 7:
				printf("\n");
				salvaArquivo(alunos);
				break;
			case 0:
				printf("\n");
				salvaArquivo(alunos);
				printf("\nSaindo....");	
				break;
			default:
				printf("\nOpcao invalida :(");				
			}
	getch();
	system("cls");
	}while(op!=0);
	
}




int menuOp(){
	int op;
	
	printf("*** Sistemas de Alunos ***\n");
	printf("[1]- Cadastrar aluno\n");
	printf("[2]- Listar alunos\n");
	printf("[3]- Buscar por matricula\n");
	printf("[4]- Buscar por nome\n");
	printf("[5]- Maior media\n");
	printf("[6]- Situacao dos alunos\n");
	printf("[7]- Salvar dados\n");
	printf("[0]- Sair\n");
	
	printf("\n\nEntre com sua Escolha: ");
	scanf("%d",&op);	
	
	return op;
}
