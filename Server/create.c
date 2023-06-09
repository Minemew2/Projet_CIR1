#include "create.h"


Node_realisator *createRealisatorTree(char * nom_fichier_csv){ //C'est un test qu'il faudra supprimer avant d'envoyer le code
    Node_realisator *newRealisator = 0;
    char *realisateur = "Tarantino";
    newRealisator -> character = *realisateur;

    return newRealisator;
}

Realisator **createByMoviesNumber(char * nom_fichier_csv){
    Realisator **newMovieNumber = 0;
    newMovieNumber[0] -> name = "Tarantino";
    newMovieNumber[0] -> nbrMovies = 5;
    newMovieNumber[1] -> name = "Lysandre";
    newMovieNumber[1] -> nbrMovies = 2;
    newMovieNumber[2] -> name = "Gwendale";
    newMovieNumber[2] -> nbrMovies=3;
    return newMovieNumber;
}