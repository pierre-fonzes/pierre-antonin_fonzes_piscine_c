#include <stdio.h>

void o_reverse_int_table(int *arr, int taille)
{
	int i;

	if( arr == NULL){
	}
	else
	{
		for(i = 0; i < taille/2 ; i++)
		{
			int tmp = arr[i];
			arr[i] = arr[taille-i-1];
			arr[taille-i-1] = tmp;
		}
	}
}

int	main(void)
{
	int tablo[5] = {1,2,3,4,5};
	o_reverse_int_table(tablo,5);
	int i;
	for(i = 0; i<5;i++)
	{
		printf("%d",tablo[i]);
	}
	printf("\n");
	int tabTest[10] = {};
	o_reverse_int_table(tabTest,10);
	int j;
	for(j = 0 ; j<10;j++)
	{
		printf("%d",tabTest[j]);
	}
	printf("\n");

	int tabPair[4] = {1,2,3,4};
	o_reverse_int_table(tabPair,4);
	int k;
	for(k = 0; k < 4 ; k++)
	{
		printf("%d",tabPair[k]);
	}

	int *vide;
	vide = NULL;
	o_reverse_int_table(vide,0);


}
