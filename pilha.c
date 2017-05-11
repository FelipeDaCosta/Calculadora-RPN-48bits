#include "pilha.h"

Pilha* create_pilha()
{
	Pilha* new_pilha = (Pilha*) malloc(sizeof(Pilha));
	if(new_pilha == NULL)
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
	if(new_node == NULL)
	{
		printf("Error: Falta de memoria ao tentar alocar novo nodo\n")
		return NULL;
	}
	new_node->number = number;
	new_node->next = NULL;
	return new_node;
}

void push(Pilha* pilha, int48_t number)
{
	if(pilha != NULL)
	{
		Node* new = create_node(number);
		if(new == NULL)
			return;

		new->next = pilha->head;
		pilha->head = new;
	}
}

int48_t pop(Pilha* pilha)
{
	if(pilha != NULL && pilha->head != NULL){
		Node* old_head = pilha->head;
		pilha->head = pilha->head->next;
		int48_t old_head_number = old_head->number;
		free(old_head);
		return old_head_number;
	}
	printf("Error: POP usado em pilha vazia\n");
	return -1;
}

void print_pilha(Pilha* pilha)
{
	if(pilha != NULL)
	{
		printf("Head ");
		for(Node* cur = pilha->head; cur != NULL; cur = cur->next)
		{
			printf("%lld %s", cur->number, cur->next == NULL ? "Tail\n" : "-> ");
		}
	}
}