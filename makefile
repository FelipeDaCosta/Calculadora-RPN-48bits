main: pilha.o
	gcc main.c -o test pilha.o

pilha:
	gcc pilha.c -o pilha.o -c