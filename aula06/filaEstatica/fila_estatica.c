#include<stdio.h>
#include<stdlib.h>
#include "fila_estatica.h"

void cria_fila(Fila *p_f){
	p_f->inicio=0;
	p_f->final=0;
	p_f->tamanho=0;
}

void destroi_fila(Fila *p_f){
	cria_fila(p_f);
}

int vazia(Fila *p_f){
	if(p_f->tamanho==0){
		return 1;
	}
	return 0;
}

int cheia(Fila *p_f){
	if(p_f->tamanho==MAX){
		return 1;
	}
	return 0;
}

int tamanho(Fila *p_f){
	return p_f->tamanho;
}

void enfileira(Fila *p_f, int e){
	if(cheia(p_f)){
		exit(-1);
	}
	p_f->dados[p_f->final]=e; // final sempre aponta para a proxima posicao livre
	p_f->final=(p_f->final+1)%MAX; // incrementa a fila de modo circular
	p_f->tamanho++;
}

int desenfileira(Fila *p_f){
	int aux;
	if(vazia(p_f)){
		return -1;
	}
	aux=p_f->dados[p_f->inicio];
	p_f->inicio=(p_f->inicio+1)%MAX;
	p_f->tamanho--;
	return aux;
}

int inicio_fila(Fila *p_f){
	if(!vazia(p_f)){
		return p_f->inicio;
	}
	return -1;
}