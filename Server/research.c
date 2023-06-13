
#include <time.h>
#include <stdio.h>

#include "research.h"


Film_List * moviesByRealisator(Node_realisator * root, char * requestedRealisator){
    return findRealisator(root, requestedRealisator)->movies;
}

Realisator *topRealisator(byMovieNumber * ranking){
    return ranking->next->data;
}

Film_List * moviesByTime(Film_List ** byDuration, int duration){
    return byDuration[duration-1];
}
