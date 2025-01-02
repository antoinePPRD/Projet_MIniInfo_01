#include <stdio.h>
#include "main.h"

int main() {
    // Ouverture des fishier 
    FILE *lifestyle = fopen("DATA/lifestyle.pengu", "r");
    FILE *patients = fopen("DATA/patients.pengu", "r");

    // calcul le nombre de ligne 
    int NombreDeLignes_lifestyle = compterLignes(lifestyle);
    int NombreDeLignes_patients = compterLignes(patients);
    printf("Nombre de lignes lifestyle : %d\n", NombreDeLignes_lifestyle);
    printf("Nombre de lignes patients : %d\n", NombreDeLignes_patients);

    // Initialiser la structure stlifestyle 
    stlifestyle OBS;
    chargerLifestyle(lifestyle, &OBS);
    // TEST Afficher les 5 premiers enregistrements pour vérifier
    afficherLifestyle(&OBS, 5);

    // Initialiser la structure stpatients 
    stpatients patient_data;
    chargerPatients(patients, &patient_data);
    // TEST Afficher les 5 premiers enregistrements pour vérifier
    afficherPatients(&patient_data, 5);

    fclose(lifestyle);
    fclose(patients);

    return 0;
}