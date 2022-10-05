#include <stdlib.h>
#include <stdio.h>

int * intervalle(int a, int b)
{
	int *res;
	int i;
	
	
	if( a < b ){
		int taille = b - a-1;//car on ne veut ni a ni b dans le tablo
		res = malloc(sizeof(int)*taille);
		for(i = 0; i < taille ; i++){
			res[i] = a+i+1;
		}
		return res;
	}
	else if( a > b){
		int taille = a - b - 1;
		res = malloc(sizeof(int)*taille);
		for(i = 0; i < taille ; i++){
			res[i] = b + i + 1;
		}
		return res;
	}
	else{
		return NULL;
	}
		
}

int	main(void){
	int a = 15;
	int b = 20;

	int *inter;
	inter = intervalle(a,b);
	int i;
	for(i = 0; i < 4 ; i++){
		printf("%d\n",inter[i]);
	}
	free(inter);
	i = 0;

	int *inter2;
	inter2 = intervalle(b,a);
	for( i = 0 ; i < 4 ; i++){
		printf("%d",inter2[i]);
	}
	free(inter2);

	int neg = -2;
	int pos = 2;
	printf("\n");

	int *inter3;
	inter3 = intervalle(neg,pos);
	i = 0;
	for( i = 0; i < 3 ; i++){
		printf("%d",inter3[i]);
	}
	free(inter3);

	int *inter4;
	inter4 = intervalle(b,b);
	printf("%d\n",inter4);
	free(inter4);

}
