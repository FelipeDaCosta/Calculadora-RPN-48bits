#include <stdio.h>
#include <assert.h>
#include "pilha.h"

int main()
{
	Pilha* pilha = create_pilha();
	assert(pilha != NULL);
	assert(top(pilha) == -1);
	pop(pilha);
	push(pilha, 1);
	push(pilha, 2);
	assert(top(pilha) == 2);
	assert(pop(pilha) == 2);
	assert(top(pilha) == 1);
	assert(pop(pilha) == 1);
	assert(pop(pilha) == -1);
	push_bellow(pilha, 1);
	push_bellow(pilha, 2);
	assert(top(pilha) == 1);
	free_pilha(&pilha);
	assert(pilha == NULL);
	printf("\n\nSUCCESS: Modulo pilha passou em todos os testes.\n\n");
	return 0;
}