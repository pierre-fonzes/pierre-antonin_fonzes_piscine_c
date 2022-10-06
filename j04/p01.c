#include <stdio.h>
#include "contact.h"
#include <string.h>
#include <stdlib.h>

typedef struct cellule cellule;
struct cellule{
	contact c;
	cellule *suiv;//adresse du prochain élément
};

typedef struct liste liste;
struct liste{
	cellule *premier;
};


void affiche_contact(contact c){
	printf("--------------------\n");
	printf("%s\n",c.nom);
	printf("%s\n",c.prenom);
	printf("%s\n",c.num);
	printf("--------------------\n");
}

contact creer_contact(char *nom, char *prenom, char *nume){

	contact c;
	c.nom = strdup(nom);//permet de faire de la copie profonde et pas juste l'adresse
	c.prenom = strdup(prenom);
	c.num = strdup(nume);

	return c;
}

liste *init(){
	liste *list = malloc(sizeof(*list));
	cellule *cell = malloc(sizeof(*cell));
	
	cell->c = creer_contact("Fonzes","Pierre le Roi","Vous ne pouvez pas voir le numéro de sa majesté");
	cell->suiv = NULL;
	list->premier = cell;

	return list;
}

void ajout_contact_annuaire(liste *list, char *nom,char *prenom, char*num){
	cellule *cell = malloc(sizeof(*cell));
	contact cont = creer_contact(nom,prenom,num);
	cell->c = cont;
	cell->suiv = list->premier;
	list->premier = cell;

}

int compare_contact(contact c1, contact c){//retourne 0 si les contacts sont les mêmes 
	if(strcmp(c1.nom,c.nom) == 0 && strcmp(c1.prenom,c.prenom) == 0 && strcmp(c1.num,c.num) == 0){
		return 0;
	}
	else{
		return 1;
	}
}

void recherche_par_nom(char *nom, liste *list){
	cellule *actuel = list->premier;
	while(actuel!=NULL){
		
		if(strcmp(actuel->c.nom,nom) == 0){
			printf("Voici un contact correspondant\n");
			affiche_contact(actuel->c);
		}
		actuel = actuel->suiv;
	}
}

void recherche_par_numero(liste *list, char *numero){
	cellule *actuel = list->premier;
	while(actuel!=NULL){
		if(strcmp(actuel->c.num,numero) == 0 ){
			printf("Voici un contact dont le numéro correspond :\n");
			affiche_contact(actuel->c);
		}
		actuel = actuel->suiv;
	}
}

void suppression_contact(liste *list,contact c){//on ne return le contact que si toutes les données correspondent
	cellule *actuel = list->premier->suiv;
	cellule *prec = list->premier;
	if(compare_contact(prec->c,c) == 0 ){//si on doit suppr la tete de liste 
		list->premier = actuel;
	}
	while(actuel != NULL )
	{
		if(compare_contact(actuel->c,c) == 0){
			prec->suiv = actuel->suiv;
			free(actuel);
		}
		actuel = actuel->suiv;
		prec = prec->suiv;
	}
}

void afficher_annuaire(liste *list){
	printf("Annuaire actuel :\n");
	cellule *actuel = list->premier;

	while(actuel != NULL){
		affiche_contact(actuel->c);
		actuel = actuel->suiv;
	}
	printf("\n");
}

void update_contact(liste *list, contact c){
	cellule *actuel = list->premier;
	while(actuel != NULL){
		if(compare_contact(actuel->c,c) == 0 ){
			char nom[20];
			char prenom[20];
			char num[20];

			printf("Veuillez saisir le nom du contact que vous souhaitez modifier (saisissez le même nom si vous voulez le garder) :\n");
			scanf("%s",nom);
			printf("Même consigne que pour le nom, saisir le prenom :\n");
			scanf("%s",prenom);
			printf("Même consigne que pour le nom, saisir le numéro :\n");
			
			scanf("%s",num);
			actuel->c.nom = strdup(nom);
			actuel->c.prenom = strdup(prenom);
			actuel->c.num = strdup(num);

			//printf("%s\n",actuel->c.nom);

		}
		actuel = actuel->suiv;
	}
}

