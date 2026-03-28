#include<stdio.h>
#include"lista_estatica.h"

// inicializa a lista
void cria(Lista *p_l){
	p_l->tam=0;
}

// verifica se esta vazia
int vazia(Lista *p_l){
	return(p_l->tam==0);
}

int insere_inicio(Lista *p_l, elem_t e){
	if(p_l->tam==MAX){
		return 0;
	}
	int i;
	for(i=p_l->tam;i>0;i--){
		p_l->vet[i]=p_l->vet[i-1];
	}
	p_l->vet[0]=e;
	p_l->tam++;
	return 1;
}

int insere_final(Lista *p_l, elem_t e){
	if(p_l->tam==MAX){
		return 0;
	}
	p_l->vet[p_l->tam] = e;
	p_l->tam++;
	return 1;
}

int insere_ordenado(Lista *p_l, elem_t e){
	if(p_l->tam==MAX){
		return 0;
	}
	int i;
	//verifica se ja existe
	for(i=0;i<p_l->tam;i++){
		if(p_l->vet[i]==e){
			return 0;
		}
	}
	// acha posicao
	i=p_l->tam-1;
	while(i>=0 && p_l->vet[i]>e){
		p_l->vet[i+1]=p_l->vet[i];
		i--;
	}
	p_l->vet[i+1]=e;
	p_l->tam++;
	return 1;
}

int ordenada(Lista *p_l){
	int i;
	for(i=0;i<p_l->tam-1;i++){
		if(p_l->vet[i]>p_l->vet[i+1]){
			return 0;
		}
	}
	return 1;
}

void ordena(Lista *p_l){
	int i, j, temp;
	for(i=0;i<p_l->tam-1;i++){
		for(j=0;j<p_l->tam-i-1;j++){
			if(p_l->vet[j]>p_l->vet[j+1]){
				temp=p_l->vet[j];
				p_l->vet[j]=p_l->vet[j+1];
				p_l->vet[j+1]=temp;
			}
		}
	}
}

int remove_inicio(Lista *p_l, elem_t *p_e){
	if(vazia(p_l)){
		return 0;
	}
	*p_e=p_l->vet[0];
	int i;
	for(i=0;i<p_l->tam-1;i++){
		p_l->vet[i]=p_l->vet[i+1];
	}
	p_l->tam--;
	return 1;
}

int remove_fim(Lista *p_l, elem_t *p_e){
	if(vazia(p_l)){
		return 0;
	}
	*p_e=p_l->vet[p_l->tam-1];
	p_l->tam--;
	return 1;
}

int remove_valor(Lista *p_l, elem_t e){
	int i, j;
	for(i=0;i<p_l->tam;i++){
		if(p_l->vet[i]==e){
			// shift pra esquerda
			for(j=i;j<p_l->tam-1;j++){
				p_l->vet[j]=p_l->vet[j+1];
			}
			p_l->tam--;
			return 1;
		}
	}
	return 0; // nao encontrou
}

void inverte(Lista *p_l){
	int i, temp;
	for(i=0;i<p_l->tam/2;i++){
		temp=p_l->vet[i];
		p_l->vet[i]=p_l->vet[p_l->tam-1-i];
		p_l->vet[p_l->tam-1-i]=temp;
	}
}

void libera(Lista *p_l){
	p_l->tam=0;
}

void exibe(Lista *p_l){
	int i;
	for(i=0;i<p_l->tam;i++){
		printf("%i ", p_l->vet[i]);
	}
	printf("\n");
}
