#include <stdbool.h>
#include <string.h>

char * itoa(int value, char * str, int base)
{
	int i = 0;
	int isNeg = false;

	if (value == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	if (value < 0 && base == 10)
	{
		value = -value;
		isNeg = true;
	}

	while (value != 0)
	{
		int rem = value % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		value = value/base;
	}

	if (isNeg)
		str[i++] = '-';

	str[i] = '\0';
	int start,end;
	char temp;
	for(start = 0, end = strlen(str) - 1; start < end; start++, end--)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
	}

	return str;
}
