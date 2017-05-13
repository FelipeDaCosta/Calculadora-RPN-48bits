#include <stdio.h>
#include <stdint.h>
#include "calculadora.h"
#include "int_48.h"

void usage()
{
	printf("Erro:\nMais de um parametro passado para programa\n");
	printf("Digite apenas a expressao desejada sem espacos\n");
	exit(0);
}


int main(int argc, char** argv)
{
	Calculadora* calc = create_calculadora();
	char* str = malloc(sizeof(char)*65);
	if(argc == 1)
	{
		printf("Digite uma expressao de no maximo 64 caracteres contendo apenas inteiros +*-/ e parentesis:\n");
		fgets(str, 64, stdin);
	}
	else if(argc == 2)
	{
		str = argv[1];
	}
	else
	{
		usage();
	}
	int48_t result = set_rpn_from_infix(calc, str);
	printf("\n\nVoce digitou a expressao: %s\n", str);
	printf("Essa expressao no formato RPN fica: ");
	print_rpn_format(calc);
	printf("O resultado da expressao eh: %lld\n", result);
	free_calc(calc);
	return 0;
}