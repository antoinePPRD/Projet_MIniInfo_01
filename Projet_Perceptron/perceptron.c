#include <stdio.h>
#include <stdlib.h>
#include "recupdata.h"
#include "perceptron.h"
#include "service.h"


//Definition de la structure Neurone
struct Neurone
{
    float **X; // Ce pointeur va servir de table d'entrées en 2D
    float biais;
    float *W;
    float *realite; // Ce pointeur va servir de tableau de coef synaptiques après l'appel du malloc
    int taille; // nombre d'entrées
    int pop; // nombre de patients
};

// Fonction d'initialisation du Neurone. Elle crée la structure du Neurone
struct Neurone *initialisation(int N, int M)
{
    struct Neurone *neurone = malloc(sizeof(*neurone)); // strictement la meme chose que "(struct Neurone *)malloc(sizeof(struct Neurone))" sauf en plus simple

    if (neurone == NULL)
    {
        exit(0);
    }
    
    float *masse = poids(M);
    float *annee = age(M);
    int *d = risque(M);
    neurone->biais = 0.5;
    neurone->taille = N;
    neurone->pop = M;
    neurone->W = malloc(N * sizeof(float));
    neurone->X = malloc(N * M * sizeof(float));// Ce code permet de créer un tableau de la taille renseignée.
    neurone->realite = malloc(M * sizeof(float));

    for (int i = 0; i < N; i++) //remplir les valeurs W[i]
    {
        neurone->W[i] = 0; // Les coef. synaptiques sont tous mis à 0 
    }
    
    return neurone;
}

//procedure pour remplir les tables realite[j] et X[i][j]
void tablesAvecJ(struct Neurone *neurone,int N, int j, int *masse, int *annee, int *d)
{
    for (int i = 0; i < N; i++)
    {
        int a = 0;
        if ( a == 0) //Partie à modifier si je veux mettre plus de 2 entrées
        {
            neurone->X[i][j] = masse[i];
            a = 1;
        }
        else
        {
            neurone->X[i][j] = annee[i];
            a = 0;
        }
    }
    
    for (int j = 0; j < N; j++) //remplir les valeurs realite[i]
    {
        neurone->realite[j] = d[j]; // Les coef. synaptiques sont tous mis à 0 
    }
}

// Fonction calcul de y(x) la somme pondérée des entrées moyennat les coef. synaptiques
float y(struct Neurone *neurone, int j)
{
    float somme = neurone->biais;
    for(int i = 0; i < neurone->taille; i++)
    {
        somme = somme + neurone->W[i] * neurone->X[i][j];
    
    return somme;
    }
}

// Fonction seuil z(x)
int z(struct Neurone *neurone, int M)
{
    for(int j= 0; j<M; j++){
        int prediction;
        if(y(neurone, j) < 0)
        {
            prediction = 0;
        }
        else
        {
            prediction = 1;
        }

        return prediction;
    }
}

// Fonction pour la correction du biais et des coef. synaptiques
int apprendre(struct Neurone *neurone, float tx_apprentissage, int M)
{
    int succes = 0;
    float prediction = z(neurone, M);

    for(int j= 0; j< M; j++){
        if (prediction == neurone->realite[j])
        {
            succes = 1;
        }
        else
        {
            for (int i = 0; i < neurone->taille; i++)
            {
                neurone->W[i] = neurone->W[i] + tx_apprentissage * neurone->X[i][j] * (neurone->realite[j] - prediction); // Corrections des coef.
            }

            neurone->biais = neurone->biais + tx_apprentissage * (neurone->realite[j] - prediction); // Correction du biais
        }
    
        return succes;
    }
}

// Procedure supprimer
void supprimer_neurone(struct Neurone *neurone)
{
    free(neurone->X);
    free(neurone->W);
    free(neurone->realite);
    free(neurone);
}
