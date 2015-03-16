#include <stdio.h>
#include <stdlib.h>

int n = 0;

struct palavra{
	char* palavra;
	Palavra* proximo;
}

typedef struct palavra Palavra;

struct listap{
	Palavra* primeiro;
	Palavra* ultimo;
}

typedef struct listap ListaP;
ListaP* lista;

void initLista(){
	lista = (ListaP*)malloc(sizeof(ListaP));
	lista->primeiro = NULL;
	lista->ultimo = NULL;
}

void insere(char* word){
	if(lista->primeiro == NULL){
		lista->primeiro = (Palavra*)malloc(sizeof(Palavra));
		lista->primeiro->palavra = (char*)malloc((strlen(word)+1)*sizeof(char));
		strcpy(lista->primeiro->palavra, word);
		lista->primeiro->proximo=NULL;
		lista->ultimo = lista->primeiro;
	} else{
		lista->ultimo->proximo = (Palavra*)malloc(sizeof(Palavra));
		lista->ultimo = lista->ultimo->proximo;
		lista->ultimo->palavra = (char*)malloc((strlen(word)+1)*sizeof(char));
		strcpy(lista->ultimo->palavra, word);
		lista->ultimo->proximo=NULL;
	}
}

int repetido(char* word){
	Palavra* aux = lista->primeiro;

	while(aux != NULL){
		if(strcmp(aux->palavra, word) == 0){
			return 1;
		}
	}

	return 0;
}

void leArquivo(char *palavra, char *nomeArq){
	FILE *arq;
	char ch;
	char[30] word;
	int posicao = 0;

	arq = fopen(nomeArq, "r");
	if(arq == NULL){
		printf("Erro na leitura de arquivo, queridinha!");
	} else{
		Palavra* p;
		//ler o arquivo ate que encontro a primeira letra de palavra, e entao compara
		//se é a mesma palavra
		//Problemas: como pego o primeiro elemento de um char*? acho que é assim:
		while(fscanf(fp,"%s", word) == 1){
			if(!repetido(word)){
				insere(word);
			}
		}
		// while((ch=fgetc(arq))!= EOF)){
		// 	posicao++;

		// 	if (ch == (*palavra)){ //(*palavra) retorna o primeiro char da palavra?
		// 		int i=1;
		// 		word[0]=ch;
		// 		palavra++;

		// 		for(i;fgetc(arq)!=EOF && i<strlen(*palavra);i++){
		// 			word[i]=fgetc(arq);
		// 			posicao++;
		// 		}
		// 			//ta, mas nao ta armazenado a palavra em lugar nenhum, 
		// 			//e nem tem como eu saber que achou a palavra
		// 		}
		// 	}
	}
	fclose(arq);
}

void nmrPalavras(){
	int i=0;
	Palavra* aux = lista->primeiro;

	for(i;aux != NULL; i++){
		aux=aux->proximo;
	}

	n = i;
}



// http://www.cplusplus.com/reference/cstdio/ftell/ 