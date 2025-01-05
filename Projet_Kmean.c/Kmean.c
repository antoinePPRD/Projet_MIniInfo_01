#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "main.h"

void afficherMenuComparaisons() {
    printf("\n--- Menu des Comparaisons ---\n");
    printf("1. Physical Activity vs Alcohol Consumption\n");
    printf("2. Physical Activity vs Caffeine Consumption\n");
    printf("3. Physical Activity vs Sleep Quality\n");
    printf("4. Alcohol Consumption vs Caffeine Consumption\n");
    printf("5. Alcohol Consumption vs Sleep Quality\n");
    printf("6. Caffeine Consumption vs Sleep Quality\n");
    printf("0. Quitter\n");
    printf("Veuillez choisir une option : ");
}

void effectuerComparaison(int choix, int *cluster1_ids_pa, int nb_cluster1_pa, int *cluster2_ids_pa, int nb_cluster2_pa, int *cluster1_ids_ac, int nb_cluster1_ac, int *cluster2_ids_ac, int nb_cluster2_ac, int *cluster1_ids_cc, int nb_cluster1_cc, int *cluster2_ids_cc, int nb_cluster2_cc, int *cluster1_ids_sq, int nb_cluster1_sq, int *cluster2_ids_sq, int nb_cluster2_sq) {
    switch (choix) {
        case 1: // Physical Activity vs Alcohol Consumption
            printf("Comparaisons entre Physical Activity et Alcohol Consumption\n");
            analyserClusters(cluster1_ids_pa, nb_cluster1_pa, cluster1_ids_ac, nb_cluster1_ac, "Cluster 1 Physical Activity", "Cluster 1 Alcohol Consumption");
            analyserClusters(cluster2_ids_pa, nb_cluster2_pa, cluster2_ids_ac, nb_cluster2_ac, "Cluster 2 Physical Activity", "Cluster 2 Alcohol Consumption");
            analyserClusters(cluster1_ids_pa, nb_cluster1_pa, cluster2_ids_ac, nb_cluster2_ac, "Cluster 1 Physical Activity", "Cluster 2 Alcohol Consumption");
            analyserClusters(cluster1_ids_ac, nb_cluster1_ac, cluster2_ids_pa, nb_cluster2_pa, "Cluster 1 Alcohol Consumption", "Cluster 2 Physical Activity");
            break;

        case 2: // Physical Activity vs Caffeine Consumption
            printf("Comparaisons entre Physical Activity et Caffeine Consumption\n");
            analyserClusters(cluster1_ids_pa, nb_cluster1_pa, cluster1_ids_cc, nb_cluster1_cc, "Cluster 1 Physical Activity", "Cluster 1 Caffeine Consumption");
            analyserClusters(cluster2_ids_pa, nb_cluster2_pa, cluster2_ids_cc, nb_cluster2_cc, "Cluster 2 Physical Activity", "Cluster 2 Caffeine Consumption");
            analyserClusters(cluster1_ids_pa, nb_cluster1_pa, cluster2_ids_cc, nb_cluster2_cc, "Cluster 1 Physical Activity", "Cluster 2 Caffeine Consumption");
            analyserClusters(cluster1_ids_cc, nb_cluster1_cc, cluster2_ids_pa, nb_cluster2_pa, "Cluster 1 Caffeine Consumption", "Cluster 2 Physical Activity");
            break;

        case 3: // Physical Activity vs Sleep Quality
            printf("Comparaisons entre Physical Activity et Sleep Quality\n");
            analyserClusters(cluster1_ids_pa, nb_cluster1_pa, cluster1_ids_sq, nb_cluster1_sq, "Cluster 1 Physical Activity", "Cluster 1 Sleep Quality");
            analyserClusters(cluster2_ids_pa, nb_cluster2_pa, cluster2_ids_sq, nb_cluster2_sq, "Cluster 2 Physical Activity", "Cluster 2 Sleep Quality");
            analyserClusters(cluster1_ids_pa, nb_cluster1_pa, cluster2_ids_sq, nb_cluster2_sq, "Cluster 1 Physical Activity", "Cluster 2 Sleep Quality");
            analyserClusters(cluster1_ids_sq, nb_cluster1_sq, cluster2_ids_pa, nb_cluster2_pa, "Cluster 1 Sleep Quality", "Cluster 2 Physical Activity");
            break;

        case 4: // Alcohol Consumption vs Caffeine Consumption
            printf("Comparaisons entre Alcohol Consumption et Caffeine Consumption\n");
            analyserClusters(cluster1_ids_ac, nb_cluster1_ac, cluster1_ids_cc, nb_cluster1_cc, "Cluster 1 Alcohol Consumption", "Cluster 1 Caffeine Consumption");
            analyserClusters(cluster2_ids_ac, nb_cluster2_ac, cluster2_ids_cc, nb_cluster2_cc, "Cluster 2 Alcohol Consumption", "Cluster 2 Caffeine Consumption");
            analyserClusters(cluster1_ids_ac, nb_cluster1_ac, cluster2_ids_cc, nb_cluster2_cc, "Cluster 1 Alcohol Consumption", "Cluster 2 Caffeine Consumption");
            analyserClusters(cluster1_ids_cc, nb_cluster1_cc, cluster2_ids_ac, nb_cluster2_ac, "Cluster 1 Caffeine Consumption", "Cluster 2 Alcohol Consumption");
            break;

        case 5: // Alcohol Consumption vs Sleep Quality
            printf("Comparaisons entre Alcohol Consumption et Sleep Quality\n");
            analyserClusters(cluster1_ids_ac, nb_cluster1_ac, cluster1_ids_sq, nb_cluster1_sq, "Cluster 1 Alcohol Consumption", "Cluster 1 Sleep Quality");
            analyserClusters(cluster2_ids_ac, nb_cluster2_ac, cluster2_ids_sq, nb_cluster2_sq, "Cluster 2 Alcohol Consumption", "Cluster 2 Sleep Quality");
            analyserClusters(cluster1_ids_ac, nb_cluster1_ac, cluster2_ids_sq, nb_cluster2_sq, "Cluster 1 Alcohol Consumption", "Cluster 2 Sleep Quality");
            analyserClusters(cluster1_ids_sq, nb_cluster1_sq, cluster2_ids_ac, nb_cluster2_ac, "Cluster 1 Sleep Quality", "Cluster 2 Alcohol Consumption");
            break;

        case 6: // Caffeine Consumption vs Sleep Quality
            printf("Comparaisons entre Caffeine Consumption et Sleep Quality\n");
            analyserClusters(cluster1_ids_cc, nb_cluster1_cc, cluster1_ids_sq, nb_cluster1_sq, "Cluster 1 Caffeine Consumption", "Cluster 1 Sleep Quality");
            analyserClusters(cluster2_ids_cc, nb_cluster2_cc, cluster2_ids_sq, nb_cluster2_sq, "Cluster 2 Caffeine Consumption", "Cluster 2 Sleep Quality");
            analyserClusters(cluster1_ids_cc, nb_cluster1_cc, cluster2_ids_sq, nb_cluster2_sq, "Cluster 1 Caffeine Consumption", "Cluster 2 Sleep Quality");
            analyserClusters(cluster1_ids_sq, nb_cluster1_sq, cluster2_ids_cc, nb_cluster2_cc, "Cluster 1 Sleep Quality", "Cluster 2 Caffeine Consumption");
            break;

        case 0:
            printf("Au revoir !\n");
            break;

        default:
            printf("Option invalide. Veuillez réessayer.\n");
    }
}

