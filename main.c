#include <stdio.h>
#include <stdint.h>
#include "calculadora.h"
#include "int_48.h"



int main()
{
	Calculadora* calc = create_calculadora();
	set_rpn_from_infix(calc, "16+(4/2)*5");
	print_rpn_format(calc);
	return 0;
}