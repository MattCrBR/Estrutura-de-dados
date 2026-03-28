#include<stdio.h>
#include"bag.h"

int main()
{
	Bag sacola;
	int op=0, num;
	init(&sacola);
	
	while(op!=4){
		printf("Voce esta usando uma sacola para inserir numeros inteiros positivos\n");
		printf("O que deseja fazer\n");
		printf("1. Inserir, 2. Remover, 3. Buscar, 4. Sair: ");
		scanf("%i", &op);
		switch(op){
			case 1:
				printf("Entre com o valor a ser inserido: ");
				scanf("%i", &num);
				if(num<=0){
					printf("Apenas numeros positivos sao permitidos\n");
					break;
				}
				if(insert(&sacola, num)){
					printf("Inserido com sucesso\n");
				}
				else{
					printf("Sacola cheia\n");
				}
				break;
			case 2:
				printf("Entre com o valor a ser removido: ");
				scanf("%i", &num);
				if(deleta(&sacola, num)){
					printf("Removido com sucesso\n");
				}
				else{
					printf("Valor nao encontrado\n");
				}
				break;
			case 3:
				int count;
				printf("Entre com o valor a ser buscado: ");
				scanf("%i", &num);
				count=check(&sacola, num);
				if(count!=0){
					printf("O valor: %i aparece %i vez(es)\n", num, count);
				}
				else{
					printf("O valor nao foi encontrado\n");
				}
				break;
			case 4: break;
			default: 
				printf("Opcao invalida, tente novamente");
		}
		printf("Sacola inteira: ");
		printall(sacola);
	}
}
