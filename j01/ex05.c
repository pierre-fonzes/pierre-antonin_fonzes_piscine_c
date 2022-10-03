#include <unistd.h>
#include <stdio.h>

int o_charpos(char *str, char c){//renvoyer la position de c dans str -1 sinon

	int cpt;
	for(cpt = 0; cpt<sizeof(str);cpt++){
		if( c == str[cpt] ){
			return cpt;
		}
	}
	return -1;

}

int main(){
	char tablo[50] = "Coucou tout le monde";
	char lettre = 't';
	int res = o_charpos(tablo,lettre);
	printf("%d",res);

}

