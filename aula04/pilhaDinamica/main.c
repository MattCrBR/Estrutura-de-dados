#include<stdio.h>
#include<stdlib.h>
#include"pilhaDinamica.h"

int main(){
	struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Pilha* pi = cria_Pilha();
    if(pi==NULL){
    	printf("Erro ao criar pilha\n");
    	return 1;
	}
    printf("Tamanho: %i\n\n",tamanho_Pilha(pi));
    int i;
    for(i=0; i < 4; i++){
        if(!insere_Pilha(pi,a[i])){
        	printf("Erro ao inserir\n");
		}
		else{
			printf("Inserido com sucesso\n");
		}
	}
    imprime_Pilha(pi);
    printf("Tamanho: %i\n\n",tamanho_Pilha(pi));

    for(i=0; i < 4; i++){
        if(!remove_Pilha(pi)){
        	printf("Erro ao remover\n");
		}
		else{
			printf("Inserido com sucesso\n");
		}
	}
    printf("Tamanho: %i\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    for(i=0; i < 4; i++){
        if(!insere_Pilha(pi,a[i])){
        	printf("Erro ao inserir\n");
		}
		else{
			printf("Inserido com sucesso\n");
		}
	}
    printf("Tamanho: %i\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    libera_Pilha(pi);
    system("pause");
    return 0;
}
