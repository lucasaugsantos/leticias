#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashEnc.h"


int n = 0;

struct palavra{
	char* palavra;
	struct palavra* proximo;
};

struct listap{
	Palavra* primeiro;
	Palavra* ultimo;
};

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
		aux=aux->proximo;
	}

	return 0;
}

void leArquivo(char *nomeArq){
	FILE *arq;
	char ch;
	char word[30];
	int posicao = 0;

	arq = fopen(nomeArq, "r");
	if(arq == NULL){
		printf("Erro na leitura de arquivo, queridinha!");
	} else{
		Palavra* p;
		initLista();
		while(fscanf(arq,"%s", word) == 1){
			if(!repetido(word)){
				insere(word);
			}
		}
	}
	fclose(arq);
}

void nmrPalavras(){
	int i;
	Palavra* aux = lista->primeiro;

	for(i=0;aux != NULL; i++){
		aux=aux->proximo;
	}

	printf("Numero de palavras %d", i);
	define(i);
}



// http://www.cplusplus.com/reference/cstdio/ftell/ 