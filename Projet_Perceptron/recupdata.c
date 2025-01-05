#include <stdlib.h>
#include <stdio.h>
#include "recupdata.h"
#include "service.h"

int *id(int M)  /* fichier pour extraire l id des patients*/
{
    char *nom_fichier;
    FILE* fichier = NULL;
    
    int caractereActuel = 0;
    int compteur = 0;

    int *donneeTest = NULL;  /* ce pointeur va servir de tableau booleens apres l'appel du malloc */
    int i = 0; // Flag

    fichier = fopen("patientsTraining.txt", "r");
    
    if (M > 0)
    {
        donneeTest = malloc(M * sizeof(int)); //Ce code permet de créer un tableau de type int qui a une taille correspondant exactement au nb de patients utiles.
        if (donneeTest == NULL) // On vérifie si l'alloc a fonctionnée ou non
        {
            exit(0);
        } 
        
        if (fichier != NULL)
        {
            do /* saut de la premiere ligne avec le titre des colonnes */
        {
            caractereActuel= fgetc(fichier);
        }
            while (caractereActuel != '\n');

            do
            {
                caractereActuel = fgetc(fichier); // On lit le caractère

                if (caractereActuel == '$') //condition qui permet de compter les colonnes du fichier pengu
                {
                    compteur ++;
                } 
            
                if (compteur == 1) // extraire le charactère qui s'affiche après le $ d'intéret
                {
                    fscanf(fichier, "%d", &donneeTest[i]);
                    printf("[recupdata id]    %d\n ", donneeTest[i]);
                    i++;
                    compteur ++;
                }
            
                if (caractereActuel == '\n') //condition qui permet de remettre le compteur à 0 quand retour à la ligne détecter
                {
                    compteur = 0;
                }
            } 
            while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        
            return donneeTest;

            //on ferme notre table donneeTest
            free(donneeTest);

            printf("[recupdata id]  ok\n"); // fermeture du fichier
            fclose(fichier);
        }
        else
        {
            // On affiche un message d'erreur si on veut
            printf("Impossible d'ouvrir le fichier\n");
        }
    }
}

float *age(int M)  /* fichier pour extraire l'age des patients*/
{
    char *nom_fichier;
    FILE* fichier = NULL;
    
    int caractereActuel = 0;
    int compteur = 0;

    float *donneeTest = NULL;  /* ce pointeur va servir de tableau booleens apres l'appel du malloc */
    int i = 0; // Flag

    fichier = fopen("patientsTraining.txt", "r");
    
    if (M > 0)
    {
        donneeTest = malloc(M * sizeof(int)); //Ce code permet de créer un tableau de type int qui a une taille correspondant exactement au nb de patients utiles.
        if (donneeTest == NULL) // On vérifie si l'alloc a fonctionnée ou non
        {
            exit(0);
        } 

        if (fichier != NULL)
        {
            do /* saut de la premiere ligne avec le titre des colonnes */
        {
            caractereActuel= fgetc(fichier);
        }
            while (caractereActuel != '\n');

            do
            {
                caractereActuel = fgetc(fichier); // On lit le caractère

                if (caractereActuel == '$') //condition qui permet de compter les colonnes du fichier pengu
                {
                    compteur ++;
                } 
            
                if (compteur == 2) // extraire le charactère qui s'affiche après le $ d'intéret
                {
                    fscanf(fichier, "%f", &donneeTest[i]);
                    printf("[recupdata age]    %f\n ", donneeTest[i]);
                    i++;
                    compteur ++;
                }
            
                if (caractereActuel == '\n') //condition qui permet de remettre le compteur à 0 quand retour à la ligne détecter
                {
                    compteur = 0;
                }
            } 
            while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        
            return donneeTest;

            //on ferme notre table donneeTest
            free(donneeTest);

            printf("[recupdata age]  ok\n"); // fermeture du fichier
            fclose(fichier);
        }
        else
        {
            // On affiche un message d'erreur si on veut
            printf("Impossible d'ouvrir le fichier\n");
        }  
    }
}

