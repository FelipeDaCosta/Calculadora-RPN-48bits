#include <string.h> //
#include <stdlib.h> // atoi()
#include "pilha.h"
#include "int_48.h"

enum {SOMA = 43, SUB = 45, MULT = 42, DIV = 47, OPENING_PAR = 40, CLOSING_PAR = 41};

typedef struct calculadora {
	Pilha* operandos; // Usada na conversao de infix para rpn
	Pilha* output_rpn; // Aqui fica os operandos e numeros ja em posicao rpn
	Pilha* is_op; // Para saber quais elementos da output_rpn sao operacoes
} Calculadora;

/*
* Cria a calculadora. As stacks comecam vazias
*/
Calculadora* create_calculadora();

/*
* Recebe uma string e um ponteiro para inteiro. O inteiro deve conter
* A Posicao na string onde o numero comeca
* Ao final retorna o numero representado na string como inteiro
* e altera o ponteiro passado para apontar pro ultimo digito do numero
*/
int48_t get_num(int* starting, char* string);


/*
* Recebe uma calculadora e uma string contendo uma expressao infixa
* Empilha as operacoes na posicao RPN na output_rpn da calculadora
*/
void set_rpn_from_infix(Calculadora* calc, char* infix_expression);

/*
*
*
*/
int48_t get_result(Calculadora* calc);

void print_rpn_format(Calculadora* calc);

