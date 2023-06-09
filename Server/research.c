
#include <time.h>

#include "research.h"
#include "create.h"


Film **moviesByRealisator(Node_realisator* root, char requestedRealisator){


    return 0;
}

Realisator *topRealisator(Realisator **byMoviesNumber){
    int timeFunction = 0;
    time_t begin = time(NULL);
    Realisator *firstRealisator = byMoviesNumber[0]; // firstRealisator vaut le premier réalisateur qui se trouve dans byMoviesNumber
    time_t end = time(NULL);
    timeFunction = difftime(end, begin);
    return firstRealisator;
}