float *poids(int M)  /* fichier pour extraire le poids risque des patients*/
{
    char *nom_fichier;
    FILE* fichier = NULL;
    
    int caractereActuel = 0;
    int compteur = 0;

    float *donneeTest = NULL;  /* ce pointeur va servir de tableau booleens apres l'appel du malloc */
    int i = 0; // Flag

    fichier = fopen("patientsTraining.txt", "r");

    if (M > 0)
    {
        donneeTest = malloc(M * sizeof(int)); //Ce code permet de créer un tableau de type int qui a une taille correspondant exactement au nb de patients utiles.
        if (donneeTest == NULL) // On vérifie si l'alloc a fonctionnée ou non
        {
            exit(0);
        } 

        if (fichier != NULL)
        {
            do /* saut de la premiere ligne avec le titre des colonnes */
        {
            caractereActuel= fgetc(fichier);
        }
            while (caractereActuel != '\n');

            do
            {
                caractereActuel = fgetc(fichier); // On lit le caractère

                if (caractereActuel == '$') //condition qui permet de compter les colonnes du fichier pengu
                {
                    compteur ++;
                } 
            
                if (compteur == 4) // extraire le charactère qui s'affiche après le $ d'intéret
                {
                    fscanf(fichier, "%f", &donneeTest[i]);
                    printf("[recupdata poids]    %f\n ", donneeTest[i]);
                    i++;
                    compteur ++;
                }
            
                if (caractereActuel == '\n') //condition qui permet de remettre le compteur à 0 quand retour à la ligne détecter
                {
                    compteur = 0;
                }
            } 
            while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        
            return donneeTest;

            //on ferme notre table donneeTest
            free(donneeTest);

            printf("[recupdata poids]  ok\n"); // fermeture du fichier
            fclose(fichier);
        }
        else
        {
            // On affiche un message d'erreur si on veut
            printf("Impossible d'ouvrir le fichier\n");
        }
    }
}

// Fonction extrait les donnée si risuqe il y a ou non chez les patients
int *risque(int M)  
{
    char *nom_fichier;
    FILE* fichier = NULL;

    int caractereActuel = 0;
    int compteur = 0;
    char a; /* permet de remplir la table bilan */

    int *donneeTest = NULL;  /* ce pointeur va servir de tableau booleens apres l'appel du malloc */
    int i = 0; // Flag

    fichier = fopen("patientsTraining.txt", "r");

    if (M > 0)
    {
        donneeTest = malloc(M * sizeof(int)); //Ce code permet de créer un tableau de type int qui a une taille correspondant exactement au nb de patients utiles.
        if (donneeTest == NULL) // On vérifie si l'alloc a fonctionnée ou non
        {
            exit(0);
        }  
    
        if (fichier != NULL)
        {
            do /* saut de la premiere ligne avec le titre des colonnes */
            {
                caractereActuel= fgetc(fichier);
            }
            while (caractereActuel != '\n');

            do
            {
                caractereActuel = fgetc(fichier); // On lit le caractère

                if (caractereActuel == '$') //condition qui permet de compter les colonnes du fichier pengu
                {
                    compteur ++;
                } 
            
                if (compteur == 9) // extraire le charactère qui s'affiche après le $ d'intéret
                {
                    fscanf(fichier, "%c", &a);

                    if (a == 'T')
                    {
                        donneeTest[i] = 1;
                        printf("[recupdata risque]    %d\n ", donneeTest[i]);
                    }
                    else if (a == 'F')
                    {
                        donneeTest[i] = 0;
                        printf("[recupdata risque]    %d\n ", donneeTest[i]);
                    }
                    else /* permet de voir si cette enchainement de if elif else fonctionne bien */
                    {
                        printf("Erreur ");
                    }

                    i++;
                    compteur ++;
                }

                if (caractereActuel == '\n') //condition qui permet de remettre le compteur à 0 quand retour à la ligne détecter
                {
                    compteur = 0;
                }
            } 
            while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)

            return donneeTest;

            //on ferme notre table donneeTest
            free(donneeTest);

            printf("[recupdata risque]  ok\n"); // fermeture du fichier
            fclose(fichier);
        }
        
        else
        {
            // On affiche un message d'erreur si on veut
            printf("Impossible d'ouvrir le fichier\n");
        }
    }
}
