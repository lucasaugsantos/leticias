#include <stdio.h>
#include <stdlib.h>

int tamHash=10;
Item* hash;

struct Item {
	char* palavra;
	Item* proximo;
}

//PRECISA: funcao que calcula o melhor tamanho do tamHash, que por enquanto vai fixado

void initHash (){
	int i;

	hash = (Item*)malloc(tamHash);

	for(i=0; i<tamHash; i++){
		hash[i] = NULL;
	}
}

Item* createItem (char* palavra){
	Item* novo = (Item*)malloc(sizeof(Item));
	novo->palavra = (char*)malloc((strlen(palavra)+1)*sizeof(char));
	strcpy(novo->palavra, palavra);
	novo->proximo = NULL;

	return novo;
}

void insereHash (char* palavra){
	int n = 0;
	Item* aux;

	//aqui tem uma chamada pra funcao que calcula N, a posicao aonde deve
	//ser inserido o item

	/*
	verifica se existe colisao, caso exista,
	vai até o fim da lista encadeada para inserir o item
	*/
	if(hash[n] == NULL){
		hash[n] = createItem(palavra);
	} else {
		aux = has[n];
		while (aux->prox != NULL){
			aux = aux->proximo;
		}
		aux->prox = createItem(palavra);
	}
}

void removeHash (char* palavra){
	short int flag=0;

	//novamente acha o N

	while(hash[n]->proximo != NULL){
		if(strcmp(hash[n]->palavra, palavra)==0){
			has[n] = hash[n]->proximo;
			flag = 1;
		}	
	}
	if(!flag){
		printf("Nenhum item removido, Leti!");
	} 
}