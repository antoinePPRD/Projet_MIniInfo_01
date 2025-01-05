#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "main.h"
int CalculeDistanceCluster(float cluster, float data) {
    return fabs(cluster - data);
}

void calculerClusters(float *data,int *data2, int *ids, int n, const char *attribut, int *cluster1_ids, int *cluster2_ids, int *nb_cluster1, int *nb_cluster2) {
    int r1, r2;
    r1 = rand() % n;
    r2 = rand() % n;
    float cluster1 = data[r1];
    float cluster2 = data[r2];

    printf("Initialisation (%s) : Cluster 1 = %f (Index %d), Cluster 2 = %f (Index %d)\n",attribut, cluster1, r1, cluster2, r2);

    float Moyen_cluster1_0 = 0, Moyen_cluster1_1 = cluster1;
    float Moyen_cluster2_0 = 0, Moyen_cluster2_1 = cluster2;

    int conteur_cluster1 = 0, conteur_cluster2 = 0;
    int conteur_Patient_Risque_cluster1 = 0 , conteur_Patient_Risque_cluster2 = 0 ;
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
                conteur_Patient_Risque_cluster1 = conteur_Patient_Risque_cluster1 + data2[i];
            } 
            else {
                Somme_cluster2 = Somme_cluster2 + data[i];
                conteur_cluster2++;
                cluster2_ids[conteur_cluster2] = ids[i];
                conteur_Patient_Risque_cluster2 = conteur_Patient_Risque_cluster2 + data2[i];
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

    int pourcentage_Patient_Risque_cluster1 = (conteur_Patient_Risque_cluster1 / conteur_cluster1)*100;
    int pourcentage_Patient_Risque_cluster2 = (conteur_Patient_Risque_cluster2 / conteur_cluster2)*100;

    printf("Final (%s): Cluster 1 = %f, Nombre d'éléments = %d\n", attribut, cluster1, conteur_cluster1);
    printf("Le nombre de patient a risque dans le cluster 1 est de : %d ce qui fait %d pourcent ", conteur_Patient_Risque_cluster1, pourcentage_Patient_Risque_cluster1 );
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

    float pourcentage1 = (intersection / nb_cluster1) * 100;
    float pourcentage2 = (intersection / nb_cluster2) * 100;

    printf("Meme IDs entre %s et %s : %f\n", attribut1, attribut2, intersection);
    printf("Pourcentage de similarité %s : %f\n", attribut1, pourcentage1);
    printf("Pourcentage de similarité %s : %f\n", attribut2, pourcentage2);
}

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

    // Ouverture des fishier 
    FILE *lifestyle = fopen("DATA/lifestyle.pengu", "r");
    FILE *patients = fopen("DATA/patients.pengu", "r");

    // calcul le nombre de ligne lifestyle
    int NombreDeLignes_lifestyle = compterLignes(lifestyle);
    
    // Mise en mémoire des informations contenues dans les fichiers dans une structure appropriée  
    stlifestyle lifestyle_data;
    chargerLifestyle(lifestyle, &lifestyle_data);
    stpatients patient_data;
    chargerPatients(patients, &patient_data);

    // Fermeture des fishier
    fclose(lifestyle);
    fclose(patients);


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
    calculerClusters(lifestyle_data.physical_activity, patient_data.condition, lifestyle_data.id, NombreDeLignes_lifestyle, "Physical Activity", cluster1_ids_pa, cluster2_ids_pa, &nb_cluster1_pa, &nb_cluster2_pa);
    calculerClusters(lifestyle_data.alcohol_consumption, patient_data.condition, lifestyle_data.id, NombreDeLignes_lifestyle, "Alcohol Consumption", cluster1_ids_ac, cluster2_ids_ac, &nb_cluster1_ac, &nb_cluster2_ac);
    calculerClusters(lifestyle_data.caffeine_consumption, patient_data.condition, lifestyle_data.id, NombreDeLignes_lifestyle, "Caffeine Consumption", cluster1_ids_cc, cluster2_ids_cc, &nb_cluster1_cc, &nb_cluster2_cc);
    calculerClusters(lifestyle_data.sleep_quality, patient_data.condition, lifestyle_data.id, NombreDeLignes_lifestyle, "Sleep Quality", cluster1_ids_sq, cluster2_ids_sq, &nb_cluster1_sq, &nb_cluster2_sq);

    int choix;
    do {
        afficherMenuComparaisons();
        scanf("%d", &choix);
        effectuerComparaison(choix, cluster1_ids_pa, nb_cluster1_pa, cluster2_ids_pa, nb_cluster2_pa,cluster1_ids_ac, nb_cluster1_ac, cluster2_ids_ac, nb_cluster2_ac,cluster1_ids_cc, nb_cluster1_cc, cluster2_ids_cc, nb_cluster2_cc,cluster1_ids_sq, nb_cluster1_sq, cluster2_ids_sq, nb_cluster2_sq);
    } while (choix != 0);

    return 0;
}