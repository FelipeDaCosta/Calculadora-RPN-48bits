#include "pilha.h"

typedef struct calculadora {
	Pilha* operandos; // Usada na conversao de infix para rpn
	Pilha* output_rpn; // Aqui fica os operandos e numeros ja em posicao rpn
} Calculadora;

/*
* Cria a calculadora. As stacks comecam vazias
*/
Calculadora* create_calculadora();

/*
* Recebe uma calculadora e uma string contendo uma expressao infixa
* Empilha as operacoes na posicao RPN na output_rpn da calculadora
*/
void set_rpn_from_infix(Calculadora* calc, char* infix_expression);