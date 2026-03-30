typedef int elem_t;
typedef struct no{
	elem_t info;
	struct no *prox;
} No_lista;

typedef No_lista * Lista;

// inicializa uma lista
void cria(Lista *p_l);

// verifica se a lista esta vazia ou nao
int vazia(Lista *p_l);

// insere um elemento no inicio da lista
int insere_inicio(Lista *p_l, elem_t e);

// insere um elemento no final da lista
int insere_final(Lista *p_l, elem_t e);

// insere um elemento de maneira ordenada, retorna 0 caso ja exista na lista, assume que a lista esteja ordenada
int insere_ordenado(Lista *p_l, elem_t e);

// verifica se a lista esta ordenada, retona 1 se estiver ordenada e 0 caso nao esteja
int ordenada(Lista *p_l);

// ordena a lista
void ordena(Lista *p_l);

// remove o elemento que esta no inicio da lista, retorna 0 caso esteja vazia
int remove_inicio(Lista *p_l, elem_t *p_e);

// remove o elemento que esta no fim da lista, retorna 0 caso esteja vazia
int remove_fim(Lista *p_l, elem_t *p_e);

// remove o no de valor "e", retorna 0 caso nao seja encontrado
int remove_valor(Lista *p_l, elem_t e);

// inverte os elementos de uma lista
void inverte(Lista *p_l);

// remove todos os nos da lista
void libera(Lista *p_l);

// exibe o conteudo da lista
void exibe(Lista *p_l);
