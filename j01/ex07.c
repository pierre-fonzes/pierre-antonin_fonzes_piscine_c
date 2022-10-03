#include <unistd.h>


long o_arrsum(int *arr)
{
	int cpt;
	int sum = 0;
	for(cpt = 0;cpt<sizeof(arr);cpt++)
	{
		sum += arr[cpt];
	}
	return sum;

}
