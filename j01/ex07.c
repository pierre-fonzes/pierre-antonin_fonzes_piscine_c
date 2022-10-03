#include <unistd.h>


long o_arrsum(int *arr, int size)
{
	int cpt;
	int sum = 0;
	for(cpt = 0;cpt<size;cpt++)
	{
		sum += arr[cpt];
	}
	return sum;

}
