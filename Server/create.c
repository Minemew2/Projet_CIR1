#include "create.h"
#include <string.h>
#include <stdlib.h>


Node_realisator *createRealisatorTree(char * nom_fichier_csv){ //C'est un test qu'il faudra supprimer avant d'envoyer le code
    Node_realisator *newRealisator = 0;
    char *realisateur = "Tarantino";
    newRealisator -> character = *realisateur;

    return newRealisator;
}

Realisator **createByMoviesNumber(char * nom_fichier_csv){

    Realisator **newMovieNumber = malloc(sizeof(Realisator*)*3);
    newMovieNumber[0] = malloc(sizeof(Realisator));
    newMovieNumber[0] -> name = "Tarantino";
    newMovieNumber[0] -> nbrMovies = 5;

    newMovieNumber[1] = malloc(sizeof(Realisator));
    newMovieNumber[1] -> name = "Lysandre";
    newMovieNumber[1] -> nbrMovies = 2;
    
    newMovieNumber[2] = malloc(sizeof(Realisator));
    newMovieNumber[2] -> name = "Gwendal";
    newMovieNumber[2] -> nbrMovies=3;
    return newMovieNumber;
}