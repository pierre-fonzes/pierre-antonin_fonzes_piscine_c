#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "test.h"
#define TAILLE_MAX 100
//#include "lireCar.h"
//#include "lettreDansMot.h"
//#include "decouvrirLettre.h"
//#include "choisirMot.h"

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}

int piocherMot(char *motPioche)
{
    FILE* dico = NULL;
    int nombreMots = 0, numMotChoisi = 0;
    int caractereLu = 0;
    dico = fopen("test.txt", "r");

    // On vérifie si on a réussi à ouvrir le dictionnaire
    if (dico == NULL) 
    {
        printf("\nImpossible de charger le dictionnaire de mots\n");
        return 0; // On retourne 0 pour indiquer que la fonction a échoué
    }

    // On compte le nombre de mots dans le fichier
    //on compte uniquement les \n sinon le compte sera mauvais car \n indique la fin du mot 
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while(caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard

    // On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivé au bon mot
    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }

    //On a placé le curseur au bon endroit 
    //on a plus qu'a stocker le mot dans motPioche
    fgets(motPioche, 100, dico);

    // On vire le \n à la fin
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);

    return 1; // Tout s'est bien passé, on retourne 1
}


void decouvrirLettre(char lettre, char* motSecret,int nbLettres,char *affichage){
  for(int i =0;i<nbLettres;i++){
    if(lettre == motSecret[i]){
      affichage[i] = lettre;
    }
  }
  printf("Bravo, Cette lettre fait bien partie du mot\n");
}

int lettreDansMot(char lettre, char *motSecret){
  int i = 0;
  while(motSecret[i] != '\0'){
    if(lettre == motSecret[i]){
      return 1;
    }
    i++;
  }
  return  0;
}

char lireLettre() 
{ 
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
    //afin d'éviter toute erreur de saisie de l'utilisateur car les mots sont en majuscules
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer) 
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu 
}

int main()
{
  FILE *fd = fopen("test.txt","r");
  if(fd==NULL){
    printf("Erreur sur l'ouverture du dictionnaire de mot");
    exit(1);
  }
  int nbCoups = 10;
  int nbMots = 0;
  char motSecret[TAILLE_MAX] = "";
  nbMots = piocherMot(motSecret);
  if(nbMots != 1){
    printf("Nous n'avons pas réussi à piocher un mot, un problème est survenu\n");
    exit(1);
  }
  char motSecretAffichage[TAILLE_MAX] = "";
  strcpy(motSecretAffichage,motSecret);
  int i = 0;
  while(motSecretAffichage[i]!='\0'){
    motSecretAffichage[i]='*';
    i++;
  }
  printf("%s\n",motSecretAffichage);
  char lettre;
  while(nbCoups>0){
    if(strcmp(motSecret,motSecretAffichage)==0){
          break;
    } 
    printf("Quelle lettre est susceptible de se trouver dans le mot \n");
    lettre = lireLettre();//pas de scanf pour éviter les erreurs de saisies -> voir fonction
    int tentative = lettreDansMot(lettre,motSecret);//inutile de lui passer la longueur on parcourt jusqu'au \0
    if(tentative==1){
      //decouvrir les lettres
      decouvrirLettre(lettre,motSecret,i,motSecretAffichage);
      printf("%s \n",motSecretAffichage);
    }
    else if(tentative==0){
      //décrémenter le compteur de coups et afficher
      nbCoups--;
      printf("Il vous reste %d coup(s) avant une mort certaine  \n",nbCoups); 
    }
  }
  if(nbCoups>0){
    printf("Bravo vous avez trouvé le mot \n");
  }
  else{
    printf("Malheureusement, vous n'avez pas trouvé le mot, le petit bonhomme est mort\n");
    printf("-------\n");
    printf("|/     |\n");
    printf("|      o\n");
    printf("|     /|/\n");
    printf("|     //\n");
    printf("----------\n");
    printf("|         |\n");
    printf("\n");
    printf("Le mot Secret était : ");
    printf("%s\n",motSecret);
  }

  
  fclose(fd);
}


