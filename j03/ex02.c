#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int ** creer_matrice(int n, int m){
	int **mat;

	mat = malloc(n*sizeof(int));
	for(int i = 0; i < n ; i++){
		mat[i] = malloc(m*sizeof(int));	
	}
	return mat;
}

void remplir_ligne_matrice(int **mat,int i,int j, int m, int n){//fonction récursive pour remplir la matrice
	while(i<n || j < m){
		int tmp = i;
		//printf("%d\n",i);
		if(i<n){
			for(tmp; tmp < m ; tmp++){//boucle pour remplir une ligne
				//printf("%d\n",i);
				//printf("%d\n",mat[i][tmp]);
				mat[i][tmp] = tmp;
			}
		}
		if(j<m){
			int jbis = j;
			for(jbis ; jbis < n ; jbis++){//boucle pour remplir une colonne
				//printf("%d\n",jbis);
				//printf("%d",mat[jbis][i]);
				mat[jbis][i] = jbis;
			}
		}
		j++;
		i++;
		
	}
			
	
}

void o_print_number(int nb)
{
	int d;
	
	if(nb<0)
	{
		nb = -nb;
		write(1,"-",1);
	}
	if(nb>9)
	{
		o_print_number(nb/10);
	}
	d = nb%10 + 48;//48 = 0 in ASCII table so -> if we want the ASCII code for 7 : 48 + 7
	write(1,&d,1);
}

int ** faire_matrice(int n, int m)
{
	int **res = creer_matrice(n,m);
	remplir_ligne_matrice(res,0,0,m,n);
	return res;
}



int	main(void){
	int **test;
	test = faire_matrice(3,3);
	for(int i=0;i<3;i++){
		for(int j =0;j<3;j++){
			//printf("%d",test[i][j]);
			o_print_number(test[i][j]);
		}
		printf("\n");
	}
	free(test);
}


