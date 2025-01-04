#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

int CalculeDistanceCluster(float cluster, float data) {
    return fabs(cluster - data);
}

int main() {
    // Ouverture des fichiers
    FILE *lifestyle = fopen("DATA/lifestyle.pengu", "r");
    FILE *patients = fopen("DATA/patients.pengu", "r");

    // Calcul du nombre de lignes
    int NombreDeLignes_lifestyle = compterLignes(lifestyle);
    int NombreDeLignes_patients = compterLignes(patients);

    // Initialisation des structures
    stlifestyle lifestyle_data;
    chargerLifestyle(lifestyle, &lifestyle_data);

    stpatients patient_data;
    chargerPatients(patients, &patient_data);

    // Fermeture des fichiers
    fclose(lifestyle);
    fclose(patients);

    // Initialisation des clusters
    float cluster1 = lifestyle_data.physical_activity[rand() % NombreDeLignes_lifestyle];
    float cluster2 = lifestyle_data.physical_activity[rand() % NombreDeLignes_lifestyle];

    float Moyen_cluster1_0 = 0, Moyen_cluster1_1 = cluster1;
    float Moyen_cluster2_0 = 0, Moyen_cluster2_1 = cluster2;

    int conteur_cluster1 = 0, conteur_cluster2 = 0;
    float Somme_cluster1 = 0, Somme_cluster2 = 0;

    int max_iterations = 100;
    int iteration = 0;

    while (iteration < max_iterations && ((fabs(Moyen_cluster1_1 - Moyen_cluster1_0) > 0.5) || (fabs(Moyen_cluster2_1 - Moyen_cluster2_0) > 0.5))) {
        
        // Réinitialiser les sommes et les compteurs
        Somme_cluster1 = Somme_cluster2 = 0;
        conteur_cluster1 = conteur_cluster2 = 0;

        for (int k = 0; k < NombreDeLignes_lifestyle; k++) {
            float Disance_cluster1 = CalculeDistanceCluster(cluster1, lifestyle_data.physical_activity[k]);
            float Disance_cluster2 = CalculeDistanceCluster(cluster2, lifestyle_data.physical_activity[k]);

            if (Disance_cluster1 < Disance_cluster2) {
                Somme_cluster1 += lifestyle_data.physical_activity[k];
                conteur_cluster1++;
            } else {
                Somme_cluster2 += lifestyle_data.physical_activity[k];
                conteur_cluster2++;
            }
        }

        Moyen_cluster1_0 = Moyen_cluster1_1;
        Moyen_cluster1_1 = Somme_cluster1 / conteur_cluster1;
        cluster1 = Moyen_cluster1_1;

        Moyen_cluster2_0 = Moyen_cluster2_1;
        Moyen_cluster2_1 = Somme_cluster2 / conteur_cluster2;
        cluster2 = Moyen_cluster2_1;

        iteration++;
    }

    printf("Cluster 1: Centre = %f, Nombre d'éléments = %d\n", cluster1, conteur_cluster1);
    printf("Cluster 2: Centre = %f, Nombre d'éléments = %d\n", cluster2, conteur_cluster2);

    return 0;
}