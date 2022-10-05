#include <unistd.h>
#include <stdio.h>

void o_print_number(int nb)
{
	int cp;
	
	if(nb<0)
	{
		nb = -nb;
		write(1,"-",1);
	}
	if(nb>9)
	{
		o_print_number(nb/10);
	}
	cp = nb%10 + 48;//48 = 0 in ASCII table so -> if we want the ASCII code for 7 : 48 + 7
	write(1,&cp,1);
}
