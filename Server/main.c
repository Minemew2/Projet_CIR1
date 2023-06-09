#include <stdio.h>

#include "research.h"
#include "create.h"


int main(){
    Realisator *bestRealisator = topRealisator(createByMoviesNumber);
    printf("\n%s\n\n",bestRealisator->name);
    printf("Hello world !\n");
    return 0;
}