int main() {
    // Fonction rodom 
    srand(time(NULL));
    FILE *lifestyle = fopen("DATA/lifestyle.pengu", "r");

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
    calculerClusters(lifestyle_data.physical_activity, lifestyle_data.id, NombreDeLignes_lifestyle, "Physical Activity", cluster1_ids_pa, cluster2_ids_pa, &nb_cluster1_pa, &nb_cluster2_pa);
    calculerClusters(lifestyle_data.alcohol_consumption, lifestyle_data.id, NombreDeLignes_lifestyle, "Alcohol Consumption", cluster1_ids_ac, cluster2_ids_ac, &nb_cluster1_ac, &nb_cluster2_ac);
    calculerClusters(lifestyle_data.caffeine_consumption, lifestyle_data.id, NombreDeLignes_lifestyle, "Caffeine Consumption", cluster1_ids_cc, cluster2_ids_cc, &nb_cluster1_cc, &nb_cluster2_cc);
    calculerClusters(lifestyle_data.sleep_quality, lifestyle_data.id, NombreDeLignes_lifestyle, "Sleep Quality", cluster1_ids_sq, cluster2_ids_sq, &nb_cluster1_sq, &nb_cluster2_sq);

    int choix;
    do {
        afficherMenuComparaisons();
        scanf("%d", &choix);
        effectuerComparaison(choix, cluster1_ids_pa, nb_cluster1_pa, cluster2_ids_pa, nb_cluster2_pa,cluster1_ids_ac, nb_cluster1_ac, cluster2_ids_ac, nb_cluster2_ac,cluster1_ids_cc, nb_cluster1_cc, cluster2_ids_cc, nb_cluster2_cc,cluster1_ids_sq, nb_cluster1_sq, cluster2_ids_sq, nb_cluster2_sq);
    } while (choix != 0);

    return 0;
}