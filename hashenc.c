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
	Item* aux, aux2;
	int n;

	//novamente acha o N

	aux=hash[n];

	if (aux == NULL){
		printf("Item a ser removido não existe, queridinha!");
		return;
	}

	//para o caso de ser o primeiro
	if(strcmp(aux->palavra, palavra)==0){
		hash[n] = aux->proximo;
		flag = 1;
	} else {
		//caso nao for o primeiro, percorre o resto da lista
		while(aux->proximo != NULL){
			aux2=aux;
			aux=aux->proximo;

			if(strcmp(aux->palavra, palavra)==0){
				aux2->proximo=aux->proximo;
				flag = 1;
			}
		}	
	} 
		
	//aviso, caso item a ser removido nao tenha sido encontrado
	if(!flag){
		printf("Item a ser removido não existe, queridinha!");
	} 
}