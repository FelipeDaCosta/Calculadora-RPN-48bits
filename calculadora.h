#include <string.h> //
#include <stdlib.h> // atoi()
#include "pilha.h"
#include "int_48.h"

enum {SOMA = 43, SUB = 45, MULT = 42, DIV = 47, OPENING_PAR = 40, CLOSING_PAR = 41};

/*
* Vao ser necessarias 4 pilhas.
* duas vao ser usadas para guardar o formato RPN 
* (output_rpn que guarda numeros e operandos e is_op que guarda quais
* numeros do output_rpn sao operandos)
* E duas para de fato resolver o problema.
* (operandos guarda os operandos para posicionalos devidamente
* de acordo com o algoritmo. A solver guarda os numeros e vai realizando
* as operacoes)
*/
typedef struct calculadora {
	// As duas primeiras sao usadas pra guardar a operacao em formato rpn
	Pilha* output_rpn; // Aqui fica os operandos e numeros em posicao rpn
	Pilha* is_op; // Para saber quais elementos da output_rpn sao operacoes
	// As duas ultimas sao usadas para resolver o problema
	Pilha* operandos; // Usada na conversao de infix para rpn
	Pilha* solver; // Pilha usada para resolver o problema
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
* Coloca um valor nas devidas pilhas
*/
void push_value_calc(Calculadora* calc, int48_t value);

/*
* Faz pop de operacao da pilha calculadora->operandos.
* (Realiza a operacao em solver e empilha o operando em output_rpn e is_op)
*/
void pop_operation(Calculadora* calc, char op);

/*
* Recebe uma calculadora e uma string contendo uma expressao infixa
* Empilha as operacoes na posicao RPN na output_rpn da calculadora
*/
int48_t set_rpn_from_infix(Calculadora* calc, char* infix_expression);

/*
* Imprime no formato RPN (Guardado na pilha output_rpn)
*/
void print_rpn_format(Calculadora* calc);

/*
* Libera memoria da calculadora
*/
void free_calc(Calculadora* calc);

