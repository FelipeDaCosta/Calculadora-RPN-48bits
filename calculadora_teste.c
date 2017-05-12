#include <stdio.h>
#include <assert.h>
#include "calculadora.h"

int main()
{
	Calculadora* calculadora = create_calculadora();
	assert(calculadora);
	assert(calculadora->operandos);
	assert(calculadora->output_rpn);
	printf("\n\nSUCCESS: Modulo calculadora passou em todos os testes.\n\n");
	return 0;
}