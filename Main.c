// Bibliotheque : 
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// calcul le nombre de ligne du fichier 
int compterLignes(FILE *fichier) {
    int car, NbLigne;

    car = 0;
    NbLigne = 1;

    // Parcourir le fichier pour compter les lignes
    while ((car = fgetc(fichier)) != EOF) {
        if (car == '\n') {
            ++NbLigne;
        }
    }

    return NbLigne;
}

int main (){

    // Ouverture des fishier 
    
    FILE* lifestyle = NULL;
    FILE* patients = NULL;
    lifestyle = fopen("DATA/lifestyle.pengu", "r+");
    patients = fopen("DATA/patients.pengu", "r+");
    
    // Test pour verifier que le fishier et bien lu 
    //int caractereActuel = 0;
    //if (patients != NULL){
            //do{
                //caractereActuel = fgetc(patients); 
                //printf("%c", caractereActuel); 
            //} while (caractereActuel != EOF);
 
            //fclose(patients);
    //}
    
    int score[3] = {0}; // Tableau des 3 meilleurs scores
 
    if (patients != NULL){
        fscanf(patients, "%d %d %d", &score[0], &score[1], &score[2]);
        printf("Les meilleurs scores sont : %d, %d et %d", score[0], score[1], score[2]);
    }
 
    // calcul le nombre de ligne du fichier 
    int nombreDeLignes_lifestyle = compterLignes(lifestyle);
    printf("Nombre de lignes : %d\n", nombreDeLignes_lifestyle);
    

    fclose(lifestyle);
    fclose(patients);

    stlifestyle OBS ; 
    OBS.id[0] = 50 ; 
    printf("%d\n", OBS.id[0]);

    
    return 0 ;
}