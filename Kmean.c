#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "main.h"

int CalculeDistanceCluster(float cluster, float data) {
    return fabs(cluster - data);
}

void calculerClusters(float *data, int *ids, int n, const char *attribut, int *cluster1_ids, int *cluster2_ids, int *nb_cluster1, int *nb_cluster2) {
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
                Somme_cluster1 = Somme_cluster1 + data[i];
                conteur_cluster1++;
                cluster1_ids[conteur_cluster1] = ids[i];
            } 
            else {
                Somme_cluster2 = Somme_cluster2 + data[i];
                conteur_cluster2++;
                cluster2_ids[conteur_cluster2] = ids[i];
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
        iteration++;
    }

    *nb_cluster1 = conteur_cluster1;
    *nb_cluster2 = conteur_cluster2;

    printf("Final (%s): Cluster 1 = %f, Nombre d'éléments = %d\n", attribut, cluster1, conteur_cluster1);
    printf("Final (%s): Cluster 2 = %f, Nombre d'éléments = %d\n", attribut, cluster2, conteur_cluster2);

    printf("-------------------------------------------------------\n");
}

void analyserClusters(int *cluster1_ids, int nb_cluster1, int *cluster2_ids, int nb_cluster2, const char *attribut1, const char *attribut2) {
    printf("\n--- Analyse des clusters entre %s et %s ---\n", attribut1, attribut2);
    float intersection = 0;

    for (int i = 0; i < nb_cluster1; i++) {
        for (int j = 0; j < nb_cluster2; j++) {
            if (cluster1_ids[i] == cluster2_ids[j]) {
                intersection++;
            }
        }
    }

    

    printf("Meme IDs entre %s et %s : %f\n", attribut1, attribut2, intersection);
    printf("Pourcentage de similariter %s : %f\n",attribut1 , (intersection/nb_cluster1)*100 );
    printf("Pourcentage de similariter %s : %f\n",attribut2 , (intersection/nb_cluster2)*100 );

    printf("-------------------------------------------------------\n");
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

    // Listes pour stocker les ids des clusters pour chaque attribut
    int cluster1_ids_pa[10000], cluster2_ids_pa[10000];
    int cluster1_ids_ac[10000], cluster2_ids_ac[10000];
    int cluster1_ids_cc[10000], cluster2_ids_cc[10000];
    int cluster1_ids_sq[10000], cluster2_ids_sq[10000];

    int nb_cluster1_pa, nb_cluster2_pa;
    int nb_cluster1_ac, nb_cluster2_ac;
    int nb_cluster1_cc, nb_cluster2_cc;
    int nb_cluster1_sq, nb_cluster2_sq;

    // Calculer les clusters pour chaque attribut
    calculerClusters(lifestyle_data.physical_activity, lifestyle_data.id, NombreDeLignes_lifestyle,"Physical Activity", cluster1_ids_pa, cluster2_ids_pa, &nb_cluster1_pa, &nb_cluster2_pa);

    calculerClusters(lifestyle_data.alcohol_consumption, lifestyle_data.id, NombreDeLignes_lifestyle,"Alcohol Consumption", cluster1_ids_ac, cluster2_ids_ac, &nb_cluster1_ac, &nb_cluster2_ac);

    calculerClusters(lifestyle_data.caffeine_consumption, lifestyle_data.id, NombreDeLignes_lifestyle,"Caffeine Consumption", cluster1_ids_cc, cluster2_ids_cc, &nb_cluster1_cc, &nb_cluster2_cc);

    calculerClusters(lifestyle_data.sleep_quality, lifestyle_data.id, NombreDeLignes_lifestyle,"Sleep Quality", cluster1_ids_sq, cluster2_ids_sq, &nb_cluster1_sq, &nb_cluster2_sq);

    // Comparer les clusters pour identifier les corrélations
    analyserClusters(cluster1_ids_pa, nb_cluster1_pa, cluster1_ids_ac, nb_cluster1_ac, "Cluster 1 Physical Activity", "Cluster 1 Alcohol Consumption");
    analyserClusters(cluster1_ids_pa, nb_cluster1_pa, cluster1_ids_cc, nb_cluster1_cc, "Cluster 1 Physical Activity", "Cluster 1 Caffeine Consumption");
    analyserClusters(cluster1_ids_pa, nb_cluster1_pa, cluster1_ids_sq, nb_cluster1_sq, "Cluster 1 Physical Activity", "Cluster 1 Sleep Quality");

    analyserClusters(cluster2_ids_pa, nb_cluster2_pa, cluster2_ids_ac, nb_cluster2_ac, "Cluster 2 Physical Activity", "Cluster 2 Alcohol Consumption");
    analyserClusters(cluster2_ids_pa, nb_cluster2_pa, cluster2_ids_cc, nb_cluster2_cc, "Cluster 2 Physical Activity", "Cluster 2 Caffeine Consumption");
    analyserClusters(cluster2_ids_pa, nb_cluster2_pa, cluster2_ids_sq, nb_cluster2_sq, "Cluster 2 Physical Activity", "Cluster 2 Sleep Quality");

    return 0;
}