int	main(void)
{
	liste *annuaire = init();
	
	ajout_contact_annuaire(annuaire,"Fonzes","Claire","0767545666");
	
	//afficher_annuaire(annuaire);
	printf("\n");

	//afficher_annuaire(annuaire);

	//update_contact(annuaire,c);
	printf("\n");
	afficher_annuaire(annuaire);

	int flag;
	flag = 1;
	while(flag>0){
		char nom[20] = " ";
		char prenom[20] = " ";
		char num[20] = " ";
		printf("Quelle action voulez vous faire :\n");
		printf("Tapez : ajouter ou supprimer ou update ou lire\n");
		char choix[20];
		scanf("%s",choix);
		if(strcmp(choix,"ajouter")==0){
			printf("Veuillez saisir le nom du contact que vous souhaitez créer :\n");
			scanf("%s",nom);
			printf("Veuillez saisir le prénom du contact que vous souhaitez créer :\n");
			scanf("%s",prenom);
			printf("Veuillez saisir le numéro de la personne que vous souhaitez créer :\n");
			scanf("%s",num);

			ajout_contact_annuaire(annuaire,nom,prenom,num);
			printf("--------------------------------------------------\n");
			afficher_annuaire(annuaire);

		}
		else if(strcmp(choix,"supprimer")==0){
			contact c;

			printf("Vous entrez dans le mode de suppression de contact, une fois effacée, la donnée est irrécupérable\n");
			printf("Pour pouvoir identifer le contact, veuillez saisir l'entièreté des informations demandées :\n");
			printf("Saisissez le nom :\n");
			scanf("%s",nom);
			printf("Saisissez le prénom :\n");
			scanf("%s",prenom);
			printf("Saisissez le numéro :\n");
			scanf("%s",num);

			c = creer_contact(nom,prenom,num);
			printf("Si vous n'avez pas fait d'erreur de saisie, le contact sera effectivement supprimé\n");

			suppression_contact(annuaire,c);
			printf("---------------------------------------------------\n");
			afficher_annuaire(annuaire);

		}
		else if(strcmp(choix,"update") == 0){

			printf("Vous entrez dans le mode de modification d'un contact\n");
			printf("Pour pouvoir trouver le bon contact, nous devons l'identifier de manière unique afin de ne pas modifier des contacts qui ne devraient pas l'être\n");
			printf("Saisissez le nom exact :\n");
			scanf("%s",nom);
			printf("Saisissez le prénom exact :\n");
			scanf("%s",prenom);
			printf("Saisissez le numéro exact :\n");
			scanf("%s",num);

			contact c;
			c = creer_contact(nom,prenom,num);

			update_contact(annuaire,c);
			printf("-----------------------------------------------------\n");
			afficher_annuaire(annuaire);

		}
		else if(strcmp(choix,"lire")==0){
			afficher_annuaire(annuaire);
			printf("----------------------------------------------------\n");
		}
		else if(strcmp(choix,"recherche") == 0){
			char type_recherche[20];
			printf("Idiquez quelle type de recherche vous souhaitez effectuer : [nom/numero]\n");
			scanf("%s",type_recherche);
			if(strcmp(type_recherche,"nom") == 0){
				printf("Veuillez saisir le nom du contact :\n");
				scanf("%s",nom);
				recherche_par_nom(nom,annuaire);
			}
			else if(strcmp(type_recherche,"numero") == 0){
				printf("Veuillez saisir le numéro du contact :\n");
				scanf("%s",num);
				recherche_par_numero(annuaire,num);
			}
		}

		char continuer[20];
		printf("Voulez vous continuer à utiliser l'annuaire ?[o/n] : \n");
		scanf("%s",continuer);
		if(strcmp(continuer,"o") != 0){
			flag = 0;
		}
	}
	free(annuaire);
	

}
