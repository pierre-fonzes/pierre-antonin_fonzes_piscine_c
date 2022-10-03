#include <unistd.h>

int main(){
	int nb = '9';
	int cpt;
	write(1,"10",2);
	write(1,"\n",1);
	for(cpt = 9;cpt>0;cpt--){
		write(1,&nb,1);
		write(1,"\n",1);
		nb--;
	}
}
