#include <stdio.h>

char * o_strcpy(char *str,int taille)
{
	if ( str == NULL )
	{
		return NULL;
	}
	int i;

	 char copie[taille];

	 char *ptr = copie;

	for(i = 0; i < taille ; i++)
	{
		copie[i] = str[i];
	}
	return ptr;

}

char * o_strncpy(char *str, int taille, int n)
{
	if ( str == NULL ){
		return NULL;
	}
	int i;

	char copie[taille];

	char *ptr = copie;

	if( n > taille )
	{
		for( i = 0; i < taille ;i++)
		{
			copie[i] = str[i];
		}
	}
	else{
		for(i = 0; i < taille ; i++)
		{
			if( i < n )
			{
				copie[i] = str[i];
			}
			else
			{
				copie[i] = '\0';
			}
		}
	}
	return ptr;
}

int main(void)
{
	char p[30] = " Ceci est un test";
	char *q = o_strcpy(p,30);

	printf("%s",q);
	printf("\n");

	char tablo[30] = "Test de copie n";
	char *tab = o_strncpy(tablo,30,3);
	printf("%s",tab);
	printf("\n");

	char test[10] = "Hello";
	char *tes = o_strncpy(test,10,15);
	printf("%s",tes);

	char *final;
	final = NULL;
	char *fin = o_strcpy(final,10);
	printf("%s",fin);
}
