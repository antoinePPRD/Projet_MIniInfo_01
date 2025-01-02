// Bibliotheque : 
#include <stdio.h>
#include <stdlib.h>
#include "main.h"


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

    // calcul le nombre de ligne du fichier 
    int car, NbLigne ;
    car = 0 ;
    NbLigne = 1;
    
    while (( car = fgetc(lifestyle)) != EOF){
        printf("%c",car);
        if (car == '\n'){
            ++NbLigne;
        }
    }
    printf("%d\n", NbLigne);
    
    fclose(lifestyle);
    fclose(patients);

    stlifestyle OBS ; 
    OBS.id[0] = 50 ; 
    printf("%d\n", OBS.id[0]);

    
    return 0 ;
}