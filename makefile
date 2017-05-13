main: calculadora.o pilha.o
	gcc main.c -o test calculadora.o pilha.o

calculadora: pilha.o
	gcc calculadora.c -o calculadora.o pilha.o

calculadora_t: calculadora.o pilha.o
	gcc calculadora_teste.c -o calculadora_teste calculadora.o pilha.o

pilha:
	gcc pilha.c -o pilha.o -c

pilha_t: pilha.o
	gcc pilha_teste.c -o pilha_teste pilha.o