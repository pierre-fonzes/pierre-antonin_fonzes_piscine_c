#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "choisirMot.h"

int piocherMot(char *motPioche)
{
    FILE* dico = NULL;
    int nombreMots = 0, numMotChoisi = 0, i = 0;
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

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}