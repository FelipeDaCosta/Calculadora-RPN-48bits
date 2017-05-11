#include "int_48.h"


int48_t sum_48bit(int48_t num1, int48_t num2)
{
	int64_t result = num1 + num2;
	int64_t overflow = result & 0x0000800000000000;
	if(overflow)
	{
		printf("Overflow");
	}
	return result;
}