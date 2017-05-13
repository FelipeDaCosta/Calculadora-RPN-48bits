#include <stdio.h>
#include <assert.h>
#include "calculadora.h"

int main()
{
	Calculadora* calculadora = create_calculadora();
	// Testando criacao
	assert(calculadora);
	assert(calculadora->operandos);
	assert(calculadora->output_rpn);
	assert(calculadora->is_op);
	// Testando a funcao get_num
	int starting = 0;
	assert(get_num(&starting, "12345") == 12345);
	assert(starting == 4);
	starting = 0;
	assert(get_num(&starting, "43 ") == 43);
	assert(starting == 1);
	starting = 1;
	assert(get_num(&starting, "12+") == 2);
	assert(starting == 1);
	printf("\n\nSUCCESS: Modulo calculadora passou em todos os testes.\n\n");
	return 0;
}