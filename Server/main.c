#include <stdio.h>

#include "research.h"
#include "create.h"
#include <ctype.h>
#include <stdlib.h>

#include "communication.h"





int main(){
    FILE * request = fopen("request.txt", "r");

    Node_realisator * trueTree = initNode('0');
    Realisator * fake = createRealisator("byMovieNumberRoot", -1);

    byMovieNumber * byMoviesNumber = createByMovieNumber(fake);

    Film_List ** byDuration = calloc(MAX_MOVIE_DURATION, sizeof(byDuration));

    readCSV("test.csv", trueTree, byMoviesNumber, byDuration);

    byMoviesNumber = sortingByMovieNumber(byMoviesNumber);
    // printByMovieNumber(byMoviesNumber);

    // Node_realisator * trueTree = initNode('R');
    for(int i = 0; i<27; i++){
        // printf("%p\n", trueTree->childs[i]);
    }
    
    // Realisator ** byMoviesNumber = createByMoviesNumber("test.csv");
    // printTree(trueTree);

    // printFilmList(byDuration[266]); 

    // realisatorResult(, 0.15);
    realisatorResult(topRealisator(byMoviesNumber), 0.15);
    return 0;
}