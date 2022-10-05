#include <stdio.h>
#include <stdlib.h>

int	o_strlen(char *str)
{
	if( str == NULL )
	{
		return 0;
	}
	int i;
	int l;
	
	i = 0;
	l = 0;
	while(str[i] != '\0')
	{
		i++;
		l++;	
	}
	return l;
}

char *o_strjoin(int size, char**arr, char*sep)
{
	char *res;
	int tailleSep = o_strlen(sep);

	if(size == 0 || arr == NULL){
		return NULL;
	}
	else{
		int i;
		int tailleRes = 0;
		for(i=0; i < size ; i++){
			tailleRes += o_strlen(arr[i]);//longueur totale en collant toutes les chaînes
			
		}
		tailleRes += (size - 1)*o_strlen(sep);//ajout du nb de cases de séparateur
		res = malloc(tailleRes * sizeof(char));
		int lastPos = 0;
		for(int j = 0; j < size ; j++){
			int k = 0;
			if(arr[j] != NULL){//on ne va pas tenter d'accéder à des éléments si la string n'existe pas 
				while(arr[j][k] != '\0'){
					res[lastPos] = arr[j][k];
					k++;
					lastPos++;	
				}
				if(j<size-1 && sep!=NULL){
					int tmp;
					for(tmp = 0; tmp<tailleSep; tmp++){
						res[lastPos] = sep[tmp];
						k++;
						lastPos++;
					}
				}
			}
		}
		return res;

	}
}

int	main(void)
{
	char tablo[10] = "Cou";
	char *tab = "Cou";
	char *sep= NULL;
	char *res;

	char *arr[2];
	arr[0] = tab;
	arr[1] = tablo;

	res = o_strjoin(2,arr,sep);
	//printf("%s",res);
	for(int i = 0; i < 8 ; i++){
		printf("%c",res[i]);
	}
	free(res);

		



}


