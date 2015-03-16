#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#define MAXTAM 97
#define MAXTAMPALAVRA 50

struct palavra {
  char palavra [MAXTAMPALAVRA];
  int n;
  struct palavra* prox;
};

typedef struct palavra Palavra;
typedef Palavra* Hash[MAXTAM];


int hash(char* s) {
    int i;
    int total =0;
    
    for (i=0;i!='\0';i++){
      total = total + s[i];
      return total % MAXTAM;
			  }
    }     

int le_palavra (FILE* fp, char* s){
  int i=0;
  int c;
  while ((c = fgetc(fp)) != EOF){
    if (isalpha(c))
      break;
  };
  
  if (c == EOF)
    return 0;
  else s[i++] = c;
  while (i< (MAXTAM-1) && (c =fgetc(fp)) != EOF && isalpha(c))
    s[i++] = c;
  s[i] ='\0';
  return 1;
}

void inicializa (Hash tab){
  int i;
  for (i=0;i<MAXTAM;i++){
    tab[i]=NULL;
  }
}

Palavra* insere(Hash tab, char* s){
  Palavra* p;
  int h = hash(s);
  
  for (p = tab[h]; p!=NULL; p=p->prox){
    if (strcmp (p->palavra,s)==0)
      return p;
  }
  
  p = (Palavra*)malloc(sizeof(Palavra));
  strcpy(p->palavra,s);
  p->n= 0 ;
  p->prox = tab[h];
  tab[h]= p;
  return p;
}

int conta_elems (Hash tab)
{
int i;
int total = 0;
Palavra* p;
for (i=0; i<MAXTAM;i++) {
for (p=tab[i]; p!=NULL; p=p->prox)
total++;
}
return total;
}

Palavra** cria (int n, Hash tab)
{
int i, j=0;

Palavra* p;
Palavra** vet = (Palavra**) malloc(n*sizeof(Palavra*));

for (i=0; i<MAXTAM;i++) {
for (p=tab[i]; p!=NULL; p=p->prox)
vet[j++] = p;
  
}
return vet;
}

int compara (const void* v1, const void* v2)
{
Palavra** pp1 = (Palavra**)v1;
Palavra** pp2 = (Palavra**)v2;
Palavra* p1 = *pp1;
Palavra* p2 = *pp2;
if (p1->n > p2->n) return -1;
else if (p1->n < p2->n) return 1;
else return strcmp(p1->palavra,p2->palavra);
}

void imprime (Hash tab){
int i;
int n;
Palavra** vet;

n = conta_elems(tab);
vet = cria(n,tab);
qsort(vet,n,sizeof(Palavra*),compara);

for (i=0; i<n; i++){
printf("%s = %d\n",vet[i]->palavra,vet[i]->n);
}
free(vet);
}


int main (int argc, char**argv){
  
FILE* fp;
Hash tab;
char s[MAXTAM];
	if (argc != 2) {
	printf("Arquivo de entrada nao fornecido.\n");
	return 0;
}

fp = fopen(argv[1],"rt");
	      if (fp == NULL) {
	      printf("Erro na abertura do arquivo.\n");
	      return 0;
	      }
inicializa(tab);
	      while (le_palavra(fp,s)) {
	      Palavra* p = insere(tab,s);
	      p->n++;
}
}

