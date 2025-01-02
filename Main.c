// Bibliotheque : 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define MAX_LINE 1024
#define MAX_FIELDS 20

// calcul le nombre de ligne du fichier 
int compterLignes(FILE *fichier) {
    int car, NbLigne;

    car = 0;
    NbLigne = 1;

    // Parcourir le fichier pour compter les lignes
    while ((car = fgetc(fichier)) != EOF) {
        if (car == '\n') {
            ++NbLigne;
        }
    }

    return NbLigne;
}

void chargerLifestyle(FILE *file, stlifestyle *lifestyle) {
    char line[MAX_LINE];
    int index = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        // Supprimer la nouvelle ligne
        line[strcspn(line, "\n")] = '\0';

        // Découper la ligne en champs
        char *token = strtok(line, "$");
        if (token != NULL) lifestyle->id[index] = atoi(token);

        token = strtok(NULL, "$");
        if (token != NULL) lifestyle->physical_activity[index] = atoi(token);

        token = strtok(NULL, "$");
        if (token != NULL) lifestyle->alcohol_consumption[index] = atof(token);

        token = strtok(NULL, "$");
        if (token != NULL) lifestyle->caffeine_consumption[index] = atof(token);

        token = strtok(NULL, "$");
        if (token != NULL) lifestyle->sleep_quality[index] = atof(token);

        index++;
    }
}

// Afficher les données de la structure stlifestyle pour n lignes
void afficherLifestyle(const stlifestyle *lifestyle, int n) {
    for (int i = 0; i < n; i++) {
        printf("Patient %d:\n", i + 1);
        printf("  ID: %d\n", lifestyle->id[i]);
        printf("  Physical Activity: %d\n", lifestyle->physical_activity[i]);
        printf("  Alcohol Consumption: %.2f\n", lifestyle->alcohol_consumption[i]);
        printf("  Caffeine Consumption: %.2f\n", lifestyle->caffeine_consumption[i]);
        printf("  Sleep Quality: %.2f\n\n", lifestyle->sleep_quality[i]);
    }
}


int main (){

    // Ouverture des fishier 
    FILE* lifestyle = NULL;
    FILE* patients = NULL;
    lifestyle = fopen("DATA/lifestyle.pengu", "r+");
    patients = fopen("DATA/patients.pengu", "r+");
 
    // calcul le nombre de ligne du fichier 
    int nombreDeLignes_lifestyle = compterLignes(lifestyle);
    printf("Nombre de lignes : %d\n", nombreDeLignes_lifestyle);
    
    // Initialiser la structure stlifestyle et charger les données
    stlifestyle OBS;
    chargerLifestyle(lifestyle, &OBS);

    // Afficher les 5 premiers enregistrements pour vérifier
    afficherLifestyle(&OBS, 5);

    fclose(lifestyle);
    fclose(patients);
    return 0 ;
}