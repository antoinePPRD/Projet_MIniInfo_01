#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "main.h"

int CalculeDistanceCluster(float cluster, float data) {
    return fabs(cluster - data);
}

void calculerClusters(float *data, int *ids, int n, const char *attribut) {
    int r1, r2;
    r1 = rand() % n;
    r2 = rand() % n;
    float cluster1 = data[r1];
    float cluster2 = data[r2];

    printf("Initialisation (%s) : Cluster 1 = %f (Index %d), Cluster 2 = %f (Index %d)\n",attribut, cluster1, r1, cluster2, r2);

    float Moyen_cluster1_0 = 0, Moyen_cluster1_1 = cluster1;
    float Moyen_cluster2_0 = 0, Moyen_cluster2_1 = cluster2;

    int conteur_cluster1 = 0, conteur_cluster2 = 0;
    float Somme_cluster1 = 0, Somme_cluster2 = 0;

    int max_iterations = 100;
    int iteration = 0;

    while (iteration < max_iterations && ((fabs(Moyen_cluster1_1 - Moyen_cluster1_0) > 0.01) || (fabs(Moyen_cluster2_1 - Moyen_cluster2_0) > 0.01))) {
        Somme_cluster1 = Somme_cluster2 = 0;
        conteur_cluster1 = conteur_cluster2 = 0;

        for (int i = 0; i < n; i++) {
            float Disance_cluster1 = CalculeDistanceCluster(cluster1, data[i]);
            float Disance_cluster2 = CalculeDistanceCluster(cluster2, data[i]);

            if (Disance_cluster1 < Disance_cluster2) {
                Somme_cluster1 += data[i];
                conteur_cluster1++;
            } else {
                Somme_cluster2 += data[i];
                conteur_cluster2++;
            }
        }

        Moyen_cluster1_0 = Moyen_cluster1_1;
        Moyen_cluster1_1 = Somme_cluster1 / conteur_cluster1;
        cluster1 = Moyen_cluster1_1;
        

        Moyen_cluster2_0 = Moyen_cluster2_1;
        Moyen_cluster2_1 = Somme_cluster2 / conteur_cluster2;
        cluster2 = Moyen_cluster2_1;
        

        printf("Iteration %d (%s): Cluster 1 = %f, Cluster 2 = %f\n", iteration, attribut, cluster1, cluster2);
        iteration++;
    }

    printf("Final (%s): Cluster 1 = %f, Nombre d'éléments = %d\n", attribut, cluster1, conteur_cluster1);
    printf("Final (%s): Cluster 2 = %f, Nombre d'éléments = %d\n", attribut, cluster2, conteur_cluster2);
}

int main() {
    srand(time(NULL));

    FILE *lifestyle = fopen("DATA/lifestyle.pengu", "r");

    if (!lifestyle) {
        perror("Erreur lors de l'ouverture du fichier lifestyle");
        return 1;
    }

    int NombreDeLignes_lifestyle = compterLignes(lifestyle);
    stlifestyle lifestyle_data;
    chargerLifestyle(lifestyle, &lifestyle_data);
    fclose(lifestyle);

    // Calculer les clusters pour chaque attribut
    calculerClusters(lifestyle_data.physical_activity, lifestyle_data.id, NombreDeLignes_lifestyle, "Physical Activity");
    calculerClusters(lifestyle_data.alcohol_consumption, lifestyle_data.id, NombreDeLignes_lifestyle, "Alcohol Consumption");
    calculerClusters(lifestyle_data.caffeine_consumption, lifestyle_data.id, NombreDeLignes_lifestyle, "Caffeine Consumption");
    calculerClusters(lifestyle_data.sleep_quality, lifestyle_data.id, NombreDeLignes_lifestyle, "Sleep Quality");

    return 0;
}