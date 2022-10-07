#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "test.h"
#define TAILLE_MAX 100
#include "lireCar.h"
#include "lettreDansMot.h"
#include "decouvrirLettre.h"
#include "choisirMot.h"

int main(int argc, char *argv[])
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

  /*char chaine[1000000];
  fgets(chaine,10000000,fd);
  char chaine1[15];
  fgets(chaine1,15,fd);
  //printf("%c\n",chaine1[0]);

  char carActuel;
  carActuel = fgetc(fd);
  //printf("%c\n",carActuel);
  if(strcmp(&carActuel,"#")==0){
      fseek(fd,0,SEEK_SET);
      printf("%d\n",1);
  }
  else{
      fseek(fd,0,SEEK_SET);
       printf("%d\n",0);
  }

  FILE *fd1 = fopen("sortie.txt","w");
  char chaine2[100];
  while(fgets(chaine2,100,fd)!=NULL){//tant que fgets renvoie pas null on écrit tout dans le fichier de sortie
      fputs(chaine2,fd1);
  }*/

  
  fclose(fd);
}


