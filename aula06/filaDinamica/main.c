#include<stdio.h>
#include<stdlib.h>
#include "fila_dinamica.h"

int main(){
    struct aluno al, a[4] = {{1, "Ana", 5.7, 6.1, 7.4},
                            {2, "Bia", 9.7, 6.7, 8.4},
                            {3, "Carlos", 7.5, 8.7, 6.8},
                            {4, "Daniel", 9.5, 7.8, 8.5}};
    Fila* fi = criar_fila();
    printf("Tamanho: %i\n\n\n\n", tamanho_fila(fi));
    int i;
    for(i=0;i<4;i++){
        insere_fila(fi, a[i]);
        if(fila_vazia(fi)){
            printf("Erro ao inserir na fila!\n");
        }
        consulta_fila(fi, &al);
        printf("Consulta: %i \t %s\n", al.matricula, al.nome);
    }
    imprime_fila(fi);
    printf("Tamanho: %i\n\n\n\n", tamanho_fila(fi));
    for(i=0;i<4;i++){
        remove_fila(fi);
        consulta_fila(fi, &al);
        printf("Consulta: %i \t %s\n", al.matricula, al.nome);
    }
    printf("Tamanho: %i\n\n\n\n", tamanho_fila(fi));
    imprime_fila(fi);
    for(i=0;i<4;i++){
        insere_fila(fi, a[i]);
    }
    printf("Tamanho: %i\n\n\n\n", tamanho_fila(fi));
    imprime_fila(fi);
    liberar_fila(fi);
    system("pause");
    return 0;
}