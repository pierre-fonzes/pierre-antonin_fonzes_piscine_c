#include <unistd.h>

int main(){
	int cpt;
	char lettre = 'Z';
	for(cpt = 26 ; cpt>0;cpt--){
		write(1,&lettre,1);
		write(1,"\n",1);
		lettre = lettre - 1; 
	}

}
