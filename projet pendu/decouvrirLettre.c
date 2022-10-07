#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void decouvrirLettre(char lettre, char* motSecret,int nbLettres,char *affichage){
  for(int i =0;i<nbLettres;i++){
    if(lettre == motSecret[i]){
      affichage[i] = lettre;
    }
  }
  printf("Bravo, Cette lettre fait bien partie du mot\n");
}