#include <stdio.h>
#include <stdlib.h> 
#include "main.h"


int CalculeDistanceCluster(float cluster, float data){
    
    float Disance = 0; 
    
    if (cluster > data)
         Disance = cluster - data ;
    else Disance = data - cluster ;

    return Disance;
}

float CalculMoyen(){

}

int main(){
    // Ouverture des fishier 
    FILE *lifestyle = fopen("DATA/lifestyle.pengu", "r");
    FILE *patients = fopen("DATA/patients.pengu", "r");

    // calcul le nombre de ligne 
    int NombreDeLignes_lifestyle = compterLignes(lifestyle);
    int NombreDeLignes_patients = compterLignes(patients);
    printf("Nombre de lignes lifestyle : %d\n", NombreDeLignes_lifestyle);
    printf("Nombre de lignes patients : %d\n", NombreDeLignes_patients);

    // Initialiser la structure stlifestyle 
    stlifestyle lifestyle_data;
    chargerLifestyle(lifestyle, &lifestyle_data);

    // Initialiser la structure stpatients 
    stpatients patient_data;
    chargerPatients(patients, &patient_data);

    int n = 2 ;  
    // Initialisation des cluster initio 
    float cluster1 = rand();
    float cluster2 = rand();

    float Moyen_cluster1_0 = 0; 
    float Moyen_cluster1_1 = 0;
    
    float Moyen_cluster2_0 = 0;
    float Moyen_cluster2_1 = 0;
    
    float Disance_cluster1 = 0;
    float Disance_cluster2 = 0;
    
    int conteur_cluster1 = 0; 
    int conteur_cluster2 = 0;
    
    float Somme_cluster1 = 0; 
    float Somme_cluster2 = 0; 

    int id_patient_cluster1[NombreDeLignes_lifestyle];
    int id_patient_cluster2[NombreDeLignes_lifestyle];

    for (int i = 0; i < 2 ; i++){
        while ((Moyen_cluster1_0 - 2 < Moyen_cluster1_1) && (Moyen_cluster1_1 < Moyen_cluster1_0 + 2)){
            for(int k = 0 ; k < NombreDeLignes_lifestyle ; k++ ){
                Disance_cluster1 = CalculeDistanceCluster(cluster1,lifestyle_data.id[k]);
                Disance_cluster2 = CalculeDistanceCluster(cluster2,lifestyle_data.id[k]);
                
                if (Disance_cluster1 < Disance_cluster2){
                    Somme_cluster1 = lifestyle_data.id[k] + Somme_cluster1;
                    id_patient_cluster1[conteur_cluster1] = lifestyle_data.id[k];
                    conteur_cluster1 ++ ;
                } 
                else{
                    Somme_cluster2 = lifestyle_data.id[k] + Somme_cluster2;
                    id_patient_cluster2[conteur_cluster2] = lifestyle_data.id[k];
                    conteur_cluster2 ++ ;
                }
            }
        Moyen_cluster1_0 = Moyen_cluster1_1 ;
        Moyen_cluster1_1 = Somme_cluster1 / conteur_cluster1;
        cluster1 = Moyen_cluster1_1 ; 
        
        Moyen_cluster2_0 = Moyen_cluster2_1 ;
        Moyen_cluster2_1 = Somme_cluster2 / conteur_cluster2 ; 
        cluster2 = Moyen_cluster2_1 ;
        }
    }

    printf("les cluster sont %f %f", cluster1 , cluster2);


}