#include <stdio.h>
#include <stdbool.h>

bool o_pow3(int n)
{
	if(n==1)
	{
		return true;
	}
	if(n%3 != 0)
	{
		return false;
	}
	o_pow3(n/3);
}

int main()
{
	int res = 9;
	printf("%s\n", o_pow3(res)?"true":"false");
}
