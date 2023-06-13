#include <stdio.h>

#include "research.h"
#include "create.h"
#include <ctype.h>
#include <stdlib.h>

#include "communication.h"


#define DATABASE "test.csv"


int main(){
    FILE * request = fopen("request.txt", "r");

    Node_realisator * trueTree = initNode('0');
    Realisator * root = createRealisator("byMovieNumberRoot", -1);

    byMovieNumber * ranking = createByMovieNumber(root);

    Film_List ** byDuration = calloc(MAX_MOVIE_DURATION, sizeof(byDuration));

    readCSV(DATABASE, trueTree, ranking, byDuration);

    ranking = sortingByMovieNumber(ranking);
    // printByMovieNumber(ranking);

    // Node_realisator * trueTree = initNode('R');
    for(int i = 0; i<27; i++){
        // printf("%p\n", trueTree->childs[i]);
    }
    
    // Realisator ** byMoviesNumber = createByMoviesNumber("test.csv");
    // printTree(trueTree);

    // printFilmList(byDuration[266]); 
    char user = 0;
    do{
        request = fopen("request.txt", "r");
        if(request != NULL){
            readRequest(request, trueTree, ranking, byDuration);
        } else {
            fclose(request);
        }
        
        // scanf("%c\n", &user);
    } while (user != 'q');
    
    
    return 0;
}