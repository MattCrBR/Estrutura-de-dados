#include<stdio.h>
#include"lista_dinamica.h"

int main()
{
	int num, op=1;
	Lista l;
	cria(&l);
	
	while(op!=0)
	{
		printf("\n1 - Insere um numero no inicio da lista");
		printf("\n2 - Insere um numero no fim da lista");
		printf("\n3 - Insere um numero de maneira ordenada");
		printf("\n4 - Verifica se a lista esta ordenada");
		printf("\n5 - Ordena a lista");
		printf("\n6 - Remove o elemento que esta no inicio da lista");
		printf("\n7 - Remove o elemento que esta no fim da lista");
		printf("\n8 - Remove um valor determinado");
		printf("\n9 - Inverte");
		printf("\n10 - Exibe a lista");
		printf("\n\nDigite 0 pra sair");
		printf("\nEntre com uma das opcoes: ");
		scanf("%i", &op);
		
		switch(op){
		case 1:
			printf("\n\nEntre com o numero a ser inserido: ");
			scanf("%i", &num);
			if(insere_inicio(&l, num)){
				printf("Inserido com sucesso");
			}
			else{
				printf("Erro ao alocar memoria");
			}
			break;
		case 2:
			printf("\n\nEntre com o numero a ser inserido: ");
			scanf("%i", &num);
			if(insere_final(&l, num)){
				printf("Inserido com sucesso");
			}
			else
			{
				printf("Lista cheia");
			}
			break;
		case 3:
			printf("\n\nEntre com o numero a ser inserido: ");
			scanf("%i", &num);
			if(!ordenada(&l)){
				ordena(&l);
			}
			if(insere_ordenado(&l, num)){
				printf("Inserido com sucesso");
			}
			else
			{
				printf("Elemento ja existe ou lista cheia");
			}
			break;
		case 4:
			if(!ordenada(&l)){
				printf("\nA lista nao esta ordenada");
			}
			else {
				printf("\nA lista esta ordenada");
			}
			break;
		case 5:
			if(ordenada(&l)){
				printf("\nA lista ja esta ordenada");
			}
			else
			{
				ordena(&l);
				printf("\nA lista foi ordenada");
			}
			break;
		case 6:
			if(remove_inicio(&l, &num)){
				printf("\nNumero removido: %i", num);
			}
			else {
				printf("\nLista vazia");
			}
			break;
		case 7:
			if(remove_fim(&l, &num)){
				printf("\nNumero removido: %i", num);
			}
			else{
				printf("\nLista vazia");
			}
			break;
		case 8:
			printf("\nEntre com o numero a ser removido: ");
			scanf("%i", &num);
			if(!remove_valor(&l, num)){
				printf("Numero nao encontrado");
			}
			else{
				printf("Numero removido: %i", num);
			}
			break;
		case 9:
			inverte(&l);
			printf("A lista foi invertida");
			break;
		case 10:
			exibe(&l);
			break;
	}
	exibe(&l);
	printf("\n\n");
	}
	libera(&l);
	return 0;
}
