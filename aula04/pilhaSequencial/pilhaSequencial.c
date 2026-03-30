#include<stdio.h>
#include<stdlib.h>
#include"pilhaSequencial.h"

// cria a pilha na memoria
Pilha* cria_Pilha(){
	Pilha *pi;
	pi=(Pilha*)malloc(sizeof(struct pilha));
	if(pi!=NULL){
		pi->qtd=0;
	}
	return pi;
}

// libera a pilha
void libera_Pilha(Pilha* pi){
	free(pi);
}

// pega o elemento do topo sem remover
int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
	if(pi==NULL || pi->qtd==0){
		return 0; // pilha vazia
	}
	*al=pi->dados[pi->qtd-1];
	return 1;
}

// push(empilha)
int insere_Pilha(Pilha* pi, struct aluno al){
	if(pi==NULL){
		return 0;
	}
	if(pi->qtd==MAX){ //pilha cheia
		return 0;
	}
	pi->dados[pi->qtd]=al;
	pi->qtd++;
	return 1;
}

// pop(desemepilha)
int remove_Pilha(Pilha* pi){
	if(pi==NULL || pi->qtd==0){
		return 0;
	}
	pi->qtd--;
	return 1;
}

// quantos elementos tem
int tamanho_Pilha(Pilha* pi){
	if(pi==NULL){
		return 0; //pq retornar -1
}
	else{
		return pi->qtd;
	}
}

// retorna 1 se vazia
int Pilha_vazia(Pilha* pi){
	if(pi==NULL){
		return 0;
	}
	return(pi->qtd==0);
}

// retorna 1 se cheia
int Pilha_cheia(Pilha* pi){
	if(pi==NULL){
		return 0;
	}
	return(pi->qtd==MAX);
}

// mostra os elementos
void imprime_Pilha(Pilha* pi){
	if(pi==NULL){
		return;
	}
	int i;
	for(i=pi->qtd-1;i>=0;i--){
		printf("Matricula: %i\n", pi->dados[i].matricula);
		printf("Nome: %s\n", pi->dados[i].nome);
		printf("Notas: %.2f %.2f %.2f\n", pi->dados[i].n1, pi->dados[i].n2, pi->dados[i].n3);
		printf("-----------------------------\n");
	}
}
