#include <stdlib.h>
#include <stdio.h>
#include "correcteur.h"

int correctionPatients()
{
    FILE* fichier1 = NULL;
    FILE* fichier_corrige = NULL;
    int charActuel1 = 0;
    int compteur = 0; // Flag permettant de dénombrer les $ dans une ligne


    fichier1 = fopen("patients.txt", "r"); /* ouverture du fichier à corriger */
    fichier_corrige = fopen("patientsCorrect.txt", "w+"); /* création du fichier corrigé */

    if (fichier1 != NULL && fichier_corrige != NULL)
    {
        do /* boucle de lecture des caractères un à un */
        {
            charActuel1 = fgetc(fichier1); // lecture du caractère

                if (charActuel1 == '$') //condition qui permet de compter les colonnes du fichier pengu
                {
                    compteur ++;
                } 

                if (charActuel1 == '\n') //condition qui permet de remettre le compteur à 0 quand retour à la ligne détecter
                {
                    fputc('\n',fichier1);
                    compteur = 0;
                }

                if (compteur != 0) // afficher le chiffre qui s'affiche après le $ d'intéret
                {
                    fputc(charActuel1, fichier_corrige);
                }
        } 
        while (charActuel1 != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        
        printf("\n"); // Fermeture du fichier
        fclose(fichier1);
        fclose(fichier_corrige);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt\n");
    }
    return 0;

}

int correctionLifestyle()
{
    FILE* fichier1 = NULL;
    FILE* fichier_corrige = NULL;
    int charActuel1 = 0;
    int compteur = 0; // Flag permettant de dénombrer les $ dans une ligne

    fichier1 = fopen("lifestyle.txt", "r"); /* ouverture du fichier à corriger */
    fichier_corrige = fopen("lifestyleCorrect.txt", "w+"); /* création du fichier corrigé */

    if (fichier1 != NULL || fichier_corrige != NULL)
    {
        do /* boucle de lecture des caractères un à un */
        {
            charActuel1 = fgetc(fichier1); // lecture du caractère

                if (charActuel1 == '$') //condition qui permet de compter les colonnes du fichier pengu
                {
                    compteur ++;
                } 

                if (charActuel1 == '\n') //condition qui permet de remettre le compteur à 0 quand retour à la ligne détecter
                {
                    fputc('\n',fichier1);
                    compteur = 0;
                }

                if (compteur != 0) // afficher le chiffre qui s'affiche après le $ d'intéret
                {
                    fputc(charActuel1, fichier_corrige);
                }
        } 
        while (charActuel1 != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        
        printf("\n"); // Fermeture du fichier
        fclose(fichier1);
        fclose(fichier_corrige);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt\n");
    }
    return 0;
}

int correction()
{
    FILE* fichier1 = NULL;
    FILE* fichier_corrige = NULL;
    char *nom_fichier;
    int charActuel1 = 0;
    int compteur = 0; // Flag permettant de dénombrer les $ dans une ligne


    printf("Avec quel fichier de données travailler ? ");
    scanf("%s", nom_fichier);
    fichier1 = fopen(nom_fichier, "r"); /* ouverture du fichier à corriger */
    fichier_corrige = fopen("Correct.txt", "w+"); /* création du fichier corrigé */

    if (fichier1 != NULL || fichier_corrige != NULL)
    {
        do /* boucle de lecture des caractères un à un */
        {
            charActuel1 = fgetc(fichier1); // lecture du caractère

                if (charActuel1 == '$') //condition qui permet de compter les colonnes du fichier pengu
                {
                    compteur ++;
                } 

                if (charActuel1 == '\n') //condition qui permet de remettre le compteur à 0 quand retour à la ligne détecter
                {
                    fputc('\n',fichier1);
                    compteur = 0;
                }

                if (compteur != 0) // afficher le chiffre qui s'affiche après le $ d'intéret
                {
                    fputc(charActuel1, fichier_corrige);
                }
        } 
        while (charActuel1 != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        
        printf("\n"); // Fermeture du fichier
        fclose(fichier1);
        fclose(fichier_corrige);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt\n");
    }
    return 0;
}

//La fonction fgets renvoie NULL si elle n'est pas parvenue à lire ce que vous avez demandez donc on va utilisez cette propiété pour lire ligne par ligne
#define TAILLE_MAX 500
int patientsTraining(int M) // cette fonction lit l'ensemble d'un texte ligne par ligne
{
    FILE* fichier1 = NULL;
    FILE* fichier2 = NULL;
    int i = 0; // flag
    char chaine[TAILLE_MAX] = ""; // Chaine vide de taille TAILLE_MAX

    fichier1 = fopen("patientsCorrect.txt", "r");
    fichier2 = fopen("patientsTraining.txt", "w+");


    if (fichier1 != NULL && fichier2 != NULL)
    {
        while (i < M) //On lit le fichier tant qu'on ne recoit pas d'erreur NULL
        {
            fgets(chaine, TAILLE_MAX, fichier1);
            printf("+1");
            fprintf(fichier2, "%s\n", chaine);
            i++;
        }

        printf("patientsTraining bien créé\n");


        fclose(fichier1);
        fclose(fichier2);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt\n");
    }

    return 0;
}

int lifestyleTraining(int M) // cette fonction lit l'ensemble d'un texte ligne par ligne
{
    FILE* fichier1 = NULL;
    FILE* fichier2 = NULL;
    int i = 0; // flag
    char chaine[TAILLE_MAX] = ""; // Chaine vide de taille TAILLE_MAX

    fichier1 = fopen("lifestyleCorrect.txt", "r");
    fichier2 = fopen("lifestyleTraining.txt", "w+");


    if (fichier1 != NULL && fichier2 != NULL)
    {
        while (i < M) //On lit le fichier tant qu'on ne recoit pas d'erreur NULL
        {
            fgets(chaine, TAILLE_MAX, fichier1);
            printf("+1");
            fprintf(fichier2, "%s\n", chaine);
            i++;
        }

        printf("lifestyleTraining bien créé\n");


        fclose(fichier1);
        fclose(fichier2);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt\n");
    }

    return 0;
}
