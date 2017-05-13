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
	new_calculadora->is_op = create_pilha();
	new_calculadora->solver = create_pilha();
	return new_calculadora;
}

// Funcoes auxiliares
static int is_num(char c)
{
	return c > 47 && c < 57;
}

static int is_op(char c)
{
	return c == SOMA || c == SUB || c == MULT || c == DIV;
}

static int is_parenthesis(char c)
{
	return c == OPENING_PAR || c == CLOSING_PAR;
}

void push_value_calc(Calculadora* calc, int48_t value)
{
	push_bellow(calc->output_rpn, value);
	push_bellow(calc->is_op, 0);
	push(calc->solver, value);	
}

void pop_operation(Calculadora* calc, char op)
{
	push_bellow(calc->output_rpn, (int48_t) op);
	push_bellow(calc->is_op, 1);


	int48_t first = pop(calc->solver);
	int48_t second = pop(calc->solver);
	switch(op){
		case SOMA:
			push(calc->solver, first+second);
			break;
		case SUB:
			push(calc->solver, second-first);
			break;
		case MULT:
			push(calc->solver, first*second);
			break;
		case DIV:
			push(calc->solver, second/first);
			break;
		default:
			printf("Ocorreu um erro: Verifique se sua expressao esta correta e tente novamente\n");
			exit(0);
	}
}

/*
* Decidi se a operacao deve ser tirada do stack de operacoes e colocada
* na stack de output. 
* Parentesis nunca sao tirados
* soma e subtracao so sao tirados se for colocar outra soma e subtracao
* divisa oe multiplicacao sao tirados por qualquer operados
*/
static int take_from_stack(char new, char on_stack)
{
	if(on_stack == OPENING_PAR || on_stack == CLOSING_PAR)
	{
		return 0;
	}
	if(on_stack == SOMA || on_stack == SUB)
	{
		if(new == DIV || new == MULT)
			return 0;
		return 1;
	}
	else
	{
		return 1;
	}
}

int48_t get_num(int* starting, char* string)
{
	int48_t valor;
	char str[20];
	int str_pointer = 0;
	for(; is_num(string[*starting]); (*starting)++, str_pointer++)
	{
		str[str_pointer] = string[*starting];
	}
	str[str_pointer] = '\0';
	// Apos a execucao do for essa variavel esta apontando para
	// o elemento posterior ao ultimo numero avaliado
	// isso volta 
	(*starting)--; 
	return atoi(str);
}

/*
* implementacao do algoritmo shunting yard. 
*/
int48_t set_rpn_from_infix(Calculadora* calc, char* infix_expression)
{
	if(!calc)
		return -1;

	if(!calc->operandos || !calc->output_rpn)
		return -1;

	// Loop pela string inteira, para cada caso (numero, operacao, parentesis)
	// faz alguma coisa diferente
	for(int str_pointer = 0; str_pointer < strlen(infix_expression); str_pointer++)
	{
		char cur = infix_expression[str_pointer];
		if(cur == ' ' || cur == '\n') // Ignorar espacos e newlines
			continue;

		if(is_num(cur))
		{
			int48_t value = get_num(&str_pointer, infix_expression);
			push_value_calc(calc, value);
		}

		else if(is_op(cur))
		{
			while(top(calc->operandos) != -1 && take_from_stack(cur, top(calc->operandos)))
			{
				char op = pop(calc->operandos);
				pop_operation(calc, op);
			}
			// Os operandos sao empilhados normalmente na pilha de operandos
			push(calc->operandos, (int48_t) cur);
		}

		else if(is_parenthesis(cur))
		{
			if(cur == CLOSING_PAR)
			{
				char op;
				while( (op = pop(calc->operandos)) != OPENING_PAR 	)
				{
					pop_operation(calc, op);
				}
			}
			else
			{
				// Os operandos sao empilhados normalmente na pilha de operandos
				push(calc->operandos, (int48_t) cur);
			}
		}
		else {
			printf("Caracter Duvidoso: %c\n", cur);
			printf("Ocorreu um erro: Verifique se sua expressao esta correta e tente novamente\n");
			exit(0);
		}
	}
	// Coloca o resto das operacoes na pilha
	char op;
	while( (op = pop(calc->operandos)) != -1 	)
	{
		pop_operation(calc, op);
	}
	return top(calc->solver);
}

void print_rpn_format(Calculadora* calc)
{
	for(Node* cur = calc->output_rpn->head, *is_op = calc->is_op->head
		; cur; cur = cur->next, is_op = is_op->next)
	{
		if(is_op->number)
		{
			switch(cur->number)
			{
				case SOMA:
					printf(" + ");
					break;
				case SUB:
					printf(" - ");
					break;
				case MULT:
					printf(" * ");
					break;
				case DIV:
					printf(" / ");
					break;
				default:
					printf(" ? ");
					break;
			}
		}
		else
		{
			printf(" %lld ", cur->number);
		}
	}
	printf("\n");
}

void free_calc(Calculadora* calc)
{
	free_pilha(&calc->output_rpn);
	free_pilha(&calc->operandos);
	free_pilha(&calc->is_op);
	free_pilha(&calc->solver);
	free(calc);
}

