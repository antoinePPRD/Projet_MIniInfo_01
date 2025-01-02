// Bibliotheque : 
#include <stdio.h>
#include <stdlib.h>

int main (){

    // Ouverture des fishier 

    FILE* lifestyle = NULL;
    FILE* patients = NULL;
    
    lifestyle = fopen("DATA/lifestyle.pengu", "r+");
    patients = fopen("DATA/patients.pengu", "r+");
    
    // Test pour verifier que le fishier et bien lu 
    int caractereActuel = 0;
    
    if (patients != NULL){
            do{
                caractereActuel = fgetc(patients); 
                printf("%c", caractereActuel); 
            } while (caractereActuel != EOF);
 
            fclose(patients);
    }
    fclose(lifestyle);

    return 0 ;
}