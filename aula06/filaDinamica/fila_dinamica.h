struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct fila Fila;

Fila* criar_fila();
void liberar_fila(Fila* fi);
int consulta_fila(Fila* fi, struct aluno* al);
int insere_fila(Fila* fi, struct aluno al);
int remove_fila(Fila* fi);
int tamanho_fila(Fila* fi);
int fila_vazia(Fila* fi);
int fila_cheia(Fila* fi);
void imprime_fila(Fila* fi);