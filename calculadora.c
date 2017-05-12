#include "calculadora.h"

Calculadora* create_calculadora()
{
	Calculadora* new_calculadora = (Calculadora*) malloc(sizeof(Calculadora));
	if(!new_calculadora)
	{
		printf("Error: Falta de memoria para alocar calculadora\n");
		return NULL;
	}
	new_calculadora->operandos = create_pilha();
	new_calculadora->output_rpn = create_pilha();
	return new_calculadora;
}


void set_rpn_from_infix(Calculadora* calc, char* infix_expression)
{
	if(!calc)
		return;

	if(!calc->operandos || !calc->output_rpn)
		return;
	
	
}