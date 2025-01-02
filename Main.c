// Bibliotheque : 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define MAX_LINE 1024
#define MAX_FIELDS 20

int compterLignes(FILE *fichier) {
    int car, NbLigne;
    car = 0;
    NbLigne = 1;

    while ((car = fgetc(fichier)) != EOF) {
        if (car == '\n') {
            ++NbLigne;
        }
    }
    rewind(fichier);
    return NbLigne;
}

void chargerPatients(FILE *file, stpatients *patients) {
    char line[MAX_LINE];
    int index = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        // Supprimer la nouvelle ligne
        line[strcspn(line, "\n")] = '\0';

        // Découper la ligne en champs
        char *token = strtok(line, "$");
        if (token != NULL) patients->patient_id[index] = atoi(token);

        token = strtok(NULL, "$");
        if (token != NULL) patients->record_id[index] = atoi(token);

        token = strtok(NULL, "$");
        if (token != NULL) patients->age[index] = atoi(token);

        token = strtok(NULL, "$");
        if (token != NULL) patients->gender[index] = token[0]; 

        token = strtok(NULL, "$");
        if (token != NULL) patients->weight[index] = atof(token);

        token = strtok(NULL, "$");
        if (token != NULL) patients->height[index] = atoi(token);

        token = strtok(NULL, "$");
        if (token != NULL) patients->systolic_bp[index] = atoi(token);

        token = strtok(NULL, "$");
        if (token != NULL) patients->diastolic_bp[index] = atoi(token);

        token = strtok(NULL, "$");
        if (token != NULL) patients->heart_rate[index] = atof(token);

        token = strtok(NULL, "$");
        if (token != NULL) patients->condition[index] = (strcmp(token, "True") == 0) ? 1 : 0;

        index++;
    }
    rewind(file);
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
    rewind(file);
}

void afficherPatients(const stpatients *patients, int n) {
    for (int i = 0; i < n; i++) {
        printf("Patient %d:\n", i + 1);
        printf("  Patient ID: %d\n", patients->patient_id[i]);
        printf("  Record ID: %d\n", patients->record_id[i]);
        printf("  Age: %d\n", patients->age[i]);
        printf("  Gender: %c\n", patients->gender[i]);
        printf("  Weight: %.2f\n", patients->weight[i]);
        printf("  Height: %d\n", patients->height[i]);
        printf("  Systolic BP: %d\n", patients->systolic_bp[i]);
        printf("  Diastolic BP: %d\n", patients->diastolic_bp[i]);
        printf("  Heart Rate: %.2f\n", patients->heart_rate[i]);
        printf("  Condition: %s\n", patients->condition[i] ? "True" : "False");
        printf("\n");
    }
}

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

    // Initialiser la structure stpatients
    stpatients patient_data;
    chargerPatients(patients, &patient_data);

    // Afficher les 5 premiers enregistrements pour vérifier
    afficherPatients(&patient_data, 5);

    fclose(lifestyle);
    fclose(patients);
    return 0 ;
}