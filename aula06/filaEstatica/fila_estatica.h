#define MAX 10

typedef struct f
{
	int inicio;
	int final;
	int tamanho;
	int dados[MAX];
} Fila;

void cria_fila(Fila *p_f);
void destroi_fila(Fila *p_f);
int vazia(Fila *p_f);
int cheia(Fila *p_f);
int tamanho(Fila *p_f);
void enfileira(Fila *p_f, int e);
int desenfileira(Fila *p_f);
int inicio_fila(Fila *p_f);