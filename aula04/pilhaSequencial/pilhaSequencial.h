#define MAX 100
struct aluno{
	int matricula;
	char nome[30];
	float n1,n2,n3;
};
typedef struct pilha{
	int qtd;
	struct aluno dados[MAX];
} Pilha;

// cria a pilha na memoria
Pilha* cria_Pilha();

// libera a pilha
void libera_Pilha(Pilha* pi);

// pega o elemento do topo sem remover
int consulta_topo_Pilha(Pilha* pi, struct aluno *al);

// push(empilha)
int insere_Pilha(Pilha* pi, struct aluno al);

// pop(desemepilha)
int remove_Pilha(Pilha* pi);

// quantos elementos tem
int tamanho_Pilha(Pilha* pi);

// retorna 1 se vazia
int Pilha_vazia(Pilha* pi);

// retorna 1 se cheia
int Pilha_cheia(Pilha* pi);

// mostra os elementos
void imprime_Pilha(Pilha* pi);
