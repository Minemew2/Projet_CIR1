#include <stdio.h>

#include "research.h"
#include "create.h"
#include <ctype.h>
#include <stdlib.h>

#include "communication.h"


int main(int argc, char **argv){
    FILE * request = fopen("request.txt", "r");

    Node_realisator * trueTree = initNode('0');
    Realisator * root = createRealisator("byMovieNumberRoot", -1);

    byMovieNumber * ranking = createByMovieNumber(root);

    Film_List ** byDuration = calloc(MAX_MOVIE_DURATION, sizeof(byDuration));

    readCSV(argv[1], trueTree, ranking, byDuration);

    ranking = sortingByMovieNumber(ranking);

    int * mustExit = malloc(sizeof(int));

    do{
        request = fopen("request.txt", "r");
        if(request != NULL){
            readRequest(request, trueTree, ranking, byDuration, mustExit);
        } else {
            fclose(request);
        }
        
    } while (!(*mustExit));
    
    
    return 0;
}