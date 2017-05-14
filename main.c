 /*******************************************************************************************************
    UnB - Universidade de Brasília
    Software Básico - 2017/1
    Professor: Marcelo Ladeira
    Grupo 5: 
    	Felipe da Costa Malaquias 13/0044440
    	Paulo Victor Gonçalves Farias - 13/0144754
    	Ricardo Hideki Ito - 12/0045818

   	Tarefa: Máquina de Pilha e aritmética via software
 -------------------------------------------------------------------------------------------------------
 
 	Objetivo: implementar um resolvedor de expressões 
 	aritméticas baseado em uma máquina de pilha, que receba 
 	uma equação por linha de comando ou dentro do programa, 
 	caso não tenham sido passados os parâmetros. 
 	A equação deve ser razoavelmente simples e utilizar apenas 
 	inteiros. Os parâmetros passados serão por notação infixa, 
 	com ou sem parênteses.

 ------------------------------------------------------------------------------------------------------
 Funcionamento do programa:
 --------------------------
 >> 1ª Etapa: Checa se o usuário passou uma expressão como parâmetro, se sim continua o programa. Caso
 contrário vai pedir uma expressão que não exceda 64 caracteres.
    
 >> 2ª Etapa: Converte a expressão passada de notação infixa para notação polonesa reversa. Utiliza
 o algoritmo de Shaunting Yard. Isso facilita para que o resolvedor possa fazer suas operações.

 >> 3ª Etapa: Com a expressão em notação pósfixa é possível resolver a expressão e imprimir o resultado.
 É importante notar que o overflow é checado.

********************************************************************************************************/
/*** Bibliotecas Usadas ***/
#include <stdio.h>
#include <stdint.h>
#include "calculadora.h"

void usage()
{
	printf("Erro:\nMais de um parametro passado para programa\n");
	printf("Digite apenas a expressao desejada sem espacos\n");
	exit(0);
}

/*************************** Main ***********************************************/
int main(int argc, char** argv)
{
	/*** Declaração de Variáveis ***/
	Calculadora* calc = create_calculadora();	/* Cria uma nova calculadora */
	char* str = malloc(sizeof(char)*65);		/* Aloca espaço para uma string */
	int64_t result; 							/* Resultado da expressão */

	/* Argument Counter = 1, usuário não digitou a expressão no terminal. */
	if(argc == 1)
	{
		printf("Digite uma expressao de no maximo 64 caracteres contendo apenas inteiros +*-/ e parentesis:\n");
		fgets(str, 64, stdin);
	}
	/* Argument Counter = 2, usuário digitou a expressão no terminal. */
	else if(argc == 2)
	{
		str = argv[1];
	}
	/* Argument Counter > 2, tratamento de erro. */
	else
	{
		usage();
	}

	/* Mostr a expressão digitada e como fica na notação polonesa reversa */
	printf("\n\nVoce digitou a expressao: %s\n", str);
	printf("Essa expressao no formato RPN fica: ");
	result = set_rpn_from_infix(calc, str);
	print_rpn_format(calc);
	/* Imprime o resultado obtido */
	printf("O resultado da expressao eh: %ld\n", result);

	/* Libera o espaço de memória alocado para a calculadora */
	free_calc(calc);

	/* Fim do programa */
	return 0;
}