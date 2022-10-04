#include <stdio.h>
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

int main(int argc, char *argv[])
{
	int i;

	for(i = 0; i<argc;i++)
	{
		o_print_string(argv[i]);
	}
}
