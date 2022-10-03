
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int nb = '0';
	int cpt;
	char tab[10] = "\n";
	for (cpt = 0; cpt<9;cpt++){
		nb++;
		write(1,&nb,1);
		write(1,&tab,1);
		
	}
	write(1,"10",2);

}
