#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef PILHA_H
#define PILHA_H

typedef struct pilha{
	struct node* head;
	struct node* last;
} Pilha;

typedef struct node{
	struct node* next;
	int64_t number;
} Node;

Pilha* create_pilha();

Node* create_node(int64_t number);

void push(Pilha* pilha, int64_t number);

// Para transformar a expressao em RPN vamos usar o alrotimo shunting yard
// para que esse algoritmo trasnforme a expressao corretamente
// precisamos empilhar na ordem inversa por isso iremos usar
// essa funcao para empilhar pra baixo
void push_bellow(Pilha* pilha, int64_t number);

int64_t pop(Pilha* pilha);

int64_t top(Pilha* pilha);

void print_pilha(Pilha* pilha);

void free_pilha(Pilha** pilha);

#endif