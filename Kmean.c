#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> // Ajout pour l'initialisation aléatoire
#include "main.h"

int CalculeDistanceCluster(float cluster, float data) {
    return fabs(cluster - data);
}

int main() {
    // Initialiser le générateur aléatoire avec l'heure actuelle
    srand(time(NULL));

    // Ouverture des fichiers
    FILE *lifestyle = fopen("DATA/lifestyle.pengu", "r");
    FILE *patients = fopen("DATA/patients.pengu", "r");

    // Calcul du nombre de lignes
    int NombreDeLignes_lifestyle = compterLignes(lifestyle);
    int NombreDeLignes_patients = compterLignes(patients);

    // Initialisation des structures
    stlifestyle lifestyle_data;
    chargerLifestyle(lifestyle, &lifestyle_data);
    fclose(lifestyle);

    stpatients patient_data;
    chargerPatients(patients, &patient_data);
    fclose(patients);

    // Initialisation des clusters
    int r1, r2;
    r1 = rand() % NombreDeLignes_lifestyle;
    r2 = rand() % NombreDeLignes_lifestyle;
    float cluster1 = lifestyle_data.physical_activity[r1];
    float cluster2 = lifestyle_data.physical_activity[r2];
    printf("Initialisation : Cluster 1 = %f (Index %d), Cluster 2 = %f (Index %d)\n",cluster1, r1, cluster2, r2);

    float Moyen_cluster1_0 = 0, Moyen_cluster1_1 = cluster1;
    float Moyen_cluster2_0 = 0, Moyen_cluster2_1 = cluster2;

    int conteur_cluster1 = 0, conteur_cluster2 = 0;
    float Somme_cluster1 = 0, Somme_cluster2 = 0;

    int max_iterations = 100;
    int iteration = 0;

    while (iteration < max_iterations && ((fabs(Moyen_cluster1_1 - Moyen_cluster1_0) > 0.01) || (fabs(Moyen_cluster2_1 - Moyen_cluster2_0) > 0.01))) {
        
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
        if (conteur_cluster1 > 0) {
            Moyen_cluster1_1 = Somme_cluster1 / conteur_cluster1;
            cluster1 = Moyen_cluster1_1;
        }

        Moyen_cluster2_0 = Moyen_cluster2_1;
        if (conteur_cluster2 > 0) {
            Moyen_cluster2_1 = Somme_cluster2 / conteur_cluster2;
            cluster2 = Moyen_cluster2_1;
        }

        printf("Iteration %d: Cluster 1 = %f, Cluster 2 = %f\n", iteration, cluster1, cluster2);
        iteration++;
    }

    printf("Final : Cluster 1 = %f, Nombre d'éléments = %d\n", cluster1, conteur_cluster1);
    printf("Final : Cluster 2 = %f, Nombre d'éléments = %d\n", cluster2, conteur_cluster2);

    return 0;
}