#include <stdio.h>
#include <unistd.h>
#include "o_linked_list.h"
#include <stdlib.h>

typedef struct list list;
struct list{
	linkedList *premier;
};

void affiche_linked_list(list *liste){
	linkedList *actuel = liste->premier;
	while(actuel!= NULL){
		int i = 0;
		while(actuel->data[i] != '\0'){
			write(1,&actuel->data[i],1);
			i++;
		}
		write(1,"\n",1);
		actuel = actuel->next;
	}
}

list *init(){
	list *liste = malloc(sizeof(*liste));
	linkedList *element = malloc(sizeof(*element));

	element->data = " ";
	element->next = NULL;
	liste->premier = element;

	return liste;
}

int	main(void){
	char nom[20] = "Pierre";
	char prenom[20] = "Fonzes";

	list *test;
	test = init();

	affiche_linked_list(test);
	free(test);

	
}
