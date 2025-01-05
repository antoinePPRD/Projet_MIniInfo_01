#include <stdlib.h>
#include <stdio.h>

/*programme pour supprimer un fichier*/
int main(int argc, char *argv[])
{
    remove(argv[1]);//la fonction qui permet de supprimer le fichier

    return 0;
}