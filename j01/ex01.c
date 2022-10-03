#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	char tablo[100] = "Hello World";
	write(1,&tablo,15);
}
