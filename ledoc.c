#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADLeDoc.h"
#include "TADHashEnc.h"


int n = 0;

struct posicao {
	int posicao;
	struct posicao* proximo;
}

struct documento {
	char* nomeDoc;
	struct posicao* posicao;
	struct documento* proximo;
};

struct palavra{
	char* palavra;
	struct documento* doc;
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

Posicao* criaPosix (int posicao){
	Posicao* novo = (Posicao*)malloc(sizeof(Posicao));
	novo->posicao = posicao;
	novo->prox = NULL;
	
	return novo;
}

Documento* criaSDoc (char* nomeDoc, int posicao){
	Documento* novo = (Documento*)malloc(sizeof(Documento));
	novo->nomeDoc = (char*)malloc((strlen(nomeDoc)+1)*sizeof(char));
	novo->posicao = criaPosix(posicao);
	novo->proximo = NULL;
	
	return novo;
}

void criaPalavra(char* word, char* nomeDoc, int posicao){
	if(lista->primeiro == NULL){
		lista->primeiro = (Palavra*)malloc(sizeof(Palavra));
		lista->primeiro->palavra = (char*)malloc((strlen(word)+1)*sizeof(char));
		strcpy(lista->primeiro->palavra, word);
		
		lista->primeiro->doc = criaSDoc(nomeDoc, posicao);
		
		lista->ultimo = lista->primeiro;
	} else{
		lista->ultimo->proximo = (Palavra*)malloc(sizeof(Palavra));
		lista->ultimo = lista->ultimo->proximo;
		lista->ultimo->palavra = (char*)malloc((strlen(word)+1)*sizeof(char));
		strcpy(lista->ultimo->palavra, word);
		
		lista->ultimo->doc = criaSDoc(nomeDoc, posicao);
		
		lista->ultimo->proximo=NULL;
	}
}

void insere(char* word, char* nomeDoc, int posicao){
	Palavra* aux = lista->primeiro;

	while(aux != NULL){
		if(strcmp(aux->palavra, word) == 0){
			Documento* aux2 = aux->doc;
			
			while(aux2 != NULL){
				if(strcmp(aux2->nomeDoc, nomeDoc) == 0){
					aux2->posicao = criaPosix(posicao);
					return;
				}
				aux2 = aux2->proximo;
			}
			
			aux2 = criaDoc(nomeDoc, posicao);
			return;
		}
		aux=aux->proximo;
	}
	
	aux = criaPalavra(word, nomeDoc, posicao);
	return;
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
			insere(word);	
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
