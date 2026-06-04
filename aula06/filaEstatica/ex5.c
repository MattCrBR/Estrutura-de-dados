#include<stdio.h>
#include<stdlib.h>
#include "fila_estatica.h"

void junta_fila(Fila *p_f1, Fila *p_f2, Fila *p_f3);

int main(){
	Fila f1,f2,f3;
	int i;
	cria_fila(&f1);
	cria_fila(&f2);
	cria_fila(&f3);
	for(i=0;i<3;i++){
		enfileira(&f1, i*3);
	}
	for(i=0;i<5;i++){
		enfileira(&f2, i*2);
	}
	junta_fila(&f1, &f2, &f3);
	while(!vazia(&f3)){
		printf("%i ", desenfileira(&f3));
	}
	printf("\n");
	return 0;
}

void junta_fila(Fila *p_f1, Fila *p_f2, Fila *p_f3){
	while(!vazia(p_f1)&&!vazia(p_f2)){
		if(inicio_fila(p_f1)<inicio_fila(p_f2)){
			enfileira(p_f3, desenfileira(p_f1));
		}
		else{
			enfileira(p_f3, desenfileira(p_f2));
		}
		while(!vazia(p_f1)){
			enfileira(p_f3, desenfileira(p_f1));
		}
		while(!vazia(p_f2)){
			enfileira(p_f3, desenfileira(p_f2));
		}
	}
}