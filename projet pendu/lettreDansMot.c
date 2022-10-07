#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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