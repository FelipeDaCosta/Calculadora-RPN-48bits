#include <stdio.h>
#include <stdlib.h>
#include "int_48.h"

typedef struct pilha{
	struct node* head;
} Pilha;

typedef struct node{
	struct node* next;
	int48_t number;
} Node;

Pilha* create_pilha();

Node* create_node(int48_t number);

void push(Pilha* pilha, int48_t number);

int48_t pop(Pilha* pilha);

void print_pilha(Pilha* pilha);