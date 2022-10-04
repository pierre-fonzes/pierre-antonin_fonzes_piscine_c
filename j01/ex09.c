#include <unistd.h>
#include <stdio.h>

int concatenate(int x, int y){
	int pow = 10;
	while(y >= pow){
		pow *= 10;
	}
	return x * pow + y;
}
int	o_atoi(char *str)
{
	int	cpt;
	int	res;

	res = 0;
	for(cpt = 0; cpt < sizeof(str); cpt++)
	{
		if(str[cpt] != 0 && str[cpt] != ' ' )
		{
			res = concatenate(res,str[cpt]);		
		}
	}
	return res;

}

int	main(void)
{
	char tablo[10] = {0,0,0,' ',1,2,3,4};
	int res = o_atoi(tablo);
	printf("%d",res);
}


