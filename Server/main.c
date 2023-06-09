#include <stdio.h>

#include "research.h"
#include "create.h"


int main(){
    char *nameTest = "Bonjour";
    printf("%s\n",nameTest);
    Realisator **byMoviesNumber = createByMoviesNumber(nameTest);
    Realisator *bestRealisator = topRealisator(byMoviesNumber);
    printf("\n%s\n\n",bestRealisator->name);
    printf("Hello world !\n");
    return 0;
}