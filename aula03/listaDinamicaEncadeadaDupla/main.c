#include<stdio.h>
#include<stdlib.h>
#include "ListaDinEncadDupla.h"

int main(){
    struct aluno al, a[4] = {{1, "Ana", 5.7, 6.1, 7.4},
                            {2, "Bia", 9.7, 6.7, 8.4},
                            {3, "Carlos", 7.5, 8.7, 6.8},
                            {4, "Daniel", 9.5, 7.8, 8.5}};
    Lista* li=cria_lista();
    printf("Tamanho: %i\n\n\n\n", tamanho_lista(li));
    int i;
    for(i=0;i<4;i++){
        insere_lista_ordenada(li, a[i]);
    }
    imprime_lista(li);
    printf("\n Tamanho: %d\n\n\n\n", tamanho_lista(li));

    for(i=0;i<4;i++){
        remove_lista_final(li);
        imprime_lista(li);
        printf("\nTamanho: %i\n\n\n\n", tamanho_lista(li));
    }
    for(i=0;i<4;i++){
        insere_lista_ordenada(li, a[i]);
    }
    imprime_lista(li);
    libera_lista(li);
    system("pause");
    return 0;
}