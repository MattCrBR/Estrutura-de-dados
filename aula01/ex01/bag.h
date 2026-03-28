#define BAGSIZE 50

typedef struct b{
	int item[BAGSIZE];
} Bag;

// inicializa a bag vazia
void init(Bag *b);

// retorna o numero de itens na bag
int size(Bag *b);

// insere um elemento na bag, retorna 1 para insercao com sucesso ou 0 pra bag cheia
int insert(Bag *b, int elem);

// verifica quantas vezes o elemento esta na bag
int check(Bag *b, int elem);

// remove o elem da bag, retorna 1 se ocorreu com sucesso ou 0 se nao foi encontrado
int deleta(Bag *b, int elem);

// imprime todos os elementos da bag
void printall(Bag b);
