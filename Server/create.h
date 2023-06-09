#ifndef CREATE_H
#define CREATE_H


typedef struct Film{
	char * name;
	char * realisator;
	float time; // en minutes
	char * category;
}Film;

typedef struct Realisator{
	char * name;
	int nbrMovies;
}Realisator;

typedef struct Node_realisator Node_realisator;
struct Node_realisator{
	char character;
	int isName;
	Film ** associateMovies; //Tous les films de l'auteur
	Node_realisator ** childs;
};


Realisator **createByMoviesNumber(char * nom_fichier_csv);

Node_realisator * createRealisatorTree(char * nom_fichier_csv); //C'est un test qu'il faudra supprimer avant d'envoyer le code
#endif