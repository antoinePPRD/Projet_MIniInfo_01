#include <stdio.h>
#include <stdlib.h>
#include "entrainement.h"



int main()
{
    char choixUtilisation;
    printf("[main.c]    ");
    printf("1: entrainer le perceptron   2: tester le perceptron   3: prédire les risques.  Veuillez répondre par 1, 2 ou 3  ");
    scanf("%c", &choixUtilisation);

    if (choixUtilisation = 1)
    {
        entrainement();
    }
    /*if (choixUtilisation = 2)
    {
        validation();
    }
    if (choixUtilisation = 3)
    {
        prediction();
    }*/
}

