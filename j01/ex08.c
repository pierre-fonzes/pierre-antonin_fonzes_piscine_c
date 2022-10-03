#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

bool	o_pow3(int n)
{
	if (n == 1)
	{
		return (true);
	}
	if (n % 3 != 0)
	{
		return (false);
	}
	o_pow3(n / 3);
}
