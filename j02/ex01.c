#include <unistd.h>

void o_print_char(char c)
{
	write(1,&c,1);
}



void o_print_string(char *str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		o_print_char(str[i]);
		i++;
	}
	write(1,"\n",1);
	i = 0;

}

int	main(void)
{
	char tablo[10] = "Le c nul";
	o_print_string(tablo);

	char tab[50] = "LA PENDAséon";
	o_print_string(tab);

	char tabl[50] = "   123 c'ést nul";
	o_print_string(tabl);
}
