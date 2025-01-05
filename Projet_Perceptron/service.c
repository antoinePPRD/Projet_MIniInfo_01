#include <stdio.h>
#include <stdlib.h>
#include "service.h"

//demander le nb de lignes
int nbLignes()
{
    int M; //le nombre de lignes
    printf("Combien de lignes de patients ? ");
    scanf("%d", &M);

    return M;
}

//demander le nb de colonnes
int nbColonnes()
{
    int N; //le nombre de colonnes
    printf("Combien d'entrées pour le perceptron ? ");
    scanf("%d", &N);

    return N;
}

//demander le nom d'un fichier
char *nomFichier()
{
    char *nom;
    printf("quel fichier prendre ? ");
    scanf("%s", nom);

    return nom;
}

//demander le tx d'apprentissage
float tx()
{
    float eta; //le nombre de colonnes
    printf("Niveau du taux d'apprentissage pour le perceptron ? ");
    scanf("%f", &eta);

    return eta;
}

//demander la colonne d'interet

