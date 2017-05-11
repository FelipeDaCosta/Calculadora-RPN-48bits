#include <stdio.h>
#include <stdint.h> // int64_t

/*
* Usando inteiros de 64 bits para representar inteiro de 48.
* a inicializacao e as operacoes vao ser feitas por meio de funcoes.
*/
typedef int64_t int48_t;

/*
* Soma com deteccao de overflow
*/
int48_t sum_48bit(int48_t num1, int48_t num2);