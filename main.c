#include <stdio.h>
#include "pilha.h"

int main()
{
	Pilha* pilha = create_pilha();
	push(pilha, 10);
	push(pilha, 20);
	push(pilha, 30);
	push(pilha, 40);
	print_pilha(pilha);
	printf("Pop valor 1: %lld\n", pop(pilha));
	printf("Pop valor 2: %lld\n", pop(pilha));
	printf("Pop valor 3: %lld\n", pop(pilha));
	print_pilha(pilha);
	return 0;
}