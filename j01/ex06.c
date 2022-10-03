#include <unistd.h>

int main(){
	char tablo[50];
	write(1,"Tapez votre input ci-dessous\n",29);
	scanf("%[^\n]",&tablo);
	tablo[41] = '\0';
	write(1,&tablo,50);

}
