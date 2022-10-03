
#include <unistd.h>
int main(){
	char tablo[100] = "Hello World";
	write(1,&tablo,100);
}
