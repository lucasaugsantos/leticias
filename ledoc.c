#include <stdio.h>
#include <stdlib.h>

void leArquivo(char *palavra, char *nomeArq){
	FILE *arq;
	char ch;

	arq = fopen(nomeArq, "r");
	if(arq == NULL){
		printf("Erro na leitura de arquivo, queridinha");
	} else{
		//ler o arquivo ate que encontro a primeira letra de palavra, e entao compara
		//se é a mesma palavra
		//Problemas: como pego o primeiro elemento de um char*? acho que é assim:
		while((ch=fgetc(arq))!= EOF)){
			if (ch == (*palavra)){
				while(ch == (*palavra)){
					ch=fgetc(arq);
					palavra++;
					//ta, mas nao ta armazenado a palavra em lugar nenhum, 
					//e nem tem como eu saber que achou a palavra
				}
			}
		}
	}

	fclose(arq);
}