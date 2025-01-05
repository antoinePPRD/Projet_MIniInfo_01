#include <stdio.h>
#include <stdlib.h>

#include "perceptron.h"
#include "correcteur.h"
#include "service.h"
#include "entrainement.h"
#include "recupdata.h"

void entrainement()
{
    //Accès aux bonnes données 
    correctionLifestyle();
    correctionPatients();

    //Demande du nombre lignes 
    printf("[entrainement.c]    ");
    int M = 5; //nbLignes();

    //Construction du perceptron
    printf("[entrainement.c]    ");
    int N = 2; //nbColonnes();
    printf("[entrainement.c]    ");
    float eta = tx();
    
    struct Neurone *neuneu = initialisation(N, M);
    for (int j = 0; j < M; j++)
    {
        void tablesAvecJ(struct Neurone *neuneu,int N, int j, int *masse, int *annee, int *d);
    }

    int prediction = z(neuneu, M);
    printf("[entrainement.c]    ");
    printf("prediction est %d", prediction);

    int succes = apprendre(neuneu, eta, M);
    printf("[entrainement.c]    ");
    printf(" succes : %d", succes);

}