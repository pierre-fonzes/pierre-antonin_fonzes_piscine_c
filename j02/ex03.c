#include <stdio.h>
#include <string.h>
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

int	o_strcmp(char *str, char *str1)
{
	int l1 = o_strlen(str);
	int l2 = o_strlen(str1);
	if(l1 == l2)
	{
		int i;

		i = 0;
		while(str[i] != '\0')
		{
			if(str[i] != str1[i])//si les cars qu'on comapre sont différents 
			{
				int ascii = (int) str[i];
				int ascii1 = (int) str1[i];
				if(ascii < ascii1 )
				{
					return -1;
				}
				else
				{
					return 1;
				}
			}
		}
		return 0;
	}
	else//si la longueur des 2 chaines n'est pas la même 
	{
		if(l1 > l2)
		{
			int j = (int) str[l2+1];//renvoyer le code ASCII du premier car qui diffère
			return j;
		}
		else
		{
			int j = (int) str1[l1+1];
			return j;	
		}
	}

}

char	* o_strcat(char *dest, char *src)//on suppose que la dest est assez grande pour stocker la src -> c'est ce que dit le man
{
	int i;
	char *start = dest;
	int longueur = o_strlen(src);
	int longueur_dest = o_strlen(dest);
	for(i = 0; i < longueur ; i++)
	{
		dest[longueur_dest + i] = src[i];
	}
	//dest[i] = '\0';
	return start;

}

int	main(void)
{
	char test[50] = "C'est où ?";
	int res = o_strlen(test);
	

	printf("%d\n",res);

	char test1[30] = "";
	int res1 = o_strlen(test1);
	printf("%d\n",res1);

	char *test2;
	test2 = NULL;
	int res2 = o_strlen(test2);
	printf("%d\n",res2);

	char toto[10] = "Toto";
	char toto1[10] = "toto";
	int resultat = o_strcmp(toto,toto1);
	printf("%d\n",resultat);

	char lgdiff[20] = "test de";
	char lgdiff1[20] = " dg";
	int resultat_lgdiff = o_strcmp(lgdiff,lgdiff1);
	printf("%d\n",resultat_lgdiff);

	char vide[10] = "";
	char vide1[10] = "";
	int resultat_vide = o_strcmp(vide,vide1);
	printf("%d\n",resultat_vide);

	char debut[100] = "dededed";
	char fin[20] = "c'est où ?";
	o_strcat(debut,fin);
	printf("%s\n",debut);

	char debut1[100] ="";
	char fin1[20] = "la fin";
	o_strcat(debut1,fin1);
	printf("%s\n",debut1);


}
