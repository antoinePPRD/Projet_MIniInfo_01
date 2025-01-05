#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "main.h"

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