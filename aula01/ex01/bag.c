#include<stdio.h>
#include"bag.h"

void init(Bag *b){
	int i;
	for(i=0;i<BAGSIZE;i++){
		b->item[i]=-1;
	}
}

int size(Bag *b){
	int i, count=0;
	for(i=0;i<BAGSIZE;i++){
		if(b->item[i]!=-1){
			count++;
		}
	}
	return count;
}

int insert(Bag *b, int elem){
	int i;
	for(i=0;i<BAGSIZE;i++){
		if(b->item[i]==-1){
			b->item[i]=elem;
			return 1;
		}
	}
	return 0;
}

int check(Bag *b, int elem){
	int i, count=0;
	for(i=0;i<BAGSIZE;i++){
		if(b->item[i]==elem){
			count++;
		}
	}
	return count;
}

int deleta(Bag *b, int elem){
	int i;
	for(i=0;i<BAGSIZE;i++){
		if(b->item[i]==elem){
			b->item[i]=-1;
			return 1;
		}
	}
	return 0;
}

void printall(Bag b){
	int i;
	for(i=0;i<BAGSIZE;i++){
		if(b.item[i]!=-1){
			printf("%i ", b.item[i]);
		}	
	}
	printf("\n\n");
}
