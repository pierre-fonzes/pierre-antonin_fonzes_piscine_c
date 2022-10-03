#include <unistd.h>

int main(void)
{
	char	tablo[11]= "Hello World";
	write(1, &tablo, 11);
}
