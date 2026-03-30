#include<stdio.h>
#include<stdlib.h>
#include"lista_dinamica.h"

// inicializa uma lista
void cria(Lista *p_l){
	*p_l = NULL;
}

// verifica se a lista esta vazia
int vazia(Lista *p_l){
	return(*p_l==NULL);
}

// insere um elemento no inicio da lista
int insere_inicio(Lista *p_l, elem_t e){
	No_lista *novo;
	novo = (No_lista*)malloc(sizeof(No_lista));
	if(novo==NULL){
		return 0;
	}
	novo->info = e;
	novo->prox = *p_l;
	*p_l=novo;
	return 1;
}

// insere um elemtno no final da lista
int insere_final(Lista *p_l, elem_t e){
	No_lista *novo;
	novo=(No_lista*)malloc(sizeof(No_lista));
	if(novo==NULL){
		return 0;
	}
	novo->info=e;
	novo->prox=NULL;
	if(vazia(p_l)){
		*p_l=novo;
		return 1;
	}
	
	No_lista *aux = *p_l;
	while(aux->prox!=NULL){
		aux=aux->prox;
	}
	aux->prox=novo;
	return 1;
}

// insere um elemento de maneira ordenada, retorna 0 caso ja exista na lista, assume que a lista esteja ordenada
int insere_ordenado(Lista *p_l, elem_t e){
	No_lista *novo=(No_lista*)malloc(sizeof(No_lista));
	if(novo==NULL){
		return 0;
	}
	novo->info=e;
	
	// lista vazia ou inserir no inicio
	if(vazia(p_l) || e<(*p_l)->info){
		novo->prox=*p_l;
		*p_l=novo;
		return 1;
	}
	No_lista *ant = *p_l;
	No_lista *aux = (*p_l)->prox;
	while(aux!=NULL && aux->info<e){
		ant=aux;
		aux=aux->prox;
	}
	
	// verifica duplicado
	if(aux!=NULL && aux->info==e){
		free(novo);
		return 0;
	}
	novo->prox=aux;
	ant->prox=novo;
	return 1;
}

// verifica se a lista esta ordenada, retona 1 se estiver ordenada e 0 caso nao esteja
int ordenada(Lista *p_l){
	if(vazia(p_l)){
		return 1;
	}
	No_lista *aux=*p_l;
	while(aux->prox!=NULL){
		if(aux->info>aux->prox->info){
			return 0;
		}
		aux=aux->prox;
	}
	return 1;
}

// ordena a lista
void ordena(Lista *p_l){
	if(vazia(p_l)){
		return;
	}
	No_lista *i, *j;
	int temp;
	for(i=*p_l;i!=NULL;i=i->prox){
		for(j=i->prox;j!=NULL;j=j->prox){
			if(i->info>j->info){
				temp=i->info;
				i->info=j->info;
				j->info=temp;
			}
		}
	}
}

// remove o elemento que esta no inicio da lista, retorna 0 caso esteja vazia
int remove_inicio(Lista *p_l, elem_t *p_e){
	if(vazia(p_l)){
		return 0;
	}
	No_lista *aux=*p_l;
	*p_e=aux->info;
	*p_l=aux->prox;
	free(aux);
	return 1;
}

// remove o elemento que esta no fim da lista, retorna 0 caso esteja vazia
int remove_fim(Lista *p_l, elem_t *p_e){
	No_lista *aux; 
	No_lista *ant;
	
	if(!vazia(p_l)){
		aux=*p_l;
		ant=NULL;
		
		// apenas um elemento na lista
		if(aux->prox==NULL){
			*p_e=aux->info;
			free(aux);
			*p_l=NULL;
			return 1;
		}
		while(aux->prox!=NULL){
			ant=aux;
			aux=aux->prox;
		}
		*p_e=aux->info;
		ant->prox=NULL;
		free(aux);
		return 1;
	}
	return 0;
}

// remove o no de valor "e", retorna 0 caso nao seja encontrado
int remove_valor(Lista *p_l, elem_t e){
	if(vazia(p_l)){
		return 0;
	}
	No_lista *aux=*p_l;
	No_lista *ant=NULL;
	
	while(aux!=NULL && aux->info!=e){
		ant=aux;
		aux=aux->prox;
	}
	if(aux==NULL){
		return 0;
	}
	
	// remover primeiro elemento
	if(ant == NULL){
		*p_l=aux->prox;
	}
	else {
		ant->prox=aux->prox;
	}
	free(aux);
	return 1;
}

// inverte os elementos de uma lista
void inverte(Lista *p_l){
	No_lista *ant = NULL;
	No_lista *atual = *p_l;
	No_lista *prox;
	while(atual!=NULL){
		prox=atual->prox;
		atual->prox=ant;
		ant=atual;
		atual=prox;
	}
	*p_l=ant;
}

// remove todos os nos da lista
void libera(Lista *p_l){
	No_lista *aux;
	while(*p_l!=NULL){
		aux=*p_l;
		*p_l=aux->prox;
		free(aux);
	}
}

// exibe o conteudo da lista
void exibe(Lista *p_l){
	No_lista *aux;
	aux=*p_l;
	while(aux!=NULL){
		printf("%i ", aux->info);
		aux=aux->prox;
	}	
	printf("\n");
}
