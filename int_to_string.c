#include "monty.h"

/**
 * get_int - Convert integer to string
 * @num: integer to convert
 * Return: pointer to converted string
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_1 = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_1 < 0)
		length++;
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);
	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_1 < 0)
		ret[0] = '-';
	return (ret);
}

/**
 * _abs - Get absolute value of integer
 * @i: integer to get absolute value of
 * Return: absolute unsigned int
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - Get length of buffer needed for the integer
 * @num: number to get length of
 * @base: base of number to be used by buffer
 * Return: length of buffer needed
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - Correct buffer with correct num up to base 16
 * @num: num to convert to string
 * @base: base of num to be converted
 * @buff: buffer to fill
 * @buff_size: size of buffer in bytes
 * Return: void
 */
void fill_numbase_buff(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';

	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
