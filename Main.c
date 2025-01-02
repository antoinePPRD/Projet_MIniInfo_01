#include <stdio.h>
#include "main.h"

int main() {
    FILE *lifestyle = fopen("DATA/lifestyle.pengu", "r");
    FILE *patients = fopen("DATA/patients.pengu", "r");

    int nombreDeLignes_lifestyle = compterLignes(lifestyle);
    printf("Nombre de lignes lifestyle : %d\n", nombreDeLignes_lifestyle);

    stlifestyle OBS;
    chargerLifestyle(lifestyle, &OBS);
    afficherLifestyle(&OBS, 5);

    stpatients patient_data;
    chargerPatients(patients, &patient_data);
    afficherPatients(&patient_data, 5);

    fclose(lifestyle);
    fclose(patients);

    return 0;
}