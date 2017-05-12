#include "pilha.h"

Pilha* create_pilha()
{
	Pilha* new_pilha = (Pilha*) malloc(sizeof(Pilha));
	if(!new_pilha)
	{
		printf("Error: Falta de memoria ao tentar alocar pilha\n");
		return NULL;
	}
	new_pilha->head = NULL;
	return new_pilha;
}

Node* create_node(int48_t number)
{
	Node* new_node = (Node *) malloc(sizeof(Node));
	if(!new_node)
	{
		printf("Error: Falta de memoria ao tentar alocar novo nodo\n");
		return NULL;
	}
	new_node->number = number;
	new_node->next = NULL;
	return new_node;
}

void push(Pilha* pilha, int48_t number)
{
	if(pilha)
	{
		Node* new = create_node(number);
		if(!new)
			return;

		new->next = pilha->head;
		pilha->head = new;
	}
}

int48_t pop(Pilha* pilha)
{
	if(pilha && pilha->head ){
		Node* old_head = pilha->head;
		pilha->head = pilha->head->next;
		int48_t old_head_number = old_head->number;
		free(old_head);
		return old_head_number;
	}
	return -1;
}

int48_t top(Pilha* pilha)
{
	if(pilha && pilha->head)
		return pilha->head->number;
	return -1;
}

void print_pilha(Pilha* pilha)
{
	if(pilha)
	{
		printf("Head ");
		for(Node* cur = pilha->head; cur; cur = cur->next)
		{
			printf("%lld %s", cur->number, cur->next == NULL ? "Tail\n" : "-> ");
		}
	}
}

void free_pilha(Pilha** pilha)
{
	if(!*pilha)
		return;

	while((*pilha)->head)
	{
		pop(*pilha);
	}

	free(*pilha);
	*pilha = NULL;
}